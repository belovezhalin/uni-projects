public class interpolacja {

    public static int szukanie(int[] tablica, int wartosc) {
    int start = 0;
    int koniec = tablica.length - 1;
    int ostatniewystapienie = -1;

    while (start <= koniec) {
        if (tablica[start] == tablica[koniec]) {ostatniewystapienie = tablica[koniec]; break;}
        
        int srodek = start + ((wartosc - tablica[start]) / (tablica[koniec] - tablica[start]) * (koniec - start));

        if (srodek < start || srodek > koniec) break;

        if (tablica[srodek] == wartosc) {
            ostatniewystapienie = srodek;
            start = srodek + 1;}

        else if (tablica[srodek] < wartosc) {
            start = srodek + 1;}

        else koniec = srodek - 1;}

    return ostatniewystapienie;}
public static void main(String[] args) {
    int[] tablica = {1, 2, 3, 4, 5, 5, 6, 7, 8};
    int x = 5;

    int ostatniewystapienie = szukanie(tablica, x);

    if (ostatniewystapienie == -1) System.out.println("Nie znaleziono"); 
    else System.out.println("Ostatnie wystapienie wartosci " + x + " w tablicy to indeks " + ostatniewystapienie);
}}




