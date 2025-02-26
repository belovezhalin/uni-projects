//Ihor Kudybyn

template<class KEY_TYPE, class DATA_TYPE>
class BST {
public:
    struct Node {
        KEY_TYPE key;
        DATA_TYPE data;

        Node *left;
        Node *right;

        /*
        Node() {}

        Node(KEY_TYPE key, DATA_TYPE data) {
            this->key = key;
            this->data = data;
            left = NULL;
            right = NULL;
        }
        */

        Node() {
            left = NULL;
            right = NULL;
        }
    };

    class Queue {
    public:
        Node **tab;
        int front, rear;

        Queue(int size) {
            tab = new Node *[size];
            front = 0;
            rear = 0;
        }

        ~Queue() {
            delete[] tab;
        }

        void Pop() {
            for (int i = 0; i < rear - 1; i++) {
                tab[i] = tab[i + 1];
            }
            rear--;
        }

        void Push(Node *node) {
            tab[rear] = node;
            rear++;
        }

        Node *Front() {
            return *(tab + front);
        }

        bool Empty() {
            return front == rear;
        }
    };

    Node *root;

    BST() {
        root = NULL;
    }

    ~BST() {
        if (root == NULL) return;
        Destructor(root);
        root = NULL;
    }

    void Destructor(Node *node) {
        if (node == NULL) return;
        Destructor(node->left);
        Destructor(node->right);
        delete node;
        node = NULL;
    }

    bool Insert(KEY_TYPE key, DATA_TYPE data) {
        if (root == NULL) {
            root = new Node();
            root->key = key;
            root->data = data;
            return true;
        } 
        else {
            Node *tempo = root;
            while (tempo != NULL) {
                if (!(key < tempo->key || tempo->key < key)) {
                    return false;
                } 
                else if (key < tempo->key && tempo->left == NULL) {
                    tempo->left = new Node();
                    tempo->left->key = key;
                    tempo->left->data = data;
                    return true;
                } 
                else if (key < tempo->key) {
                    tempo = tempo->left;
                } 
                else if (tempo->key < key && tempo->right == NULL) {
                    tempo->right = new Node();
                    tempo->right->key = key;
                    tempo->right->data = data;
                    return true;
                } 
                else {
                    tempo = tempo->right;
                }
            }
        }
    }

    /*
    bool Insert(KEY_TYPE key, DATA_TYPE data) {
        if (root == NULL) {
            root = new Node(key, data);
            return true;
        } 
        else {
            Node *tempo = root;
            while (tempo != NULL) {
                if (!(key < tempo->key || tempo->key < key)) {
                    return false;
                } 
                else if (key < tempo->key && tempo->left == NULL) {
                    tempo->left = new Node(key, data);
                    return true;
                } 
                else if (key < tempo->key) {
                    tempo = tempo->left;
                } 
                else if (tempo->key < key && tempo->right == NULL) {
                    tempo->right = new Node(key, data);
                    return true;
                } 
                else {
                    tempo = tempo->right;
                }
            }
        }
    }
    */

    DATA_TYPE *Search(KEY_TYPE key) {
        if (root == NULL) {
            return NULL;
        } 
        else {
            Node *tempo = root;
            while (tempo != NULL) {
                if (!(key < tempo->key || tempo->key < key)) { return &tempo->data; } 
                else if (key < tempo->key && tempo->left == NULL) { return NULL; } 
                else if (key < tempo->key) { tempo = tempo->left; } 
                else if (tempo->key < key && tempo->right == NULL) { return NULL; } 
                else { tempo = tempo->right; }
            }
        }
    }

    Node *RecDelete(Node *node, KEY_TYPE key) {
        if (node == NULL) {
            return NULL;
        } 
        else if (key < node->key) {
            node->left = RecDelete(node->left, key);
            return node;
        } 
        else if (node->key < key) {
            node->right = RecDelete(node->right, key);
            return node;
        }
        if (node->left == NULL) {
            Node *temp = node->right;
            delete node;
            return temp;
        } 
        else if (node->right == NULL) {
            Node *temp = node->left;
            delete node;
            return temp;
        } 
        else {
            Node *tempParent = node;
            Node *temp = node->right;

            while(temp->left != NULL) {
                tempParent = temp;
                temp = temp->left;
            }

            if (tempParent != node) {
                tempParent->left = temp->right;
            } 
            else {
                tempParent->right = temp->right;
            }

            node->key = temp->key;
            node->data = temp->data;
            delete temp;
            return node;
        }
    }

    /*
    Node* RecDelete(Node* node, KEY_TYPE key) {
        if (node == NULL) {
            return NULL;
        }

        if (key < node->key) {
            node->left = RecDelete(node->left, key);
        } 
        else if (node->key < key) {
            node->right = RecDelete(node->right, key);
        } 
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } 
            else {
                Node* successor = FindMin(node->right);
                node->key = successor->key;
                node->data = successor->data;
                node->right = RecDelete(node->right, successor->key);
            }
        }
        return node;
    }

    Node* FindMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    */

    bool Delete(KEY_TYPE key) {
        if (root == NULL) return false;
        if (Search(key) == NULL) return false;
        root = RecDelete(root, key);
        return true;
    }

    void PreOrder() {
        RecPreOrder(root);
    }

    void RecPreOrder(Node *node) {
        if (node == NULL) return;
        cout << node->key << node->data;
        RecPreOrder(node->left);
        RecPreOrder(node->right);
    }

    void InOrder() {
        RecInOrder(root);
    }

    void RecInOrder(Node *node) {
        if (node == NULL) return;
        RecInOrder(node->left);
        cout << node->key << node->data;
        RecInOrder(node->right);
    }

    void PostOrder() {
        RecPostOrder(root);
    }

    void RecPostOrder(Node *node) {
        if (node == NULL) return;
        RecPostOrder(node->left);
        RecPostOrder(node->right);
        cout << node->key << node->data;
    }

    void LevelOrder() {
        if (root == NULL) return;
        //wedlug wzoru: maksymalna pojemnosc kolejki = i * (j-1) * (j-2) * ... * 2
        int i = 4;
        for (int j = 2; j < Height(); j++) {           
            i *= j;
        }

        Queue *queue = new Queue(i);
        queue->Push(root);

        while (!queue->Empty()) {
            Node *node = queue->Front();
            cout << node->key << node->data;
            queue->Pop();

            if (node->left != NULL) {
                queue->Push(node->left);
            }

            if (node->right != NULL) {
                queue->Push(node->right);
            }
        }

        delete queue;
    }

    int Height() {
        if (this->root == NULL) return -1;
        return RecHeight(root);
    }

    int RecHeight(Node *node) {
        if (node == NULL) return -1;

        int fromleft = this->RecHeight(node->left);
        int fromright = this->RecHeight(node->right);

        if (fromright < fromleft) return fromleft + 1;
        else return fromright + 1;
    }
};
