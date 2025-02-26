//Anhelina Belavezha - grupa nr 2
/*Ogolna idea programu: ten kod zawiera implementacje algorytmu rozwiazujacego problem pakowania plecaka metoda rekurencyjna i sprawdzaniem z metoda
iteracyjna.
Na poczatku odczytywana jest liczba zestawow danych, potem maksymalna waga plecaka, liczba elementow do umieszczenia w plecaku 
oraz ich wagi.
Nastepnie wywolanie funkcji rec_pakuj() ktora rekurencyjnie szuka rozwiazania problemu pakowania plecaka.
Jesli nie uda sie znalezc kombinacji elementow o zadanej wadze, to nalezy odrzucic pierwszy element i rozpoczac caly proces od 
poczatku, wybierajac element kolejny. 
Wynik jej dzialania zostaje zapisany na stosie. Jesli funkcja rec_pakuj() nie znalazla rozwiazania, zostaje wyswietlony "BRAK".
W przeciwnym razie wynik zostaje odczytany z wierzcholka stosu, a potem wypisany na standardowe wyjscie.*/
import java.util.Scanner;                                                                  //import do skanera

class Params {                                                                             //parametry zapisywane na stosie
    public int n;                                                                          //parametr wywolania
    public int i;                                                                          //adres powrotu
    public int step;                                                                       //miejsce ktore musi byc zrobione
    public boolean result;                                                                 //rezultat rekurencji 
    public Params(int nn, int adress) {                                                    //konstruktor
        n = nn;
        i = adress;
        step = 0;
    }
} 

class Stack {
    private int maxSize;                                                                   //dlugosc tablicy Stack
    private Params[] Tab;                                                                  //referencja do Tab o elem. Params
    private int top;                                                                       //wierzcholek stosu

    public Stack(int n) {                                                                  //konstruktor
        maxSize = n;                                                                       //okreslamy wielkosc tablicy
        Tab = new Params[maxSize];                                                         //tworzymy tablice
        top = -1;                                                                          //na razie tablica jest pusta
    }

    public void push(Params p) {                                                           //umieszczenie elementu na wierzcholku
        Tab[++top] = p;
    }

    public Params pop() {                                                                  //pobranie elementu z wierzcholka stosu
        return Tab[top--];
    }

    public Params top() {                                                                  //odczyt elementu z wierzcholka stosu
        return Tab[top];
    }

    public int size() {                                                                    //pobieranie ilosci elementow
        return top + 1;
    }
} 

public class Source {
    public static Scanner sc = new Scanner(System.in);

    public static int z;                                                                   //ilosc zestawow
    public static int k = 0;                                                               //rozmiar input

    public static int[] input = new int[1000000];                                          //tablica input
    public static int[] output = new int[1000000];                                         //tablica output przechowujaca rezultat
    public static int endOfOutput = 0;                                                     //koniec tablicy rezultatu
    public static Stack recursion = new Stack(1000000);                                    //stos do wersji iteracyjnej
    public static int sum = 0;                                                             //suma elementow tablicy

    public static void main(String[] args) {                                                //funckja glowna programu
        z = sc.nextInt();                                                                   //zmienna przechowujaca ilosc zestawow danych
        while(z-- > 0) {
            int n = sc.nextInt();                                                           //zmienna przechowujaca pojemnosc plecaka
            k = sc.nextInt();                                                               //zmienna przechowujaca ilosc mozliwych elementow
            sum = 0;                                                                        //zmienna przechowujaca sume
            for(int i = 0; i < k; i++) {                                                    //wprowadzenie elementow z klawiatury i obliczanie ich sumy
                input[i] = sc.nextInt();
                sum += input[i];
            }

            endOfOutput = 0;
                                                                                            //wypisywanie rezultatu
            if(!rec_pakuj(n, 0)) {
                System.out.println("BRAK");
            }
            else {
                System.out.print("REC: " + n + " = ");
                for(int i = 0; i < endOfOutput; i++) {
                    System.out.print(output[i]);
                    System.out.print(" ");
                }
                System.out.println("");

                endOfOutput = 0;
                iter_pakuj(n, 0);
                System.out.print("ITER: " + n + " = ");
                for(int i = 0; i < endOfOutput; i++) {
                    System.out.print(output[i]);
                    System.out.print(" ");
                }
                System.out.println("");
            } 
        }
    }

