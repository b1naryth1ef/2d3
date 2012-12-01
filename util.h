#ifndef UTIL_H
#define UTIL_H

struct Pos { //Handy struct for postional data
    float x, y;

    Pos ();
    Pos (float ix, float iy);

    void operator+= (float inc);
    Pos operator+ (Pos other);
    Pos operator+ (float inc);
    Pos operator- (Pos other);
    Pos operator- (float inc);
    Pos operator* (Pos other);
    Pos operator* (float inc);

    void setX(float v);
    void setY(float v);

    void addX(float v);
    void addY(float v);

};

struct Vector {
    float x, y, z;
};

#endif