#include <iostream>
#include <ostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedStack {
public:
    Node<T>* top;
    int size;

    LinkedStack() : top(nullptr), size(0) {}

    int Size() const {
        return size;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void Push(const T& element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        newNode->next = top;

        top = newNode;
        size++;
    }

    T Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        T poppedData = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;

        size--;
        return poppedData;
    }

    void Print() {
        Node<T>* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

template <>
class LinkedStack<int> {
public:
    int* data;
    int top;
    int size;

    LinkedStack() : top(-1), size(0) {
        data = new int[MAX_SIZE];
    }

    ~LinkedStack() {
        delete[] data;
    }

    int Size() const {
        return size;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void Push(const int& element) {
        data[++top] = element;
        size++;
    }

    int Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return 0;
        }

        size--;
        return data[top--];
    }

    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    static const int MAX_SIZE = 1000;
};

class MyClass {
public:
    int value;

    MyClass() : value(0) {}  
    MyClass(int v) : value(v) {}

    friend ostream& operator<<(ostream& os, const MyClass& object) {
        os << object.value;
        return os;
    }
};

int main() {
    LinkedStack<MyClass> stack1;
    stack1.Push(MyClass(2));
    stack1.Push(MyClass(3));
    stack1.Push(MyClass(6));
    stack1.Print();
    stack1.Pop();
    stack1.Print();

    LinkedStack<int> stack2;
    stack2.Push(11);
    stack2.Push(45);
    stack2.Push(67);
    stack2.Print();
    stack2.Pop();
    stack2.Print();

    return 0;
}
