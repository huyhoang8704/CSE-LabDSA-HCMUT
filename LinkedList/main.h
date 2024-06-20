#ifndef __Singly_Linked_List_H__
#define __Singly_Linked_List_H__

#include "main.h"
class Singly_Linked_List
{
public:
    class Node;
    public:
    class Node{
    public:
        int data;   //! dữ liệu
        Node* next; //! trỏ tới node tiếp theo
    public:
        Node(int data = 0, Node* next = nullptr)
        :data(data), next(next){}
    };
protected:
    Node* head, *tail;  //! Node đầu tiên và Node cuối cùng
    int size;           //! kích thước của 1 
public:
    //! khởi tạo
    Singly_Linked_List();
    Singly_Linked_List(const Singly_Linked_List& others);
    ~Singly_Linked_List();
    int Count();
    bool Empty();
    //! các hàm chỉnh sửa dữ liệu
    void Insertion(int data, int index);
    void Deletion(int index);

    //! cách hàm lấy dữ liệu
    int Get(int index);
    int IndexOf(int data);
    bool Contains ( int data );

    //! các hàm sort tăng dần nha
    void SelecetionSort();
    //void MergerSort(); //~ hàm này qua lý thuyết sort sẽ có

    //! các hàm hay dùng
    Singly_Linked_List Concat(const Singly_Linked_List& others);
    Singly_Linked_List SubSingly_Linked_List(int from, int to);
    void Reverse();

    //! hàm dislay cấu trúc [Size=2,DataHead=1,DataTail=2,DataNode : 1->2->nullptr]
    string Dislay();

    //! các hàm làm thêm bài tập

};




#endif // __Singly_Linked_List_H__