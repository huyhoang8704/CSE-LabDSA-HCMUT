#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

int longestSublist(vector<string>& words) {
    if(words.size() == 0) return 0;
    char c;
    int Max = 0;
    c = words[0][0];
    int count = 1;
    int len = words.size();
    for(int i = 1; i < len; i++){
        if(words[i][0] == c) count ++;
        else{
            Max = max(count,Max);
            c = words[i][0];
            count = 1;
        }
    }
    return max(count,Max);
}

int main(){
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
    //!3
    vector<string> words1 {"also", "and", "an", "currying", "and", "day", "and", "and", "constituent", "an"};
    cout << longestSublist(words1);
    //!3 
    vector<string> words2 {};
    cout << longestSublist(words2);
    //!0
}