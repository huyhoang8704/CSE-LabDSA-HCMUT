#include <bits/stdc++.h>
using namespace std;


// [100, 80, 60, 70, 60, 75, 85].
vector<int> stock_span(const vector<int>& ns) {
    // Your code here
    stack<int> s;
    vector<int> ans;
    for (unsigned  i = 0; i < ns.size(); i++) {
        while (!s.empty() and ns[s.top()] <= ns[i])
            s.pop();
 
        if (s.empty())
            ans.push_back( i+1);
        else {
            int top = s.top();
            ans.push_back(i - top);
        }
        s.push(i);
    }
 
    return ans;
}
vector<int> stock_span(const vector<int>& ns) {
       // Your code here
       vector<int> ans(ns.size());
       stack<int> s;
       for(int i = 0; i < ns.size(); i++){
           while(!s.empty() and ns[s.top()] <= ns[i]) s.pop();
           if(!s.empty()) ans[i] = (i-s.top());
           else ans[i] = i+1;
           s.push(i);
       }
       return ans;
    
}





int main(){

}