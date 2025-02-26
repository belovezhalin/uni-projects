//Anhelina Belavezha - grupa nr 2
/*Ogolna idea programu: operacje nad pociagami i ich modyfikacja. Program musi dzialac w czasie O(1) (poza Display i TrainsList) i uzywac jak
 * najmniej pamieci. Wszystkie pomocnicze operacje (np wstawianie nowego pociagu) sa zaimplementowane tak aby zawieraly minimalna
liczbe przegladow list.*/
import java.util.Scanner;                                //import do scannera

class Wagon {                                            //klasa wagon
    public String nazwawagonu;                           //zmienna przechowujaca nazwe wagonu
    public Wagon previous;                               //referencja na poprzedni wagon
    public Wagon next;                                   //referencja na nastepny wagon

    public Wagon(String name) {                          //konstruktor klasy Wagon
        nazwawagonu = name;}

    public void Update() {                               //aktualizacja referencji na poprzedni i nastepny wagon
        if(next.previous != this) {                      //jesli nastepny wagon nie ma ustawianej referencji na obecny wagon jako poprzedni
            Wagon tempwagon = next.previous;             //swap referencji na nastepny wagon 
            next.previous = next.next;
            next.next = tempwagon;}

        if(previous.next != this) {                      //jesli poprzedni wagon nie ma ustalionej referencji na obecny wagon jako nastepny
            Wagon tempwagon = previous.previous;         //swap referenji na poprzedni wagon
            previous.previous = previous.next;
            previous.next = tempwagon;}}}

class Train {                                            //klasa pociag
    public String nazwapociagu;                          //zmienna przechowujaca nazwe pociagu
    public Wagon pierwszywagon;                          //referencja na pierwszy wagon
    public Train next;                                   //referencja na nastepny pociag

    public Train(String name) {                          //konstruktor klasy Train
        nazwapociagu = name;}}

class TrainsList {                                       //klasa przechowujaca liste pociagow
    public Train pierwszypociag;                         //referencja na pierwszy pociag

    public TrainsList() {                                //konstruktor klasy TrainsList
        pierwszypociag = null;}

    Train Find(String nazwapociagu) {                                 
        Train actual = pierwszypociag;

        while (actual != null) {                        //wyszukowanie pociagu wedlug nazwy i jej zwracanie                         
            if (nazwapociagu.equals(actual.nazwapociagu)) return actual;                                     
            actual = actual.next;}
    return null;}                                       //w przeciwnym przypadku zwracamy null

    void NewTrain(String nazwapociagu, String nazwawagonu) {       //funkcja dodajaca nowy pociag                                                      
        Train NewTrain = new Train(nazwapociagu);                  //tworzenie nowego pociagu           
        Train previousfirst = pierwszypociag;                      //aktualizacja referencji na poprzedni pierwszy pociag oraz na pierwszy wagon nowego pociagu             
        pierwszypociag = NewTrain;                                      
        pierwszypociag.next = previousfirst;                                
        pierwszypociag.pierwszywagon = new Wagon(nazwawagonu);     //zamykamy liste wagonow w pierwszym pociagu (przez inicjalizacje referencji na poprzedni i nastepny wagon w nowym pociagu)               
        pierwszypociag.pierwszywagon.next = pierwszypociag.pierwszywagon;             
        pierwszypociag.pierwszywagon.previous = pierwszypociag.pierwszywagon;}

    void InsertFirst(String nazwapociagu, String nazwawagonu) {                //dodawanie wagonu na poczatek pociagu             
        Train changetrain = Find(nazwapociagu);                        

        if(changetrain != null) {                                              //jesli pociag istnieje                        
            Wagon previousfirstwagon = changetrain.pierwszywagon;                          
            changetrain.pierwszywagon = new Wagon(nazwawagonu);                         
            changetrain.pierwszywagon.previous = previousfirstwagon.previous;  //poprzedni wagon nowego wagonu ustawiany jest na poprzedni wagon pierwszego wagonu w pociagu      
            changetrain.pierwszywagon.next = previousfirstwagon;               //nastepny wagon nowego wagonu ustawiany jest na pierwszy wagon w pociagu       
            previousfirstwagon.previous.next = changetrain.pierwszywagon;      //referencje na poprzedni i nastepny wagon poprzedniego pierwszego wagonu w pociągu sa ustawiane na nowy wagon       
            previousfirstwagon.previous = changetrain.pierwszywagon;}}

