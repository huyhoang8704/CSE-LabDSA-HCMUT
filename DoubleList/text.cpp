#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& arr){
    // 15 2 4 10      -1 4 10 -1
    int size = arr.size();
    vector <int> v(-1,size);
    for(int i=0;i<size;i++){
        if (i == size-1) { v.push_back(-1); break;}
        if (arr[i+1] > arr[i]){
            v.push_back(arr[i+1]);
        }
        else v.push_back(-1);
    }
    return v;
}
int main(){
   int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];
    vector<int> greaterNums = nextGreater(nums);
    for(int i : greaterNums) 
        cout << i << ' ';
    cout << '\n';   
}