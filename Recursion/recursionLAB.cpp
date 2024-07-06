#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
stack <int> k;

int findGCD(int a,int b){
    if(b==0) return a;
    else return findGCD(b,a%b);
}

void printHailstone(int number) {
    cout << number;
    
    // Base case: Stop when the number reaches 1
    if (number == 1) {
        return;
    }
    
    // Recursive case
    if (number % 2 == 0) {
        // If even, divide by 2
        cout << " ";
        printHailstone(number / 2);
    } else {
        // If odd, multiply by 3 and add 1
        cout << " ";
        printHailstone(3 * number + 1);
    }
}
void printArray(int n){
    if (n == 0) {
        std::cout << 0;
    } else {
        printArray(n - 1);
        std::cout <<", "<<n;
    }
}
int findMax(int* arr, int length){
    if(length==1) return arr[0];
    if(arr[length-2] <arr[length-1]){
        arr[length-2] =arr[length-1];
    }
    return findMax(arr,length-1);
}

bool isPalindrome(string str){
    int len =str.length();
    if(len==0 || len==1) return true;
    if(str[0]==' ') return isPalindrome(str.substr(1));
    if(str[len-1]==' ') return isPalindrome(str.substr(0,len-1));
    if(str[0] != str[len-1]) return false;
    else return isPalindrome(str.substr(1,len-2));
    return true;
}

void printPattern(int n) 
{
    
    if(n<=0){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    printPattern(n-5);
    cout<<" "<<n;
}


int myArrayToInt(char *str, int n) 
{ 
   string charAsTring(1,str[0]);
   int a= stoi(charAsTring);
   if(n==1) return a;
   return a* pow(10,n-1) + myArrayToInt(str+1,n-1);    
}
int findLCM(int a, int b)

{
    return (a*b)/ findGCD(a,b);
}


// BÀI 11
void count(string s){
    if(s == "") return; // chuỗi rỗng

    if(k.empty()) k.push(s[0]);
    //! nếu phần từ đàu là ) và phần tử cuối stack là ( thì loại bỏ ra khỏi stack
    else if(s[0]== ')' && k.top() == '(') k.pop();
    else k.push(s[0]);
    count(s.substr(1));
}
void clear(){
    if(k.empty()) return;
    k.pop();
    clear();
}   
int mininumBracketAdd(string s) {
    if(s=="") return 0;
    count(s);
    int i =k.size();
    clear();
    return i;
}


// BÀI 12
string reverseSentence(string s) {
    // STUDENT ANSWER
   int len = s.length();
   if(len <=1) return s;
   int l = s.find(" ");   // tìm vị trí của khoảng trắng bên trái
   if (l == -1) return s;  // không tìm thấy khoảng trắng
   string left = s.substr(0,l);
   

   int r = s.rfind(" ");
   string right = s.substr(r+1);
   if(l==r) return right + " " + left;  // trường hợp chỉ còn 1 khoảng trắng thì l==r
   string mid = reverseSentence(s.substr(l+1,r-l-1));
   return right + " " + mid + " " + left;

}

// BÀI 13
int strLen(char* str)     
{ 
    if(str[0]=='\0') return 0;
    return 1 + strLen(str+1);
}

string expand(string s) {
//! Đây là trường hợp cơ bản của đệ quy. Nếu chuỗi đầu vào rỗng, hàm trả về một chuỗi rỗng.
    if(s.length()==0){
        return "";
    }
    else if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
        return s[0]+expand(s.substr(1));
    }
//! 
    else if(s[0]>='2'&&s[0]<='9'){
        if(s[1]=='('){
            s[0]--;
            string x=expand('1'+s.substr(2));
            return x+expand(s[0]+s.substr(2))+expand(s.substr(1));

        }
        else{
            s[0]--;
            return expand('1'+s.substr(1))+expand(s);
        }
    }
    else if(s[0]=='1'){
        if(s[1]=='('){
            string x=expand(s.substr(2));
            return x+expand(s.substr(x.length()+3));
        }
        else{
            return expand(s.substr(1));
        }
    }
    else if(s[0]=='0'){
        return expand(s.substr(2+expand(s.substr(2)).length()));
    }
    else if(s[0]==')'){
        return "";
    }
    else if(s[0]=='('){
        int x=expand(','+s.substr(1)).length();

        return expand(s.substr(x+2));
    }
    else{
        if(s[1]=='('){
            string x=expand(','+s.substr(2));
            return "aa"+x+expand(','+s.substr(x.length()+3));
        }
        else if(s[1]==')'){
            return "";
        }
        else{
            return 'a'+expand(','+s.substr(2));
        }

    }
}





int main() {
    
}


// "2(ab3(cde)x)" changes into "abcdecdecdexabcdecdecdex".