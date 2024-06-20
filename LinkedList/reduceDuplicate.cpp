#include<iostream>

using namespace std;

class Node
{
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr){}

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
  

};
  void printList(Node* root) {
    Node* current = root;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

void reduceDuplicate(Node* root)
{
//! nếu rỗng hay chỉ có 1 phần tử thì không xét nữa
    if(root && root->getNext() == NULL) return;
//! Khởi tạo hai con trỏ, curr trỏ tới node hiện tại, prev trỏ tới node trước đó.
    Node* curr = root->getNext(),* prev = root;
    while(curr){
//! Nếu giá trị của node hiện tại trùng với giá trị của node trước đó.
        if(curr->getData() == prev->getData()){
 //! Bỏ qua node hiện tại bằng cách cập nhật con trỏ next của node trước đó.
            prev->setNext(curr->getNext());
            curr = prev->getNext();
        }
        else{
//! Cập nhật con trỏ prev để trỏ tới node hiện tại.
            prev->setNext(curr);
//! Cập nhật con trỏ curr để trỏ tới node tiếp theo.
            curr = curr->getNext();
        }
    }
}

int main(){
    Node* node0 = new Node(1, nullptr);
    Node* node1 = new Node(1,  node0 );
    Node* node2 = new Node(1, node1);
    Node* node3 = new Node(0, node2);
    printList(node3);
    reduceDuplicate(node3);
    printList(node3);
    /*0 1 1 
    0 1*/
}