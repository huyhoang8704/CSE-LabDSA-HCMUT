#include<iostream>
#include<stack> 

using namespace std;

stack<int> k;
void count(string s){
 //! nếu chuỗi rỗng thì dừng lại   
    if(s == "") return;
//! nếu stack trống thì thêm phần tử vào
    else if(k.empty()){
        k.push(s[0]);
    }
//! nếu phần từ đàu là ) và phần tử cuối stack là ( thì loại bỏ ra khỏi stack
    else if(s[0] == ')' && k.top() == '('){
            k.pop();
    }
//! nếu không phải thì thêm vào stack
    else{
        k.push(s[0]);
    }
    count(s.substr(1));
}

// void clear(){
//     if(k.empty()) return;
//     k.pop();
//     clear();
// }   

int mininumBracketAdd(string s) {
    if(s == "") return 0;
    count(s);
    int i = k.size();
    // clear();
    return i;
}

int main(){
    cout << mininumBracketAdd(")))((")<<endl;
//! 5
    cout << mininumBracketAdd("))()))()()")<<endl;
//!4
    cout << mininumBracketAdd("");
//! 0
}