    void InsertLast(String nazwapociagu, String nazwawagonu) {                 //dodawanie wagonu na koniec pociagu            
        Train changetrain = Find(nazwapociagu);                       

        if(changetrain != null) {                                              //jesli pociag istnieje 
            Wagon newwagon = new Wagon(nazwawagonu);                                         
            newwagon.previous = changetrain.pierwszywagon.previous;            //poprzedni wagon nowego wagonu ustawiany jest na poprzedni wagon ostatniego wagonu w pociagu                  
            changetrain.pierwszywagon.previous.next = newwagon;                //nastepny wagon nowego wagonu ustawiany jest na pierwszy wagon w pociagu            
            changetrain.pierwszywagon.previous = newwagon;                     //referencje na poprzedni i nastepny wagon ostatniego wagonu w pociagu sa ustawiane na nowy wagon  
            newwagon.next = changetrain.pierwszywagon;}}

    void Display(String nazwapociagu) {                                        //funkcja wyswietlajaca pociag                                  
        Train showtrain = Find(nazwapociagu);                              

        if(showtrain != null) {                                                //jesli pociag istnieje                                        
            Wagon actual = showtrain.pierwszywagon;                     
            System.out.print(nazwapociagu + ": ");
    
            do {
                boolean needtoupdate = false;                                  //flaga wskazujaca czy trzeba zaktualizowac referencje
                if(actual.previous.next != actual) needtoupdate = true;
                else if(actual.next.previous != actual) needtoupdate = true;
                if(needtoupdate)
                      actual.Update();                                         //aktualizacja referencji na poprzedni i nastepny wagon, jesli sa niepoprawne
                System.out.print(actual.nazwawagonu + " ");                    //wypisywanie wagonow                 
                actual = actual.next;}
            while (actual != showtrain.pierwszywagon);
            System.out.println("");}}

    void DisplayList() {                                                       //funkcja wyswietlajaca liste wszystkich pociagow  
        Train actual = pierwszypociag;                                                   
        System.out.print("Trains: ");

        while(actual != null) {                                            
            System.out.print(actual.nazwapociagu + " ");                       //wypisywanie pociagow                 
            actual = actual.next;}
        System.out.println("");}
    
    void Reverse(String nazwapociagu) {                                        //funkcja obracajaca kierunek jazdy pociagu
        Train changewagon = Find(nazwapociagu);                                     

        if(changewagon != null) {                                              //jesli wagon istnieje
            changewagon.pierwszywagon.Update();                                //zmieniamy referencje na poprzedni i nastepny wagon
            changewagon.pierwszywagon.previous.Update();

            Wagon previousfirstwagon = changewagon.pierwszywagon;              //ustawiamy referencje pierwszywagon na poprzedni wagon previous od pierwszywagon
            changewagon.pierwszywagon = previousfirstwagon.previous;                                  
            changewagon.pierwszywagon.next = previousfirstwagon.previous.previous;//ustawiamy referencje next od pierwszywagon na previous.previous, czyli wagon ktory byl przed previous 
            changewagon.pierwszywagon.previous = previousfirstwagon;           //ustawiamy referencje previous od pierwszywagon na previous                           
            previousfirstwagon.previous = previousfirstwagon.next;             //zmieniamy referencje na previous i next dla wagonow previous i previous.previous aby odwrocic ich kolejnosc                
            previousfirstwagon.next = changewagon.pierwszywagon;}}
        
    void DeleteTrain(Train previoustrain) {                                                           
        if(previoustrain == null) pierwszypociag = pierwszypociag.next;        //pierwszy pociag na liscie zostanie usumiety                                                         
        else previoustrain.next = previoustrain.next.next;}                    //usuniecie pociagu poprzez zmiane wskaznika                                        

