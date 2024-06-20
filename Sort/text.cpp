#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

// Calculate Euclidean distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Compare function to sort points by distance from des_point
void closestKPoints(Point points[], int n, Point &des_point, int k){
    // Create a vector of points
    vector<Point> pointVector(points, points + n);

    // Sort the points based on distance from des_point
    sort(pointVector.begin(), pointVector.end(), [des_point](const Point& p1, const Point& p2) {
        return calculateDistance(p1, des_point) < calculateDistance(p2, des_point);
    });

    for (int i = 0; i < k && i < static_cast<int>(pointVector.size()); i++){
            pointVector[i].display();
            cout<<endl;
    }
}

int main() {
    Point points[] = {{3, 3},{5, -1},{-2, 4}};
int n = sizeof(points)/sizeof(points[0]);
int k = 2;
Point des_point = {0,2};
closestKPoints(points, n, des_point, k);
}
