#include <iostream>

using namespace std;


//* trạng thái cân bằng của 1 cây
enum class BalanceState {
    LEFT_HEAVY, 
    BALANCED,
    RIGHT_HEAVY
};

template <typename E>
class AVLNode {
public:
    E data;
    AVLNode* left;
    AVLNode* right;
    int height;
    //* chiều cao của 1 node là bằng 1
    AVLNode(const E& v) : data(v), left(nullptr), right(nullptr), height(1) {}
};

template <typename E>
class AVLTree {
private:
    AVLNode<E>* root;
    int getHeight(AVLNode<E> *node){
        if(!node) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return 1 + max(left,right);
    }
    BalanceState getBalanceState(AVLNode<E>* node) {
        //* rỗng thì hight cây con bên trái = hight cây con bên phải -> nên cân bằng
        if (node == nullptr) return BalanceState::BALANCED;

        //* lấy chiều cao cây con bên trái và bên phải
        int leftHeight = getHeight(node ->left);
        int rightHeight = getHeight(node ->right);

        //* xem thử lệch bên nào rồi
        int balance = leftHeight - rightHeight;

        //* lệch bên trái rồi chiều cao bên trái cao hơn -> (lệch ở đây nghĩ là bên trái cao hơn thôi còn cao hơn nhiêu thì không cần biết)
        if (balance > 1) return BalanceState::LEFT_HEAVY;
        else if (balance < -1) return BalanceState::RIGHT_HEAVY;
        //* cân bằng Là 2 chiều cao không lệch nhau quá 1 đơn vị
        return BalanceState::BALANCED;
    }
    //* Xoay phải
    AVLNode<E>* rightRotate(AVLNode<E>* Node_A) {
        //* vẽ ra mới thấy nha các bạn ngồi nghĩ chắc tới mai
        //* ví dụ cây này đi A (B (D, E), C)  xem mấy này là node nha thật ra là cây con ví dụ cây con chỉ có 1 node cho dễ
        /*
        *            A                                          B
        *           / \                                        / \
        *          B   C        <--right router-->            D   A
        *         / \                                            / \  
        *        D   E                                          E   C
        */
       // A là Node mất cân bằng
        AVLNode<E>* Node_B = Node_A->left; //! này là B
        AVLNode<E>* Node_E = Node_B->right; //! này là E

        Node_A->left = Node_E; //! CẬP NHẬT NODE E
        Node_B->right = Node_A; //! CẬP NHẬT NODE A
        
        //* chỉ có cây con A và cây con B mới thay đổi chiều cao
        Node_A->height = 1 + max((Node_A->left == nullptr) ? 0 : Node_A->left->height, (Node_A->right == nullptr) ? 0 : Node_A->right->height);
        Node_B->height = 1 + max((Node_B->left == nullptr) ? 0 : Node_B->left->height, (Node_B->right == nullptr) ? 0 : Node_B->right->height);

        return Node_B; //! NODE B đang là root
    }

    AVLNode<E>* leftRotate(AVLNode<E>* Node_A) {
        //* vẽ ra mới thấy nha các bạn ngồi nghĩ chắc tới mai
        //* ví dụ cây này đi A (B (D, E), C)  xem mấy này là node nha thật ra là cây con ví dụ cây con chỉ có 1 node cho dễ
        /*
        *            A                                          C
        *           / \                                        / \
        *          B   C        <-- left router-->            A   E
        *             / \                                    / \  
        *            D   E                                  B   D
        */

        AVLNode<E>* Node_C = Node_A->right; //! này là C
        AVLNode<E>* Node_D = Node_C->left; //! này là D

        Node_A->right = Node_D; //! CẬP NHẬT NODE D
        Node_C->left = Node_A; //! CẬP NHẬT NODE A
        
        //* chỉ có cây con A và cây con C mới thay đổi chiều cao
        Node_A->height = 1 + std::max((Node_A->left == nullptr) ? 0 : Node_A->left->height, (Node_A->right == nullptr) ? 0 : Node_A->right->height);
        Node_C->height = 1 + std::max((Node_C->left == nullptr) ? 0 : Node_C->left->height, (Node_C->right == nullptr) ? 0 : Node_C->right->height);

        return Node_C; //! NODE C đang là root
    }

