#include "main.h"
#include <iostream>

using namespace std;

//* tùy vào tham số truyền vào mà ta có thể có nhiều contructor
//* Thông thường thì chỉ cần rỗng và tham số truyền vào chính nó
Singly_Linked_List::Singly_Linked_List():head(nullptr), tail(nullptr), size(0){

};


Singly_Linked_List::Singly_Linked_List(const Singly_Linked_List& others):head(nullptr), tail(nullptr), size(0){
    Node* temp = others.head;
    for(int i = 0; i < others.size; i++)
    {
        this->Insertion(temp->data, i); //! chèn tại cuối
        temp = temp->next;  //! dịch ptr temp
    }
}

int Singly_Linked_List::Count(){
    return size;
}

bool Singly_Linked_List::Empty(){
    return size == 0;
}

//* xóa tất cả các phần tử Node đang còn trong Singly_Linked_List
//* hàm này tương đương với clear nhưng chỉ gọi ghi kết thúc phạm vi
//* có thể dùng hàm remove để xử lý
//^ độ phức tạp O(n)
Singly_Linked_List::~Singly_Linked_List(){
    Node* temp; //~ node mẫu

    while(size != 0){
       
        temp = head;
        head = head->next;
        delete temp;
        size --;
    }
    
    head = tail = nullptr;
    size = 0;
}

//! insert có 5 TH: index ngoài phạm vi, danh sách rỗng, chèn đầu, chèn cuối, chèn mid
void Singly_Linked_List::Insertion(int data,int index){
    if(index <0 || index > size) throw out_of_range("Index out of range");
    
    Node *p = new Node(data , nullptr);
    // danh sách rỗng
    if(size ==0) head = tail = p;
    // chèn đầu
    else if( index == 0){
        p->next = head;
        head = p;
    }
    // chèn cuối
    else if( index == this->size){
        tail ->next = p;
        tail = p;
    }
    // chèn mid
    else{
        Node * temp = head;
        for(int i=0;i<=index - 2 ;i++) temp = temp->next; // tới vị trí thứ index-1
        p->next = temp->next ;
        temp->next = p;
    }
    this->size ++;
}


//! Deletion có 5 TH: index ngoài phạm vi, danh sách 1 phần tử, chèn đầu, chèn cuối, chèn mid
void Singly_Linked_List::Deletion(int index){

    // trường hợp index nằm ngoại phạm vi
    if(index < 0 || index >= this->size) out_of_range("Index of Linked List is invalid!");

    Node* deleteNode; // lưu node cần xóa

    // Singly_Linked_List đang có 1 phần tử
    if(this->size == 1){
        deleteNode = head;
        head = tail = nullptr;
    }

    // Delete ở đầu danh sách (head)
    else if(index == 0){
        deleteNode = head;
        head = head->next;
    }

    // Delete ở cuối danh sách (tail) or Delete ở giữa danh sách (mid) - các trường hợp còn lại
    else{
        Node* temp = head;
        // tìm kiếm node thứ index - 1 (node trước newNode cần insert)
        for(int i = 0 ; i <= index-2; i++) temp = temp->next;
        // deleteNode node cần xóa index
        deleteNode = temp->next;
        // node index - 1 trỏ đến index + 1;
        temp->next = deleteNode->next;
        // trường hợp node cuối cùng xóa đi tail -> cập nhật tail lên node trước node Index - 1
        if(index == this->size - 1) tail = temp;
    }
    delete deleteNode;
    this->size --;

}

// du!yệt tuyến tính(liner) đến phần tử cần lấy data
int Singly_Linked_List::Get(int index){
    if(index < 0 || index >= this->size) out_of_range("Index of Linked List is invalid!");

    Node* temp = head;
    // Get node thứ index (node cần tìm)
    for(int i = 0 ; i < index; i++) temp = temp->next;     
    return temp->data;   
}

//! duyệt tuyến tính(liner) hết phần tử khi nào gặp phần tử data giống thôi
int Singly_Linked_List::IndexOf(int data){
    Node* temp = head;
    // IndexOf node đầu tiên có data = với data truyền vào
    for(int i = 0 ; i < this->size; i++){
        if(temp->data == data){
            return i;
        }
        temp = temp->next;   
    }  
    return -1;   
}

//! duyệt tuyến tính(liner) hết phần tử khi nào gặp phần tử data giống thôi
bool Singly_Linked_List::Contains ( int data ){
    Node* temp = head;
    // Contains tìm kiếm thử data có nằm trong link list hay không
    for(int i = 0 ; i < this->size; i++){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;   
    }  
    // không tìm thấy vị trí
    return false;   
}

//* hàm này có 2 cách là swap data và swap Node
//* phần này dùng swap data còn swap node tự làm nha khá là khoai
//^ độ phức tạp O(n^2)
void Singly_Linked_List::SelecetionSort(){
    Node* node_I = head;
    while(node_I != nullptr){
        Node* node_J = node_I->next;
        while(node_J != nullptr){
            if(node_I->data > node_J->data) swap(node_I->data, node_J->data);
            node_J = node_J->next;
        }
        node_I = node_I->next;
    }
}

//* hàm này sẽ tạo ra 2 Singly_Linked_List mới từ this và other và hợp chúng lại
Singly_Linked_List Singly_Linked_List::Concat(const Singly_Linked_List& others){
    Singly_Linked_List h1(*this);
    Singly_Linked_List h2(others);

    // nếu size this khác không
    if(h1.size != 0) h1.tail->next = h2.head;
    else h1 = h2;
    h1.size += h2.size; //~ cập nhật size
    return h1;
}

//* Deletion có 3 TH: lỗi range, lỗi logic, cắt
//^ độ phức tạp O(n)
//! hàm lấy ra Linked list con 
Singly_Linked_List Singly_Linked_List::SubSingly_Linked_List(int from, int to){
    if(from < 0 || from >= size || to <= 0 || to > size) out_of_range("Index of Link List is invalid!");
    // lỗi logic
    else if(from >= to) logic_error("Invalid range");

    Singly_Linked_List result;
    Node* temp = head;
    //! tìm đến vị trí cần cắt
    for(int i = 0 ; i < from; i++){
        temp = temp->next;
    }

    for(int i = from; i < to; i++){
        result.Insertion(temp->data, i - from); // insert tail
        temp = temp->next;
    }
    return Singly_Linked_List(result);
}


//! Reverse list
void Singly_Linked_List::Reverse(){
    if(this->size <= 1) return;
    // curr là con trỏ hiện tại, pre là con trỏ phía trước
    Node* curr = this->head;
    Node* pre = this->head->next;  // Node thứ 2
    // Duyệt toàn bộ ds liên kết
    for(int i = 0; i <= this->size - 2; i++){

        Node* temp = pre->next; // lưu con trỏ tới node sau node pre
        // trỏ node i + 1 tới node i
        pre->next = curr;
        // gán curr thành node i + 1 và pre thành node i + 2 (tăng lên)
        curr = pre;
        pre = temp;
    }
    
    // cập nhật lại node đầu thành node cuối
    this->head->next = nullptr;
    this->tail = this->head;
    // cập nhật node cuối thành node đầu
    this->head = curr; //! node cuối đang là curr
}



//^ độ phức tạp O(n)
string Singly_Linked_List::Dislay(){
    string result = "[Size=" + to_string(size)
                    + ",DataHead=" + (head ? to_string(head->data) : "nullptr")
                    + ",DataTail=" + (tail ? to_string(tail->data) : "nullptr")
                    + ",DataNode: ";
    if(this->size == 0) return result + "nullptr]";
    Node* temp = head;
    for(int i = 0 ; i < this->size; i++){
        result += to_string(temp->data) + "->";
        temp = temp->next;  
        if(i == this->size - 1) result += "nullptr]"; 
    }  
    return result;
}