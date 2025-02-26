public class sortowania {
public static void CountSort(int[] array) {
    int n = array.length;
    int[] output = new int[n];

    int max = array[0];                                        //znajdowanie maksymalnej wartosci w tablicy
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int[] count = new int[max + 1];                            //inicjalizacja tablicy count[] i zliczanie elementow
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    //obliczenie gornych granic obszarów wynikowych dla poszczególnych wartości
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // przepisanie elementów z tablicy array[] do output[] w właściwe miejsca
    for (int i = n - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // przepisanie posortowanej tablicy output[] z powrotem do array[]
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}
}