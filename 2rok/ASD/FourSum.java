//Anhelina Belavezha

//dla kazdej pary elementow z tablicy, znajdujemy przeciwna sume w posortowanej tablicy sum dwoch elementow. 
//Dzieki temu, zamiast uzywac zagniezdzonych petli, mozemy zredukowac zlozonosc obliczeniowa do O(n^3logn)

//Najpierw utworzymy tablice wszystkich mozliwych sum dwoch elementow z tablicy wejsciowej a i zapiszemy je w osobnej tablicy.
//Nastepnie posortujemy te tablice sum dwoch elementow, co zajmie O(n^2logn)
//Nastepnie iterujac sie przez wszystkie mozliwe pary sum dwoch elementow, znajdziemy, czy istnieje para sumy przeciwnych, 
//korzystajac z wyszukiwania binarnego w posortowanej tablicy. Dla kazdej pary znajdzmy czy istnieje przeciwna suma. To zajmie O(n^2logn)
//Dla kazdej znalezionej przeciwnosci, mozemy zlokalizowac odpowiadajace im indeksy w tablicy wejsciowej a


import java.util.Arrays;
public class FourSum {
    public static int count(long[] a) {
        int N = a.length;
        Arrays.sort(a); 
        int count = 0;

        long[] TwoSum = new long[N*N];
        int index = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                TwoSum[index++] = a[i] + a[j];
            }
        }

        Arrays.sort(TwoSum);

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long target = -(a[i] + a[j]);
                int left = 0, right = N*N - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (TwoSum[mid] == target) {
                        count++;
                        break;
                    } 
                    else if (TwoSum[mid] < target) {
                        left = mid + 1;
                    } 
                    else {
                        right = mid - 1;
                    }
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int N = StdIn.readInt();
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = StdIn.readLong();
        }
        int count = count(a);
        StdOut.println(count);
    }
}


