//Anhelina Belavezha - grupa nr 2
import java.util.Scanner;                                                                 //import do scannera
/*Ogolna idea programu: za pomoca sortowania MergeSort wyznaczyc ilosc inwersji w tablice o elementach a[0], ..., a[n - 1].
 * Rekurencyjna funkcja Inversion dziala w O(nlogn), tworzy pomocnicza tablice o dlugosci n / 2 + 1(zgodnie z poleceniem),
 * po wywolaniu zwraca na ekran ilosc inwersji.*/
public class Source {
    public static Scanner scanner = new Scanner(System.in);                               //zmienna przechowujaca dane wprowadzone z klawiatury
    public static void main(String[] args) {                                              //funkcja glowna kodu
        int count = scanner.nextInt();                                                    //zmienna przechowujaca ilosc zestawow danych
        while(count-- > 0) {
            int n = scanner.nextInt();                                                    //zmienna przechowujaca dlugosc tablicy
            int[] a = new int[n];                                                         //tablica o dlugosci wprowadzonej z klawiatury
            for(int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();}                                                //wprowadzanie elementow tablicy
            long result = Inversion(a);                                                   //zmienna przechowujaca szukana ilosc inwersji w tablice
            System.out.println(result);}}                                                 //wyswietlenie rezultatu
            
    public static long Inversion(int[] a) {                                               //rekurencyjna funkcja, dzialajaca w O(nlogn)
        int[] b = new int[a.length / 2 + 1];                                              //tablica pomocnicza o dlugosci n / 2 + 1                   
        return MergeSort(a, 0, a.length - 1, b);}

    public static long MergeSort(int[] a, int left, int right, int[] b) {                 //algorytm 
        long inversions = 0;
        if(left < right) {
            int mid = (left + right) / 2;
            inversions += MergeSort(a, left, mid, b);
            inversions += MergeSort(a, mid + 1, right, b);
            if(right - left + 1 != a.length) inversions += Merge(a, left, mid + 1, right, b);//tablice sa duze, musimy dalej dzielic
            else {                                                                       //tablice sa dostatecznie male, zeby ich dzielic i scalic
                int i = left;
                int j = mid + 1;
                while (i <= mid && j <= right) {
                    if (a[i] > a[j]) {
                       j++;
                       inversions += mid + 1 - i;}
                    else 
                       i++;}}}
        return inversions;}

    public static long Merge(int[] a, int left,int mid, int right, int[] b) {
        int i = left;                                                                    //wartosc poczatkowa pierwszej podtablicy
        int j = mid;                                                                     //wartosc poczatkowa drugiej podtablicy
        int k = 0;                                                                       //indeks tablicy wynikowej
        long inversions = 0;                                                             //zmienna przechowujaca ilosc inwersji

        while(i <= mid - 1 && j <= right) {                                              //sortowanie
           if(a[i] <= a[j]) b[k++] = a[i++];
         else {
            b[k++] = a[j++];
            inversions += mid - i;}}                                                     //podtablice juz sa posortowane, dlatego inwersje wystepuja tylko miedzy elementami podtablic

        while(i <= mid - 1) b[k++] = a[i++];                                             //kopiowanie pozostalych elementow lewej podtablicy
        
        while(j <= right) b[k++] = a[j++];                                               //kopiowanie pozostalych elementow prawej podtablicy

        for (i = left, k = 0; i <= right; i++, k++) {
            a[i] = b[k];}                                                                //przepisanie do tablicy glownej
    return inversions;}}                                                                 //zwracanie ilosci inwersji
/*
 * input
 * 10
 * 10
 * 2 5 9 2 1 5 9 4 3 2 
 * 6
 * 23 78 54 12 9 3
 * 10
 * 0 0 0 0 0 0 0 0 0 0 
 * 8
 * 8 7 6 5 4 3 2 1 0 
 * 10
 * 1 1 1 1 1 1 1 1 1 1
 * 5
 * 2 1 4 3 5
 * 7
 * 21 34 23 78 65 99 0
 * 10
 * 10 9 8 7 6 5 4 3 2 1
 * 0
 * 0
 * 6
 * 7 6 3 5 7 2
 * ouput
 * 22
 * 13
 * 0
 * 28
 * 0
 * 2
 * 8
 * 45
 * 0
 * 10
 */
