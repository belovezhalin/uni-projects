// Anhelina Belavezha
template <typename KEY_TYPE, typename DATA_TYPE>
class BST
{
    struct Node
    {
        KEY_TYPE key;
        DATA_TYPE data;
        Node *left;
        Node *right;
    };

public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        DeleteTree(root);
    }

    void DeleteTree(Node *node)
    {
        if (node)
        {
            DeleteTree(node->left);
            DeleteTree(node->right);
            delete node;
        }
    }

    int Height()
    {
        return Height(root);
    }

    int Height(Node *node)
    {
        if (!node)
            return -1;
        else
        {
            int leftside = Height(node->left);
            int rightside = Height(node->right);

            if (rightside < leftside)
                return (leftside + 1);
            else
                return (rightside + 1);
        }
    }

    void PrintPREORDER(Node *node)
    {
        if (node)
        {
            cout << node->key << node->data;
            PrintPREORDER(node->left);
            PrintPREORDER(node->right);
        }
    }

    void PreOrder()
    {
        PrintPREORDER(root);
    }

    void PrintINORDER(Node *node)
    {
        if (node)
        {
            PrintINORDER(node->left);
            cout << node->key << node->data;
            PrintINORDER(node->right);
        }
    }

    void InOrder()
    {
        PrintINORDER(root);
    }

    void PrintPOSTORDER(Node *node)
    {
        if (node)
        {
            PrintPOSTORDER(node->left);
            PrintPOSTORDER(node->right);
            cout << node->key << node->data;
        }
    }

    void PostOrder()
    {
        PrintPOSTORDER(root);
    }

    void PrintLEVELORDER(Node *node, int i)
    {
        if (node)
        {
            if (i == 1)
                cout << node->key << node->data;
            else if (1 < i)
            {
                PrintLEVELORDER(node->left, i - 1);
                PrintLEVELORDER(node->right, i - 1);
            }
        }
    }

    void LevelOrder()
    {
        for (int i = 1; i <= Height() + 1; i++)
        {
            PrintLEVELORDER(root, i);
        }
    }

    bool Insert(KEY_TYPE keyinput, DATA_TYPE datainput)
    {
        return Insert(root, keyinput, datainput);
    }

    bool Insert(Node *&node, KEY_TYPE keyinput, DATA_TYPE datainput)
    {
        if (!node) // jesli wskaznik na wezel jest pusty, to tworzymy nowy wezel
        {
            Node *temp = new Node();
            temp->key = keyinput;
            temp->data = datainput;
            temp->left = NULL;
            temp->right = NULL;
            node = temp;
            return true;
        }
        else // jesli wskaznik nie jest pusty,
        {
            if (node->key < keyinput) // i jest mniejszy od keyinput, to rekurencyjne dzialamy na prawym dziecku
            {
                return Insert(node->right, keyinput, datainput);
            }
            else if (keyinput < node->key) // w innym przypadku na lewym dziecku
            {
                return Insert(node->left, keyinput, datainput);
            }
        }
        return false;
    }

    DATA_TYPE *Search(Node *node, KEY_TYPE keyinput) ////////////////////////?? tylko operator <
    {
        if (node)
        {
            if (!(node->key < keyinput) && !(keyinput < node->key))
                return &(node->data);
            else if (keyinput < node->key)
                return Search(node->left, keyinput);
            else
                return Search(node->right, keyinput);
        }
        return NULL;
    }

    DATA_TYPE *Search(KEY_TYPE keyinput)
    {
        return Search(root, keyinput);
    }

    Node *Delete(Node *node, KEY_TYPE keyinput, bool &isdeleted)
    {
        if (!node)
            return node;
        if (keyinput < node->key)
        {
            node->left = Delete(node->left, keyinput, isdeleted);
            return node;
        }
        else if (node->key < keyinput)
        {
            node->right = Delete(node->right, keyinput, isdeleted);
            return node;
        }
        // przypadek jednego dziecka
        if (!node->left)
        {
            Node *temp = node->right;
            delete node;
            isdeleted = true;
            return temp;
        }
        else if (!node->right)
        {
            Node *temp = node->left;
            delete node;
            isdeleted = true;
            return temp;
        }
        else // przypadek dwoch dzieci
        {
            Node *nextparent = node;
            Node *mynext = node->right;

            while (mynext->left)
            {
                nextparent = mynext;
                mynext = mynext->left;
            }

            if (!(!(node < nextparent) && !(nextparent < node)))
                nextparent->left = mynext->right;
            else
                nextparent->right = mynext->right;

            node->key = mynext->key;
            node->data = mynext->data;
            isdeleted = true;
            delete mynext;
            return node;
        }
    }

    bool Delete(KEY_TYPE keyinput)
    {
        bool isdeleted = false;
        root = Delete(root, keyinput, isdeleted);
        return isdeleted;
    }
};