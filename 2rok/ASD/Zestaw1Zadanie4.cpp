//Anhelina Belavezha
//Zestaw 1 zadanie 4
//algorytm sekwencyjny wyznaczajacy, czy element nalezy do ciagu 

//zlozonosc pamieciowa: n + 3
//(n-elementowa tablica i 3 int zmienne)

//zlozonosc czasowa: 
//-pesymistyczna: Tmax(A, n) = n (najgorszy przypadek: x jest ostatnim elementem lub w ogole nie nalezy do ciagu)
//-srednia: O(n)

bool CzyJestElementem(int n, int* A, int x) {
    int i = 0;
    while(i < n && A[i] != x) {
        i++;
    }
    if(i < n) return true;
    else return false;
}