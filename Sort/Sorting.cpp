
#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T* Partition(T* start, T* end) ;
    static void merge(T* left, T* middle, T* right);
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
    static void QuickSort(T* start, T* end) ;
    static void mergeSort(T* start, T* end);
    static void InsertionSort(T* start, T* end) ;
    static void TimSort(T* start, T* end, int min_size) ;
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T* result = start;
    while(start != end - 1){
//! Con trỏ min trỏ đến phần tử nhỏ nhất trong phạm vi chưa sắp xếp
        T* min = start;
//! Con trỏ tmp dùng để duyệt qua các phần tử còn lại
        T* tmp = start + 1;
        while(tmp != end){
//! Nếu phần tử tại tmp nhỏ hơn phần tử nhỏ nhất hiện tại, cập nhật min
            if(*tmp < * min){
                min = tmp;
            }
            tmp++;
        }
//! Hoán đổi phần tử nhỏ nhất tìm được với phần tử đầu tiên trong phạm vi chưa sắp xếp
        swap(*start, *min);
//! in ra phần tử 
        Sorting<T>::printArray(result,end);
        start++;
       
    }
}
template <class T>
static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total){
        int n=end-start;
        for(int i=segment_idx;i<n;i+=cur_segment_total){
            for(int j=i+cur_segment_total; j<n; j+=cur_segment_total){
                if(start[j]<start[i]){
                    int temp=start[j];
                    start[j]=start[i];
                    start[i]=temp;
                }
            }
        }
    }
template <class T>
static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases){
        for(int i=num_phases-1;i>=0;i--){
            cout<<num_segment_list[i]<<" segments: ";
            for(int j=0;j<num_segment_list[i];j++){
                sortSegment(start,end,j,num_segment_list[i]);
            }
            printArray(start,end);
        }
}

template <class T>
static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
       if (start == end)
        {
            return start;
        }
        int count = end - start + 1;
        int i = 1;
        int j = count - 1;
        while (i <= j)
        {
            while (start[i] < start[0] )
            {
                i++;
            }
            while (start[j] > start[0] && j >= 1)
            {
                j--;
            }
            if (i < j)
            {
                swap(start[i], start[j]);
                i++;
                j--;
            }
           
        }
        swap(start[0], start[j]);
        return start + j;

}
template <class T>
static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
     if (end - start > 0)
        {
            T *x = Partition(start, end - 1);
            cout << x - start << " ";
            QuickSort(start, x);
            QuickSort(x + 1, end);
        }
}
template <class T>
static void merge(T* left, T* middle, T* right){
    /*TODO*/
     //! Khai báo mảng tạm thời
    T* arr = left;
    int l = 0, m = middle - left, r = right - left;
    //! Kích thước mảng con thứ nhất
    int n1 = m - l + 1; 
    //! Kích thước mảng con thứ hai
    int n2 = r - m; 
  
    // Create temp arrays 
    //! Tạo mảng tạm thời  
    int L[n1], R[n2]; 
  
    //* Copy data to temp arrays L[] and R[]  
 //! Sao chép dữ liệu vào mảng tạm thời L[] và R[]
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r] 
      int i = 0;
    //* Initial index of second subarray 

    int j = 0;  
      
    //* Initial index of merged subarray 
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    //* Copy the remaining elements of 
    //* L[], if there are any  
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    //* Copy the remaining elements of 
    //* R[], if there are any  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
    Sorting::printArray(left, right);
}
template <class T>
static void mergeSort(T* start, T* end){
    if(start < end){
       T* mid = (end - start) / 2 + start;
       mergeSort(start, mid);
       mergeSort(mid+1,end);
       merge(start, mid, end);
   }
}


int main(){
    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
    /*
    *-2, 0, 8, 1, 2, 9
    *-2, 0, 1, 8, 2, 9
    *-2, 0, 1, 2, 8, 9
    *-2, 0, 1, 2, 8, 9

    */
}