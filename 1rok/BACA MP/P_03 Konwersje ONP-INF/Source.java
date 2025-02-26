//Anhelina Belavezha - grupa nr 2
import java.util.Scanner;                                                                    //import do scannera
/*Ogolna idea programu: konwersje z onp na inf, z inf na onp.
Implementacja dwoch metod konwertujacych wyrazenia matematyczne miedzy postacia algebraiczna(INF) i postacia Odwrotnej Notacji Polskiej(ONP).
Na podstawie wprowadzonego wyrazenia odpowiednia metoda jest wywolywana i wywolanie jej wynik jest wyswietlany.
Metoda ONPTOINF konwertuje wyrazenie z postaci ONP na postaz INF. 
Metoda INFTOONP konwertuje wyrazenie z postaci INF na postac ONP. 
Obie metody wykorzystuja stos do przechowywania kolejnych znakow wprowadzonego wyrazenia matematycznego i przetwarzaja je w celu uzyskania 
ostatecznego wyniku w odpowiedniej postaci. Pozostale metody w kodzie są wykorzystywane w procesie konwersji wyrazen i wykonuja rozne operacje
na znakach i stosie w celu uzyskania poprawnego wyniku.*/
public class Source {
    public static Scanner scanner = new Scanner(System.in);                                  //zmienna przechowujaca dane wprowadzone z klawiatury
     public static void main(String[] args) {                                                //funkcja glowna
      int z = scanner.nextInt();                                                             //zmienna przechowujaca ilosc zestawow 
      while(z-- > 0) {
         String operation = scanner.next();                                                  //zmienna przechowujaca operacje
         switch(operation) {                                                                 //w zaleznosci od operacji robimy dzialania
         case "INF:":                                                                                                                                 //jesli konwertujemy z INF na ONP
            String sequenceINF = scanner.nextLine();                                         //pobieramy wyrazenie do konwersji
            if(!IsINFTrue(DeleteINF(sequenceINF))) System.out.println("ONP: error");       //sprawdzamy poprawnosc input
            else {
               String result = INFTOONP(DeleteINF(sequenceINF));
               System.out.println("ONP: " + (result));}                                      //wypisujemy rezultat
            break;                                     

         case"ONP:":                                                                         //jesli konwertujemy z ONP na INF
            String sequenceONP = scanner.nextLine();                                         //pobieramy wyrazenie do konwersji
            if(!IsONPTrue(DeleteONP(sequenceONP))) System.out.println("INF: error");       //sprawdzamy poprawnosc input
            else {
               String result = ONPTOINF(DeleteONP(sequenceONP));
               System.out.println("INF: " + (result));}                                      //wypisujemy rezultat 
            break;}}}                                              

    public static String DeleteINF(String sequence) {                                        //metoda czyszczajaca input INF
      String result = new String();
      for(int i = 0; i < sequence.length(); i++) {
         if(Priority(sequence.charAt(i)) != -1 || IsOperand(sequence.charAt(i)) || sequence.charAt(i) == '(' || sequence.charAt(i) == ')') {
            result += sequence.charAt(i);}}
      return result;}

    public static String DeleteONP(String sequence) {                                       //metoda czyszczajaca input ONP
      String result = new String();
      for(int i = 0; i < sequence.length(); i++) {
         if(Priority(sequence.charAt(i)) != -1 || IsOperand(sequence.charAt(i))) {
            result += sequence.charAt(i);}}
      return result;}

    public static int Priority(char symbol) {                                               //przechowywanie priorytetow operatorow wedlug polecenia
      if(symbol == '!' || symbol == '~')                       return 8;
      else if(symbol == '^')                                   return 7;
      else if(symbol == '*' || symbol == '/' || symbol == '%') return 6;
      else if(symbol == '+' || symbol == '-')                  return 5;
      else if(symbol == '<' || symbol == '>')                  return 4;
      else if(symbol == '?')                                   return 3;
      else if(symbol == '&')                                   return 2;
      else if(symbol == '|')                                   return 1;
      else if(symbol == '=')                                   return 0;
      else                                                     return -1;}                

    public static boolean IsBinaryOperator(char symbol) {                                   //zwracanie true gdy operator jest dwustronny
      int priority = Priority(symbol);
      if(priority >= 0 && priority <= 7) return true;
      else return false;}

    public static boolean IsUnaryOperator(char symbol) {                                    //zwracanie prawdy gdy operator jest jednostronny
      if(Priority(symbol) == 8) return true;
      else return false;}

