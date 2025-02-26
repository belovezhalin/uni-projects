//Anhelina Belavezha - grupa nr 2
/* Ogolna idea programu: wykonywanie konstrukcji drzewa binarnego na podstawie podanych porzadkow wezlow i wyswietlenie porzadkow wezlow 
w roznych formatach. Dla każdego zestawu danych wypisuje w kolejnych liniach dwie listy: pierwsza to lista w porządku w glab,
druga jest lista w porzadku wrzesz. */
import java.util.Scanner;                                                                  //import do scanera

public class Source {
public static Scanner scanner = new Scanner(System.in);                                    //zmienna przechowujaca zmienne wprowadzone z klawiatury
    public static void main(String[] args) {                                               //funkcja glowna kodu
       int z = scanner.nextInt();                                                          //zmienna przechowujaca ilosc zestawow
       for (int i = 1; i <= z; i++) {
          System.out.println("ZESTAW " + i);                                               //wyswietlenie numeracji
          int n = scanner.nextInt();                                                       //zmienna przechowujaca ilosc wierzcholkow
          String order = scanner.next();                                                   //napis przechowujacy porzadek
          if(order.equals("PREORDER")) {                                          //jesli porzadek preorder...
             int preORDER[] = new int[n];                                                  //tworzymy tablice o dlugosci wierzcholkow
             for(int j = 0; j < n; j++) {
                preORDER[j] = scanner.nextInt();                                           //wypelniamy ja 
             }
             scanner.next();                                                               //pomiajmy "INORDER"
             int inORDER[] = new int[n];
             for(int j = 0; j < n; j++) {
                inORDER[j] = scanner.nextInt();                                            //tworzymy i wypelniamy tablice z porzadkiem inorder
             }
 
             BinaryTree tree = new BinaryTree();                                           //tworzymy drzwo binarne
             tree.root = tree.BuildPreorder(preORDER, inORDER, 0, n - 1);            //tworzymy korzen w porzadku preorder
             BinaryTree.previousIndex = 0; 
             System.out.println("POSTORDER");                                            //wypisujemy rezultat
             tree.PrintPostorder(tree.root);
             System.out.println();
             System.out.println("LEVELORDER");
             tree.PrintLevelorder(tree.root);
             System.out.println();
          } 
          else {                                                                           //jesli porzadek postorder...
             int postORDER[] = new int[n];
             for(int j = 0; j < n; j++) {
                postORDER[j] = scanner.nextInt();                                          //tworzymy i wypelniamy tablice z porzadkiem postorder
             }
             scanner.next();                                                               //pomijamy "INORDER"
             int inORDER[] = new int[n];
             for(int j = 0; j < n; j++) {
                inORDER[j] = scanner.nextInt();                                            //tworzymy i wypelniamy tablice z porzadkiem inorder
             }
             
             BinaryTree tree = new BinaryTree();                                           //tworzymy drzewo binarne
             tree.root = tree.BuildPostorder(postORDER, inORDER, 0, n - 1, 0, n - 1); //tworzymy korzen w porzadku postorder
             System.out.println("PREORDER");                                             //wypisujemy rezultsat
             tree.PrintPreorder(tree.root);
             System.out.println();
             System.out.println("LEVELORDER");
             tree.PrintLevelorder(tree.root);
             System.out.println();
          }
       }
    }
 }

class Node {                                                                               //klasa wezel                
    int key;                                                                               //wartosc wezla
    Node right = null;                                                                     //dzieci 
    Node left = null;
 
    Node(int k) {                                                                          //konstruktor klasy Node
       right = left = null;
       key = k;
    }
 }

class Queue {                                                                              //klasa przechowujaca kolejke fifo
   private QueueNode start, end;                                                           //poczatek i koniec kolejki                                                        

   private class QueueNode {                                                               //reprezentacja wezla kolejki
      QueueNode next = null;
      Node data;

      QueueNode(Node data) {
         this.data = data;
         this.next = null;
      }
   }

   public Queue() {                                                                       //konstruktor klasy queue
      start = null;
      end = null;
   }

   public boolean isEmpty() {                                                            //funkcja sprawdzajaca czy kolejka jest pusta
      return start == null;
   }
 
   public void Insert(Node data) {                                                       //wstawiamy wezel w zaleznosci od tego czy kolejka byla pusta 
      QueueNode newQueueNode = new QueueNode(data);

      if(!isEmpty()) {
        end.next = newQueueNode;
        end = newQueueNode;
      } 
      else {
         start = newQueueNode;
         end = newQueueNode;
      }
   }

