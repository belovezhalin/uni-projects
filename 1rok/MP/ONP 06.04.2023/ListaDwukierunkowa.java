//Anhelina Belavezha - grupa nr 2
import java.util.Iterator;

public class ListaDwukierunkowa<E> implements Iterable<E> {
    private Node<E> head;
    private int size;

    private static class Node<E> {
        E data;
        Node<E> prev;
        Node<E> next;

        Node(E data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    public ListaDwukierunkowa() {
        this.head = null;
        this.size = 0;
    }

    public void Add(E data) {
        Node<E> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
            head.next = head;
            head.prev = head;
        } 
        else {
            Node<E> lastNode = head.prev;
            newNode.next = head;
            newNode.prev = lastNode;
            lastNode.next = newNode;
            head.prev = newNode;
        }
        size++;
    }

    public boolean Remove(E data) {
        if (head == null) return false;
        
        Node<E> current = head;
        do {
            if (current.data.equals(data)) {
                current.prev.next = current.next;
                current.next.prev = current.prev;
                if (current == head) {
                    head = current.next;
                }
                size--;
                return true;
            }
            current = current.next;
        } 
        while (current != head);
        return false;
    }

    public void PrintForward() {
        if (head == null) {
            System.out.println("Lista jest pusta");
            return;
        }
        Node<E> current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } 
        while (current != head);
        System.out.println();
    }

    public void printBackward() {
        if (head == null) {
            System.out.println("Lista jest pusta.");
            return;
        }
        Node<E> current = head.prev;
        do {
            System.out.print(current.data + " ");
            current = current.prev;
        } 
        while (current != head.prev);
        System.out.println();
    }

    public Iterator<E> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<E> {
        private Node<E> current = head;
        private int count = 0;

        public boolean hasNext() {
            return count < size;
        }

        public E next() {
            E data = current.data;
            current = current.next;
            count++;
            return data;
        }
    }
    public static void main(String[] args) {
        ListaDwukierunkowa<Integer> list = new ListaDwukierunkowa<>();

        list.Add(1);
        list.Add(2);
        list.Add(3);
        list.Add(4);
        list.Add(5);
        list.PrintForward();
        list.printBackward();
        list.Remove(3);
        list.PrintForward();
        list.printBackward();
    }
}