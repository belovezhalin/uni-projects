//Anhelina Belavezha - grupa nr 2
/*Ogolna idea programu: sortowanie wedlug wybranej kolumny w dwuwymiarowej tablicy stringow.
Tablica wyglada jako plyta z piosenkami oraz informacja o nich. Do sortowania danych program wykorzystuje 
algorytm QuickSort w wersji iteracyjnej, o stalej zlozonosci pamieciowej oraz bez uzycia stosu. Dla podzadan o rozmiarze mniejszym lub 
rownym niz wykorzystujemy algorytm SelectionSort. W efekcie srednia zlonosc czasowa programu dla zestawu o rozmiarze N wynosi O(N log (N)).*/

import java.util.Scanner;

public class Source {
    public static Scanner scanner = new Scanner(System.in);                                           //zmienna przechowujaca dane wprowadzone z klawiatury
   public static void main(String[] args) {                                                           //funkcja glowna kodu
      int count = scanner.nextInt();                                                                  //zmienna przechowujaca ilosc zestawow
      scanner.nextLine();

      for(int i = 0; i < count; i++) {
         String[] lines = scanner.nextLine().split(",");                                        //zmienna przechowujaca wiersz danych pomiajac ,
         int rows = Integer.valueOf(lines[0]);                                                        //pierwszy symbol stingu przecowuje liczbe wierszy
         int columns = Integer.valueOf(lines[1]) - 1;                                                 //drugi symbol przechowuje liczbe kolumn
         int order = Integer.parseInt(lines[2]);                                                      //trzeci symbol przechowuje kolejnosc sortowania
         String[][] tab = new String[rows][];                                                         //tablica dwuwymiarowa z danymi
         String[] names = scanner.nextLine().split(",");                                        //napis przechowujacy nazwy kolumns

         for(int j = 0; j < rows; j++) {
            tab[j] = scanner.nextLine().split(",");                                             //wprowadzamy zawartosc tablicy pomijajac ,
         }

         if(columns != 0) {                                                                           //swapujemy wedlug kolumny ktora wybralismy
            for(int j = 0; j < columns; j++) {
               String temp = names[j];
               names[j] = names[columns];
               names[columns] = temp;
               for(int j2 = 0; j2 < rows; j2++) {
                  String temp2 = tab[j2][j];
                  tab[j2][j] = tab[j2][columns];
                  tab[j2][columns] = temp2;
               }
            }
         }

         QuickSort(tab, rows, order);
         PrintResult(names, tab, rows);
      }
   }

   public static void QuickSort(String[][] tab, int size, int order) {                                //iteracyjny quicksort bez uzycia stosu
    int left = 0;                                                                                     //najbardziej lewy element
    int right = size - 1;                                                                             //najbardziej prawy element
    int pivot;                                                                                        //element dzielacy
    int currentright = right;                                                                         //zmienna przechowujaca adres aktualnie prawego elementu

    int i = 0;
    while(true) {
       i--;
       while(left < currentright && currentright - left + 1 >= 5) {
          pivot = Partition(tab, left, currentright, order);                                          //funkcja dokonuje podzialu tablicy na czesc mniejsza i wieksza wzgledem pivotu
          tab[currentright][0] = "-" + tab[currentright][0];                                          //oznaczamy wartosia ujemna zeby wiedziec ze
          currentright = pivot - 1;                                                                   //zostal juz przetworzony jako czesc sortowania i nie musi 
                                                                                                      //byc brany pod uwage podczas kolejnych iteracji
          ++i;
       }

       if(currentright - left + 1 < 5 && left < currentright) {
          SelectionSort(tab, left, currentright, order);                                              //wedlug polecenia wywolujemy selectionsort w tablicach o dlugosci < 5
          left = currentright; 
       }

       if(i < 0) break;                                                                               //przerwanie petli

       left++;
       currentright = Next(tab, left, size);                                                          //szukamy nowy skrajny element
       tab[currentright][0] = tab[currentright][0].substring(1, tab[currentright][0].length());  //usuwamy minus
    }
 }

   public static int Partition(String[][] tab, int low, int high, int order) {                        //funkcja do ustawienia pivotu na poprawne miejsce
    Swap(tab, high, (low + high) / 2);

    int i = low - 1;
    int j;
    String pivot = tab[high][0];

    for(j = low; j < high; j++) {
       if(Compare(tab[j][0], pivot, order) < 0) {                                                     //elementy mniejsze od pivotu ustawiamy po 
          i++;                                                                                        //lewej stronie, wieksze od pivotu po prawej
          Swap(tab, i, j);
       }
    }
    Swap(tab, i + 1, high);
    return i + 1;
   }

