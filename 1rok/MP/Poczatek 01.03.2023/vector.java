class vector {

    private int[] a; // referencja do wektora
    private int maxSize; // maksymalna długość wektora
    private int n; // aktualna długość wektora

    public vector(int m) { // konstruktor
        maxSize = m;
        n = 0;
        a = new int[maxSize];
    }

    // Dopisz:

    // konstruktor przyjmujący maksymalny rozmiar "m" i wypełniający wektor
    // "l" losowymi wartościami z przedziału 0-100 (proszę znaleźć jak losować w
    // Internecie)
    public vector(int m, int l) {
        maxSize = m;
        n = l;
        a = new int[maxSize];
        int x = 0;
        int y = 100;
        for (int i = 0; i < n; i++) {
        a[i] = x + (int)(Math.random() * y);
        }
    }

    // wyświetl wektor na ekran
    public void display() {
        for (int i = 0; i < n; i++) {
        System.out.print(a[i] + " ");
        }
        System.out.println("");
    }

    // zwróć Stringa z kolejnymi wartościami z wektora rozdzielonymi spacją
    @Override
    public String toString() {
        String spacja = "";
        for (int i = 0; i < n; i++) {
            spacja += Integer.toString(a[i]) + " ";
        }
        return spacja;
    }

    // wstaw "x" na koniec wektora (uwaga na maksymalny rozmiar)
    public void insert(int x) {
        if (n != maxSize) {
            a[n] = x;
            n += 1;
        }
    }

    // usuń z wektora wszystkie wystąpienia liczby "x"
    public void remove(int x) {
        int u = 0;
        for (int i = 0; i < n - u; i++) {
            if (a[i + u] == x) {
                u += 1;
                i -= 1;
            }
            else a[i] = a[i + u];
        }
        n -= u;
    }

    // zwraca element o podanym indeksie (uwaga na nieprawidłowe indeksy)
    public int at(int i) {
        if (i >= 0 && i < 100) {
        return a[i];
        }
        else return -1;
    }
    // Stwórz w funkcji main prezentację wszystkich funkcji
    public static void main(String[] args) {
        vector v = new vector(15, 10);
        v.display();
        v = new vector(14);
        v.insert(5);
        v.insert(7);
        v.insert(8);
        v.insert(3);
        v.insert(9);
        v.insert(1);
        v.insert(2);
        System.out.println(v.toString() + " ");
        v.remove(5);
        System.out.println(v.toString() + " ");
        System.out.print(v.at(3));}}