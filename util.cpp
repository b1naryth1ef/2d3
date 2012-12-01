#include "util.h"

Pos::Pos () {
    x = 1;
    y = 1;
}
Pos::Pos (float ix, float iy) {
    x = ix;
    y = iy;
}

void Pos::operator+= (float inc) {
    addX(inc);
    addY(inc);
}

Pos Pos::operator+ (Pos other) {
    Pos n (x+other.x, y+other.y);
    return n;
}

Pos Pos::operator+ (float inc) {
    Pos n (x+inc, y+inc);
    return n;
}

Pos Pos::operator- (Pos other) {
    Pos n (x-other.x, y-other.y);
    return n;
}

Pos Pos::operator- (float inc) {
    Pos n (x-inc, y-inc);
    return n;
}

Pos Pos::operator* (Pos other) {
    Pos n (x*other.x, y*other.y);
    return n;
}

Pos Pos::operator* (float inc) {
    Pos n (x*inc, y*inc);
    return n;
}

void Pos::setX(float v) { this->x = v; }
void Pos::setY(float v) { this->y = v; }

void Pos::addX(float v) { this->x += v; }
void Pos::addY(float v) { this->y += v; }
