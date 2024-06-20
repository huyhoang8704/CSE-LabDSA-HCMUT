int pairMatching(vector<int>& nums, int target) {
    map<int, int> m;
    for(int i : nums) m[i] ++;
    int count = 0;
    for(int i :  nums){
        if(i + i == target){
            if(m[i] > 1){
            count ++;
            m[i] -= 2;
            }
        }
        else if(m[target - i] > 0 && m[i] > 0){
            //cout << i << " ";
            //cout << m[i] << " " << m[target - i] << endl;
            count ++;
            m[i] --;
            m[target - i]--;
        } 
    }
    return count;
}