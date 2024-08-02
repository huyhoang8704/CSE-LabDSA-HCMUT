#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <class K, class V>
class BinaryTree
{
public:
    class Node;
    Node *root;

private:
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node *walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    int height(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int lheight = height(root->pLeft);
            int rheight = height(root->pRight);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }
    void printCurrentLevel(Node *root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
            printf("%d ", root->value);
        else if (level > 1)
        {
            printCurrentLevel(root->pLeft, level - 1);
            printCurrentLevel(root->pRight, level - 1);
        }
    }
    void BFS()
    {
        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            printCurrentLevel(root, i);
        }
    }
    // STUDENT ANSWER END
    // STUDENT ANSWER END
};

int main()
{
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);  // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node
    cout << binaryTree.height(binaryTree.root) << endl;
    binaryTree.printCurrentLevel(binaryTree.root, 2);
    cout << endl;
    binaryTree.BFS();
}