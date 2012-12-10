#ifndef ENTITY_H
#define ENTITY_H

#include "global.h"
#include "tickable.h"
#include "render.h"
#include "sprite.h"

const cpFloat defaultMass = INFINITY;
const cpFloat defaultMoment = INFINITY;

class Entity: public Tickable, public Renderable {
    private:
        // physics 
        cpFloat mass;
        cpFloat moment;
        cpBody *body;
        cpShape *shape;

        bool physicsEnabled;

        // shared by constructors
        void sharedInit(cpFloat m, cpFloat moi);

        // Overrides
        bool tick ();
        bool render (ALLEGRO_DISPLAY *display);

    public:
        BaseSprite *sprite;
        Entity ();
        Entity (cpFloat m, cpFloat i);
        Entity (cpFloat m, cpFloat i, BaseSprite *s);
        ~Entity ();

        void applyImpulse(float x, float y);

        void disablePhysics();
        void enablePhysics(cpSpace *space);

        cpFloat getMass() { return mass; }
        cpFloat getMoment() { return moment; }

        bool setShape(cpShape *sh);

        void setSprite(BaseSprite *sp) { sprite = sp; }
};

#endif
