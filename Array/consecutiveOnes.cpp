#include <iostream>
#include <vector>

using namespace std;
#define ll long long

bool consecutiveOnes(vector<int>& nums){
    int len = nums.size();
    bool check = false;
    if(len ==0) return true;
    if(nums[len-1]==1 && nums[len-2]!=1) return false;
    for(int i=0;i<len-1;i++){   // từ phần tử 0 đến n-1;
       if(nums[i]== 1 && nums[i+1] != 1 && nums[i-1] !=1) return false;
    }
    return true;
}
/*
bool consecutiveOnes(vector<int>& nums) {
    //! gan mac dinh test bang false
    bool test = false;
    int len = nums.size();
    for(int i = 0 ; i < len; i++){
        //! tim vi tri co gia tri bang 1 
        if(nums[i] == 1 && !test){
            test = true;
          
        }
        else if(nums[i] == 1 && nums[i] != nums[i-1]) return false;
    }
    return true;
}
*/

int main(){
   	
vector<int> nums {0, 1, 1, 1, 9, 8};
cout << consecutiveOnes(nums);
//!1
vector<int> nums1 {0, 1, 1, 1, 9, 8,1};
cout << consecutiveOnes(nums1);
//! 0
vector<int> nums2 {};
cout << consecutiveOnes(nums2);
//!1
return 0;

}