   public static int Compare(String row1, String row2, int order) {                                    //porownujemy wedlug polecenia:
      if(order == 1) {                                                                                 //order == 1 -> sortujemy rosnaco
         if(IsInteger(row1) && IsInteger(row2)) return Integer.compare(Integer.parseInt(row1), Integer.parseInt(row2));
         else return row1.compareTo(row2);
      } 
      else {                                                                                          //order == -1 -> sortujemy malejaco
         if(IsInteger(row1) && IsInteger(row2)) return Integer.compare(Integer.parseInt(row2), Integer.parseInt(row1));
         else return row2.compareTo(row1);
      }
   }

   public static boolean IsInteger(String str) {                                                      //funkcja sprawdzajaca czy element jest liczba
      if(str == null || str.isEmpty()) {
         return false;
      }
   
      for(int i = 0; i < str.length(); i++) {
         char c = str.charAt(i);
         if(!Character.isDigit(c)) 
            return false;
      }
      return true;
   }

   public static int Next(String[][] tab, final int a, final int size) {                             //szukamy nastepne prawe ograniczenie wczesniej oznaczone z minusem
      for(int i = a; i < size; ++i) {
         if(tab[i][0].charAt(0) == '-') return i;
      }
      return size - 1;
   }

   public static void SelectionSort(String[][] tab, int left, int right, int order) {                 //selectionsort dla tablic o dlugosci mniejszej niz 5
      for(int i = left; i <= right - 1; i++) {                                                        //algorytm iteracyjnie wybiera najmniejszy lub najwiekszy element 
         int min = i;                                                                                 //z nieposortowanej czesci i zamienia go miejscami z pierwszym elementem
         for(int j = i + 1; j <= right; j++)
            if(Compare(tab[j][0], tab[min][0], order) < 0) min = j;
         Swap(tab, min, i);
      }
   }

   public static void Swap(String[][] tab, int i, int j) {                                          
    String[] temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
   }
   
   public static void PrintResult(String[] names, String[][] tab, int rows) {                         //wypisanie wyniku
      for(int j = 0; j < names.length - 1; j++) {
         System.out.print(names[j] + ",");
      }
      System.out.println(names[names.length - 1]);

      for(int j = 0; j < rows; j++) {
         for(int j2 = 0; j2 < names.length - 1; j2++) {
            System.out.print(tab[j][j2] + ",");
         }
         System.out.println(tab[j][names.length - 1]);
      }
      System.out.println();
   }
}

/*
 * input:
 * 4
 * 4,3,1
 * Album,Year,Songs,Length
 * Stadium Arcadium,2006,28,122
 * Unlimited Love,2022,17,73
 * Californication,1999,15,56
 * The Wall,1979,26,82
 * 5
 * 5,2,-1
 * Album,Year,Songs,Length,Artist
 * Stadium Arcadium,2006,28,122,Red Hot Chili Peppers
 * Unlimited Love,2022,17,73,John Doe
 * Californication,1999,15,56,RHCP
 * The Wall,1979,26,82,Pink Floyd
 * Bohemian Rhapsody,1975,1,354,Queen
 * 3
 * 3,1,-1
 * Title,Artist,Duration
 * Bohemian Rhapsody,Queen,355
 * Stairway to Heaven,Led Zeppelin,480
 * Hotel California,Eagles,390
 * 5
 * 5,1,-1
 * Title,Artist,Album,Year,Duration
 * Imagine,John Lennon,Imagine,1971,185
 * Paint It Black,The Rolling Stones,Aftermath,1966,205
 * Bohemian Rhapsody,Queen,A Night at the Opera,1975,355
 * Hotel California,Eagles,Hotel California,1976,390
 * Like a Rolling Stone,Bob Dylan,Highway 61 Revisited,1965,365
 * 
 * output:
 * Songs,Length,Album,Year
 * 15,56,Californication,1999
 * 26,82,The Wall,1979
 * 28,122,Stadium Arcadium,2006
 * 17,73,Unlimited Love,2022
 * Year,Album,Songs,Length,Artist
 * 1975,Bohemian Rhapsody,1,354,Queen
 * 1979,The Wall,26,82,Pink Floyd
 * 1999,Californication,15,56,RHCP
 * 2006,Stadium Arcadium,28,122,Red Hot Chili Peppers
 * 2022,Unlimited Love,17,73,John Doe
 * Title,Artist,Duration
 * Stairway to Heaven,Led Zeppelin,480
 * Hotel California,Eagles,390
 * Bohemian Rhapsody,Queen,355
 * Title,Artist,Album,Year,Duration
 * Paint It Black,The Rolling Stones,Aftermath,1966,205
 * Like a Rolling Stone,Bob Dylan,Highway 61 Revisited,1965,365
 * Hotel California,Eagles,Hotel California,1976,390
 * Bohemian Rhapsody,Queen,A Night at the Opera,1975,355
 * Imagine,John Lennon,Imagine,1971,185
 */