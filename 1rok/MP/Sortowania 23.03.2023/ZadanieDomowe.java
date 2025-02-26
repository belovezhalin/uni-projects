import java.util.Arrays;
public class ZadanieDomowe {

    public static void BubbleSort(int[] tab) {                                //zwyczajny bubblesort
        for(int i = 0; i < tab.length - 1; i++) {                             //wada: musimy przechodzic do konca listy
            for(int j = 0; j < tab.length - i - 1; j++) {
                if(tab[j] > tab[j + 1]) {
                    int temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;}}}}
        
    public static void BubbleSortImprovement1(int[] tab) {                    //pierwsze usprawnienie bubblesort: 
        for(int i = 1; i < tab.length; i++) {                                 //zamiast przetwarzac liste do konca, lepiej 
            for(int j = 0; j < tab.length - i; j++) {                         //zatrzymac sie przed posortowanym "babelkiem"
                if(tab[j] > tab[j + 1]) swap(tab, j, j + 1);}}}               //zmiana trzech linijek kodu na jedna za pomoca swap

    public static void BubbleSortImprovement2(int[] tab) {                    //drugie usprawnienie bubblesort:
        int i = 0;
        boolean brakzmiany = true;                                            //zmienna pokazujaca po pierwszym przejsciu czy musimy
        while(brakzmiany) {                                                   //w ogole sortowac tablice
            brakzmiany = false;
            i++;
            for(int j = 0; j < tab.length - i; j++) {                         //poczatek kolejnego sprawdzania od poprzedniego babelka
                if(tab[j] > tab[j + 1]) {
                    swap(tab, j, j + 1);                                      //swap zamiast trzech linijek
                    brakzmiany = true;}}}}
    
    private static void swap(int[] tab, int x, int y) {
        int temp = tab[x];
        tab[x] = tab[y];
        tab[y] = temp;}

    public static void InsertionSort(int[] tab) {
        for (int i = 1; i < tab.length; i++) {
            int x = tab[i];
            int insert = BinarySearch(tab, x, 0, i - 1);
            for (int j = i; j > insert; tab[j] = tab[j - 1], j--);           //szukanie miesjca dla wstawiania
            tab[insert] = x;}}
        
    public static int BinarySearch(int[] tab, int x, int start, int koniec) {
        while (start <= koniec) {
            int srodek = start + (koniec - start) / 2;
            if (tab[srodek] == x) return srodek;
            else if (tab[srodek] < x) start = srodek + 1;
            else koniec = srodek - 1;}
            return start;}

    public static void main(String[] args) {
        int[] tab1 = {8, 2, 3, 5, 1, 13, 17, 2};
        int[] tab2 = {8, 2, 3, 5, 1, 13, 17, 2};
        int[] tab3 = {3, 7, 1, 9, 0, 2, 6, 13};

        System.out.println("---------------------------------------------------");
        System.out.println("Przed sortowaniem: " + Arrays.toString(tab1));
        BubbleSort(tab1);
        System.out.println("Po sortowaniu zwyczajnym BubbleSort: " + Arrays.toString(tab1));
        BubbleSortImprovement2(tab2);
        System.out.println("Po sortowaniu ulepszonym BubbleSort: " + Arrays.toString(tab2));

        System.out.println("---------------------------------------------------");
        System.out.println("Przed sortowaniem: " + Arrays.toString(tab3));
        InsertionSort(tab3);
        System.out.println("Po sortowaniu InsertionSort: " + Arrays.toString(tab3));
        System.out.println("---------------------------------------------------");}
}