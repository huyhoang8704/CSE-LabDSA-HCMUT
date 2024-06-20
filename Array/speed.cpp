#include<iostream>
#include<vector>

using namespace std;

int steadySpeed(vector<int>& positions) {
    int len = positions.size();
//! tao ra vector chua abs cua 2 phan tu lien ke
    vector<int> v(len - 1,0);
    for(int i = 1; i < len; i++){ v[i-1] = abs(positions[i] - positions[i-1]);}
//! luu phan tu dau tien cua vector moi tao
    int tmp = v[0];
    int count = 1;
    int Max = 0;
    for(int i = 1;i < len - 1; i++){
//! giong thi cong count len
        if(tmp == v[i]) count ++;
        else {
//! luu phan tu count lon nhat
            Max = max(Max, count);
            count = 1;
            tmp = v[i];
        }
    }
    return max(Max, count) + 1;
}

int main(){
    vector<int>positions{5,4,3,5,4,5,1,3,5,3};
    cout << steadySpeed(positions);
//! 4
    cout<<endl;
    vector<int> positions1{0, 3, 6, 3, 0};
    cout << steadySpeed(positions1);
//! 5
}