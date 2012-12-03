#include "tickable.h"

Tickable::Tickable (void) {
    active = true;
}

bool Tickable::ticks () {
    if (active) {
        return tick();
    } else {
        return false;
    }
}

bool Tickable::tick () {
    return true;
}

bool Tickable::getActive() {
    return active;
}

void Tickable::setActive(bool v) {
    active = v;
}