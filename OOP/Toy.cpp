#include <bits/stdc++.h>
using namespace std;


enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }
    //Toy(){}

    virtual void printType() = 0;
    friend class ToyBox;   // cho phép ToyBox truy cập đến tất cả thành viên trong Toy
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price) , color(color){}

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price) , size(size) {}

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox() : numberOfItems(0)
    {
        for(int i= 0 ;i<5;i++) this->toyBox[i] = nullptr;
    }
    
    int addItem(const CarToy& carToy)
    {
        if(numberOfItems == 5) return -1;
        for(int i=0 ;i<5;i++){
            if(this->toyBox[i] == nullptr){
                toyBox[i] = new CarToy(carToy); //! ////////////////////////////////////////////
                numberOfItems++;
                break;
            }
        }
        return this->numberOfItems;
    }
    
    int addItem(const PuzzleToy& puzzleToy)
    {
        if(numberOfItems == 5 ) return -1;
        for(int i=0 ;i <5;i++){
            if(this->toyBox[i] == nullptr){
                toyBox[i] = new PuzzleToy(puzzleToy);
                numberOfItems++;
                break;
            }
        }
        return numberOfItems;
    }
    
    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }
};

int main(){
    CarToy car(20000,red);
    PuzzleToy puzzle(30000,small);

ToyBox box;
box.addItem(car);
box.addItem(puzzle);
box.printBox();
}