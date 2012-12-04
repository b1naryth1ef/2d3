#ifndef ENGINE_H
#define ENGINE_H

#include "global.h"
#include "tickable.h"
#include "sprite.h"

class Entity: public Tickable {
    public:
        BaseSprite *sprite;
        Entity ();
        Entity (cpFloat mass, cpFloat inhertia);
};

#endif