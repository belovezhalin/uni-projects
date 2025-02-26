import java.util.Random;
public class QuickSort {
    ////////////////////////////////////////////////////////////////////////////////z wyborem dzielacego elementu z lewej
    public static void QuickSort1(int[] array) {
        QuickSort1(array, 0, array.length - 1);
    }

    private static void QuickSort1(int[] array, int left, int right) {
        if (left >= right) return;
    
        int pivotindex = Partition1(array, left, right);
        
        QuickSort1(array, left, pivotindex - 1);
        QuickSort1(array, pivotindex + 1, right);
    }

    private static int Partition1(int[] array, int left, int right) {
        int pivot = array[left];
        int i = left + 1;
        int j = right;

        while (i <= j) {
            if (array[i] <= pivot) {
                i++;
            } 
            else if (array[j] > pivot) {
                j--;
            } 
            else {
                swap(array, i, j);
            }
        }

        swap(array, left, j);
        return j;
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
///////////////////////////////////////////////////////////////////////////////////jako mediany z trzech
    public static void QuickSort2(int[] array) {
        QuickSort2(array, 0, array.length - 1);
    }

    private static void QuickSort2(int[] array, int left, int right) {
        if (left >= right) return;
        
        int pivotindex = MedianOfThree(array, left, right);
        int newpivotindex = Partition2(array, left, right, pivotindex);
        
        QuickSort2(array, left, newpivotindex - 1);
        QuickSort2(array, newpivotindex + 1, right);
    }

    private static int MedianOfThree(int[] array, int left, int right) {
        int center = (left + right) / 2;

        if (array[left] > array[center]) {
            swap(array, left, center);
        }

        if (array[left] > array[right]) {
            swap(array, left, right);
        }

        if (array[center] > array[right]) {
            swap(array, center, right);
        }

        return center;
    }

    private static int Partition2(int[] array, int left, int right, int pivotindex) {
        int pivot = array[pivotindex];
        int i = left - 1;
        int j = right + 1;

        while (true) {
            do {
                i++;
            } 
            while (array[i] < pivot);

            do {
                j--;
            } 
            while (array[j] > pivot);

            if (i >= j) {
                return j;
            }

            swap(array, i, j);
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] array = new int[10000];
        int[] array1 = new int[10000];
        int[] array2 = new int[10000];
        int[] array3 = new int[10000];
        
        for(int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(10000);
        }

        long startTime = System.nanoTime();
        QuickSort1(array);
        long endTime = System.nanoTime();
        long duration1 = (endTime - startTime) / 10000;

        startTime = System.nanoTime();
        QuickSort2(array);
        endTime = System.nanoTime();
        long duration2 = (endTime - startTime) / 10000;

        System.out.println("QuickSort: " + duration1 + " ms");
        System.out.println("QuickSortMedian: " + duration2 + " ms");

        for(int i = 0; i < array1.length; i++) {
            array1[i] = rand.nextInt(10000);
        }

        startTime = System.nanoTime();
        QuickSort1(array1);
        endTime = System.nanoTime();
        long duration3 = (endTime - startTime) / 10000;

        startTime = System.nanoTime();
        QuickSort2(array1);
        endTime = System.nanoTime();
        long duration4 = (endTime - startTime) / 10000;

        System.out.println("QuickSort: " + duration3 + " ms");
        System.out.println("QuickSortMedian: " + duration4 + " ms");

        for(int i = 0; i < array2.length; i++) {
            array2[i] = rand.nextInt(10000);
        }

        startTime = System.nanoTime();
        QuickSort1(array2);
        endTime = System.nanoTime();
        long duration5 = (endTime - startTime) / 10000;

        startTime = System.nanoTime();
        QuickSort2(array2);
        endTime = System.nanoTime();
        long duration6 = (endTime - startTime) / 10000;

        System.out.println("QuickSort: " + duration5 + " ms");
        System.out.println("QuickSortMedian: " + duration6 + " ms");

        for(int i = 0; i < array3.length; i++) {
            array3[i] = rand.nextInt(10000);
        }

        startTime = System.nanoTime();
        QuickSort1(array3);
        endTime = System.nanoTime();
        long duration7 = (endTime - startTime) / 10000;

        startTime = System.nanoTime();
        QuickSort2(array3);
        endTime = System.nanoTime();
        long duration8 = (endTime - startTime) / 10000;

        System.out.println("QuickSort: " + duration7 + " ms");
        System.out.println("QuickSortMedian: " + duration8 + " ms");
    }
}

