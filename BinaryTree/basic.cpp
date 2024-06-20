#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(const int& data) { this->data = data; }
};
class BinaryTree {
private:
        Node* root;
    
protected:
        int getSizeRec(Node *);
        int countTwoChildrenNodesRec(Node *);
        int getHeightRec(Node *);
        Node* maxNodeRec(Node*&);
        bool addRec(Node *&, const int &); //tìm kiếm và thêm node vào tree
        bool removeRec(Node *&, const int &);
        Node* findMin(Node*);
public:
	BinaryTree(){this->root = NULL;}
    int getSize();
    int countTwoChildrenNodes();
    int getHeight();
    Node* maxNode();
    void BFS();
    bool add(const int &value);
    bool remove(const int &value);
};


int BinaryTree::getSizeRec(Node *node){
    if (node == NULL) return 0;
    int left = getSizeRec(node ->left);
    int right = getSizeRec(node ->right);
    return left + right + 1;
}
int BinaryTree::getSize(){return getSizeRec(root);}


int BinaryTree::countTwoChildrenNodesRec(Node *node){
    if (node == nullptr) return 0;
    int left = countTwoChildrenNodesRec(node->left);
    int right = countTwoChildrenNodesRec(node->right);
    if (node->left && node->right) return 1 + left + right;
    return left + right;
}
int BinaryTree::countTwoChildrenNodes(){return countTwoChildrenNodesRec(root);}


int BinaryTree::getHeightRec(Node *node){
    if (!node) return 0;
    int left = getHeightRec(node ->left);
    int right = getHeightRec(node ->right);
    return 1 + max (left,right);
}
int BinaryTree::getHeight(){ return getHeightRec(root);}

Node* BinaryTree::maxNodeRec(Node *&node)
{
   if (node == nullptr || !node->left || !node->right) return nullptr;
   Node *leftMax = maxNodeRec(node->left);
   Node *rightMax = maxNodeRec(node->right);
   
   // So sánh giá trị của nút hiện tại với giá trị lớn nhất của hai cây con
   if (node->data >= leftMax->data && node->data >= rightMax->data) {
       return node;
   }
   if (leftMax->data >= rightMax->data) {
       return leftMax;
   }
   return rightMax;
}
Node* BinaryTree::maxNode()
{
    return maxNodeRec(root);
}

void BinaryTree::BFS()
{
	 if (root == nullptr)  return;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " "; // In giá trị của node hiện tại

            if (current->left != nullptr) q.push(current->left);
            
            if (current->right != nullptr) q.push(current->right);
            
        }
        cout << std::endl;
}

bool BinaryTree::addRec(Node *&node, const int &value)
{
	if (node == nullptr) {
        // Nếu nút hiện tại là null, chúng ta thêm giá trị vào đây.
        node = new Node(value);
        return true;
    }

    if (value == node->data) {
        // Giá trị đã tồn tại trong cây.
        return false;
    }
    
    if (value < node->data) {
        // Nếu giá trị cần thêm nhỏ hơn giá trị hiện tại của nút, đệ quy vào cây con trái.
        return addRec(node->left, value);
    } else {
        // Nếu giá trị cần thêm lớn hơn giá trị hiện tại của nút, đệ quy vào cây con phải.
        return addRec(node->right, value);
    }
}
bool BinaryTree::add(const int &value){return addRec(root,value);}

bool BinaryTree::removeRec(Node *&node, const int &value) {
    if (node == nullptr) return false;

    if (value < node->data) return removeRec(node->left, value);
    else if (value > node->data) return removeRec(node->right, value);
    else {
        // Giá trị đã được tìm thấy, chúng ta xử lý các trường hợp xóa.

        if (node->left == nullptr && node->right == nullptr) {
            // Trường hợp 1: Nút hiện tại là nút lá, đơn giản xóa nó đi.
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            // Trường hợp 2: Nút hiện tại có một cây con (cây con phải).
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            // Trường hợp 2: Nút hiện tại có một cây con (cây con trái).
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            // tìm node lớn nhất cây con bên trái (
            // Trường hợp 3: Nút hiện tại có cả hai cây con.
            // Tìm giá trị nhỏ nhất trong cây con phải (cây con con lớn nhất).
            Node* minRight = findMin(node->right);
            // Sao chép giá trị của nút có giá trị nhỏ nhất vào nút hiện tại.
            node->data = minRight->data;
            // Gọi đệ quy để xóa nút có giá trị nhỏ nhất từ cây con phải.
            removeRec(node->right, minRight->data);
        }

        return true;
    }
}
Node* BinaryTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
