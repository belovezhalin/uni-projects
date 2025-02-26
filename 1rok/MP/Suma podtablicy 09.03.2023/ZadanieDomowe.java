class ZadanieDomowe {
    public static void main(String[] args) {
        int n = 7; 
        int[] a = {-1, 1, 2, -3, -1, 11, 2};

        int b1 = 0, e1 = 0, max1 = 0; 
        for (int i = 0; i < n; i++) {                 // pętla obliczająca maksymalną sumę podtablicy
            for (int j = i; j < n; j++) {             // i - poczatek podtablicy, j - koniec podtablicy 
                int sum1 = 0;                         //suma podtablicy a[i..j]
                for (int k = i; k <= j; k++) {
                     sum1 += a[k];}
                if (sum1 > max1) {
                        max1 = sum1;
                        b1 = i;                       //b i e - poczatek i koniec maksymalnej podtablicy
                        e1 = j;}}}
        System.out.println("Najwieksza suma (rozpatrujemy wszystkie podtablice(O(n^3))): " + max1);

        int b2 = 0, e2 = 0, max2 = 0; 
        for (int i = 0; i < n; i++) {                //początek podtablicy
         int sum2 = 0;
            for (int j = i; j < n; j++) {            //koniec podtablicy
            sum2 = sum2 + a[j];
            if (sum2 > max2) {
            max2 = sum2;
            b2 = i;
            e2 = j;}}} 
        System.out.println("Najwieksza suma (korzystujac z poprzedniej najwiekszej tablicy(O(n^2))): " + max2);
        
        int curr = 0, bk1 = 0, bk2 = 0, max3 = 0, e3 = 0;              //curr - suma aktualnej podtablicy o koncu i-1
        for (int i = 0; i < n; i++) {                                  //max - maksymalna suma podtablicy
            curr = curr + a[i]; 
            if (curr < 0) {26
               curr = 0;
               bk2 = i + 1;}

            else if (curr > max3) {
               max3 = curr;
               bk1 = bk2;
               e3 = i;}}
        System.out.println("Najwieksza suma (algorytm Kadane(O(n))): " + max3);}
}
    