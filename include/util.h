#pragma once

#include <map>
enum InputState {DOWN, UP};
typedef void (*fpointy)(int, bool);

class InputHolder {
    private:
        std::map<int, fpointy> binds;
        std::map<int, InputState> keys;

        void setKeyDown(int k) { keys[k] = DOWN; }
        void setKeyUp(int k) { keys[k] = UP; }

    public:
        void setInput(int k, bool down);
        InputState getKey(int k);

        void bindKey(int k, void (*pointer)(int, bool));
        void unbindKey(int k);
};

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
