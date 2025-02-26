public class ZadanieDomowe {
    public static void CountSort(int[] array) {
        int n = array.length;
        int max = array[0];                                    //inicjalizacja maksymalnego elementu
        for (int i = 1; i < n; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        int m = max + 1;                                       //znaleziony maksymalny element

        int[] count = new int[m];                              //tablica pomocnicza do przechowywania ilosci wystapien
        for (int i = 0; i < n; i++) {
            count[array[i]]++;                                 //zliczamy ilosc wystapien poszczegolnych elementow
        }

        for (int j = 1; j < m; j++) {
            count[j] = count[j - 1] + count[j];                //obliczamy gorne granice obszarow wynikowych dla poszczegolnych wartosci
        }

        int[] result = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            count[array[i]]--;
            result[count[array[i]]] = array[i];                //przepisujemy elementy z tablicy array[] do tablicy result[] na wlasciwe miejsca
        }

        for (int i = 0; i < n; i++) {
            array[i] = result[i];                              //przepisujemy do tablicy glownej
        }
    }

    public static void RadixSort(int[] array) {
        if (array.length == 0) {
            return;
        }

        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];                                //wyszukiwanie maksymum
            }
        }

        for (int exp = 1; max / exp > 0; exp *= 10) {          //exp - wartosc potegi dziesiatki
            CountingSort(array, exp);
        }
    }

    public static void CountingSort(int[] array, int exp) {
        int[] result = new int[array.length];
        int[] count = new int[10];

        for (int i = 0; i < array.length; i++) {
            count[(array[i] / exp) % 10]++;                    //zliczanie wystapien cyfry
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];                          //sumowanie ilosci cyfr mniejszych lub rownych od biezacej cyfry
        }

        for (int i = array.length - 1; i >= 0; i--) {
            result[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (int i = 0; i < array.length; i++) {
            array[i] = result[i];
        }
    }

    public static int HoareSelect(int[] array, int k) {
        int n = array.length; 
        int pivot = array[0];                                  //wybieramy pierwszy element jako pivot
        int s1Size = 0, s2Size = 0, s3Size = 0;                //inicjujemy rozmiary podzbiorow
        for (int i = 0; i < n; i++) {                          //przechodzimy przez zbior i zliczamy elementy w kazdym podzbiorze
            if (array[i] < pivot) {
                s1Size++;
            } 
            else if (array[i] == pivot) {
                s2Size++;
            } 
            else {
                s3Size++;
            }
        }

        int[] s1 = new int[s1Size];
        int[] s2 = new int[s2Size];
        int[] s3 = new int[s3Size];
        int s1Index = 0, s2Index = 0, s3Index = 0;             //inicjujemy indeksy do wypelniania tablic
           
        for (int i = 0; i < n; i++) {                          //przepisujemy elementy z array do odpowiednich tablic w zależnosci od wartosci pivot        
            if (array[i] < pivot) {
                s1[s1Index++] = array[i];
            } 
            else if (array[i] == pivot) {
                s2[s2Index++] = array[i];
            } 
            else {
                s3[s3Index++] = array[i];
            }
        }

        if (k <= s1.length) {                                  //jesli k-ty element jest w S1, rekurencyjnie wywolujemy funkcję na S1
            return HoareSelect(s1, k);
        } 
        else if (k <= s1.length + s2.length) {                 //jesli k-ty element jest w S2, to zwracamy pivot, ktory jest k-tym elementem
            return pivot;
        } 
        else {                                                 //jesli k-ty element jest w S3, to rekurencyjnie wywolujemy funkcję na S3, ale przesuwajac numer elementu o rozmiar S1 i S2
            return HoareSelect(s3, k - s1.length - s2.length);
        }
    }

    public static void main(String[] args) {
        int[] array = { 3, 2, 5, 1, 4, 2, 3 };
    
        System.out.print("Przed sortowaniem CountSort: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    
        CountSort(array);
    
        System.out.print("Po sortowaniu CountSort: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();

        int[] array2 = {170, 45, 75, 90, 802, 24, 2, 66};

        System.out.print("Przed sortowaniem RadixSort: ");
        for (int i = 0; i < array2.length; i++) {
            System.out.print(array2[i] + " ");
        }
        System.out.println();

        RadixSort(array2);

        System.out.print("Po sortowaniu RadixSort: ");
        for (int i = 0; i < array2.length; i++) {
            System.out.print(array2[i] + " ");
        }
        System.out.println();

        int[] array3 = {8, 5, 2, 9, 7, 6, 3};
        int k = 3;
        int kElement = HoareSelect(array3, k);
        System.out.println("K-ty element: " + kElement);
    }
    }
    
