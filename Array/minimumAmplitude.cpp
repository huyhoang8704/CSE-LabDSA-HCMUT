#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minimumAmplitude(vector<int>& nums, int k) {
    //! lấy độ dài của vector
    int len = nums.size();
    int result = INT_MAX;
    for(int i = 0; i < len - k; i++){
    //! gán giá trị Min Max mặc định
        int Min = INT_MAX;
        int Max = INT_MIN;
    //! xet tu phan tu i ve truoc
        for(int j = 0; j < i; j++){
            Min = min(Min,nums[j]);
            Max = max(Max,nums[j]);
        }
        //! xet tu phan tu i + k ve sau
        for(int j = i + k; j < len; j++){
            Min = min(Min,nums[j]);
            Max = max(Max,nums[j]);
        }
        //! luu gia tri nho nha cua max - min
        result = min(result,Max - Min);
    }
    return result;
}

int main(){
    	
    vector<int> nums {9, 6, 2, 1, 10, 7};
    int k = 2;
    cout << minimumAmplitude(nums, k)<<endl;
    //! 4
	
    vector<int> nums1 {375, 8734, 7366, 433, 1063, 371, 412, 6424, 3680, 4100};
    int k1 = 3;
    cout << minimumAmplitude(nums1, k1)<<endl;
    //! 6053

}