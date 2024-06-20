#include<iostream>
#include<vector>
using namespace std;
vector<int> updateArrayPerRange(vector<int> &nums, vector<vector<int>> &operations)
{   //! duyet qua cac phan tu trong operations
    for (auto i : operations) // biến i lần lượt là các vector hàng của operations
    {
        for (int j = i[0]; j <= i[1]; j++)
            nums[j] += i[2];
    }
    return nums;
}
void printVector(vector<int> nums){
 for (auto i : nums){
        cout<<i<<" ";
     }
}
int main(){
    vector<int> nums {13, 0, 6, 9, 14, 16}; 
    vector<vector<int>> operations {{5, 5, 16},{3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums,operations));
    //[21, 8, 14, 9, 14, 32]

}