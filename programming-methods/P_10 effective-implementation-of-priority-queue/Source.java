//Anhelina Belavezha - grupa nr 2
/* Ten kod implementuje operacje wstawiania, pobierania maksymalnych elementow oraz sortowania w kopcu. 
Kopiec jest struktura danych, ktora utrzymuje najwiekszy element na szczycie, a pozostale elementy sa uporzadkowane w odpowiedni sposob,
aby umożliwic skuteczne wykonywanie tych operacji.
 */
import java.util.Scanner;                                                                 //import do scannera
public class Source {
    public static Scanner scanner = new Scanner(System.in);                               //zmienna do scannera
    public static void main(String[] args) {                                              //funkcja glowna kodu
        int count = scanner.nextInt();                                                    //ilosc zestawow
        while(count-- > 0) {
            int N = scanner.nextInt();                                                    //liczba elementow kopca
            int P = scanner.nextInt();                                                    //maksymalna liczba elementow kopca
            Heap heap = new Heap(N, P);                                                   //tworzymy kopiec
            while(true) {
                String letter = scanner.next();                                           //operacja
                if(letter.equals("i")) {                                         //operacja wstawiania elementu x w kopiec
                    int k = scanner.nextInt();
                    while(k-- > 0) {
                        int x = scanner.nextInt();
                        insert(heap, x);
                    }
                } 
                else if(letter.equals("g")) {                                    //operacja wynalezienia maksymalnego elementu k 
                    int k = scanner.nextInt();
                    Element element = getMax(heap, k);
                    System.out.println(element.value + " " + element.count);              //oraz wypisuje razem z iloscia 
                } 
                else {
                    int number = heap.sort();                                             //operacja sortowania
                    for(int i = 0; i < number; i++) {
                        System.out.print(heap.tab[i].value + " " + heap.tab[i].count + " ");
                    }
                    System.out.println();
                    break;                                                                //po sortowaniu konczymy zestaw
                }
            }
        }
    }
/* jesli liczby x i y maja tyle samo wystapien w kolejce, to wieksza liczba ma wyzszy priorytet. 
   jesli liczba powtorzeń elementu x w kolejce jest wieksza niz liczba powtorzen elementu y,to x ma priorytet wyzszy niz y.
*/
    public static boolean Compare(Element element1, Element element2) {                   //metoda porownujaca priorytet elementow zgodnie z poleceniem
        return (element1.count == element2.count && element1.value >= element2.value) || element1.count > element2.count;
    }

    public static Element getMax(Heap heap, int k) {                                      //metoda zwracajaca maksymalny element kopca
        if(heap.currentn == 0) return new Element(0, 0);                    //przypadek pustego kopca
        Element start = heap.tab[0];                                                      //szczyt kopca, najwiekszy element
        if(start.count > k) {                                                             //sprawdzenie wystarczenia ilosci wystapienia
            heap.tab[0].count -= k;                                                       //zmniejszamy ilosc o liczbe 
            heap.downheap(0);                                                    //przesuwamy w dol kopca(aby zachowac go wlasciwosci)
            heap.total -= k;
            return new Element(start.value, k);              
        } 
        else {                                                                            //nie mamy wystarczonej ilosci wystapienia elementow
            heap.total -= start.count;                                                    //odejmujemy ilosc wystapien
            heap.tab[0] = heap.tab[--heap.currentn];                                      //zamieniamy z ostatnim elementem kopca
            heap.downheap(0);                                                    //przesuwamy w dol kopca(aby zachowac go wlasciwosci)
            return start;
        }
    }

    public static void insert(Heap heap, int k) {                                         //wstawianie elementu do kopca
        if(heap.totalmax == heap.total) return;                                           //nie mamy mozliwosci wstawiania elementow
        for(int i = 0; i < heap.currentn; i++) {
            if(heap.tab[i].value == k) {                                                  //element do wstawiania juz jest elementem kopca
                heap.tab[i].count++;                                                      //zwiekszamy ilosc wystapien
                heap.total++;
                heap.upheap(i);                                                           //ustawiamy na gorze
                return;
            }
        }
        if(heap.currentn == heap.n) return;                                               //sprawdzamy czy kopiec nie jest pelny
        heap.tab[heap.currentn++] = new Element(k);                                       //jesli zaden warunek nie byl spelniony to tworzymy nowy element
        heap.total++;                                                                     //zwiekszamy ilosc elementow
        heap.upheap(heap.currentn - 1);                                                   //ustawiamy na gorze
    }

    static class Element {                                                                //klasa elementu reprezentujaca element kopca
        public int value;
        public int count;

        public Element(int value_) {
            value = value_;
            count = 1;
        }

        public Element(int value_, int count_) {
            value = value_;
            count = count_;
        }
    }

    static class Heap {                                                                   //klasa kopca
        public Element[] tab;                                                             //tablica elementow
        int n;                                                                            //maksymalny rozmiar kopca
        int currentn;                                                                     //aktualna liczba elementow
        int total;                                                                        //suma wszystkich elementow
        int totalmax;                                                                     //maksymalna suma wszystkich elementow

        Heap(int n_, int maxtotal) {                                                      //konstruktor
            tab = new Element[n_];
            n = n_;
            currentn = 0;
            total = 0;
            totalmax = maxtotal;
        }

        public void upheap(int position) {                                                //metoda odpowiedzialna za przesuwanie elementu o indeksie position w gore kopca
            while(position > 0) {                                                         //poki element nie znajdzie swoja pozycje
                if(Compare(tab[position], tab[(position - 1) / 2])) {                     //porownujemy rodzica z dzieckiem wedlug priorytetu
                    Swap(position, (position - 1) / 2);
                    position = (position - 1) / 2;
                } 
                else {
                    break;
                }
            }
        }

        public void downheap(int position) {                                              //metoda odpowiedzialna za przesuwanie elementu o indeksie position w dol kopca
            while(position * 2 + 1 < currentn) {                                          //poki patrzymy na dziecko
                int child = position * 2 + 1;                                             //dziecko elementu o indekscie position            
                if(child + 1 < currentn && Compare(tab[child + 1], tab[child])) child++;  
                if(Compare(tab[position], tab[child])) break;
                Swap(position, child);                                                    //jesli warunek jest spelniony to zamieniamy dziecka z rodzicem
                position = child; 
            }
        }

        public void Swap(int position1, int position2) {
            Element temp = tab[position1];
            tab[position1] = tab[position2];
            tab[position2] = temp;
        }

        public int sort() {                                                               //sortujemy za pomoca metody wynalezienia maksymalnego elementu
            int n = currentn;
            for(int i = 0; i < n; i++) {
                Element m = getMax(this, Integer.MAX_VALUE);
                tab[currentn] = m;
            }
            return n;
        }
    }
}

/*
 * input
3
4 8
i 4 1 1 2 3 g 2 s
5 10
g 2 i 2 1 1 g 1 i 3 2 3 4 g 2
i 7 4 4 4 4 4 1 3 g 3
i 9 2 6 1 6 7 7 7 7 2 g 2 s
8 10
i 10 1 2 3 4 5 6 7 8 9 10 g 2 g 1 g 5
i 10 1 1 1 1 1 1 1 1 4 4 g 3
i 9 1 1 1 1 1 1 3 3 3 g 30 g 2
i 11 3 3 3 5 5 5 5 10 10 2 1 s

* output
1 1
2 1 3 1
0 0
1 1
4 1
4 3
1 2
1 1 6 1 2 2 3 2 4 2
8 1
7 1
6 1
1 3
1 6
5 1
2 1 4 1 3 4 5 4
*/
