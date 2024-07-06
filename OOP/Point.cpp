#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(){
        this -> x = 0;
        this -> y = 0;
    }

    Point(double x, double y)
    {
        this -> x = x;
        this -> y = y;
    }

    void setX(double x)
    {
        this -> x = x;
    }

    void setY(double y)
    {
        this -> y = y;
    }

    double getX() const
    {
        return this->x;
    }

    double getY() const
    {
        return this->y;
    }

    double distanceToPoint(const Point& pointA)
    {
        return sqrt(pow(pointA.x - this->x, 2) + pow(pointA.y - this->y, 2));
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle() : radius(0) {
        this->center.setX(0);
        this->center.setY(0);
    }

    Circle(Point center, double radius) : center(center), radius(radius)
    {
    }

    Circle(const Circle &circle)
    {
        this->center = circle.center;
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        this->center = point;
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    Point getCenter() const
    {
        return this->center;
    }

    double getRadius() const
    {
        return this->radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};


int main() {

}