    public static boolean IsRight(char symbol) {                                            //zwracanie prawdy gdy operator jest prawostronny
      int priority = Priority(symbol);
      if(priority == 0 || priority == 7 || priority == 8) return true;
      else return false;}

    public static boolean IsOperand(char symbol) {                                          //zwracanie wartosci czy symbol jest mala litera (operandem)
      return Character.isLowerCase(symbol);}

    public static boolean IsOperator(char symbol) {                                         //zwracanie czy symbol jest operatorem
      if(Priority(symbol) >= 0) return true;
      else return false;}
    
    public static boolean IsONPTrue(String sequence) {                                      //sprawdzanie czy input ONP jest poprawny
      int binaryoperators = 0;
      int operands = 0;
      if(IsOperator(sequence.charAt(0))) return false;                                //zwracamy falsz gdy pierwszy znak input nie jest operandem
      if(sequence.length() > 1 && IsBinaryOperator(sequence.charAt(1))) return false; //zwracamy falsz gdy dlugosc ciagu jest wieksza od dwoch a drugi symbol jest operatorem dwustronnym
      
      for(int i = 0; i < sequence.length(); i++) {
         if (IsOperand(sequence.charAt(i))) operands++;                                     //zwiekszamy liczbe operandow jesli symbol jest operandem
         else if (IsBinaryOperator(sequence.charAt(i))) binaryoperators++;                  //zwiekszamy liczbe operatorow jesli symbol jest operatorem
         else if (sequence.charAt(i) == '(' || sequence.charAt(i) == ')') return false;}    //zwracamy falsz gdy spotykamy nawiasy w ONP
         
      if(operands - 1 != binaryoperators) return false;                                     //zwracamy falsz gdy nie mamy lacznosci miedzy liczba operatorow a liczba operandow
      if(IsOperand(sequence.charAt(sequence.length() - 1)) && sequence.length() != 1) return false; //zwracamy falsz gdy nie mamy lacznosci miedzy dlugoscia a liczba operandow
      
      return true;}                                                                         //w ostatnich przypadkach input jest poprawny

    public static String ONPTOINF(String sequence) {                                        //konwersja z ONP na INF
      String result = "";                                                                   //zmienna przechowujaca resultat konwersji
      int sizeofstack = 0;                                                                  //zmienna przechowujaca rozmiar stosu
      String[] stack = new String[256];                                                     //tablica stosu
      int[] priority = new int[256];                                                        //tablica priorytetow operandow 

      for(int i = 0; i < sequence.length(); i++) {
         if(IsOperand(sequence.charAt(i))) {                                                //jesli symbol jest operandem 
            stack[sizeofstack] = String.valueOf(sequence.charAt(i)) + " ";                  //kladziemy go na stos
            priority[sizeofstack] = 10;                                                     //przepisujemy mu najwyzszy priorytet
            sizeofstack++;}                                                                 //zwiekszmy stos
         else {                                                                             //jesli symbol jest operatorem lub nawisem
            if(IsRight(sequence.charAt(i))) {                                               //jest operatorem prawostronnym
               if(Priority(sequence.charAt(i)) > priority[sizeofstack - 1]) {               //jesli priorytet operatora jest wiekszy od priorytetu operanda
                  stack[sizeofstack - 1] = "( " + stack[sizeofstack - 1] + ") ";}}          //zamykamy go w nawiasy
            else {                                                                          //jest operatorem lewostronnym lub nawiasem
               if(Priority(sequence.charAt(i)) >= priority[sizeofstack - 1]) {              //jesli priorytet operatora nie jest mniejszy od priorytetu operanda
                  stack[sizeofstack - 1] = "( " + stack[sizeofstack - 1] + ") ";}}          //zamykamy go w nawiasy

            if(IsBinaryOperator(sequence.charAt(i))) {                                      //jesli jest operatorem prawostronnym
               if (Priority(sequence.charAt(i)) > priority[sizeofstack - 2]) {              //sprawdzamy czy priorytet operatora jest wiekszy niz priorytet symbolu znajdujacego sie przed nim na stosie, poniewaz operator binarny wymaga dwoch argumentow
                  stack[sizeofstack - 2] = "( " + stack[sizeofstack - 2] + ") ";}           //jesli tak, zamykamy go w nawiasy
               stack[sizeofstack - 2] += sequence.charAt(i) + " " + stack[sizeofstack - 1]; //operator i drugi argument sa dodawane do symbolu ktory znajduje sie na szczycie stosu
               priority[sizeofstack - 2] = Priority(sequence.charAt(i));                    //priorytet operatora jest przypisywany do symbolu na szczycie stosu
               sizeofstack--;}                                                              //ostatni element na stosie jest usuwany
            else {                                                                          //jesli jest opetarorem unarnym lub nawisem zamykajcym
               stack[sizeofstack - 1] = sequence.charAt(i) + " " + stack[sizeofstack - 1];  //symbol jest dodawany do symbolu na szczycie stosu
               priority[sizeofstack - 1] = Priority(sequence.charAt(i));}}}                 //aktualizacja priorytetu (element przesuwa sie na stosie na jedno miejsce w dol)
      for(int i = 0; i < sizeofstack; i++) {
         result += stack[i] + " ";}
    return result;}                                                                         //zwracanie rezultatu

