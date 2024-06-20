#include <bits/stdc++.h>
using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree(){}

    void addRec(Node *&node , T value){
        if (node == nullptr){
            node = new Node(value);
            return;
        }
        else if (node ->value < value) addRec(node->pRight , value);
        else if (node ->value > value) addRec(node->pLeft , value);
    }
    void add(T value){
        if (root == nullptr){
            root = new Node(value);
        }
        else addRec(root,value);
    }
    void deleteRec(Node *&node,T value){
        if (!node) return;
        else if (node->value > value) deleteRec(node->pLeft , value);
        else if (node->value < value)  deleteRec(node->pRight , value);
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
        
    }
    void deleteNode(T value){
        //TODO
        deleteRec(root, value);
    }
bool find(T i) {
    Node* tmp = root;
    while(tmp){
        if(tmp->value > i) tmp = tmp->pLeft;
        else if(tmp->value < i) tmp = tmp->pRight;
        else return true;
    }
    return false;
    
}

T rangeCount(Node* root, T lo, T hi) {
    if(root == NULL) return 0;
    else if(root->value >= lo && root->value <= hi)
        return root->value + rangeCount(root->pLeft,lo,hi) + rangeCount(root->pRight,lo,hi);
    return rangeCount(root->pLeft,lo,hi) + rangeCount(root->pRight,lo,hi);
}
T sum(T l, T r) {
    return rangeCount(root,l,r);
}
T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    Node *temp = root;
    while (temp->pLeft) temp = temp->pLeft;
    return temp->value;
    
}

T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    Node *temp = root;
    while(temp->pRight) temp = temp->pRight;
    return temp->value;
}


    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};