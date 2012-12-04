#ifndef ENTITY_H
#define ENTITY_H

#include "global.h"
#include "tickable.h"
#include "sprite.h"

const cpFloat defaultMass = INFINITY;
const cpFloat defaultInertia = INFINITY;

class Entity: public Tickable {
    private:
        /* physics */
        cpFloat mass;
        cpFloat inertia;
        cpBody *body;
        cpShape *shape;

    public:
        BaseSprite *sprite;
        Entity ();
        Entity (cpFloat m, cpFloat i);
        ~Entity();

        cpFloat getInertia();
        cpFloat getMass();
};

#endif
