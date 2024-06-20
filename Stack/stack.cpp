#include<iostream>
#include<stack>
#include<utility>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string S) {
    stack<char> chars;
    unsigned int size = S.size();
    for (unsigned int i=0; i<size; i++) {
        bool flag = false;
        while (!chars.empty() && S[i] == chars.top()) {
            chars.pop();
            flag = true;
        }
        if (!flag) {
            chars.push(S[i]);
        }
    }

    string ans = "";

    while (!chars.empty()) {
        ans = chars.top() + ans;
        chars.pop();
    }

    return ans;
}

string deleteDuplicate(string s, int k) {
    unsigned int size = s.size();
    
    if (k == 1) return "";
    
    stack<pair<char, unsigned int>> st;
    for (unsigned int i=0; i<size; i++) {
        if (!st.empty() && st.top().first == s[i]) {
            int t = st.top().second + 1;
            st.pop();
            if (t < k) {
                pair<char, unsigned int> p = {s[i], t};
                st.push(p);
            }
        }
        else {
            pair<char, unsigned int> p = {s[i], 1};
            st.push(p);
        }
    }

    string ans = "";

    while (!st.empty()) {
        pair<char, unsigned int> top = st.top();
        st.pop();
        char c = top.first;

        for (unsigned int i=0; i<top.second; i++) {
            ans = c + ans;
        }
    }

    return ans;
}

vector<int> nextGreater(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (unsigned int i=0; i<arr.size(); i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }

    return ans;
}

int baseballScore(string ops) {
    stack<int> st;

    for (char c : ops) {
        if (isdigit(c)) {
            st.push(c - 48);
        }
        else {
            switch (c) {
                case 'C':
                    st.pop();
                    break;
                case 'D':
                    st.push(st.top() * 2);
                    break;
                case '+':
                    int tmp = st.top();
                    st.pop();
                    int sum = tmp + st.top();
                    st.push(tmp);
                    st.push(sum);
                    break;
            }
        }
    }

    int ans = 0;

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string parenthesesReversal(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == ')') {
            string temp = "";
            while (!st.empty() && st.top() != '(') {
                temp += st.top();
                st.pop();
            }

            st.pop();

            for (char cR : temp) {
                st.push(cR);
            }
        }
        else {
            st.push(c);
        }
    }

    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

bool tripleIndexSLM(vector<int>& nums) {
    if (nums.size() < 3) return false;

    stack<int> st;
    int rE = -1e7;

    for (int e : nums) {
        if (e < rE) return true;

        while (!st.empty() && e > st.top()) {
            rE = st.top();
            st.pop();
        }

        st.push(e);
    }

    return false;
}

int trap(vector<int>& height) {
    stack<int> st;
    unsigned int n = height.size();

    if (n < 2) {
        return 0;
    }

    int ans = 0;

    for (unsigned int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();

            if (st.empty()) break;

            int bH = height[i] > height[st.top()] ? height[st.top()] : height[i];
            int dis = i - st.top() - 1;
            ans += dis * (bH - height[top]);
        }
        st.push(i);
    }
    return ans;
}

int sumOfMinSubarray(vector<int>& nums) {
    // STUDENT ANSWER
    const int MOD = 10000;
    int n = nums.size();
    long long result = 0;  // We use long long to avoid integer overflow

    stack<int> s;  // Stack to keep track of indices

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack while they are greater than the current element
        while (!s.empty() && nums[i] < nums[s.top()]) {
            int top = s.top();
            s.pop();
            int left = (s.empty() ? -1 : s.top());
            result = (result + (long long)nums[top] * (i - top) * (top - left)) % MOD;
        }
        s.push(i);
    }

    // Pop remaining elements in the stack
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int left = (s.empty() ? -1 : s.top());
        result = (result + (long long)nums[top] * (n - top) * (top - left)) % MOD;
    }

    return result;
}

bool isPossible(const std::vector<int>& piles, int k, int r) {
    int boxesUsed = 0;
    for (int pile : piles) {
        boxesUsed += (pile + r - 1) / r;
    }
    return boxesUsed <= k;
}

int boxRequire(std::vector<int>& piles, int k) {
    int left = 1;
    int right = *std::max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isPossible(piles, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
int evaluatePostfix(string expr){
    /*TODO*/
    stack <int> s;
    stringstream ss(expr);
    string c;
    while(ss >>c){
        if (c == "+"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a+b);
        }
        else if (c== "-"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b-a);
        }
        else if (c=="*"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b*a);
        }
        else if (c== "/"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b/a);
        }
        else s.push(stoi(c));
    }
    return s.top();
}
vector<int> stock_span(const vector<int>& ns) {
    stack<int> stackNum;
    stack<int> stackNumTemp;
    vector<int> returnVal;
    int n = ns.size();
    for (int i = 0; i < n; i++) {
        int count = 1;
        if (i == 0) { 
            returnVal.push_back(1);
            stackNum.push(ns[i]);
        }
        else {
            while (!stackNum.empty()) {
                if (ns[i] <= stackNum.top()) {
                    returnVal.push_back(count);
                    break;
                }
                else {
                    stackNumTemp.push(stackNum.top());
                    stackNum.pop();
                    count++;
                }
            }
            while (!stackNumTemp.empty()) {
                stackNum.push(stackNumTemp.top());
                stackNumTemp.pop();
            }
            stackNum.push(ns[i]);
            int numCount = returnVal.size();
            if ( numCount == i ) {
                returnVal.push_back(count);
            }
        }
    }
    return returnVal;
    // STUDENT ANSWER
}


bool canEatFood1(int maze[5][5], int x, int y, int fx, int fy, bool visited[5][5]) {
    if (x == fx && y == fy) {
        return true;
    }
    visited[x][y] = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5 && maze[newX][newY] == 1 && !visited[newX][newY]) {
            if (canEatFood1(maze, newX, newY, fx, fy, visited)) {
                return true;
            }
        }
    }

    return false;
}
bool canEatFood(int maze[5][5], int fx, int fy){
    /*TODO*/
    bool visited[5][5]={false};
    bool canGo= canEatFood1(maze,0,0,fx,fy,visited);
    return canGo;
}

int main() {

    // string S = "aab";
    // cout << removeDuplicates(S);

    // string s = "aaabbbbccddddefffghiiiiihhhhggggffda";
    // int k = 5;

    // cout << deleteDuplicate(s, k);

    // vector<int> arr = {15, 2, 4, 10};

    // vector<int> ans = nextGreater(arr);

    // for (int e : ans) {
    //     cout << e << " ";
    // }

    // string ops = "524CD9++";
    // cout << baseballScore(ops);

    // string s = "vi(i(lm)k)kq";

    // cout << parenthesesReversal(s);

    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    // cout << trap(height);

    vector<int> nums = {1, 2, 3, 4};
    cout << sumOfMinSubarray(nums);

    return 0;
}

/*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */