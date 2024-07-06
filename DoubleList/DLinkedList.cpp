#include<iostream>

using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList():head(nullptr),tail(nullptr),count(0){};
    ~DLinkedList(){};
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    string  toString();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template<class T>
string DLinkedList<T>::toString() {
    string s = "[";
    Node* current = head;
    
    while (current) {
        s+= to_string(current->data);
       
        if (current->next) {
            s+= ",";
        }
        current = current->next;
    }
   s+= "]";
    return s;
}


template <class T>
void DLinkedList<T>::add(const T& e) {
    Node * p = new Node(e);
    if(count == 0) head = tail = p;
    else {
        tail -> next = p;
        p->previous = tail;
        tail = p;
    }
    count ++; 
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
//! kiểm tra đầu vào có hợp lệ hay không nếu không hợp lệ thì dừng chương trình
    if(index < 0 && index > count) throw out_of_range("");
//! nếu chưa có phần tử nào và thêm vào đầu danh sách 
    else if(count == 0 || index == count ) add(e);
    else if(index == 0){
//! xử lý con trỏ
        Node* tmp = new Node(e);
        tmp->next = head;
        head->previous = tmp;
        head = tmp;
        count  ++;
    }
    else{
//! tạo 2 node curr và prev lưu node ở vị trí chèn và node trước vị trí chèn
        Node* curr = head->next,* prev = head;
        index --;  
        while(index){
            index--;
            prev = curr;
            curr= curr->next;
        }
//! thực hiện chèn node

        Node* tmp = new Node(e);
        prev->next = tmp;
        tmp->previous = prev;
        tmp->next = curr;
        curr->previous = tmp;
        count ++;
    }
    
}

template<class T>
int DLinkedList<T>::size() {
    return count;
}


template<class T>
T DLinkedList<T>::get(int index) {
//! kiểm tra đầu vào có hợp lệ hay không
    if(index < 0 && index >= count) throw out_of_range("");
    Node * temp = head;
    for(int i=0;i<= index-1;i++) temp = temp->next;
    
    return temp-> data;
    
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
//! kiểm tra đầu vào có hợp lệ hay không
    if(index < 0 && index >= count) throw out_of_range("");
    Node * temp = head;
    for(int i=0;i<= index-1;i++) temp = temp->next;
    temp ->data = e;  
}

template<class T>
bool DLinkedList<T>::empty() {
    return count == 0;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    Node * temp = head;
    for(int i=0 ;i<count;i++){
        if(temp ->data == item) return i;
        temp = temp ->next;
    }
    return -1;    
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    Node * temp = head;
    for(int i=0;i<count;i++){
        if(temp -> data == item) return true;
        temp = temp-> next;
    }
    return false;
    
}
template <class T>
T DLinkedList<T>::removeAt(int index)
{
    T result;
// kiểm tra đầu vào
    if(index < 0 && index >= count) throw out_of_range("");
// nếu chỉ có 1 phần tử
    if(count == 1){
        result = head->data;
        delete head;
        head = tail = NULL;
    }
// nhiều hơn 1 phần tử và ở vị trí đầu tiên
    else if(index == 0){
        Node* tmp = head;
        head = head->next;
        head ->previous = nullptr;
        result = tmp->data;
        delete tmp;
        head->previous = NULL;
    }
    else{
        Node* tmp = head;
//! tìm vị trí trước vị trí cần xóa
        index --; 
        while(index){
            tmp = tmp->next;
            index --;
        }
//! lưu vị giá trị xóa đi
        result = tmp->next->data;
//! nếu nó là vị trí cuối cùng
        if(tmp->next == tail){
            delete tail;
            tail = tmp;
            tail->next = NULL;
        }
        else{
            Node* h = tmp->next;
            tmp->next = tmp->next->next;
            tmp->next->previous = tmp;
            delete h;
        }
    }
    count --;
    return result;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    int index = indexOf(item);
    if(index == -1) return false;
    removeAt(index);
    return true;
    
}

template<class T>
void DLinkedList<T>::clear(){
    Node* tmp = head;
    while(head){
        head = head->next;
        delete tmp;
        tmp = head;
    }
    head = tail = NULL;
    count = 0;  
}










int main(){
    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
    list.add(idx);
    }
    for(int idx=0; idx < size; idx++){
    cout << list.get(idx) << " |";
    }
//! 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |  


    DLinkedList<int> list1;
    int size1 = 10;
    int value1[] = {2,5,6,3,67,332,43,1,0,9};
    for(int idx=0; idx < size1; idx++){
    list1.add(idx);
    }
    for(int idx=0; idx < size1; idx++){
    list1.set(idx, value1[idx]);
    }
    cout << list1.toString();
//! [0,1,2,3,4,5,6,7,8,9]
}