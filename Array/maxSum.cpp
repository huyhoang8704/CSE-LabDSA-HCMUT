#include<iostream>

using namespace std;

void Sum(int* nums,int& n,int& k, int index, int sum,int &Maxsum){
    if(index < n){
   
        int Max = -10e8;
        int m = -10e8;
        for(int i = 0; i < k; i++){
            if(index + i > n) return;
            Max = max(Max,nums[index + i]);
            if(Max * (i+1) < m) m = max(m,Max * (i+1));
            else Sum(nums,n,k,index + i + 1,sum + Max * (i+1),Maxsum);
            
        }
    }
    else if(index == n){
        Maxsum = max(Maxsum,sum);
    }
}

int maxSum(int* nums, int n, int k) {
    int Maxsum = -10e8;
    Sum(nums,n,k,0,0,Maxsum);
    return Maxsum;  
}

int main(){
    
    int arr[] = {1,6,3,2,2,5,1};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, length, 3) << "\n";
    //!35
}