//! C++ program to print largest contiguous array sum
 
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
 
void maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << max_so_far
         << endl;
    cout << "Starting index " << start << endl // 2
         << "Ending index " << end << endl;  // 6
}
// Hàm tìm dãy con dài nhất có tổng nhỏ nhất
std::vector<int> findLongestSubarrayWithMinSum(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result;
    int minSum = INT_MAX;
    int currentSum = 0;
    int start = 0;
    int minLength = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (currentSum < minSum) {
            minSum = currentSum;
            minLength = i - start + 1;
        }
        if (currentSum == minSum && i - start + 1 > minLength) {
            minLength = i - start + 1;
        }
        if (currentSum >= 0) {
            currentSum = 0;
            start = i + 1;
        }
    }

    for (int i = start; i < start + minLength; ++i) {
        result.push_back(nums[i]);
    }

    return result;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    maxSubArraySum(a, n); // 7 
    return 0;
}