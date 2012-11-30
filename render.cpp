#include "render.h"

void Renderable::setID (int i) {
    id = i;
}

bool Renderable::renders (ALLEGRO_DISPLAY *display) {
    return true;
}

bool Renderable::isActive () { return active; }

void Renderable::setActive (bool i) { active = i; }

bool TestRenderable::renders (ALLEGRO_DISPLAY *display) {
    printf("Render!\n");
    return true;
}