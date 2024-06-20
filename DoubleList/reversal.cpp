#include<iostream>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
//! Khai báo một bảng băm (unordered_map) để lưu trữ con trỏ tới các ListNode với khóa là chỉ số.
    unordered_map<int ,ListNode* > v;
//! Khởi tạo một con trỏ tạm thời để duyệt qua danh sách.
    ListNode* tmp = head;
//! Khởi tạo biến index để theo dõi chỉ số của các nút trong danh sách.
    int index = 1;
//! Khởi tạo biến i với giá trị b, sẽ được sử dụng để đảo ngược thứ tự của các nút từ b đến a.
    int i = b;
    while(tmp){
        if(index >= a && index <= b){
 //! Lưu trữ con trỏ tới các nút trong khoảng a đến b vào bảng băm v.
            v[i] = tmp;
            i--;
        }
//! Lưu trữ con trỏ tới các nút nằm ngoài khoảng a đến b.
        else v[index] = tmp;
        tmp = tmp->right;
        index ++;
    }
//! Gán con trỏ head bằng con trỏ tới nút đầu tiên sau khi đảo ngược.
    head = v[1];
    head->left = NULL;
    tmp = head;
    for(int i = 2; i < index; i++){
//! thực hiện các thao tác liên kết lại
        tmp->right = v[i];
        v[i]->left = tmp;
        tmp = v[i];
    }
    tmp->right = NULL;
    return head;
}
ListNode* init(int* list, int size, unordered_map<ListNode*, int>& nodeValue) {
    if (size == 0) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(list[0]);
    nodeValue[head] = list[0];
    ListNode* prev = head;
    
    for (int i = 1; i < size; i++) {
        ListNode* newNode = new ListNode(list[i]);
        nodeValue[newNode] = list[i];
        prev->right = newNode;
        newNode->left = prev;
        prev = newNode;
    }
    
    return head;
}

void printList(ListNode* head, unordered_map<ListNode*, int>& nodeValue) {
    ListNode* tmp = head;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->right;
    }
    cout << endl;
}

void freeMem(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->right;
        delete tmp;
    }
}


int main(){
    int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
}