    public static boolean IsINFTrue(String sequence) {                                     //dziala na podstawie automatu 
        boolean binaryoperator = false;                                                    //zmienna przechowujaca wystapienie operatora binarnego
        boolean unaryoperator = false;                                                     //zmienna przechowujaca wystapienie operatora unarnego
        boolean operand = false;                                                           //zmienna przechowujaca wystapienie operanda
        boolean nawias = false;                                                            //zmienna przechowujaca wystapienie nawiasu
        int opennawias = 0;                                                                //zmienna przechowujaca wystapienie otwartych nawiasow
        if((IsBinaryOperator(sequence.charAt(0)) || sequence.charAt(0) == ')'))  return false; //zwracamy falsz gdy na poczatku ciagu jest operator binarny lub nawias zamykajacy (nie odpowiada postaci INF)
      
        for(int i = 0; i < sequence.length(); i++) {
         if(sequence.charAt(i) == '(') {                                                   //jesli napotkamy na nawias otwarty
            if(operand) return false;                                                      //jesli operand jest przed nawiasem zwracamy falsz (nie odpowiada postaci INF)
            opennawias++;
            nawias = true;
            binaryoperator = false;
            unaryoperator = false;
            operand = false;}

         else if(sequence.charAt(i) == ')') {                                              //jesli napotkamy na nawias zamykajacy
            if(binaryoperator || unaryoperator || nawias || opennawias == 0) return false; //sprawdzenie czy wystapili wszystkie znaki operacji w nawiasach przed nawiasem zamykajacym
            opennawias--;
            nawias = false;
            binaryoperator = false;
            unaryoperator = false;
            operand = true;}

         else if(IsUnaryOperator(sequence.charAt(i))) {                                   //jesli napotkamy na operator unarny
            if(operand) return false;                                                     //jesli poprzednim elementem nie byl operand to zwracamy falsz
            binaryoperator = false;
            unaryoperator = true;
            nawias = false;
            operand = false;}

         else if(IsBinaryOperator(sequence.charAt(i))) {                                  //jesli napotkamy na operator binarny
            if(binaryoperator || unaryoperator || nawias || i == 0) return false;         //sprawdzenie czy wzesniej juz wystapily wszystkie operatory / nawiasy, czy to nie jest poczatek ciagu
            binaryoperator = true;
            unaryoperator = false;
            nawias = false;
            operand = false;}
            
         else {                                                                           //jesli napotkamy na operand
            if(operand) return false;                                                     //sprawdzenie czy poprzedni element byl operandem
            binaryoperator = false;
            unaryoperator = false;
            nawias = false;
            operand = true;}}

      if((opennawias != 0 || IsOperator(sequence.charAt(sequence.length() - 1)))) return false;  //zwaracamy falsz gdy w ciagu sa otwarte nawiasy lub gdy ostatni symbol jest operatorem
    
      return true;}                                                                         //w przeciwnym przypadku zwracamy prawde

