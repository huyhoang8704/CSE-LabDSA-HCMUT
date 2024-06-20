#include "Binary_Search_Trees.h"

//! INSERT NODE
template <typename E> 
BSTNode<E>* insertBTSNode(BSTNode<E>* root,const E& TKey )
{
    if (root == nullptr) return new BSTNode<E>(TKey);

    if (root->Key < TKey) root->right = insertBTSNode(root->right, TKey);

    else                  root->left = insertBTSNode(root->left, TKey);
    return root;
}


//! DELETE NODE
template <typename E> 
BSTNode<E>* deleteBTSNode(BSTNode<E>* root,const E& TKey)
{
    if (root == nullptr) return nullptr;

    //* bước 2.1: xét trường hợp xóa vào cây con bên phải  
    if (root->Key < TKey)
    {
        root->right = deleteBTSNode(root->right, TKey);
    }
    //* bước 2.2: xét trường hợp thêm vào cây con bên Trái  
    else if (root->Key > TKey)
    {
        root->left = deleteBTSNode(root->left, TKey);
    }
    //* bước 2.3: tìm thấy node cần xóa ta sẽ tìm con lớn nhất bên trái để thay thế nếu có
    else if (root->Key == TKey)
    {
        BSTNode<E>* nodeDelete = root;
        //* bước 2.3.1: nếu node cần xóa là node lá (node lá node không có con)
        if (root->left == nullptr && root->right == nullptr) root = nullptr;
        
        //* bước 2.3.2: nếu không có con con bên trái lấy con bên phải thay thế
        else if (root->left == nullptr)
        {
            root = root->right;
        }
        //* bước 2.3.2: trường hợp còn lại ta phải tìm node lớn nhất của cây con bên trái
        //* node lớn nhất cây con bên trái -> node này chắc chắn là lá bên phải cùng
        //* khi tìm được thì swap và bắt đầu gọi đệ quy
        //* có thể thay thế bằng nhỏ nhất cây con bên phải mà ít khi dùng TH này
        else
        {
            //* tìm node lớn nhất cây con bên trái trong cây con nhị phân
            BSTNode<E>* temp = root->left;
            while(temp->right != nullptr) temp = temp->right;
            //* ta đổi node đó với node cần xóa rồi gọi đệ quy tiếp xóa node cần xóa
            swap(root->Key, temp->Key);
            root->left = deleteBTSNode(root->left, TKey);
            return root;
        }
        delete nodeDelete;
    }
    return root;

}


//! FIND NODE
//^ độ phức tạp O(log(N))
/* MÔ TẢ
*/
template <typename E> 
bool findBTSNode(BSTNode<E>* root,const E& TKey)
{
    //* bước 1: xét trường hợp Cây đang rỗng
    if (root == nullptr) return false;

    //* bước 2.1: xét trường hợp tìm vào cây con bên phải  
    if (root->Key < TKey)
    {
        return findBTSNode(root->right, TKey);
    }
    //* bước 2.2: xét trường hợp tìm vào cây con bên Trái  
    else if (root->Key > TKey)
    {
        return findBTSNode(root->left, TKey);
    }

    //* bước 2.3: tìm thấy rồi
    return true;
}



//! PREODER - TIỀN THỨ TỰ
//^ độ phức tạp O(N)
/* MÔ TẢ
& theo cơ chế là duyệt node cha -> node con trái -> node con phải (ROOT - LEFT - RIGHT)
*/
template <typename E> 
void preoderBTS(BSTNode<E>* root)
{
    //* bước 1: xét trường hợp Cây đang rỗng
    if (root == nullptr) return;

    cout << root->Key << " "; //* vì cơ chế root được in đầy tiên

    //* bước 2: tìm cây con bên trái
    preoderBTS(root->left);
    //* bước 3: tìm cây con bên phải
    preoderBTS(root->right);

}


//! INODER - TRUNG THỨ TỰ 
//^ độ phức tạp O(N)
/* MÔ TẢ
& theo cơ chế là duyệt node con trái -> node cha  -> node con phải (LEFT - ROOT - RIGHT)
& này sẽ in ra theo thứ tự từ nhỏ -> lớn
*/
template <typename E> 
void inoderBTS(BSTNode<E>* root)
{
    //* bước 1: xét trường hợp Cây đang rỗng
    if (root == nullptr) return;
    //* bước 2: tìm cây con bên trái
    inoderBTS(root->left);
    
    cout << root->Key << " "; //* vì cơ chế root in sau khi cây con bên trái in trước

    //* bước 3: tìm cây con bên phải
    inoderBTS(root->right);
}


//! POSTODER - HẬU THỨ TỰ
//^ độ phức tạp O(log(N))
/* MÔ TẢ
& theo cơ chế là duyệt node con trái -> node con phải -> node cha (LEFT - RIGHT - ROOT)
*/
template <typename E> 
void postoderBTS(BSTNode<E>* root)
{
    //* bước 1: xét trường hợp Cây đang rỗng
    if (root == nullptr) return;

    //* bước 2: tìm cây con bên trái
    postoderBTS(root->left);

    //* bước 3: tìm cây con bên phải
    postoderBTS(root->right);

    cout << root->Key << " "; //* vì cơ chế root in cuối cùng
}


//! HEIGHT TREE
//^ độ phức tạp O(N)
/* MÔ TẢ
*/
template <typename E> 
int heightBTS(BSTNode<E>* root)
{
    //* bước 1: xét trường hợp Cây đang rỗng
    if (root == NULL) return 0;
    //* bước 1: tìm cây nào có chiều cao lớn hơn
    return 1 + max(heightBTS(root->left), heightBTS(root->right)); 
}


//! BFS - DUYỆT CHIỀU RỘNG 
//^ độ phức tạp O(N)
/* MÔ TẢ
*/
template <typename E> 
void bfsBTS(BSTNode<E>* root)
{
    if (root == nullptr) return;
    //* bước 1: đưa node root vào hàng đợi
    queue<BSTNode<E>*> qBTS;
    qBTS.push(root);
    cout << root->Key << " ";

    //* bước 2: duyệt hàng đợi tới khi dừng
    while(!qBTS.empty())
    {
        //* bước 2.1 lấy node đầu tiên trong hàng đợi
        BSTNode<E>* temp = qBTS.front();
        qBTS.pop();
        
        //* bước 2.2 nếu cây con bên trái không rỗng thì đưa vào hàng đợi
        if(temp->left)
        {
            cout << temp->left->Key << " ";
            qBTS.push(temp->left);
        }

        //* bước 2.3 nếu cây con bên phải không rỗng thì đưa vào hàng đợi
        if(temp->right)
        {
            cout << temp->right->Key << " ";
            qBTS.push(temp->right);            
        }
    }

    
}


//! CHECK BTS - kiếm tra có phải cây nhị phân hay không
//^ độ phức tạp O(N)
/* MÔ TẢ
*/
template <typename E> 
bool isBST(BSTNode<E>* root,E minValue,E maxValue) {
    //* bước 1 Cây rỗng được xem là BST.
    if (root == nullptr) return true; 
    //* bước 2 Giá trị nút không nằm trong khoảng hợp lệ.
    else if (root->Key < minValue || root->Key > maxValue) return false; 

    //*  bước 3 Kiểm tra các cây con trái và phải, cập nhật giá trị min và max.
    return isBST(root->left, minValue, root->Key - 1) && isBST(root->right, root->Key + 1, maxValue);
}
