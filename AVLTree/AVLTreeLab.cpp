#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return 1 + max(lh,rh);
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value);
int getBalance(Node*subroot){
    if(!subroot) return 0;
    return getHeightRec(subroot->pLeft)- getHeightRec(subroot->pRight);
}







    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    Node* rightRotate(Node* y)
    {
        Node* x = y->pLeft;
        y->pLeft = x->pRight;
        x->pRight = y;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
    }
    Node* insert(Node* node, T key)
    {
        if (node == NULL)
            return(new Node(key));

        if (key < node->data)
            node->pLeft = insert(node->pLeft, key);
        else if (key >= node->data)
            node->pRight = insert(node->pRight, key);
        
        int balance = getBalance(node);
        // Left Left Case  
        if (balance > 1 && key < node->pLeft->data)
            return rightRotate(node);

        // Right Right Case  
        if (balance < -1 && key >= node->pRight->data)
            return leftRotate(node);

        // Left Right Case  
        if (balance > 1 && key >= node->pLeft->data)
        {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        // Right Left Case  
        if (balance < -1 && key < node->pRight->data)
        {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return node;
    }
    void insert(const T& value)
    {
        // TODO
        this->root = insert(this->root, value);
    }










    Node* maxValueNode(Node* node)
    {
        Node* current = node;

        /* loop down to find the leftmost leaf */
        while (current->pRight != NULL)
            current = current->pRight;

        return current;
    }

    Node* deleteNode(Node* root, int key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE  
        if (root == NULL)
            return root;
        // If the key to be deleted is smaller  
        // than the root's key, then it lies 
        // in left subtree  
        if (key < root->data)
            root->pLeft = deleteNode(root->pLeft, key);
        // If the key to be deleted is greater  
        // than the root's key, then it lies  
        // in right subtree  
        else if (key > root->data)
            root->pRight = deleteNode(root->pRight, key);

        // if key is same as root's key, then  
        // This is the node to be deleted  
        else
        {
            // node with only one child or no child  
            if ((root->pLeft == NULL) ||
                (root->pRight == NULL))
            {
                Node* temp = root->pLeft ?
                    root->pLeft :
                    root->pRight;

                // No child case  
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else // One child case  
                    *root = *temp; // Copy the contents of  
                                   // the non-empty child  
                free(temp);
            }
            else
            {
                Node* temp = maxValueNode(root->pLeft);
                root->data = temp->data;
                root->pLeft = deleteNode(root->pLeft,
                    temp->data);
            }
        }
        if (root == NULL)
            return root;
        // STEP 3: GET THE BALANCE FACTOR OF  
        // THIS NODE (to check whether this  
        // node became unbalanced)  
        int balance = getBalance(root);

        // If this node becomes unbalanced,  
        // then there are 4 cases  

        // Left Left Case  
        if (balance > 1 && getBalance(root->pLeft) >= 0)
            return rightRotate(root);
        // Left Right Case  
        if (balance > 1 && getBalance(root->pLeft) < 0)
        {
            root->pLeft = leftRotate(root->pLeft);
            return rightRotate(root);
        }

        // Right Right Case  
        if (balance < -1 &&  getBalance(root->pRight) <= 0)
            return leftRotate(root);

        // Right Left Case  
        if (balance < -1 && getBalance(root->pRight) > 0)
        {
            root->pRight = rightRotate(root->pRight);
            return leftRotate(root);
        }

        return root;
    }
    void remove(const T& value)
    {
        // TODO
        this->root = deleteNode(root, value);
    }



void printInorder(){
    if(root == NULL) return;
    
    Node*x = root;
    root = root->pLeft;
    printInorder();
    root = x;
    cout << root->data << " ";
    root = root->pRight;
    printInorder();
    root = x;
    
}

bool search(const T &value){
    //return search1(root,value);
    Node* x = root;
    while(x){
        if(x->data == value) return true;
        else if(x->data > value) x = x->pLeft;
        else x =x->pRight;
    }
    return false;
}
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};