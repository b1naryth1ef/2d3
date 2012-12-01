#include "tickable.h"

Tickable::Tickable (void) {
    active = false;
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