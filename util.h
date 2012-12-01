#ifndef UTIL_H_
#define UTIL_H_

#include <map>

struct Pos { //Handy struct for postional data
    float x, y, maxx, maxy;

    Pos ();
    Pos (float ix, float iy);
    Pos (float ix, float iy, float mx, float my);

    bool checkPos (float vx, float vy);

    void operator+= (float inc);
    void operator*= (float inc);
    void operator-= (float inc);
    void operator/= (float inc);

    bool operator== (Pos p2);
    bool operator> (Pos p2);
    bool operator<= (Pos p2);
    bool operator< (Pos p2);
    bool operator>= (Pos p2);

    bool addX(float v);
    bool addY(float v);

    bool multiX(float v);
    bool multiY(float v);

    bool divX(float v);
    bool divY(float v);

    Pos *copy();
};

struct Vector {
    float x, y, z;
};

#endif
