#include "entity.h"

void Entity::sharedInit(cpFloat m, cpFloat moi) {
    mass = m;
    moment = moi;
    body = cpBodyNew(mass, moment);
    shape = NULL;
    physicsEnabled = false;

    sprite = NULL;
}

Entity::Entity () {
    sharedInit(10, 1);
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
    sprite->pos->x = body->p.x;
    sprite->pos->y = body->p.y;
    //printf("%f %f\n", body->p.x, body->p.y);
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
    printf("Enabled phsyics!\n");
    if (shape) cpSpaceAddShape(space, shape);
    if (body) cpSpaceAddBody(space, body);
}

bool Entity::setShape(cpShape *sh) {
    if (physicsEnabled || sh == NULL) return false;

    if (shape) cpShapeFree(shape);
    shape = sh;

    return true;
}

void Entity::applyImpulse(float x, float y) {
    const cpVect a = cpv(x, y);
    const cpVect b = cpv(0, 0);

    cpBodyApplyImpulse(body, a, b);
}