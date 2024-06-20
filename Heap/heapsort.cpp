//Helping functions go here
static void heapSort(T* start, T* end){
    priority_queue<T> q(start, end);
    T* tmp = end - 1;
    while(!q.empty()){
        *tmp = q.top();
        q.pop();
        tmp --;
    }
    Sorting<T>::printArray(start,end);
}