    void Union(String nazwa1, String nazwa2) {
        Wagon tempwagon = null;                                                //aktualny wagon
        Train t1 = Find(nazwa1);                                               //szukanie pierwszego pociagu
        Train t2 = null;
        Train beforesecondtrain = null;
        Train temptrain = null;
        Train actual = pierwszypociag;
        boolean findsecondtrain = false;
    
        while(actual != null) {
            if(nazwa2.equals(actual.nazwapociagu)) {                           //po wynalezieniu dwoch pociagow
                beforesecondtrain = temptrain;
                findsecondtrain = true;}
            temptrain = actual;                                                //zapisujemy wskaznik do drugiego pociagu oraz jego poprzednika
            actual = actual.next;}
    
        if(findsecondtrain && t1 != null) {
            if(beforesecondtrain == null) t2 = pierwszypociag;
            else t2 = beforesecondtrain.next;

            t1.pierwszywagon.Update();
            t2.pierwszywagon.Update();
            t1.pierwszywagon.previous.Update();
            t2.pierwszywagon.previous.Update();

            /*funkcja laczy wagon poprzedzajacy pierwszy wagon pierwszego pociagu z wagonem poprzedzajacym pierwszy wagon drugiego pociagu.
             * W ten sposob powstaje nowa lista pociagu zawierajaca wszystkie wagony z obu pociagow. 
             * Nastepnie drugi pociag jest usuwany z listy pociagow przy uzyciu funkcji DeleteTrain.*/

            t2.pierwszywagon.previous.next = t1.pierwszywagon;
            t1.pierwszywagon.previous.next = t2.pierwszywagon;
            tempwagon = t1.pierwszywagon.previous;
            t1.pierwszywagon.previous = t2.pierwszywagon.previous;
            t2.pierwszywagon.previous = tempwagon;
            DeleteTrain(beforesecondtrain);}}
    
    void DeleteFirst(String nazwa1, String nazwa2) {                           //funkcja usuwa pierwszy wagon pierwszego pociagu i przypina do drugiego pociagu
        Train t1 = null;
        Train beforefirsttrain = null;
        Train temptrain = null;
        String nazwawagonu = "";
        Train actual = pierwszypociag;
        boolean findfirsttrain = false;
    
        while(actual != null) {
            if(nazwa1.equals(actual.nazwapociagu)) {                           //wynalezienie pierwszego wagonu i jego poprzednika (aby pozniej wskazac na niego w przypadku usuniecia z listy)
                beforefirsttrain = temptrain;
                findfirsttrain = true;}
                temptrain = actual;                                            //aktualizacja 
                actual = actual.next;}
            
            /*funkcja wykonuje aktualizacje pierwszego wagonu pociagu t1. Pobiera nazwe wagonu nazwawagonu i sprawdza, 
            czy pociag ma wiecej niz jeden wagon. Jesli tak, to funkcja tworzy nowy pociag o nazwie nazwa2 i przepina 
            pierwszy wagon z t1 na nowy pociag. Jesli pierwszy wagon byl jedynym wagonem pociagu, 
            to caly pociag zostaje usuniety z listy, a jego pierwszy wagon zostaje przypiety do nowego pociagu nazwa2.*/

            if(findfirsttrain) {
                if(beforefirsttrain == null) t1 = pierwszypociag;
                else t1 = beforefirsttrain.next;

                t1.pierwszywagon.Update();
                t1.pierwszywagon.previous.Update();
    
                nazwawagonu = t1.pierwszywagon.nazwawagonu;
    
                if(t1.pierwszywagon.next != t1.pierwszywagon) {
                    NewTrain(nazwa2, nazwawagonu);
                    t1.pierwszywagon.previous.next = t1.pierwszywagon.next;
                    t1.pierwszywagon.next.previous = t1.pierwszywagon.previous;
                    t1.pierwszywagon = t1.pierwszywagon.next;}
                else {
                    DeleteTrain(beforefirsttrain);
                    NewTrain(nazwa2, nazwawagonu);}}}
        
