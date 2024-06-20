#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;  // max size
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    int getItem(T item);
    void remove(T item);
    void clear();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return !count;
}

template<class T>
T Heap<T>::peek(){
    if(count == 0) return -1;
    else return this->elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i=0;i<count;i++){
        if(this->elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(count == 0) return false;
    swap(elements[0], elements[count-1]);
    count--;
    reheapDown(0);
    return true;
}

template<class T>
void Heap<T>::push(T item){
    ensureCapacity(capacity);
    this->elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if(count<capacity) return;
    capacity++;
    T*elementsnew =new T[capacity];
    for(int i=0;i<count;i++){
        elementsnew[i]=elements[i];
    }
    delete[]elements;
    elements=elementsnew;
}

template<class T>
void Heap<T>::reheapUp(int position){
    int parent = (position-1)/2;
    if (position == 0 || elements[parent] >= elements[position]) return;
    swap(elements[parent],elements[position]);
    reheapUp(parent);
    
}


template<class T>
int Heap<T>::getItem(T item) {
    for(int i = 0 ; i < count ; i++){
        if(elements[i] == item)
            return i;
    }
    
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    
    int index = getItem(item); 
    
    if (index == -1) 
        return;
        
    if (index == count - 1) 
    {
        count--; 
        return;
    }
    
    T temp = elements[index];
    elements[index] = elements[count - 1];
    elements[count - 1] = temp;
    count--; 
    
    if (elements[index] > elements[(index - 1) / 2]) 
        reheapUp(index); 
    else 
        reheapDown(index); 
}

template<class T>
void Heap<T>::clear() {
    delete[]elements; 
    capacity = 10; 
    count = 0;
    elements = new T[capacity]; 
}