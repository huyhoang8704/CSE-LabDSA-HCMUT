#include <iostream>
#include <vector>
using namespace std;

void print(int a[],int size){
    for (int i=0;i<size;i++) cout << a[i] << " ";
    cout << endl;
}


// trang web xem visualgo.net
// sắp xếp chọn
//? Mỗi bước thì sẽ có phần tử nhỏ nhất đưa về đầu
void SelectionSort(int a[], int n){
    for (int i=0;i<n-1;i++){
        int min=i;  // dùng biến min để lưu vị trí phần tử nhỏ nhất 
        // Dùng vòng lặp để duyệt các phần tử phía sau và cập nhật vị trí của phần tử nhỏ nhất 
        for (int j=i+1;j<n;j++){
            if (a[j]<a[min]) min=j;
        }
        swap(a[i], a[min]);
    }
}
// void selection(int a[], int n){
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             if (a[i]>a[j]) swap(a[i],a[j]);
//         }
//     }
// }

void SelectionSortTotal(int a[], int n){
    int total = 0;
    for (int i=0;i<n-1;i++){
        int min=i;
        for (int j=i+1;j<n;j++){
                total += 5;
            if (a[j]<a[min]){
                min=j;

            } 
        }
        total +=5;
        swap(a[i], a[min]);
        cout << total << endl;
        print(a,n);
    }
}

// sắp xếp nổi bọt
//? Mỗi bước thì sẽ có phần tử lớn nhất đưa về cuối
void BubbleSort(int a[],int n){
    int total = 0;
    for (int i=0; i<n-1;i++){
        for (int j=0;j<n-i-1;j++) 
           if (a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            total += 8;
           }
        cout << total << endl;
        print(a,n);  
    }
}




// sắp xếp chèn
void InsertionSort(int a[],int n){
    for (int i=1;i<n;i++){
        int x=a[i],pos=i-1;   // x là phần tử lấy ra xét , pos là vị trí trước nó 
        while (pos >=0 && x<a[pos]){
            a[pos+1]= a[pos];
            pos--;
        }
        a[pos+1]=x;
        print(a,n);
    }

}




// sắp xếp trộn (Merge Sort) , chia và trị
// Hàm trộn 2 hàm lại với nhau
void merge(int a[], int l, int m, int r){
    vector <int> x(a+l,a+m+1);
    vector <int> y(a+m+1,a+r+1);
    int i=0,j=0;
    while (i< x.size() && j<y.size()){
        if (x[i] <= y[j]){
            a[l]= x[i];
            l++; i++;
        }
        else {
            a[l]=y[j];
            l++; j++;
        }
    }
    while (i <x.size()){
        a[l]=x[i];
        l++; i++;
    }
     while (j <y.size()){
        a[l]=y[j];
        l++; j++;
    }
}
// hàm đệ quy mergeSort
void mergeSort(int a[], int l,int r){
    if (l >=r) return;
    int m = (l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}


// QuickSort
// patition : trả về vị trí của pivot
int patition(int a[], int l , int r){
    int pivot = a[r];  // phần tử cuối cùng 
    int i= l-1;
    for (int j=l ; j<=r-1;j++){
        if (a[j]<= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;    // để i nhảy đến phần tử đầu tiên > pivot xong swap pivot với phần tử đó
    swap(a[i],a[r]);
    return i;

}
void quickSort(int a[], int l , int r){
    if (l>=r) return;
    int m= patition(a,l,r);
    quickSort(a,l,m-1);
    quickSort(a,m+1,r);
}





int main(){
    int arr[7]={37,27,43,3,9,82,10};
    SelectionSortTotal(arr,7);
    //BubbleSort(arr,6);
    //mergeSort(arr,0,5);
    // quickSort(arr,0,5);
    // for(int x:arr) cout <<x<<" ";
}