#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
};
template <class T>
void ArrayList<T>::ensureCapacity(int cap) {
    if (cap >= capacity) {
        int new_capacity = capacity * 1.5;
        T* new_data = new T[new_capacity];
        
        for (int i = 0; i < count; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

template <class T>
void ArrayList<T>::add(T e) {
    ensureCapacity(count + 1); // Ensure capacity for the new element
    data[count++] = e;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("The input index is out of range!");
    }

    ensureCapacity(count + 1); // Ensure capacity for the new element

    for (int i = count; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = e;
    count++;
}

template<class T>
int ArrayList<T>::size() {
    return count;
}

template<class T>
T ArrayList<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index is out of range");
    }

    T removedValue = data[index]; // Store the value to be removed

    // Shift the elements to the left to fill the gap
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }

    count--; // Decrement the count to reflect the removed element
    return removedValue;
}

template<class T>
bool ArrayList<T>::removeItem(T item) {
    for (int i = 0; i < count; i++) {
        if (data[i] == item) {
            // Shift elements to the left to fill the gap
            for (int j = i; j < count - 1; j++) {
                data[j] = data[j + 1];
            }
            
            count--; // Decrement the count to reflect the removed element
            return true; // Element found and removed
        }
    }

    return false; // Element not found in the array
}

template<class T>
void ArrayList<T>::clear() {
    if (data != nullptr) {
        delete[] data; // Delete the existing array if it's not NULL
    }
    
    // Create a new array with size 0 and capacity 5
    data = new T[5];
    capacity = 5;
    count = 0;
}

int main(){
ArrayList<int> arr;
int size = 10;

for(int index = 0; index < size; index++){
    arr.add(index);
}

//cout << arr.toString() << '\n';
cout << arr.size();
}