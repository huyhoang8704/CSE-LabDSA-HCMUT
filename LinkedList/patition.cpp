#include<iostream>

using namespace std;

class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
	    void partition(int k);
        void add(int val){
            Node * ad = new Node(val);
            if(this->head == nullptr){
                head = ad;
                tail = head;
            }
            else{
                tail->next = ad;
                tail = ad;
            }
            this->size++;
           
        }
        string toString() {
        string result;
        Node* current = head;
        while (current) {
//! chuyển đổi số thành chuỗi và lưu lại
            result += to_string(current->value) + " ";
            current = current->next;
        }
        return result;
    }
};

void LinkedList::partition(int k) {
// Khởi tạo con trỏ result để theo dõi đầu danh sách sau khi phân chia.
    Node* result = NULL;
// Tạo một nút mới để đại diện cho các phần tử nhỏ hơn k.
    Node* smaller = new Node(1);
// Tạo một nút mới để đại diện cho các phần tử bằng k.
    Node* equal = new Node(1);
// Tạo một nút mới để đại diện cho các phần tử lớn hơn k.
    Node* larger = new Node(1);
// Con trỏ head1 trỏ đến nút equal, đại diện cho danh sách các phần tử bằng k.
    Node* head1 = equal;
// Con trỏ head2 trỏ đến nút larger, đại diện cho danh sách các phần tử lớn hơn k.
    Node* head2 = larger;
// Con trỏ tạm thời tmp được sử dụng để duyệt qua danh sách liên kết.
    Node* tmp = head;
// Cập nhật con trỏ head để trỏ đến nút smaller, đại diện cho danh sách các phần tử nhỏ hơn k.
    head = smaller;

    while(tmp){
 // Liên kết phần tử nhỏ hơn k vào danh sách smaller.
        if(tmp->value < k){
            // thêm tmp vào cuối của ds smaller
            smaller->next = tmp;
            smaller = tmp;
        } 
// Liên kết phần tử bằng k vào danh sách equal.
        else if(tmp->value == k){
            equal->next = tmp;
            equal = tmp;
        }
// Liên kết phần tử lớn hơn k vào danh sách larger.
        else{
            larger->next = tmp;
            larger = tmp;
        }
// Di chuyển con trỏ tmp đến phần tử tiếp theo trong danh sách
        tmp = tmp->next;
    }
    
    if(head != smaller){
 // Nếu result chưa được cập nhật, cập nhật nó bằng phần tử đầu của danh sách smaller.
        if(result == NULL) result = head->next;
    }
    
    if(head1 != equal){
// Tương tự như trên, cập nhật result nếu cần.
        if(result == NULL) result = head1->next;
// Liên kết phần tử cuối của danh sách smaller với phần tử đầu của danh sách equal.
        else{
            smaller->next = head1->next;
        }
        smaller = equal;
    }
 
    if(head2 != larger){
 // Tương tự như trên, cập nhật result nếu cần.
        if(result == NULL) result = head2->next;
// Liên kết phần tử cuối của danh sách smaller với phần tử đầu của danh sách larger.
        else{
            smaller->next = head2->next;
        }
        smaller = larger;
    }
// gán lại giá trị head và tail
    head = result;
    tail = smaller;
}

int main(){
    LinkedList* l1 = new LinkedList();
    l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
    l1->partition(45);
    cout << l1->toString() << "\n";
//! 20 30 10 40 45 60 55 
    }