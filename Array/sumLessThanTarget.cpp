#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int patition(vector<int> &v, int l , int r){
    int i = l-1;
    int pivot =v[r];
    for(int j=l;j<=r-1;j++){
        if(v[j] <= pivot){
            i++;
            swap(v[j],v[i]);
        }
    }
    ++i; 
    swap(v[i],v[r]);
    return i;
}

void QuickSort(vector<int> &v , int l , int r){
    if(l >=r ) return;
    int m = patition(v,l,r);
    QuickSort(v,l,m-1);
    QuickSort(v,m+1,r);
}

int sumLessThanTarget(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    // ! gan gia tri nho nhat cho max
    int MAX = -10e6;
    while(left < right){
//! lon hon thi giam ben phai
        if(nums[left] + nums[right] >= target) right--;
//! nho hon thi tang ben trai len
        else{
// ! luu phan tu thoa man de bai lon nhat
            MAX = max(MAX,nums[left] + nums[right]);
            left ++;
        }
    }
    return MAX;
}

int main(){
    vector<int> nums {1, 2, 3, 5, 6, 9};
    int target = 7;
    cout << sumLessThanTarget(nums, target)<<endl;
    //!6
    vector<int> nums1 {1, 2, 3, 5, 6, 11, 12, 13 };
    int target1 = 8;
    cout << sumLessThanTarget(nums1, target1);
    //!7
}