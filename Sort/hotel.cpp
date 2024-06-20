#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//* bài toán hotel 
int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {

    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    int i=0,j=0;
    int cnt=0;
    while(i<people.size() && j < rooms.size()){
        if (rooms[j]-k <= people[i] && people[i] <= rooms[j]+k){
            i++;
            j++;
            cnt++;
        }
        else if (rooms[j]-k > people[i]) i++;
        else if (rooms[j]+k < people[i]) j++;
    }
    return cnt;
}

string minDiffPairs(int* arr, int n){

   if (n<2) return "";
   sort(arr,arr+n);
   int Min = INT_MAX;
   for (int i=0;i<n-1;i++) if (Min > arr[i+1]-arr[i]) Min = arr[i+1]-arr[i];
   string s("");
   for (int i=0;i<n-1;i++){
       if (Min == arr[i+1]-arr[i]){ s+= "(" + to_string(arr[i]) + ", " + to_string(arr[i+1]) + ")" ;
       if (i <n-3) s+=", ";}
   }
    if (s.length() > 1) {
        s = s.substr(0, s.length() - 2);
    }
   return s;
}
string minDiffPairs(int* arr, int n) {
    string save = "";
    sort(arr, arr + n);
    int min = INT8_MAX;
    for (int i = 0; i < n - 1; i++) {
        int g = *(arr+i) ;
        int k = *(arr + i + 1);
        int a = abs(g-k);
        if (min > a) {
            min = a;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a = abs(*(arr + i) - *(arr + i + 1));
        if (a == min) {
            save = save + "(" + to_string(*(arr + i)) + ", " + to_string(*(arr + i + 1)) + "), ";
        }
    }
    if (save.length() > 1) {
        save = save.substr(0, save.length() - 2);
    }
    return save;
}
// // Calculate Euclidean distance between two points
// double calculateDistance(const Point& p1, const Point& p2) {
//     return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
// }

// // Compare function to sort points by distance from des_point
// void closestKPoints(Point points[], int n, Point &des_point, int k){
//     // Create a vector of points
//     vector<Point> pointVector(points, points + n);

//     // Sort the points based on distance from des_point
//     sort(pointVector.begin(), pointVector.end(), [des_point](const Point& p1, const Point& p2) {
//         return calculateDistance(p1, des_point) < calculateDistance(p2, des_point);
//     });

//     for (int i = 0; i < k && i < static_cast<int>(pointVector.size()); i++){
//             pointVector[i].display();
//             cout<<endl;
//     }
// }


int main(){
//     int k=5;
//     vector<int> people={30,60,75};
//     vector<int> rooms={57,45,80,65};
//     cout << maxNumberOfPeople(rooms, people, k) << '\n';
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout<<minDiffPairs(arr, 10);
}
