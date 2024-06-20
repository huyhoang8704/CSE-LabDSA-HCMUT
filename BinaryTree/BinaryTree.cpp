#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {  
       deleteNode(root);
    }
    void deleteNode(Node * root){
        if(!root) return;
        deleteNode(root->pLeft);
        deleteNode(root->pRight);
        delete root;
    }
public:
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

    //* Đếm số lượng nút có hai con
int countTwoChildrenNodeREC(Node* root){
    if(root == nullptr) return 0; 
    else if(root->pLeft != nullptr && root->pRight != nullptr) return 1+ countTwoChildrenNodeREC(root->pLeft) + countTwoChildrenNodeREC(root->pRight);
    return  countTwoChildrenNodeREC(root->pLeft) + countTwoChildrenNodeREC(root->pLeft);
} 
int countTwoChildrenNode(){
    return countTwoChildrenNodeREC(root);
}

    //* Infix
void inorderTraversal(Node *node){
    if (node)
    {
        inorderTraversal(node->pLeft);
        cout << "(" << node->key << ", " << node->value << ") ";
        inorderTraversal(node->pRight);
    }
}
void inorderTraversal(){
    inorderTraversal(root);
    cout << endl;
}

    //* chiều cao của cây
int getHeightRec(Node* root) {
    if(root == NULL) return 0;
    return 1 + max( getHeightRec(root->pLeft), getHeightRec(root->pRight));
}
int getHeight() {return  getHeightRec(root);}

    //* Prefix
void preOrderRec(Node* root, string & result) {
    if(root == NULL) return;
    result += to_string(root->value) + " ";
    preOrderRec(root->pLeft,result);
    preOrderRec(root->pRight,result);
}
string preOrder() {
    string result;
    preOrderRec(root,result);
    return result;
}
void inOrderRec(Node* root, string & result) {
    if(root == NULL) return;
    inOrderRec(root->pLeft,result);
    result += to_string(root->value) + " ";
    inOrderRec(root->pRight,result);
}
string inOrder() {
    string result;
    inOrderRec(root,result);
    return result;
}

void postOrderRec(Node* root, string & result) {
    if(root == NULL) return;
     postOrderRec(root->pLeft,result);
     postOrderRec(root->pRight,result);
      result += to_string(root->value) + " ";
}
string  postOrder() {.
    string result;
    postOrderRec(root,result);
    return result;
}

    //* tổng các node lá của cây
int sumOfLeafsRec(Node* root){
    if(root == NULL) return 0;
    else if(root->pLeft == NULL && root->pRight == NULL) return root->value;
    return sumOfLeafsRec(root->pLeft) + sumOfLeafsRec(root->pRight);
}

int sumOfLeafs(){return sumOfLeafsRec(root);}

void BFS()
{
	if (root == nullptr)  return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->value<< " "; // In giá trị của node hiện tại
        if (current->pLeft!= nullptr) q.push(current->pLeft); 
        if (current->pRight != nullptr) q.push(current->pRight);       
    }
    cout << std::endl;
}
};

int main()
{
    BinaryTree<int, int>tree;
    tree.addNode("",2, 4); //! Add to root
    tree.addNode("L",3, 6); //! Add to root's left node
    tree.addNode("R",5, 9); //! Add to root's right node
    
   
     
    cout << "In-order traversal of the tree:" << endl;
    tree.inorderTraversal();

    int count = tree.countTwoChildrenNode();
    cout << "Number of nodes with two children: " << count << endl;
    cout<<tree.postOrder();
    return 0;
}

