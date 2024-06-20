
//* mỗi lần lấy số nhỏ nhất nhân với 2 rồi đẩy nó vào lại mảng 
int leastAfter(vector<int>& nums, int k) {
    priority_queue<int, std::vector<int>, std::greater<int>> q(nums.begin(), nums.end());
    while(k){
        int n = q.top();
        q.pop();
        q.push(n*2);
        k--;
    }
    return q.top();
}   