    public static String INFTOONP(String sequence) {                                        //konwersja z INF na ONP
        String result = new String();                                                       //zmienna przechowujaca rezultat
        String[] stack = new String[256];                                                   //tablica stosu
        int sizeofstack = 0;                                                                //rozmiar stosu

        for(int i = 0; i < sequence.length(); i++) {
           if (IsOperand(sequence.charAt(i))) {                                             //jesli symbol jest operandem przepisujemy go do rezultatu
              result += sequence.charAt(i) + " ";}

           else if(IsOperator(sequence.charAt(i))) {                                        //jesli symbol jest operatorem...
              if(IsRight(sequence.charAt(i))) {                                             //...prawostronnym
                 if(sizeofstack == 0 || Priority(stack[sizeofstack - 1].charAt(0)) <= Priority(sequence.charAt(i))) { //jesli stos jest pusty lub priorytet operatora jest wiekszy lub rowny priorytetowi operatora na szczycie stosu 
                    stack[sizeofstack] = String.valueOf(sequence.charAt(i));                //dodajemy operator na stos
                    sizeofstack++;}                                                         //zwiekszamy stos
                 else {                                      
                    for(int j = sizeofstack - 1; j >= 0; j--) {                             //dopoki na sszczycie stosu nie zostanie operator o mniejszym priorytecie lub lewy nawias
                       if(sequence.charAt(i) != '(' && Priority(stack[j].charAt(0)) > Priority(sequence.charAt(i))) { //wszystkie operatory o wiekszym priorytecie sa usuwane ze stosu i dodawane so rezultatu
                          result += stack[j] + " ";
                          sizeofstack--;                                                   //zmniejszamy stos
                          stack[j] = "";}
                       else break;}
                    stack[sizeofstack] = String.valueOf(sequence.charAt(i));               //dopisywanie symboli na stos
                    sizeofstack++;}}                                                       //zwiekszanie stosu
                    
              else {                                                                       //...lewostronnym
                 if(sizeofstack == 0 || Priority(stack[sizeofstack - 1].charAt(0)) < Priority(sequence.charAt(i))) { //jesli stos jest pusty lub priorytet operatora jest wiekszy priorytetowi operatora na szczycie stosu 
                    stack[sizeofstack] = String.valueOf(sequence.charAt(i));               //dodajemy operator na stos
                    sizeofstack++;}                                                        //zwiekszamy stos
                 else { 
                    for(int j = sizeofstack - 1; j >= 0; j--) {
                       if(sequence.charAt(i) != '(' && Priority(stack[j].charAt(0)) >= Priority(sequence.charAt(i))) { //wszystkie operatory o wiekszym lub rownym priorytecie sa usuwane ze stosu i dodawane so rezultatu
                          result += stack[j] + " ";
                          sizeofstack--;                                                   //zmniejszamy stos
                          stack[j] = "";}
                       else break;}
                    stack[sizeofstack] = String.valueOf(sequence.charAt(i));               //dopisywanie symboli na stos
                    sizeofstack++;}}}                                                      //zwiekszanie stosu   
           else {
              if(sequence.charAt(i) == '(') {                                              //jesli symbol jest nawiasem lewostronnym
                 stack[sizeofstack] = String.valueOf(sequence.charAt(i));                  //dopisujemy na stos
                 sizeofstack++;}                                                           //zwiekszanie stosu
              else {  
                 int j;                                                                    //jesli jest nawiasem prawostronnym
                 for(j = sizeofstack - 1; stack[j].charAt(0) != '('; j--) {                //do napotkania pierwszego (
                    result += stack[j] + " ";                                              //dopisujemy ze stosu symbole do rezultatu
                    sizeofstack--;                                                         //zmniejszamy stos
                    stack[j] = "";}
                 stack[j] = "";
                 sizeofstack--;}}}
        for(int i = sizeofstack - 1; i >= 0; i--) {                                        
           result += stack[i] + " ";                                                       //koncowe przepisanie resultatu se stosu
           sizeofstack--;}                                                                 //zmniejszanie stosu
        
    return result;}}
/*
 * input
 * 15
 * INF: (a+b)/c+q
 * ONP: ab*cab**^
 * INF: ((a^b)^c)^d
 * ONP: xabcde^^==
 * INF: x=(a=(b=c^(d^e)))
 * ONP: xa~~~~~~-
 * INF: a+b+(~a-a)
 * INF: x=~~a+b*c
 * ONP: a
 * INF: a
 * INF: a*b+c*d+d*e+f*g
 * ONP: ab*cd*+de*+fg*+
 * ONP: abcd+++
 * ONP: ab+c+d+
 * INF: a+b+c+d
 * output
 * ONP: a b + c / q +
 * INF: ( a * b ) ^ ( c * ( a * b ) )
 * ONP: a b ^ c ^ d ^
 * INF: error
 * ONP: x a b c d e ^ ^ = = = 
 * INF: x - ~ ~ ~ ~ ~ ~ a
 * ONP: a b + a ~ a - +
 * ONP: x a ~ ~ b c * + = 
 * INF: a
 * INP: a
 * ONP: a b * c d * + d e * + f g * +
 * INF: a * b + c * d + d * e + f * g
 * INF: a + ( b + ( c + d ) )
 * INF: a + b + c + d
 * ONP: a b + c + d +
 */

   

   


