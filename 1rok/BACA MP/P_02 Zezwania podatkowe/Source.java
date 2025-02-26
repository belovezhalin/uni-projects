//Anhelina Belavezha - grupa nr 2
//ogolna idea programu: odpowiedz na pytanie "ilu obywateli w ostatnim roku uzyskalo dochody mieszczace sie w przedziale o zadanych wartosciach"
import java.util.Scanner;                                                  //import do skanera
public class Source {
    public static Scanner sc = new Scanner(System.in);                     //zmienna przechowujaca dane wprowadzane z klawiatury
    public static int[] tab;
        public static void main(String[] args) {                           //funkcja glowna programu                             
        int counter = sc.nextInt();                                        //zmienna przechowujaca ilosc zestawow
        while(counter > 0) {                              
            int amount = sc.nextInt();                                     //zmienna przechowujaca ilosc danych w zestawie
            tab = new int[amount];
            for(int i = 0; i < amount; i++) {                              //uzupelnienie danych zestawu
                tab[i] = sc.nextInt();}
            int question = sc.nextInt();                                   //zmienna przechowujaca ilosc zapytan
            while(question > 0) {
                int x = sc.nextInt();                                      //zmienna przechowujaca poczatek przedzialu
                int y = sc.nextInt();                                      //zmienna przechowujaca koniec przedzialu
                int first = SearchBinFirst(x);
                int last = SearchBinFirst(y + 1);                          //liczby uporzadkowane niemalejaco, wiec ostatnie wystapienie y bedzie wczesniej niz y + 1
                int number;                                                //zmienna przechowujaca ilosc elementow przedzialu [x..y]
                if(last < first) number = 0;
                else number = last - first;                                                                                                                    
                System.out.println(number);
                question--;}
            int count = Count(tab);                                        //zmienna przechowujaca liczbe zeznan
            System.out.println(count);                                                         
            counter--;}}

        public static int SearchBinFirst(int x) {                          //algorytm BinarySearch, wyszukajacy pierwsze wystapienie liczby x
            int start = 0;                                                 //zlozonosc czasowa O(logn), bo przejmujemy posortowana tablice
            int end = tab.length;                                          //zlozonosc pamieciowa O(1), bo nie alokujemy pamieci
            int result = -1;
            while (start <= end) {
                   int middle = (start + end) / 2;
                   if (middle == tab.length) return tab.length;            //przypadek gdy element nie znajduje sie w przedziale
                   if (tab[middle] > x) {
                      end = middle - 1;
                      result = middle;} 
                   else if (tab[middle] < x) {
                      start = middle + 1;
                      result = start;} 
                   else {
                      result = middle;
                      end = middle - 1;}}
                return result;}

        public static int Count(int[] tab) {                                //metoda zwracajaca liczbe zeznan tablicy
            int count = 1;                                                  //zlozonosc czasowa O(n), bo musimy przejrzec kazdy element tab
            for (int i = 1; i < tab.length; i++) {                          //zlozonosc pamieciowa O(1), bo nie alokujemy pamieci
                if (tab[i] != tab[i - 1]) count++;}                            
            return count;}
 }

 /*
  * test.in
  3
  7
  0 0 1 2 2 5 5
  5
  0 5
  5 1
  1 2
  0 2
  5 2
  10
  2 2 2 2 2 2 2 2 2 2
  4
  0 3
  2 2
  8 1
  -1 -1
  8 
  1 1 2 3 3 3 6 8
  4
  0 6
  8 3
  1 3
  2 6
  * test.out
  7
  0
  3
  5
  0
  4
  10
  10
  0
  0
  1
  7
  0
  6
  5
  5
  */
