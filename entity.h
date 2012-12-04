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



    public:
        BaseSprite *sprite;
        Entity ();
        Entity (cpFloat mass, cpFloat inertia);

        cpFloat getInertia();
        cpFloat getMass();
};

#endif