   public Node Remove() {                                                               //usuwamy wezel z kolejki
      Node data = start.data;
      start = start.next;

      if(start == null) {
         end = null;
      }
      return data;
   }
}

class BinaryTree {                                                                     //klasa przechowujaca drzewo binarne
   static int previousIndex = 0;
   Node root = null;

   BinaryTree() {                                                                      //konstruktor
      root = null;
   }

   Node BuildPreorder(int[] preORDER, int[] inORDER, int start, int end) {
      if(start > end) return null;                                                     //przypadek blednego drzewa
      Node node = new Node(preORDER[previousIndex++]);
      if(start == end) return node;                                                    //przypadek braku dzieci
      int index = Find(inORDER, start, end, node.key);                                 //szukamy index wezla w preorder
      node.left = BuildPreorder(preORDER, inORDER, start, index - 1);                  //budujemy drzewo
      node.right = BuildPreorder(preORDER, inORDER, index + 1, end);
      return node;
   }

   Node BuildPostorder(int[] postORDER, int[] inORDER, int inStart, int inEnd, int postStart, int postEnd) { 
      if(inStart > inEnd) return null;                                                 //przypadek blednego drzewa
      Node node = new Node(postORDER[postEnd]);
      if(inStart == inEnd) return node;                                                //przypadek braku dzieci
      int index = Find(inORDER, inStart, inEnd, node.key);                             //szukamy index wezla w postorder
      node.left = BuildPostorder(postORDER, inORDER, inStart, index - 1, postStart, postStart + index - 1 - inStart); //budujemy drzewo
      node.right = BuildPostorder(postORDER, inORDER, index + 1, inEnd, postEnd + index - inEnd, postEnd - 1);
      return node;
   }

   int Find(int[] array, int left, int right, int x) {                                 //wyszukiwanie elementu
      for(int i = left; i <= right; i++) {
         if(array[i] == x)
            return i;
      }
      return -1;
   }

   void PrintPreorder(Node node) {                                                     //wypisanie rezultatu preorder
      if(node == null) return;
      System.out.print(node.key + " ");
      PrintPreorder(node.left);
      PrintPreorder(node.right);
   }

   void PrintPostorder(Node node) {                                                   //wypisanie rezultatu postorder
      if(node == null) return;
      PrintPostorder(node.left);
      PrintPostorder(node.right);
      System.out.print(node.key + " ");
   }

   public void PrintLevelorder(Node node) {                                           //poziomowe przechodznie drzewa
      Queue queue = new Queue();                                                      //tworzymy pusta kolejke
      queue.Insert(node);                                                             //wstawiamy wezel jako korzen
      while(!queue.isEmpty()) {                                                       //dopoki kolejka nie jest pusta            
         Node rnode = queue.Remove();                                                 //usuwamy pierwszy wezel kolejki
         System.out.print(rnode.key + " ");                                           //wyswietlamy zawartosc usunietego wezla

         if(rnode.left != null) queue.Insert(rnode.left);                             //o ile dzieci usunietego wezla istnieja wstawiamy ich do kolejki
         if(rnode.right != null) queue.Insert(rnode.right);
      }
   }
}
/*
 * input:
 * 1
 * 7
 * PREORDER
 * 1 2 4 3 5 6 7
 * INORDER
 * 4 2 1 5 3 6 7
 * 1
 * 8
 * POSTORDER
 * 8 4 5 2 7 6 3 1
 * INORDER
 * 4 2 5 8 6 7 3 1
 * 1
 * 5
* POSTORDER
 * 3 2 5 4 1
 * INORDER
 * 3 2 1 5 4
 * 2
 * 6
 * PREORDER
 * 1 2 3 4 5 6
 * INORDER
 * 6 5 4 3 2 1
 * 4
 * POSTORDER
 * 4 3 2 1
 * INORDER
 * 4 3 2 1
 * output:
 * ZESTAW 1
 * POSTORDER
 * 4 2 5 7 6 3 1
 * LEVELORDER
 * 1 2 3 4 5 6 7
 * ZESTAW 1
 * PREORDER
 * 1 2 4 8 5 6 7 3
 * LEVELORDER
 * 1 2 3 4 5 6 7 8
 * ZESTAW 1
 * PREORDER
 * 1 2 3 4 5
 * LEVELORDER
 * 1 2 3 4 5
 * ZESTAW 1
 * POSTORDER
 * 6 5 4 3 2 1
 * LEVELORDER
 * 1 2 3 4 5 6
 * ZESTAW 2
 * PREORDER
 * 1 2 3 4
 * LEVELORDER
 * 1 2 3 4
 */