    void DeleteLast(String nazwa1, String nazwa2) {                            //funkcja usuwa ostatni wagon z pierwszego pociagu i dodaje do drugiego pociagu
        Train t1 = null;
        Train beforefirsttrain = null;
        Train temptrain = null;
        String nazwawagonu = "";
        Train actual = pierwszypociag;
        boolean findfirsttrain = false;
    
        while(actual != null) {
            if(nazwa1.equals(actual.nazwapociagu)) {                           //wynalezienie pociagu i jego poprzednika
                beforefirsttrain = temptrain;
                findfirsttrain = true;}
            temptrain = actual;                                                //aktualizacja 
            actual = actual.next;}
    
        /*funkcja pobiera nazwe ostatniego wagonu, ktory ma zostac usuniety i sprawdza, czy pociag sklada sie z wiecej niz jednego wagonu. 
        Jesli tak, funkcja tworzy nowy pociag o nazwie "nazwa2" i aktualizuje wskazniki wagonow tak, aby usunac ostatni wagon. 
        Jesli pociag sklada sie tylko z jednego wagonu, funkcja usuwa caly pociag i tworzy nowy pociag z jednym wagonem o nazwie ostatniego wagonu.*/

        if(findfirsttrain) {
            if(beforefirsttrain == null) t1 = pierwszypociag;
            else t1 = beforefirsttrain.next;

            t1.pierwszywagon.Update();
            t1.pierwszywagon.previous.Update();
    
            nazwawagonu = t1.pierwszywagon.previous.nazwawagonu;
    
            if(t1.pierwszywagon.next != t1.pierwszywagon) {
                NewTrain(nazwa2, nazwawagonu);
                t1.pierwszywagon.previous.previous.next = t1.pierwszywagon;
                t1.pierwszywagon.previous = t1.pierwszywagon.previous.previous;}
                else {
                    DeleteTrain(beforefirsttrain);
                    NewTrain(nazwa2, nazwawagonu);}}}}

public class Source {
    public static Scanner scanner = new Scanner(System.in);                    //zmienna przecowujaca dane wprowadzone z klawiatury
    public static void main(String[] args) {                                   //funkcja glowna kodu
        int number = 0;                                                        //zmienna przechowujaca ilosc zestawow danych                                    
        int n = 0;                                                             //zmienna przechowujaca ilosc operacji  
        String operation = "";                                                 //zmienna przechowujaca operacje

        String t1 = "";                                                        //zmienna przechowujaca nazwe pierwszego pociagu      
        String t2 = "";                                                        //zmienna przechowujaca nazwe drugiego pociagu     
        String w = "";                                                         //zmienna przechowujaca nazwe wagonu   

        number = scanner.nextInt();                                            //wprowadzenie ilosci zestawow

        while (number-- > 0) {                               
            TrainsList trains = new TrainsList();                              //tworzenie pociagow                
            n = scanner.nextInt();                                             //wprowadzenie ilosci operacji
            while (n-- > 0) {
                operation = scanner.next();                                    //wprowadzenie operacji
                switch(operation) {                                            //w zaleznosci od operacji wprowadzamy dane i przecodzimy do dzialania                         
                    case "New": {
                        t1 = scanner.next();
                        w = scanner.next();
                        trains.NewTrain(t1, w);
                        break;}

                    case "InsertFirst": {
                        t1 = scanner.next();
                        w = scanner.next();
                        trains.InsertFirst(t1, w);
                        break;}

                    case "InsertLast": {
                        t1 = scanner.next();
                        w = scanner.next();
                        trains.InsertLast(t1, w);
                        break;}

                    case "Display": {
                        t1 = scanner.next();
                        trains.Display(t1);
                        break;}

                    case "TrainsList": {
                        trains.DisplayList();
                        break;}

                    case "Reverse": {
                        t1 = scanner.next();
                        trains.Reverse(t1);
                        break;}

                    case "Union": {
                        t1 = scanner.next();
                        t2 = scanner.next();
                        trains.Union(t1, t2);
                        break;}

                    case "DelFirst": {
                        t1 = scanner.next();
                        t2 = scanner.next();
                        trains.DeleteFirst(t1, t2);
                        break;}

                    case "DelLast": {
                        t1 = scanner.next();
                        t2 = scanner.next();
                        trains.DeleteLast(t1, t2);
                        break;}}}}}}
/*
 * input 
1
20
New T1 W1
InsertFirst T1 W2
Display T1
InsertLast T1 W0
Display T1
DelFirst T1 T2
Display T1
TrainsList
DelLast T1 T3
Display T1
New T4 Z1
InsertLast T4 Z2
Reverse T4
Union T3 T4
Display T3
TrainsList
Display T3
Reverse T3
Display T3
TrainsList
 * output
T1: W2 W1
T1: W2 W1 W0
T1: W1 W0
Trains: T2 T1
T1: W1
T3: W0 Z2 Z1
Trains: T3 T2 T1
T3: WO Z2 Z1
T3: Z1 Z2 W0
Trains: T3 T2 T1
 */
