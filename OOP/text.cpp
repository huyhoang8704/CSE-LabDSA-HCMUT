#include <bits/stdc++.h>
using namespace std;
#define ll long long


//! Khai báo template <Class T> trước khi sử dụng hàm
//!  Kiểu_dữ_liệu_hàm   tên_class<T>::Tên_hàm();

template <class T>    //! đại diện cho kiểu dữ liệu 
T myAbs(T x){
    return x >=0 ? x : -x;
}
template <class T>
T Max (T a, T b){
    return a >b ? a : b;
}


template <class T>

class Stack{
    private: 
    int size;
    T *a;
    public:
    Stack(int size);
    ~Stack();
    void push(T x);
    T pop();
};

template <class T>
Stack<T>::Stack(int size){
    this->size = size;
    this->a = new T[size];
}
template <class T>
Stack<T>::~Stack(){
    delete []a ;
    a=nullptr;
}
template <class T>
void Stack<T>::push(T x){

}

template <class T>
T Stack<T>::pop(){

}






//! Muốn dùng kiểu nào thì khai báo
template class Stack<int>;
template class Stack<double>;
template class Stack<ll>;
template class Stack<string>;




int main(){

}