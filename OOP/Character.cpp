#include <bits/stdc++.h>
using namespace std;

class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};





Character::Character() : hp(0), x(0), y(0) {}

Character::Character(int hp, int x, int y) : hp(hp), x(x), y(y) {
}

int Character::getHp() {
    return this->hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getX() {
    return this->x;
}

void Character::setX(int x) {
    this->x = x;
}

int Character::getY() {
    return this->y;
}

void Character::setY(int y) {
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    return abs(this->x - other->x) + abs(this->y - other->y);
}

int main() {

}
