#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int fibonacci(int n) {
    if(n==1) return 0;
    else if (n==2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);


}

int main(){
    cout << fibonacci(5);
    return 0;
}