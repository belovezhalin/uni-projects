//Anhelina Belavezha - grupa nr 2
/* Ogolna idea programu: wyszukiwanie k-tego co do wielkosci elementu tablicy n-elementowej a[0],…,a[n-1] w porzadku niemalejacym, liczac od
najmniejszego. Glowna funkcja programu na ktorej opiera sie caly algorytm jest funkcja rekurencyjna i dziala w oparciu o algorytm magicznych 
piątek przedstawiony na wykladzie. Rekurencyjne obliczanie mediany nie przekracza pesymistycznego przypadku liniowego, poniewaz
mediana median ma rozmiar n/5, podczas gdy inne wywolanie rekurenyjne nie przekracza 3/4 listy. */
import java.util.Scanner;

public class Source {
    public static Scanner scanner = new Scanner(System.in);
    public static int[] tab;                                                                         //referencja do tablicy
    public static void main(String[] args) {                                                         //funkcja glowna kodu
        int z = scanner.nextInt();                                                                   //liczba zestawow
        while(z-- > 0) {
            int size = scanner.nextInt();                                                            //zmienna przechowujaca dlugosc tablicy
            tab = new int[size];
            for(int i = 0; i < tab.length; i++)
               tab[i] = scanner.nextInt();                                                           //wpisywanie wartosci tablicy      
            int m = scanner.nextInt();                                                               //zmienna przechowujaca liczbe zapytan
            while(m-- > 0) {                
                int k = scanner.nextInt();                                                           //wczytanie wartosci k
                if(k > 0 && k <= tab.length)                                                         //jesli k jest elementem tablicy
                    System.out.println(k + " " + (tab[Select(0, tab.length - 1, k - 1)]));      //wypisywanie rezultatu
                else
                    System.out.println(k + " brak");                                                  
            }
        }
    }

    public static int Select(int left, int right, int k) {                                           //funkcja szukajaca pivot, dzielac tablice
        while(true) {                                                                                //na piatki, w ktorych sa obliczane mediany
            if(left == right) return left;                                                           //ktore ustawiamy na poczatku
            int pivotIndex = GetPivotIndex(left, right);
            pivotIndex = Partition(left, right, k, pivotIndex);
            if(k == pivotIndex) return k;
            else if(k < pivotIndex) right = pivotIndex - 1;
            else left = pivotIndex + 1;
        }
    }

    public static int GetPivotIndex(int left, int right) {
        if(right - left + 1 <= 5)                                                                    //dla 5 lub mniej elementow obliczanamy mediane
            return Median(left, right);

        for(int i = left; i <= right; i+=5) {                                                        //w innym przypadku przesuwamy mediany piecioelementowych podtablic na pierwsze n/5 pozycji
            int currentright = i + 4;                                                                //prawa granica piecioelementowej podgrupy
            if(currentright > right) currentright = right;                                           //jesli wyjdziemy poza tablice to aktualizujemy

            int median5 = Median(i, currentright);                                                   //obliczanie mediany z 5
            int tempo = tab[median5];                     
            tab[median5] = tab[left + ((i - left)/5)];                                               //zamiana elementow, ktore sa w odleglosci wielokrotnosci pieciu pozycji od siebie z mediana piecioelementowych podtablic
            tab[left + ((i - left)/5)] = tempo;
        }
        int mid = (right - left) / 10 + left + 1;                                                    //obliczamy mediane z zakresu od left do left + ((right - left)/5)
        return Select(left, left + ((right - left)/5), mid);
    }

    public static int Median(int left, int right) {                                                  //funkcja wyznaczajaca mediane
        boolean isswap = false;

        for(int i = left; i < right; i++) {              
            for(int j = left + 1; j <= right; j++) {     
                if(tab[i] > tab[j]) {                                                               //jesli w zlej kolejnosci to zamieniamy
                    int tempo = tab[i];
                    tab[i] = tab[j];
                    tab[j] = tempo;
                    isswap = true;
                }
            }
            if (!isswap) break;                                                                     //jesli tablica jest posortowana to wychodzimy
            isswap = false;
        }
        return (left + right) / 2;                                                                  //zwracamy mediane
    }

    public static int Partition(int left, int right, int k, int pivotIndex) {
        int pivot = tab[pivotIndex];                                                                 //zmienna przechowujaca wartosc pivota
        int equal;
        int i = left - 1;                  
        int j = right;

        int tempo = tab[pivotIndex];                                                                 //ustawiamy pivot na koniec tablicy 
        tab[pivotIndex] = tab[right];
        tab[right] = tempo;

        while(true) {
            while(tab[++i] < pivot);                                                                 //szukamy pierwszego z lewej strony wiekszego od pivota elementu
            while(j > left && tab[--j] >= pivot);                                                    //szukamy pierwszego z prawej strony mniejszego elementu od pivota

            if (i >= j) break;                                                                       //jesli jest posortowana, to wychodzimy z petli
            else {                                                                                   //jesli nie to zamieniamy miejscami
                tempo = tab[i];
                tab[i] = tab[j];
                tab[j] = tempo;
            }
        }

        tempo = tab[i];                                                                              //wstawiamy pivot na odpowiednie miejsce
        tab[i] = tab[right];
        tab[right] = tempo;

        int smaller = i;                                                                             //indeks pivota
        equal = i;                                                                                 
        ++i;

        for(j = i; j <= right; j++) {                                                                //przenosimy za pivot elementy rowne mu
            if(tab[j] == pivot) {
                 tempo = tab[j];
                 tab[j] = tab[i];
                 tab[i] = tempo;

                 ++i;
                 ++equal;
            }
        }

        if (k < smaller)                                                                             //w zaleznosci w ktorej czesci jest k zwracamy element
            return smaller;
        if (k <= equal)
            return k;
        return equal;
    }
}
/*
 * input:
 * 1
 * 7
 * 10 5 8 3 7 3 1
 * 4
 * 2 3 5 7
 * 2
 * 6
 * 1 2 3 4 5 6
 * 3
 * 1 5 6
 * 4
 * 4 2 3 1
 * 10
 * 1 1 1 1 1 1 1 1 1 1
 * 5
 * 1 10 0 2 11
 * output:
 * 2 8
 * 3 7
 * 5 5
 * 7 1
 * 1 6
 * 5 2
 * 6 1
 * 4 4
 * 2 5
 * 3 4
 * 1 6
 * 1 1
 * 10 1
 * 0 brak
 * 2 1
 * 11 brak
 */

