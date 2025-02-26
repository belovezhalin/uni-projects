// Illia Kolisnyk

template <typename KEY_TYPE, typename DATA_TYPE>
class Node
{
public:
    KEY_TYPE key;
    DATA_TYPE data;
    Node<KEY_TYPE, DATA_TYPE> *left;
    Node<KEY_TYPE, DATA_TYPE> *right;

    Node(KEY_TYPE key, DATA_TYPE data) : key(key), data(data), left(NULL), right(NULL) {}
    ~Node() {}

    void Display()
    {
        cout << key << data << " ";
    }
};

template <typename KEY_TYPE, typename DATA_TYPE>
class BST
{
public:
    Node<KEY_TYPE, DATA_TYPE> *root;
    BST() : root(NULL) {}

    ~BST()
    {
        Delete(root);
    }

    void Delete(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node != NULL)
        {
            Delete(node->right);
            Delete(node->left);
            delete node;
        }
    }

    void PreOrder()
    {
        PreOrder(root);
    }

    void PreOrder(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node != NULL)
        {
            node->Display();
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }

    void InOrder()
    {
        InOrder(root);
    }

    void InOrder(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node != NULL)
        {
            InOrder(node->left);
            node->Display();
            InOrder(node->right);
        }
    }

    void PostOrder()
    {
        PostOrder(root);
    }

    void PostOrder(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node != NULL)
        {
            PostOrder(node->left);
            PostOrder(node->right);
            node->Display();
        }
    }

    void LevelOrder()
    {
        int height = Height() + 1;
        for (int i = 1; i <= height; i++)
            LevelOrder(root, i);
    }

    void LevelOrder(Node<KEY_TYPE, DATA_TYPE> *node, int level)
    {
        if (node == NULL)
            return;
        if (level == 1)
            node->Display();
        else if (level > 1)
        {
            level--;
            LevelOrder(node->left, level);
            LevelOrder(node->right, level);
        }
    }

    bool Insert(KEY_TYPE key, DATA_TYPE data)
    {
        Node<KEY_TYPE, DATA_TYPE> *curr = root;
        Node<KEY_TYPE, DATA_TYPE> *prev = NULL;
        Node<KEY_TYPE, DATA_TYPE> *newNode = new Node<KEY_TYPE, DATA_TYPE>(key, data);

        if (root == NULL)
        {
            root = new Node<KEY_TYPE, DATA_TYPE>(key, data);
            return true;
        }

        while (curr != NULL)
        {
            prev = curr;
            if (key < curr->key)
                curr = curr->left;
            else if (curr->key < key)
                curr = curr->right;
            else
                return false;
        }

        if (key < prev->key)
            prev->left = newNode;
        else
            prev->right = newNode;
        return true;
    }

    int Height()
    {
        return Height(root);
    }

    int Height(Node *node)
    {
        if (node == NULL) return -1;
        else
        {
            int leftside = Height(node->left);
            int rightside = Height(node->right);

            if (rightside < leftside) return (leftside + 1);
            else return (rightside + 1);
        }
    }

    DATA_TYPE *Search(KEY_TYPE key)
    {
        Node<KEY_TYPE, DATA_TYPE> *curr = root;
        while (curr != NULL)
        {
            if (key < curr->key)
                curr = curr->left;
            else if (curr->key < key)
                curr = curr->right;
            else
                return &(curr->data);
        }
        return NULL;
    }

    Node<KEY_TYPE, DATA_TYPE> *Parent(Node<KEY_TYPE, DATA_TYPE> *child)
    {
        Node<KEY_TYPE, DATA_TYPE> *curr = root;

        if (child == NULL)
            return NULL;

        while (curr != NULL)
        {
            if (curr->left == child || curr->right == child)
                return curr;
            if (child->key < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return NULL;
    }

    Node<KEY_TYPE, DATA_TYPE> *Next(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node == NULL)
            return NULL;
        if (node->right != NULL)
        {
            Node<KEY_TYPE, DATA_TYPE> *curr = node->right;
            while (curr->left != NULL)
                curr = curr->left;
            return curr;
        }
        else
        {
            Node<KEY_TYPE, DATA_TYPE> *parent = Parent(node);
            Node<KEY_TYPE, DATA_TYPE> *previousNode = node;
            while (parent != NULL && parent->left != previousNode)
            {
                previousNode = parent;
                parent = Parent(parent);
            }
            return parent;
        }
    }

    bool Delete(KEY_TYPE key)
    {
        Node<KEY_TYPE, DATA_TYPE> *foundNode = root;

        while (foundNode != NULL)
        {
            if (key < foundNode->key)
                foundNode = foundNode->left;
            else if (foundNode->key < key)
                foundNode = foundNode->right;
            else
                break;
        }

        if (foundNode == NULL)
            return false;

        while (foundNode != NULL)
        {
            Node<KEY_TYPE, DATA_TYPE> *parent = Parent(foundNode);
            if (foundNode->left == NULL && foundNode->right == NULL)
            {
                if (parent != NULL)
                {
                    if (parent->right == foundNode)
                        parent->right = NULL;
                    else
                        parent->left = NULL;
                }
                else
                    root = NULL;
                delete foundNode;
                return true;
            }
            else if (foundNode->left != NULL && foundNode->right == NULL)
            {
                if (parent != NULL)
                {
                    if (parent->left == foundNode)
                        parent->left = foundNode->left;
                    else
                        parent->right = foundNode->left;
                }
                else
                    root = foundNode->left;

                delete foundNode;
                return true;
            }
            else if (foundNode->left == NULL && foundNode->right != NULL)
            {
                if (parent != NULL)
                {
                    if (parent->left == foundNode)
                        parent->left = foundNode->right;
                    else
                        parent->right = foundNode->right;
                }
                else
                    root = foundNode->right;
                delete foundNode;
                return true;
            }
            else
            {
                Node<KEY_TYPE, DATA_TYPE> *next = Next(foundNode);
                foundNode->data = next->data;
                foundNode->key = next->key;
                foundNode = next;
            }
        }
    }
};