#include <iostream>
#include <vector>
using namespace std;

int patition(int a[],int l,int r){
    int pivot =a[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    ++i;
    swap(a[i],a[r]);
    return i;
}
void QuickSort(int a[],int l,int r){
    if(l>=r) return;
    int m =patition(a,l,r);
    QuickSort(a,l,m-1);
    QuickSort(a,m+1,r);
}




int buyCars(int a[],int n,int k){
    int cnt=0;
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        if(k >= a[i]){
            cnt++;
            k-= a[i];
        }
    }
    return cnt;
}

int main(){
    int a[5]={20,50,30,40,90};
    int n = sizeof(a)/ sizeof(a[0]);
    cout << buyCars(a,n,90);
}