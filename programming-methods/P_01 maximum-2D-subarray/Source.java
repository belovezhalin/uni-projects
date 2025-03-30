//Anhelina Belavezha - grupa nr 2
//ogolna idea programu(dzialajcego w O(n^3)) - wynalezienie maksymalnej podtablicy (patrzac na sume elementow) o najmniejszej liczbie elementow 
import java.util.Scanner;                                       //import sluzacy do wprowadzenia danych z klawiatury
class Source {                                                  //clasa zewnetrzna nazywana jako plik(szczegolnosc javy)
public static Scanner scan = new Scanner(System.in);            //zmienna przechowujaca kolejne pobierania danych z klawiatury
public static void main(String[] args) {                        //funkcja glowna kodu
    int count = scan.nextInt();                                 //zmienna przecowujaca ilosc zestawow tablic
    while(0 < count--) {                                        //po wykonaniu dzialan dla pierwszego zestawu przechodzimy do nastepnego
        int nz = scan.nextInt();                                //zmienna przechowujaca aktualny numer zestawu
        scan.next();                                            //pobieranie z klawiatury :
        int rows = scan.nextInt();                              //zmienna przechowujaca ilosc wierszy tablicy
        int columns = scan.nextInt();                           //zmienna przechowujaca ilosc kolumn tablicy
        int tab[][] = new int[rows][columns];                   //tworzenie tablicy o podanych wartosciach 
        int maxsum = -1;                                        //zmienna przechowujaca maksymalna sume podtablicy
        int maxrow1 = 0;                                        //zmienna przechowujaca indeks poczatkowego wierszu makszymalnej podtablicy
        int maxrow2 = 0;                                        //zmienna przechowujaca indeks koncowego wierszu maksymalnej podtablicy
        int maxcolumn1 = 0;                                     //zmienna przechowujaca indeks poczatkowej kolumny maksymalnej podtablicy
        int maxcolumn2 = 0;                                     //zmienna przechpwujaca indeks koncowej kolumny maksymalnej podtablicy

        for(int i = 0; i < rows; i++) {                         //pobieranie z klawiatury elementow tablicy
            for(int j = 0; j < columns; j++) {
                tab[i][j] = scan.nextInt();}}
            
        for(int column1 = 0; column1 < columns; column1++) {                       //algorytm Kadane w O(n^3)
            int curtab[] = new int[rows];                                          //tworzenie tablicy pomocniczej
            for(int column2 = column1; column2 < columns; column2++) {             
                for(int i = 0; i < rows; i++) curtab[i] += tab[i][column2];        //(column1 == column2) => (curtab == [0..rows][column1])
                int row1 = 0;                                                      //zmienna przechowujaca indeks poczatkowego wierszu aktualnej podtablicy
                int sum = 0;                                                       //zmienna przechowujaca aktualna sume podtablicy
                for(int row2 = 0; row2 < rows; row2++) {                           //iteracja po podtalicy z cela wynalezienia maksymalnej sumy

                    if(curtab[row2] < curtab[row2] + sum) sum += curtab[row2];     //warunek sprawdzajacy czy wartosc jest wieksza od poprzedniej sumy
                    else {                                                         //jesli warunek nie jest spelniony, to zaczynamy od nowa szukac maksymalna podtablice od aktualnego wiersza
                        sum = curtab[row2];
                        row1 = row2;}

                    if(maxsum < sum) {                                             //ustawienie nowych wartosci w przypadku wynalezienia najwiekszej podtablicy
                        maxsum = sum;
                        maxrow1 = row1;
                        maxrow2 = row2;
                        maxcolumn1 = column1;
                        maxcolumn2 = column2;}
                    else if(maxsum == sum) {                                       //w przypadku rownych sum bierzemy maksymalna podtalice o najmniejszej liczbe elementow
                        if(((row2 - row1 + 1) * (column2 - column1 + 1)) < ((maxrow2 - maxrow1 + 1) * (maxcolumn2 - maxcolumn1 + 1))) {  //porownujemy wedlug pola obszaru (dodajemy 1 bo pole nie moze byc rowne 0)
                            maxrow1 = row1;
                            maxrow2 = row2;
                            maxcolumn1 = column1;
                            maxcolumn2 = column2;}
                        else if (((row2 - row1 + 1) * (column2 - column1 + 1)) == ((maxrow2 - maxrow1 + 1) * (maxcolumn2 - maxcolumn1 + 1))) { //tworzenie ciagu leksykograficznie najmniejszego
                            if(row1 < maxrow1) {
                                maxrow1 = row1;
                                maxrow2 = row2;
                                maxcolumn1 = column1;
                                maxcolumn2 = column2;}
                            else if(row1 == maxrow1 && row2 < maxrow2) {
                                maxrow1 = row1;
                                maxrow2 = row2;
                                maxcolumn1 = column1;
                                maxcolumn2 = column2;}
                            else if(row1 == maxrow1 && row2 == maxrow2 && column1 < maxcolumn1) {
                                maxrow1 = row1;
                                maxrow2 = row2;
                                maxcolumn1 = column1;
                                maxcolumn2 = column2;}
                            else if(row1 == maxrow1 && row2 == maxrow2 && column1 == maxcolumn1 && column2 < maxcolumn2) {
                                maxrow1 = row1;
                                maxrow2 = row2;
                                maxcolumn1 = column1;
                                maxcolumn2 = column2;}}}}}}
    if(maxsum == -1) System.out.println(nz + ": n = " + rows + " m = " + columns + ", ms = 0, mst is empty");        //wypisywanie rezultatu 
    else System.out.println((nz + ": n = " + rows + " m = " + columns + ", ms = " + maxsum + ", mst = a[" + maxrow1 + ".." + maxrow2 + "]["  + maxcolumn1 + ".." + maxcolumn2 + "]"));
}}}

/*
 test.in
 8
 1 : 1 6
 2 3 54 -1 -21 0
 2 : 2 3
 1 0 -4
 3 1 2
 3 : 2 5
 1 0 1 0 1
 -1 -1 -1 -1 -1
 4 : 1 3
 -1 -1 -2
 5 : 2 4
 0 0 0 0
 0 0 0 0
 6 : 2 5
 99 -99 2 3 4
 1 2 3 4 5
 7 : 1 4
 67 45 2 -1
 8 : 1 6
 0 0 0 0 0 0

 test.out
 1: n = 1 m = 6, ms = 59, mst = a[0..0][0..2]
 2: n = 2 m = 3, ms = 6, mst = a[1..1][0..2]
 3: n = 2 m = 5, ms = 3, mst = a[0..0][0..4]
 4: n = 1 m = 3, ms = 0, mst is empty
 5: n = 2 m = 4, ms = 0, mst = a[0..0][0..0]
 6: n = 2 m = 5, ms = 100, mst = a[0..1][0..0]
 7: n = 1 m = 4, ms = 114, mst = a[0..0][0..2]
 8: n = 1 m = 6, ms = 0, mst = a[0..0][0..0]
 */



