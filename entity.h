#ifndef ENTITY_H
#define ENTITY_H

#include "global.h"
#include "tickable.h"
#include "sprite.h"

const cpFloat defaultMass = INFINITY;
const cpFloat defaultMoment = INFINITY;

class Entity: public Tickable {
    private:
        /* physics */
        cpFloat mass;
        cpFloat moment;
        cpBody *body;
        cpShape *shape;

        bool physicsEnabled;

        /* shared by constructors */
        void sharedInit(cpFloat m, cpFloat moi);

    public:
        BaseSprite *sprite;
        Entity ();
        Entity (cpFloat m, cpFloat i);
        ~Entity ();

        void disablePhysics();
        void enablePhysics(cpSpace *space);

        cpFloat getMass() { return mass; }
        cpFloat getMoment() { return moment; }

        bool setShape(cpShape *sh);

        void setSprite(BaseSprite *sp) { sprite = sp; }
};

#endif
