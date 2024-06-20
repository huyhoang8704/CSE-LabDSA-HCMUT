#include <iostream>
using namespace std;





class IntSLinkedList {
public:
    class Node; // Forward declaration
public:
    class Node {
    public:
        int data;
        Node* next;

    public:
        Node() : next(NULL) {};
        Node(int data) : data(data), next(NULL) {};  // constructor
    };
private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {};
    void add(int element) {
        Node* temp = new Node(element);
        if (count == 0) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    void add(int index, int element) {

        if (index<0 || index>count) throw("out_of_range");

        else if (index == count || (count == 0 && index == 0)) add(element); // thêm vào cuối
    
        else if (index == 0) {  // thêm vào đầu
            Node* temp = new Node(element);
            temp->next = head;
            head = temp;
            count++;
        }

        else {
            Node *p = new Node(element);
            Node *temp = head;
            for(int i=0;i<=index-2;i++) temp = temp -> next; // tới vị trí index-1
            p->next = temp -> next;
            temp -> next = p;
            count++;

            //De Quy

        }

    }

    int removeAt(int index) {
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

    bool removeItem(int item) {
        Node* cur = head;
        for (int i = 0; i < count; i++) {
            
            if (cur->data == item) { removeAt(i); return true; }
            cur = cur->next;
        }
        return false;
    }

    bool empty() {

        return !count;
    }

    int size() {

        return count;
    }

    int get(int index) {
        if (index<0 || index>count) {
            throw std::out_of_range("Index out of range");
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void set(int index, int element) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = element;
    }

    int indexOf(int item) {
        Node* temp = head;
        for (int i = 0; i < count; i++) {
            if (temp->data == item) { return i; }
            temp = temp->next;
        }
        return -1;
    }

    bool contains(int item) {
        Node* temp = head;
        for (int i = 0; i < count; i++) {
            if (temp->data == item) { return true; }
            temp = temp->next;
        }
        return false;
    }

    void clear() {
        for (int i = 0; i < count; i++) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
        count = 0;
    }
    string toString();
    void print(){
        Node * temp=head;
        for(int i=1;i<=count;i++){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
    }
    void a(){
        for(int i=1;i<=3;i++){
            Node *temp =head;
            head = head->next;
            delete temp;
        }
    }
    Node *listduong() {
    Node *duong = nullptr; // Khởi tạo duong là nullptr
    Node *temp = head; // Bắt đầu từ đầu danh sách
    while (temp != nullptr) {
        if (temp->data > 0) {
            // Tạo một Node mới và thêm nó vào danh sách duong
            Node *newNode = new Node(temp->data);
            newNode->next = duong;
            duong = newNode;
        }
        temp = temp->next; // Di chuyển đến phần tử tiếp theo trong danh sách
    }
    return duong;
}

Node *listam() {
    Node *am = nullptr; // Khởi tạo am là nullptr
    Node *temp = head; // Bắt đầu từ đầu danh sách
    while (temp != nullptr) {
        if (temp->data < 0) {
            // Tạo một Node mới và thêm nó vào danh sách am
            Node *newNode = new Node(temp->data);
            newNode->next = am;
            am = newNode;
        }
        temp = temp->next; // Di chuyển đến phần tử tiếp theo trong danh sách
    }
    return am;
}


};

int main(){
    IntSLinkedList *p = new IntSLinkedList();
    // p->add(1);
    // p->add(2);
    // p->add(3);
    // p->add(4);
    // p->add(5);
    // p->add(6);
    // p->add(2,7);
    // p->print();
    // IntSLinkedList *pnew = p;
    // pnew->a();
    // cout<<endl;
    // p->print();
    p->add(1);
    p->add(-2);
    p->add(3);
    p->add(-4);
    p->add(5);
    p->add(-6);
    p->add(7);
    p->add(-8);
    p->add(9);
    IntSLinkedList::Node *duong = p->listduong();
    for(IntSLinkedList::Node *k = duong; k!=nullptr; k = k->next) cout<< k->data<<" ";
    cout<<endl;
    IntSLinkedList::Node *am = p->listam();
    for(IntSLinkedList::Node *k = am; k!=nullptr; k = k->next) cout<< k->data<<" ";
    delete p;
}