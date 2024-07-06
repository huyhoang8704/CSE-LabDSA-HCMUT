#include<iostream>

using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(){
        this->count = 0;
        head = tail = nullptr;
    }
    ~SLinkedList(){}
    void    add( const T& e);
    void    add(int index, const T& e);
    int     size();
    T       get(int index);
    void    set(int index, const T& e);
    bool    empty();
    int     indexOf(const T& item);
    bool    contains(const T& item);
    T       removeAt(int index);
    bool    removeItem(const T& item);
    void    clear();
    string toString();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};
//! hiện thực hàm add(const T& e)
template <class T>
void SLinkedList<T>::add(const T& e) {
    // Chia làm 2 TH rỗng và không rỗng
    if(this->empty()){  head = tail = new Node(e,nullptr);}

    else{
        Node* tmp = new Node(e,nullptr);
      
        tail->next = tmp;
        
        tail = tmp;
        
    }
    count++;
    
}
//! hiện thực hàm add(int index, const T& e)
template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if(index < 0 || index > count) return;
    else if(count == 0 || index == count) add(e);
    else if(index == 0){
        Node* tmp = new Node(e,nullptr);
        tmp->next = head;
        head = tmp;
        count ++;
    }
    else{
        Node* tmp = head;
        Node* New = new Node(e,nullptr);
        for(int i= 0 ; i< index -1 ; i++) tmp = tmp->next;
        // while(index){    // đi đến trước index
        //     tmp = tmp->next;
        //     index--;
        // }
        New->next = tmp->next;
        tmp->next = New;
        count ++;
    } 
    
}
//! hiện thực hàm size()
template<class T>
int SLinkedList<T>::size() {
   return this->count;
}
template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index<0 || index>= this->count) throw std::out_of_range("Index out of range");
    Node *tmp = head;
    for(int i=0;i<index;i++) tmp = tmp->next;
    return tmp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if(index <0 || index >count) return;
    Node *tmp = head;
    for(int i=0;i<index;i++) tmp = tmp->next;
    tmp ->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    return !this->count;   
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index when item appears in list, otherwise return -1 */
    Node* temp = head;
        for (int i = 0; i < count; i++) {
            if (temp->data == item) return i;
            temp = temp->next;
        }
        return -1;    
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* temp = head;
        for (int i = 0; i < count; i++) {
            if (temp->data == item) return true;
            temp = temp->next;
        }
        return false;
}
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    int val=0;
        if (index<0 || index>count) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            val = temp->data;
            delete temp;
            count--;
        }
        else {
            Node* pre = NULL;
            Node* cur = head;
            for (int i = 0; i < index; i++) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
            val = cur->data;
            delete cur;
            count--;
            if (index == count) {
                tail = pre;
            }
        }
        return val;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node* cur = head;
        for (int i = 0; i < count; i++) {
            
            if (cur->data == item) { removeAt(i); return true; }
            cur = cur->next;
        }
        return false;
    
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
   for(int i=0 ;i<count;i++){
    Node *temp = head;
    head = head->next;
    delete temp;
   }
   head = nullptr;
   tail = nullptr;
   count = 0;
}






//! hiện thực hàm toString 
template<class T>
string SLinkedList<T>::toString() {
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



int main(){
    SLinkedList<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
         
        list.add(index);
    }

    cout << list.toString();

}