import java.util.Stack;

public class srodek {

    class Params {
        public int n;
        public int addr;

        public Params(int nn, int dd) {
            n = nn;
            addr = dd;
        }
    }

    class StackSimulationApp {
        static int n;
        static Params Par;
        static Stack S;
        static int label;
        static int sum;

        public static void main(String[] args) {
            n = sc.nextInt();
            Simulation();
            System.out.println(sum);
        }

        public static void Simulation() {
            S = new Stack(100);
            label = 1;
            while(step == false) ;
        }

        public static boolean step() {
            switch(label) {

                case 1: 
                Par = new Params(n, 6);
                S.push(Par);
                label = 2;
                break;

                case 2: 
                Par = S.top();
                if(Par.n == 1) {
                   sum = 1;
                   label = 5;
                   }
                else label = 3;
                break;

                case 3: 
                Params nPar = new Params(Par.n - 1, 4);
                S.push(nPar);
                label = 2;
                break;

                case 4:
                Par = S.top();
                sum = sum + Par.n;
                label = 5;
                break;

                case 5:
                Par = S.top();
                label = Par.addr;
                S.pop();
                break;

                case 6: 
                return true;
            }
            return false;
        }

    }

    public int iter_sum(int n) {
        S = new Stack(100);
        sum = 0;
        while(n > 0) {
            S.push(n);
            n--;
        }
        while(!S.isEmpty()) {
            int x = S.pop();
            sum = sum + x;
        }
    }

    void MergeSort(int[] A, int L, int R) {
        if(L > R) return;
        M = (L + R) / 2;
        MergeSort(A, L, M);
        MergeSort(A, M + 1, R);
        Merge(A, L, M, R, B);
    }

    void Merge(int[] A, int L, int M, int R, int[] B) {
        for(int i = 0; i < n; i++) B[i] = A[i];

        int i = L;
        int j = M + 1;
        int k = L;

        while(i <= M && j <= R) {
            if(B[i] < b[j]) A[k++] = B[i++];
            else A[k++] = B[j++];
        }

        while(i <= M) A[k++] = B[i++];
        while(j <= R) A[k++] = B[j++];
    }

    void ShellSort() {
        int j, n;
        int tmp;
        h = 1;
        while(h <= n/3) h = h*3 + 1;
        while(h > 0) {
            for(int k = h; k < n; k++) {
                tmp = a[k];
                j = k;
                while(j > h - 1 && a[j - h] >= tmp) {
                    a[j] = a[j - h];
                    j = j - h;
                }
                a[j] = tmp;
            }
            h = (h - 1) / 3;
        }
    }
}
