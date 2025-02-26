//Anhelina Belavezha
/*
 * Aby osiagnac sortowanie odwrotne w stosunku do wersji z wykladu, zamieniamy miejsca w linii int temp = arr[0]; i arr[0] = arr[i]; 
 * w petli for, ktora wyodrebnia elementy z kopca. Zamiana ta powoduje, że najwiekszy element zostaje przeniesiony na koniec tablicy, 
 * a kolejne najwieksze elementy sa umieszczane przed nim. Ostatecznie, po zakonczeniu sortowania, tablica bedzie uporzadkowana od 
 * najwiekszego do najmniejszego elementu.
 */
import java.util.Arrays;

class ZadanieDomowe2 {
    public static void HeapSort(int[] tab) {
        int n = tab.length;
        for(int i = n / 2 - 1; i >= 0; i--) {                                        //budowanie kopca (max-heap)
            Heapify(tab, n, i);
        }
        for(int i = n - 1; i >= 0; i--) {
            int temp = tab[0];                                                       //zamiana korzenia (najwiekszego elementu) z ostatnim elementem
            tab[0] = tab[i];
            tab[i] = temp;

            Heapify(tab, i, 0);                                                    //naprawianie kopca dla zmniejszonej tablicy
        }
    }

    public static void Heapify(int[] tab, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && tab[left] > tab[largest]) {
            largest = left;
        }

        if(right < n && tab[right] > tab[largest]) {
            largest = right;
        }

        if(largest != i) {                                                          //jezeli najwiekszy element nie jest korzeniem
            int swap = tab[i];
            tab[i] = tab[largest];
            tab[largest] = swap;

            Heapify(tab, n, largest);                                               //naprawianie kopca w poddrzewie
        }
    }

    public static void main(String[] args) {
        int[] tab = {4, 10, 3, 5, 1};
        System.out.println("Tablica przed sortowaniem: " + Arrays.toString(tab));
        HeapSort(tab);
        System.out.println("Tablica po sortowaniu: " + Arrays.toString(tab));
    }
}
