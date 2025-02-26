
class Car {

    private double mileage;

    public Car() {
        mileage = 0;
    }


    public void drive(double miles) {
        // cout << miles << endl;
        System.out.println(miles);
        if (miles > 0) {
            mileage += miles;
        }

    }

    public void display() {
        System.out.println("Car " + mileage);
    }
    
    @Override // nadpisujemy z klasy Object
    public String toString() {
        return "Car " + Double.toString(mileage);
    }
    // --------------------------------------------------

    @Override
    public boolean equals(Object o) {
        System.out.println("Equals");
        // self check
        if (this == o) {
            return true;
        }
        // null check
        if (o == null) { // this == null, o == null -> true ?
            return false;
        }
        // type check and cast
        if (getClass() != o.getClass()) {
            return false;
        }
        return this.mileage == ((Car) o).mileage;
    }
    
}

// nie można dać metody "luzem"
// void method() {}
class CarParking {

    static void strangeMethod(Car car, Integer m) {
        car.drive(m);
        m = 0; // warning - i tak nie używamy
    }
}

public class HelloWorld {

    public static void main(String[] args) {
        // Nazwa pliku jak klasy
        // Alt+Shift+F - formatowanie kodu

        // Referencja a nie zmienna
        // New zwraca referencję a nie wskaźnik
        // Nie ma delete
        Car c1 = new Car();

        // cout << "ALA" << endl;
        System.out.println("ALA");

        System.out.println(c1); // toString
        c1.display();

        // Wbudowane typy - kopia, obiekty - przypisanie referencji
        int a = 5;
        int b = a;
        a = 3; // warning - i tak nie używamy
        System.out.println(b);

        Car c2 = c1;
        c2.drive(10);
        // c1.display();
        // c2.display();
        System.out.println(c1);
        System.out.println(c2);

        // ++++++++++
        // Doświadczenie - jak działa ==? Jak działa equal? Co gdy go nadpiszemy?
        // Dopisać metodę wyświetlają wszystkie dane samochodu na ekran
        Car c3 = new Car();
        Car c4 = new Car();


        if (c3 == c4) {
            System.out.println("Są identyczne");
        } else {
            System.out.println("Nie są identyczne");
        }

        if (c3.equals(c4)) {
            System.out.println("Są równe");
        } else {
            System.out.println("Nie są równe");
        }

        // Tablice
        int size = 5;
        int[] tablica = new int[size];
        for (int i = 0; i < 5; i++) {
            tablica[i] = i + 1;
        }
        System.out.println(tablica[3]);
        for (int i = 0; i < 5; i++) {
            System.out.println("Kolejna komórka to: " + tablica[i]);
        }

        // --------------------------------------------------
        // Typy wbudowane przekazywane przez kopię, obiekty zawsze przez referencje
        Car carArgument = new Car();
        Integer intArgument = 80;

        // System.out.println(carArgument);
        // System.out.println(intArgument);
        // Metoda statyczna
        CarParking.strangeMethod(carArgument, intArgument);
        // System.out.println(carArgument);
        // System.out.println(intArgument);
        int x = 0;

        // ++++++++++
        // Dopisać do samochodu tablicę z 5 ostatnimi przejazdami
        // Dodać metodę - przesuwanie przejazdów jak nowa podróż, ma zwiększać przebieg
    }

}