    AVLNode<E>* insertNode(AVLNode<E>* node, const E& data) {
        
        if (node == nullptr) return new AVLNode<E>(data);

    //* bước 1: gọi đệ quy để thêm nó đó vào này giống với insert cây BST
        if (data < node->data) node->left = insertNode(node->left, data);
        else if (data > node->data) node->right = insertNode(node->right, data);
        //* này là trường hợp trùng nhau
        else return node;
    
        //* cập nhật chiều cao của cây xem thử cây con bên trái hay cây con bên phải lớn hơn thì chọn cây cao nhất cộng thêm 1 là chính nó
        node->height = 1 + std::max((node->left == nullptr) ? 0 : node->left->height, (node->right == nullptr) ? 0 : node->right->height);

    //* bước 2: cân bằng lại cây khi insert
        //* bước 2.1: xem thử cây lệch bên trái hay bên phải
        BalanceState balanceState = getBalanceState(node);

        //* LEFT OF LEFT ->  left - right = 2, với thêm bên trái của cây con bên trái
        if (balanceState == BalanceState::LEFT_HEAVY && data < node->left->data) {
            //* ví dụ dễ hiểu nhất là A (B (C))  -> link list bên trái
            return rightRotate(node);
        }

        //* RIGHT OF RIGHT ->  left - right = -2, với thêm bên phải của cây con bên phải
        if (balanceState == BalanceState::RIGHT_HEAVY && data > node->right->data) {
            //* ví dụ dễ hiểu nhất là A (null, B (null , C))  -> link list bên phải
            return leftRotate(node);
        }


        //* LEFT OF RIGHT -> nghĩa là cây con bên trái đang cao hơn cây con bên phải 2 đơn vị:  left - right = 2, với thêm bên phải của cây con bên trái
        if (balanceState == BalanceState::LEFT_HEAVY && data > node->left->data) {
            //* xoay phải cây con bên trái trước
            //* ví dụ dễ hiểu nhất là A (B (null, C)) sau xoay A (C (B)) -> đã trở thành LEFT OF LEFT
            node->left = leftRotate(node->left); // tìm đến cây con bên trái xoay trái
            // tiếp theo xoay phải node gốc
            //* cây đã thành LEFT OF LEFT -> giống trên
            return rightRotate(node);
        }

        //* RIGHT OF LEFT -> nghĩa là cây con bên trái đang thấp hơn cây con bên phải 2 đơn vị:  left - right = -2, với thêm bên trái của cây con bên phải
        if (balanceState == BalanceState::RIGHT_HEAVY && data < node->right->data) {
            //* xoay trái cây con bên phải trước
            //* ví dụ dễ hiểu nhất là A (Null, B (C)) sau xoay A (Null,B (Null,C)) -> đã trở thành RIGHT OF RIGHT
            node->right = rightRotate(node->right);

             //* cây đã thành RIGHT OF RIGHT -> giống trên
            return leftRotate(node);
        }

        //* không bị mất cân bằng thì thôi
        return node;
    }

    //* Tìm giá trị nhỏ nhất trong cây
    AVLNode<E>* minENode(AVLNode<E>* node) {
        AVLNode<E>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    AVLNode<E>* deleteNode(AVLNode<E>* root, const E& data) {

        if (root == nullptr) return root;
    //* bước 1: gọi đệ quy để  xóa nó đó vào này giống với delete cây BST    
        if (data < root->data) root->left = deleteNode(root->left, data);
        else if (data > root->data) root->right = deleteNode(root->right, data);
        else {
            //* trường hợp 1 cây bị khuyết hoặc cả 2
            if (root->left == nullptr || root->right == nullptr) {
                //* tìm cây không bị khuyết
                AVLNode<E>* temp = root->left ? root->left : root->right;
                //* trường hợp xóa lá
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } 
                //* trường hợp không phải là lá
                else *root = *temp;

                delete temp;
            } else {
                //* cơ chế thì tìm cây con nhỏ nhất bên phải để xóa (này tùy vào đệ mà chọn có thể cây lớn nhất bên trái)
                AVLNode<E>* temp = minENode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        //* trường hợp xóa lá
        if (root == nullptr) return root;
        //* chiều cao mới
        root->height = 1 + std::max((root->left == nullptr) ? 0 : root->left->height, (root->right == nullptr) ? 0 : root->right->height);


    //* Bước 2: cân bằng lại khi xóa
        BalanceState balanceState = getBalanceState(root);
        //* này giống insert thôi thay vì bên trên xét data tìm bị mất cân bằng OF <LEFT OF RIGHT> thì ta dùng  getBalanceState(root-><LEFT OF RIGHT>)

        //* LEFT OF LEFT
        if (balanceState == BalanceState::LEFT_HEAVY && getBalanceState(root->left) == BalanceState::BALANCED) {
            return rightRotate(root);
        } 

        //* LEFT OF RIGHT
        if (balanceState == BalanceState::LEFT_HEAVY && getBalanceState(root->left) == BalanceState::RIGHT_HEAVY) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //* RIGHT OF RIGHT
        if (balanceState == BalanceState::RIGHT_HEAVY && getBalanceState(root->right) == BalanceState::BALANCED) {
            return leftRotate(root);
        }

        //* RIGHT OF LEFT
        if (balanceState == BalanceState::RIGHT_HEAVY && getBalanceState(root->right) == BalanceState::LEFT_HEAVY) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inoder(AVLNode<E>* root) // trái gốc phải
    {
        if(root == nullptr) return;

        inoder(root->left);
        cout << root->data << " ";
        inoder(root->right);
    }
void preorder(AVLNode<E>* root) {
    if (root == nullptr) return;

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

public:
    AVLTree() : root(nullptr) {}

    void insert(const E& data) {root = insertNode(root, data);}

    void remove(const E& data){ root = deleteNode(root, data);}

    void print(){
        cout << "INODRE Tree AVL : ";
        inoder(root);
        cout << endl;
    }

};

int main() {
    AVLTree<int> avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(60);
    avlTree.insert(50);
    avlTree.insert(25);
    avlTree.print(); // 10 20 25 30 40 50 60 
    // avlTree.remove(10);
    // avlTree.remove(50);
    // avlTree.remove(40);
    // avlTree.print();
    // avlTree.remove(20);
    // avlTree.remove(30);
    // avlTree.remove(60);
    // avlTree.print();
    // Perform operations on the AVL tree

    return 0;
}