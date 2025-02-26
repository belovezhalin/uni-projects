--STATUS FULLTEXT
SELECT FULLTEXTSERVICEPROPERTY('IsFullTextInstalled') 
AS [FULLTEXTSERVICE]



USE Northwind
GO

--ZASTOSOWANIE THESAURUS DO SYNONIMOW
EXEC sys.sp_fulltext_load_thesaurus_file 1033;

SELECT * FROM Suppliers

--TWORZENIE INDEKSU UNIKALNEGO, NA KTORYM BEDZIE TWORZONY INDEX PELNOTEKSTOWY
CREATE UNIQUE INDEX ui_SupplierID ON dbo.Suppliers(SupplierID);

SELECT name, type_desc, is_primary_key, is_unique 
FROM sys.indexes 
WHERE object_id = OBJECT_ID('dbo.Suppliers');

--TWORZENIE KATALOGU I INDEKSU PELNOTEKSTOWYCH
CREATE FULLTEXT CATALOG FullTextCatalog

CREATE FULLTEXT INDEX ON dbo.Suppliers
(  
    ContactTitle Language 1033     
)  
KEY INDEX ui_SupplierID ON FullTextCatalog
WITH CHANGE_TRACKING AUTO          
GO

--ROZNICA MIEDZY CONTAINS A FREETEXT
SELECT * FROM Suppliers

SELECT * FROM Suppliers
WHERE CONTAINS(ContactTitle,'Sales')

SELECT * FROM Suppliers
WHERE CONTAINS(ContactTitle,'Sale')

SELECT * FROM Suppliers
WHERE FREETEXT(ContactTitle,'Sales')

SELECT * FROM Suppliers
WHERE FREETEXT(ContactTitle,'Sale')

--KORZYSTANIE Z SYNONIMOW I THESAURUS
INSERT INTO Products (ProductName, SupplierID, CategoryID, QuantityPerUnit, UnitPrice, UnitsInStock, UnitsOnOrder, ReorderLevel, Discontinued)
VALUES
    ('Dark Chocolate Bar', 1, 3, '10 bars per pack', 15.00, 100, 0, 10, 0),
    ('Milk Chocolate Truffles', 2, 3, '5 pieces per box', 25.00, 50, 0, 5, 0),
    ('White Chocolate Cookies', 3, 3, '12 cookies per pack', 12.00, 80, 0, 8, 0),
    ('Hot Chocolate Mix', 4, 3, '500g pack', 10.00, 60, 0, 6, 0),
    ('Belgian Chocolate Pralines', 5, 3, '20 pieces per box', 30.00, 40, 0, 4, 0);

INSERT INTO Products (ProductName, SupplierID, CategoryID, QuantityPerUnit, UnitPrice, UnitsInStock, UnitsOnOrder, ReorderLevel, Discontinued)
VALUES
    ('Cocoa Powder', 6, 3, '250g pack', 8.00, 100, 0, 10, 0),
    ('Hot Cocoa Drink', 7, 3, '500ml bottle', 12.00, 50, 0, 5, 0),
    ('Hazelnut Spread', 8, 3, '300g jar', 20.00, 40, 0, 5, 0),
    ('Sweet Dessert Truffles', 9, 3, '10 pieces per box', 18.00, 30, 0, 3, 0),
    ('Dark Cocoa Beans', 10, 3, '1kg bag', 25.00, 20, 0, 2, 0);

SELECT * FROM Products
WHERE CONTAINS(ProductName,'Cocoa')

SELECT * FROM Products
WHERE FREETEXT(ProductName,'Cocoa')




USE AdventureWorks2022  
GO  

CREATE UNIQUE INDEX ui_ProductID ON Production.Product(ProductID);

SELECT name, type_desc, is_primary_key, is_unique 
FROM sys.indexes 
WHERE object_id = OBJECT_ID('Production.Product');

CREATE FULLTEXT CATALOG FullTextCatalog

CREATE FULLTEXT INDEX ON Production.Product
(  
     Name Language 1033     
)  
KEY INDEX ui_ProductID ON FullTextCatalog
WITH CHANGE_TRACKING AUTO          
GO

SELECT * FROM Production.Product

SELECT Name, ListPrice FROM Production.Product  
WHERE ListPrice = 80.99 AND Name LIKE '%mountain%'

SELECT Name, ListPrice FROM Production.Product  
WHERE ListPrice = 80.99 AND CONTAINS(Name, 'Mountain')   
  
SELECT * FROM Production.Document

--DOPASOWYWANIE DO ZNACZENIA
SELECT Title  FROM Production.Document  
WHERE FREETEXT (Document, 'vital safety components')
  
--WYSZUKIWANIE FRAZY
SELECT Comments FROM Production.ProductReview  
WHERE CONTAINS(Comments, '"learning curve"')  



CREATE UNIQUE INDEX ui_ProductDescriptionID ON Production.ProductDescription(ProductDescriptionID);

CREATE FULLTEXT INDEX ON Production.ProductDescription
(  
     Description Language 1033     
)  
KEY INDEX ui_ProductDescriptionID ON FullTextCatalog
WITH CHANGE_TRACKING AUTO          

--WYSZUKIWANIE NA PODSTAWIE CZESCI SLOWA
SELECT Description, ProductDescriptionID FROM Production.ProductDescription  
WHERE CONTAINS (Description, '"top*"' )  

--WYKORZYSTANIE STEMMEROW
SELECT Comments, ReviewerName FROM Production.ProductReview  
WHERE CONTAINS (Comments, 'FORMSOF(INFLECTIONAL, "foot")')  


EXEC sp_helpindex 'Person.Address';
CREATE FULLTEXT INDEX ON Person.Address (AddressLine1)
    KEY INDEX PK_Address_AddressID; 

--WYSZUKIWANIE Z RANK I WAGA
SELECT K.RANK,
    AddressLine1,
    City
FROM Person.Address AS A
INNER JOIN CONTAINSTABLE(Person.Address, AddressLine1, 'ISABOUT ("des*",
    Rue WEIGHT(0.5),
    Bouchers WEIGHT(0.9))', 3) AS K
    ON A.AddressID = K.[KEY];

USE AdventureWorks2022;
GO

--PRZYKLAD ZAAWANSOWANEGO WYSZUKIWANIA PELNOTEKSTOWEGO
SELECT FT_TBL.ProductDescriptionID,
    FT_TBL.Description,
    KEY_TBL.RANK
FROM Production.ProductDescription AS FT_TBL
INNER JOIN FREETEXTTABLE(Production.ProductDescription,
    Description, '(light NEAR aluminum) OR (lightweight NEAR aluminum)', 5) AS KEY_TBL
        ON FT_TBL.ProductDescriptionID = KEY_TBL.[KEY];



--STOPLIST
CREATE FULLTEXT STOPLIST MyStoplist;

ALTER FULLTEXT STOPLIST MyStoplist
ADD 'the', 'and', 'is';

CREATE FULLTEXT INDEX ON Production.ProductReview (Comments)
KEY INDEX ui_ProductReviewID
ON FullTextCatalog
WITH STOPLIST = MyStoplist;

SELECT * FROM Production.ProductReview
WHERE CONTAINS(Comments, 'just');