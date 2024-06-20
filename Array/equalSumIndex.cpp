#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector <int> &nums){
    if(nums.size() == 0) return -1;
    if(nums.size()==1 ) return 0;
    int sum=0, index;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
    }

    int sumLeft=0;
    for(int i=1;i<nums.size();i++){
        sumLeft += nums[i-1];
        if((sumLeft *2 + nums[i]) == sum) return i;
    }
    return -1;
}



int main(){
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums)<<endl;
    	//!3

    vector<int> nums1 {3};
    cout << equalSumIndex(nums1)<<endl;;
        //!0
    vector<int> nums2 {2, 6, 19, 17, 13, 12, 3, 10};
    cout << equalSumIndex(nums2)<<endl;
    return 0;

    
}