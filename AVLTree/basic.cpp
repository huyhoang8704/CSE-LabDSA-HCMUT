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







//Helping functions
Node* rotateLeft(Node* root){
    Node* tempPtr = root->pRight;
    root->pRight = tempPtr->pLeft;
    tempPtr->pLeft = root;
    return tempPtr;
}
Node* rotateRight(Node* root){
    Node* tempPtr = root->pLeft;
    root->pLeft = tempPtr->pRight;
    tempPtr->pRight = root;
    return tempPtr;   
}




void insertRec(Node* & node, const T &value){
    if (node == nullptr){
        node  = new Node(value);
        return;
    }
    else if (value < node ->data) insertRec(node->pLeft , value);
    else if (value > node ->data) insertRec(node->pRight,value);

    BalanceValue balance = getBalance(node);
    if (balance == BalanceValue::LH && value < node ->pLeft->data)  node = rotateRight(node);
    else if (balance == BalanceValue::RH && value > node ->pRight->data)  node = rotateLeft(node);
    else if (balance == BalanceValue::LH && value > node ->pLeft->data){
        node ->pLeft = rotateLeft(node->pLeft);
        node = rotateRight(node);
    }
    else if (balance == BalanceValue::RH && value < node ->pRight->data){
        node ->pRight = rotateRight(node->pRight);
        node = rotateLeft(node);
    } 
}
void insert(const T &value){
    //TODO
    insertRec(this->root,value);

}










void removeRec(Node *&node , const T &value){
    if (node == nullptr) return;
    else if (node ->data > value) removeRec(node->pLeft , value);
    else if (node ->data < value) removeRec(node->pRight,value);
    else {
            if (!node->pLeft && !node->pRight) {
                delete node;
                node = nullptr;
            }
            else if (!node->pLeft){
                Node * temp = node;
                node = node->pRight;
                delete temp;
            }
            else if (!node->pRight){
                Node * temp = node;
                node = node->pLeft;
                delete temp;
            }
            else {
                Node *findMax = node->pLeft;
                while(findMax ->pRight) findMax = findMax->pRight;
                swap(node->value , findMax->value);
                deleteRec(node->pLeft,findMax->value);
            }
        }
    BalanceValue balance = getBalance(node);
    
}


void remove(const T &value){
    //TODO   
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