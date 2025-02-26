//Anhelina Belavezha

class Node {                                                                 //klasa reprezentujaca wezel drzewa BST
    double value;
    Node left;
    Node right;

    public Node(double value) {
        this.value = value;
        left = right = null;
    }
}

class BST {                                                                 //klasa reprezentujaca drzewo BST
    Node root;

    public BST() {
        root = null;
    }

    public void PrintPreorder(Node node) {                                  //wypisanie wszystkich orderow
        if (node != null) {
            System.out.print(node.value + " ");
            PrintPreorder(node.left);
            PrintPreorder(node.right);
        }
    }

    public void PrintInorder(Node node) {
        if (node != null) {
            PrintInorder(node.left);
            System.out.print(node.value + " ");
            PrintInorder(node.right);
        }
    }

    public void PrintPostorder(Node node) {
        if (node != null) {
            PrintPostorder(node.left);
            PrintPostorder(node.right);
            System.out.print(node.value + " ");
        }
    }

    public double FindMax() {                                            //wynalezienie maksymalnego elementu
        if (root == null) {
            System.out.println("Drzewo jest puste.");
            return Double.MIN_VALUE;
        }

        Node current = root;
        while (current.right != null) {
            current = current.right;
        }
        return current.value;
    }

    public double FindMin() {                                           //wynalezienie minimalnego elementu
        if (root == null) {
            System.out.println("Drzewo jest puste.");
            return Double.MAX_VALUE;
        }

        Node current = root;
        while (current.left != null) {
            current = current.left;
        }
        return current.value;
    }

    public void Insert(double value) {                                 //wstawianie wezla
        root = InsertNode(root, value);
    }

    private Node InsertNode(Node node, double value) {
        if (node == null) {
            return new Node(value);
        }

        if (value < node.value) {
            node.left = InsertNode(node.left, value);
        } 
        else if (value > node.value) {
            node.right = InsertNode(node.right, value);
        }
        return node;
    }

    public void Delete(double value) {                                 //usuwanie wezla
        root = DeleteNode(root, value);
    }

    private Node DeleteNode(Node node, double value) {
        if (node == null) {
            return null;
        }

        if (value < node.value) {
            node.left = DeleteNode(node.left, value);
        } 
        else if (value > node.value) {
            node.right = DeleteNode(node.right, value);
        } 
        else {                                                        //wezel do usuniecia zostal znaleziony
            if (node.left == null) {
                return node.right;
            } else if (node.right == null) {
                return node.left;
            }

            node.value = findMinValue(node.right);                   //wezel dwoch potomkow
            node.right = DeleteNode(node.right, node.value);
        }
        return node;
    }

    private double findMinValue(Node node) {
        double minValue = node.value;
        while (node.left != null) {
            minValue = node.left.value;
            node = node.left;
        }
        return minValue;
    }
}

public class ZadanieDomowe1 {
    public static void main(String[] args) {
        BST bst = new BST();
        bst.Insert(10);
        bst.Insert(5);
        bst.Insert(15);
        bst.Insert(3);
        bst.Insert(7);

        System.out.println("Preorder:");
        bst.PrintPreorder(bst.root);
        System.out.println();

        System.out.println("Inorder:");
        bst.PrintInorder(bst.root);
        System.out.println();

        System.out.println("Postorder:");
        bst.PrintPostorder(bst.root);
        System.out.println();

        System.out.println("Max value: " + bst.FindMax());
        System.out.println("Min value: " + bst.FindMin());

        bst.Delete(5);
        System.out.println("Inorder po usunieciu 5:");
        bst.PrintInorder(bst.root);
    }
}