    public static boolean rec_pakuj(int n, int i) {                                        //wersja rekurencyjna
        if(n == 0) {                                                                       //znaleziono
            return true;
        }

        if(sum < n || n < 0 || i == k) {                                                   //zwracamy false, gdy suma wynalezionych elementow jest 
            return false;                                                                  //mniejsza niz oczekiwana, gdy suma jest zbyt wielka, gdy
        }                                                                                  //jestesmy na koncu tablicy

        output[endOfOutput] = input[i];                                                    //przepisujemy input do output
        endOfOutput++;
        sum -= input[i];                                                                   //zmniejszenie sumy pozostalych elementow o wartosc przepisanego elementu

        if(rec_pakuj(n - input[i], i + 1)) {                                               //rekurencyjne wywolywanie dla reszty bagazu i dla
            sum += input[i];                                                               //kolejnych elementow input (i + 1, k)
            return true;                                                                   //w przypadku wynalezienia zwiekszamy sume i zwracamy true
        }
                                                                                           //w przeciwnym przypadku usuwamy element z output i wywolujemy rekurencyjnie funkcje rec_pakuj 
        endOfOutput--;                                                                     //dla oryginalnego bagazu n i dla kolejnych elementow w input (i + 1, k)                         
        boolean res = rec_pakuj(n, i + 1); 
        sum += input[i];
        return res;
    }

    public static Params last;                                                             //last sluzy do przechowywania informacji o 
                                                                                           //ostatnim wywolaniu funkcji rec_pakuj, w szczegolnosci o tym, 
                                                                                           //czy funkcja zakonczyła sie sukcesem. Pola tej struktury sa
                                                                                           //inicjalizowane w funkcji rec_pakuj i odczytywane w funkcji iter_pakuj

    public static boolean iter_pakuj(int n, int i) {                                       //wersja iteracyjna
        Params callRecursion = new Params(n, i);                                               
        recursion.push(callRecursion);                                                     //dodajemy do parametrow wywolywawnie funkcji
        while(Step(recursion));                                                            //przechodzimy przez wszystko 
        return last.result;                                                                //zwracamy rezultat
    }

    public static boolean Step(Stack stack) {                                              //funkcja wykonuje jeden krok i zwraca true, gdy algorytm nie jest ukonczony
        if(stack.size() == 0) return false;
        Params callRecursion;                                                              //tworzona jest nowa struktura Params reprezentujaca parametry wywolania 
                                                                                           //funkcji rec_pakuj z wartosciami otrzymanymi ze stosu stack

        switch(stack.top().step) {                                                         //na podstawie wartosci pola step wykonuje sie jeden z krokow funkji rec_pakuj
        case 0:                                                                            //krok 1: sprawdzenie warunkow (analogicznie jak w rek_pakuj)
            if(stack.top().n == 0) {
                last = stack.pop();
                last.result = true;
            break;
            }
            if(sum < stack.top().n || stack.top().n < 0 || stack.top().i == k) {
                last = stack.pop();                                                        
                last.result = false;                       
            break;
            }
            
            output[endOfOutput] = input[stack.top().i];                                     //analogicznie jak w rec_pakuj
            endOfOutput++;
            stack.top().step = 1;
            sum -= input[stack.top().i];

            callRecursion = new Params(stack.top().n - input[stack.top().i], stack.top().i + 1);
            stack.push(callRecursion);
        break;

        case 1:                                                                             //krok 2: zapisanie wyniku lub zdejmowanie elementu ze stosu
            if(last.result) {
                sum += input[stack.top().i];
                last = stack.pop();
                last.result = true;
                break;
            }
            endOfOutput--;
            stack.top().step = 2;
            callRecursion = new Params(stack.top().n, stack.top().i + 1);
            stack.push(callRecursion);
        break;

        case 2:                                                                             //krok 3: przeskok do kolejnego elementu lub zapisanie wyniku
            sum += input[stack.top().i];
            stack.top().result = last.result;
            last = stack.pop();
        break;
        }
        return true;
    }
}
/*
 * input
 * 1
 * 15
 * 6
 * 2 4 6 8 10 12
 * 1
 * 10
 * 4
 * 7 3 2 5
 * 1
 * 50
 * 5 
 * 10 20 30 40 50
 * 1 
 * 7
 * 3
 * 1 2 4
 * 1 
 * 25
 * 4
 * 6 8 10 12
 * 1
 * 12
 * 4
 * 1 3 4 6
 * 1
 * 30
 * 6
 * 5 6 8 10 12 14
 * 1
 * 100
 * 5
 * 10 20 30 40 50
 * 1
 * 16
 * 4
 * 1 3 5 7
 * 1
 * 50
 * 5
 * 10 15 20 25 30
 * 
 * output
 * REC: 15 = 12 2 1
 * ITER: 15 = 12 2 1
 * REC: 10 = 7 3
 * ITER: 10 = 7 3
 * REC: 50 = 50
 * ITER: 50 = 50
 * BRAK
 * REC: 25 = 12 6 4 3
 * ITER: 25 = 12 6 4 3
 * REC: 12 = 6 4 1 1
 * ITER: 12 = 6 4 1 1
 * REC: 30 = 14 12 4
 * ITER: 30 = 14 12 4
 * REC: 100 = 50 40 10
 * ITER: 100 = 50 40 10
 * REC: 16 = 7 5 3 1
 * ITER: 16 = 7 5 3 1
 * REC: 50 = 30 20
 * ITER: 50 = 30 20
 */
