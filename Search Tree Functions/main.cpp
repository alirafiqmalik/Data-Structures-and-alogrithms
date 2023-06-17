//ALI HAMZA MALIK CMS:291480

#include <iostream>
using namespace std;

template <typename A>

struct Node
{
    A data;
    Node *right;
    Node *left;

    Node(A val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BST
{
public:
    // Constructor, destructor
    BST()
    {
        this->root = NULL;
        numNodes = 0;
    }
    ~BST()
    {
        delete root;
    };

    // Public interface
    bool isEmpty();          //
    bool find(const T &x);   //
    const T &findMin();      //
    const T &findMax();      //
    void insert(const T &x); //
    void remove(const T &x);
    void makeEmpty();
    void printTree(); //

    Node<T> *returnMaxNode();

private:
    // Root node (Private)
    Node<T> *root;
    int numNodes;

    // Utility methods (Private)
    Node<T> *findNode(Node<T> *node, const T &x);     //
    Node<T> *findMinNode(Node<T> *node);              //
    Node<T> *findMaxNode(Node<T> *node);              //
    Node<T> *findSuccessor(Node<T> *node);            //
    Node<T> *findParentOf(Node<T> *node, const T &x); //
    Node<T> *insertNode(Node<T> *node, const T &x);   //
    void removeAllNodes(Node<T> *node);
    void printNodesInOrder(Node<T> *node); //
};

template <typename T>
bool BST<T>::isEmpty()
{
    if (this->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void BST<T>::insert(const T &x)
{
    if (this->isEmpty())
    {
        this->root = new Node<T>(x);
    }
    else
    {
        this->root = insertNode(this->root, x);
    }
    numNodes += 1;
}

template <typename T>
Node<T> *BST<T>::insertNode(Node<T> *node, const T &x)
{
    if (node == NULL)
    {
        Node<T> *tmp = new Node<T>(x);
        return tmp;
    }
    else if (x <= node->data)
    {
        node->left = insertNode(node->left, x);
    }
    else
    {
        node->right = insertNode(node->right, x);
    }
    return node;
}

template <typename T>
void BST<T>::printTree()
{
    printNodesInOrder(this->root);
}

template <typename T>
void BST<T>::printNodesInOrder(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        printNodesInOrder(node->left);
        cout << node->data << "  ";
        printNodesInOrder(node->right);
    }
}

template <typename T>
bool BST<T>::find(const T &x)
{

    if (findNode(this->root, x) == NULL)
    {
        return false;
    }
    else
    {

        return true;
    }
}

template <typename T>
Node<T> *BST<T>::findNode(Node<T> *node, const T &x)
{
    if (node == NULL)
        return NULL;
    else if (x < node->data)
        return findNode(node->left, x);
    else if (x > node->data)
        return findNode(node->right, x);
    else
        return node;
}

template <typename T>
Node<T> *BST<T>::findMinNode(Node<T> *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->left == NULL)
    {
        return node;
    }
    else
    {
        return findMinNode(node->left);
    }
}

template <typename T>
Node<T> *BST<T>::findMaxNode(Node<T> *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->right == NULL)
    {
        return node;
    }
    else
    {
        return findMaxNode(node->right);
    }
}

template <typename T>
const T &BST<T>::findMax()
{
    if (this->findMaxNode(this->root) == NULL)
    {
        throw 1;
    }
    return (this->findMaxNode(this->root)->data);
}

template <typename T>
const T &BST<T>::findMin()
{
    if (this->findMinNode(this->root) == NULL)
    {
        throw 1;
    }
    return (this->findMinNode(this->root)->data);
}

template <typename T>
Node<T> *BST<T>::findSuccessor(Node<T> *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->left == NULL)
    {
        return node;
    }
    else
    {
        node = findSuccessor(node->left);
    }
    return node;
}

template <typename T>
Node<T> *BST<T>::findParentOf(Node<T> *node, const T &x)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if ((node->left->data == x) || (node->right->data == x))
    {
        return node;
    }
    else if (x <= node->data)
    {
        return findParentOf(node->left, x);
    }
    else
    {
        return findParentOf(node->right, x);
    }
}

template <typename T>
void BST<T>::remove(const T &x)
{
    Node<T> *tmp;
    tmp = findNode(this->root, x);
    if (tmp != NULL)
    {
        cout << "Removing Node with value=" << tmp->data << endl;
        if ((tmp->left == NULL) && (tmp->right == NULL))
        {
            Node<T> *tmp2;
            tmp2 = findParentOf(this->root, x);
            if (tmp2->left == tmp)
            {
                tmp2->left = NULL;
            }
            else
            {
                tmp2->right = NULL;
            }
            delete tmp;
        }
        else if (tmp->left == NULL)
        {
            Node<T> *par;
            par = findParentOf(this->root, x);
            if (par->right == tmp)
            {
                par->right = tmp->right;
            }
            else
            {
                par->left = tmp->right;
            }
            tmp->right = NULL;
            delete tmp;
        }
        else if (tmp->right == NULL)
        {
            Node<T> *par;
            par = findParentOf(this->root, x);
            if (par->right == tmp)
            {
                par->right = tmp->left;
            }
            else
            {
                par->left = tmp->left;
            }
            tmp->left = NULL;
            delete tmp;
        }
        else
        {
            Node<T> *succ, *par;
            succ = findSuccessor(tmp->right);
            par = findParentOf(this->root, succ->data);
            tmp->data = succ->data;
            if (par->left == succ)
            {
                par->left = NULL;
            }
            else
            {
                par->right = NULL;
            }

            delete succ;
        }
    }
    else
    {
        cout << "Value not Found in Tree" << endl;
        return;
    }
    this->numNodes -= 1;
}

template <typename T>
void BST<T>::removeAllNodes(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        removeAllNodes(node->left);
        removeAllNodes(node->right);
        delete node;
        this->numNodes -= 1;
    }
}

template <typename T>
void BST<T>::makeEmpty()
{
    removeAllNodes(this->root);
    this->root = NULL;
}

int main()
{
    BST<int> B1;

    cout << B1.isEmpty() << endl;

    B1.insert(10);
    B1.insert(8);
    B1.insert(9);
    B1.insert(5);
    B1.insert(15);
    B1.insert(20);
    B1.insert(13);
    B1.insert(16);
    B1.insert(28);
    B1.insert(11);

    cout << B1.isEmpty() << endl;

    B1.printTree();

    cout << B1.find(9) << endl;
    cout << B1.find(0) << endl;
    cout << B1.find(10) << endl;

    cout << B1.findMin() << endl;
    cout << B1.findMax() << endl;

    B1.remove(5);
    B1.printTree();
    cout << endl;

    B1.remove(8);
    B1.printTree();
    cout << endl;

    B1.remove(11);
    B1.printTree();
    cout << endl;

    B1.remove(5);
    B1.printTree();
    cout << endl;

    B1.remove(20);
    B1.printTree();
    cout << endl;

    B1.remove(200);
    B1.printTree();
    cout << endl;

    cout << B1.isEmpty()<<endl;

    B1.makeEmpty();

    cout << B1.isEmpty();

    return 1;
}
