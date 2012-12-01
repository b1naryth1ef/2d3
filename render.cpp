#include "render.h"

Renderable::Renderable () {
    pos = new Pos(0, 0, size_x, size_y);
}

bool Renderable::renders (ALLEGRO_DISPLAY *display) {
    return true;
}

bool Renderable::isActive () { return active; }

void Renderable::setActive (bool i) { active = i; }


// Constructor
Text::Text (const char *t, ALLEGRO_FONT *f) : Renderable () {
    text = t;
    font = f;
    color = al_map_rgb(0, 0, 0);
}

Text::Text (const char *t, ALLEGRO_FONT *f, ALLEGRO_COLOR *c) : Renderable () {
    text = t;
    font = f;
    color = *c;
}

// Setters
void Text::setText(char *t) { text = t; }
void Text::setColor(ALLEGRO_COLOR *c) { color = *c; }
void Text::setFont(ALLEGRO_FONT *f) { font = f; }

// Getters
ALLEGRO_COLOR *Text::getColor() { return &color; }
ALLEGRO_FONT *Text::getFont() { return font; }
const char *Text::getText() { return text; }

bool Text::renders (ALLEGRO_DISPLAY *display) {
    al_draw_text(font, color, pos->x, pos->y, 0, text);
    return true;
}