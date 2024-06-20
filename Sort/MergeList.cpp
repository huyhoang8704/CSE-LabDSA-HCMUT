#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    ListNode* mergeSortList(ListNode* head);
    ListNode* mergeSortList(ListNode* head);

    static void merge(T* left, T* middle, T* right);
    static void mergeSort(T* start, T* end);

};


// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
//! Hàm để hợp nhất hai danh sách đã sắp xếp
template <class T>
ListNode*  Sorting<T>::mergeLists(ListNode* a, ListNode* b){
    //! Nếu danh sách a rỗng, trả về danh sách b
    if(a == NULL) return b;
    //! Nếu danh sách b rỗng, trả về danh sách a
    else if(b == NULL) return a;
    //! Tạo một node mới để làm node gốc của danh sách kết quả
    ListNode * result = new ListNode(0);
    ListNode* tmp = result;
    //! Lặp qua cả hai danh sách a và b
    while(a || b){
        if(!b || (a && a->val < b->val)){
            tmp->next = a;
            a = a->next;
            tmp = tmp->next;
        }
        else{
            tmp->next = b;
            b = b->next;
            tmp = tmp->next;               
        }
    }
    return result->next;
}

// Sort and unsorted list given its head pointer
//! Hàm tìm node giữa của danh sách
template <class T>
ListNode* Sorting<T>::idnode(ListNode* a){
    ListNode* tmp = a;
    while(tmp->next && tmp->next->next){
    //! Di chuyển con trỏ a đến node giữa
        a = a->next;
    //! Di chuyển con trỏ tmp đến node hai bước tiếp theo
        tmp = tmp->next->next;
    }
    tmp = a->next;  //! Lấy node sau node giữa
    a->next = NULL; //! Cắt kết nối giữa danh sách từ node giữa
    return tmp;
}
ListNode* mergeSortList(ListNode* head) {

    if(head == NULL || head->next == NULL) return head;
    ListNode* mid = midnode(head);
    head = mergeSortList(head);
    mid = mergeSortList(mid);
    return mergeLists(head,mid);
    
}

int main(){
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};
    unordered_map<ListNode*, int> nodeAddr;
    ListNode* a = init(arr1, sizeof(arr1) / 4, nodeAddr);
    ListNode* b = init(arr2, sizeof(arr2) / 4, nodeAddr);
    ListNode* merged = mergeLists(a, b);
    try {
        printList(merged, nodeAddr);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(merged);
}