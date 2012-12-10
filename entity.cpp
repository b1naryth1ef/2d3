#include "entity.h"

void Entity::sharedInit(cpFloat m, cpFloat moi) {
    mass = defaultMass;
    moment = defaultMoment;
    body = cpBodyNew(mass, moment);
    shape = NULL;
    physicsEnabled = false;

    sprite = NULL;
}

Entity::Entity () {
    sharedInit(defaultMass, defaultMoment);
}

Entity::Entity (cpFloat m, cpFloat i) {
    sharedInit(m, i);
}

Entity::Entity(cpFloat m, cpFloat i, BaseSprite *s) {
    sharedInit(m, i);
    setSprite(s);

}

Entity::~Entity() {
    disablePhysics();
    if (shape) cpShapeFree(shape);
    if (body) cpBodyFree(body);
}

bool Entity::tick () { 
    bool v = sprite->tick();
    return true && v;
}

bool Entity::render (ALLEGRO_DISPLAY *display) {
    bool v = sprite->render(display);
    return true && v;
}

void Entity::disablePhysics() {
    cpSpace *space;

    if (shape) {
        space = cpShapeGetSpace(shape);
        if (space) cpSpaceRemoveShape(space, shape);
    }

    if (body) {
        space = cpBodyGetSpace(body);
        if (space) cpSpaceRemoveBody(space, body);
    }
}

void Entity::enablePhysics(cpSpace *space) {
    if (shape) cpSpaceAddShape(space, shape);
    if (body) cpSpaceAddBody(space, body);
}

bool Entity::setShape(cpShape *sh) {
    if (physicsEnabled || sh == NULL) return false;

    if (shape) cpShapeFree(shape);
    shape = sh;

    return true;
}
