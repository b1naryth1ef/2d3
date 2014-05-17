#include "util.h"

void DEBUG(const char* format, ...) {
    #ifndef ENABLE_DEBUG
    return;
    #endif

    printf("DEBUG: ");
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stdout, format, argptr);
    va_end(argptr);
    printf("\n");
}

void InputHolder::setInput(int k, bool down) {
    if (down) {
        setKeyDown(k);
    } else {
        setKeyUp(k);
    }
    if (binds.find(k) != binds.end()) {
        binds[k](k, down);
    }
}

InputState InputHolder::getKey (int k) {
    if (keys.find(k) != keys.end()) {
        return keys[k];
    } else {
        return UP;
    }
}

void InputHolder::bindKey(int k, void (*pointer)(int, bool)) {
    binds[k] = pointer;
}

void InputHolder::unbindKey(int k) {
    binds.erase(binds.find(k));
}

/*
    Binds a keyboard-character from A-Z 
*/
int InputHolder::bindChar(char k, void (*pointer)(int, bool)) {
    int index = 1;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == toupper(k)) {
            break;
        }
        index++;
    }

    // If the index is 0, this means we didnt find a match anywhere, (remember
    //    a == 1)
    if (index == 27) {
        throw GenericEngineError(
            INVALID_INPUT,
            "Character passed to bindChar must be from A-z (was: `%c`, %i)!", k, k);
    }

    // Pass the call on to bindKey and return the key-index
    this->bindKey(index, pointer);
    return index;
}

Pos::Pos () {
    x = 1;
    y = 1;
}

Pos::Pos (float ix, float iy) {
    x = ix;
    y = iy;
}

Pos::Pos (float ix, float iy, float mx, float my) {
    x = ix;
    y = iy;
    maxx = mx;
    maxy = my;
}

bool Pos::checkPos (float vx, float vy) {
    if (!maxx || !maxy) { return true; }
    if ((0 <= vx <= maxx) && (0 <= vy <= maxy)) {
        return true;
    }
    return false;
}

void Pos::operator+= (float inc) {
    addX(inc);
    addY(inc);
}

void Pos::operator*= (float inc) {
    multiX(inc);
    multiY(inc);
}

void Pos::operator-= (float inc) {
    addX(-1*inc);
    addY(-1*inc);
}

void Pos::operator/= (float inc) {
    divX(inc);
    divY(inc);
}

bool Pos::operator== (Pos p2) {
    return (p2.x == x && p2.y == y);
}

bool Pos::operator> (Pos p2) {
    return (x > p2.x && y > p2.y);
}

bool Pos::operator<= (Pos p2) {
    return (x <= p2.x && y <= p2.y);
}

bool Pos::operator< (Pos p2) {
    return (x < p2.x && y < p2.y);
}

bool Pos::operator>= (Pos p2) {
    return (x >= p2.x && y >= p2.y);
}


bool Pos::addX(float v) { 
    //if (!checkPos(x+v, y)) { return false; }
    x += v;
    return true;
}

bool Pos::addY(float v) { 
   // if (!checkPos(x, y+v)) { return false; }
    y += v;
    return true;
}

bool Pos::multiX(float v) {
    if (!checkPos(x*v, y)) { return false; }
    x *= v;
    return true;
}

bool Pos::multiY(float v) {
    if (!checkPos(x, y*v)) { return false; }
    y *= v;
    return true;
}

bool Pos::divX(float v) {
    if (!checkPos(x/v, y)) { return false; }
    x /= v;
    return true;
}

bool Pos::divY(float v) {
    if (!checkPos(x, y/v)) { return false; }
    x /= v;
    return true;
}

Pos *Pos::copy() {
    if (!maxx || !maxy) {
        return new Pos(x, y);
    } else {
        return new Pos(x, y, maxx, maxy);
    }
}