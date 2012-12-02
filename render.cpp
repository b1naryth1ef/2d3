#include "render.h"

bool loadFont (int f, const char * name, int size) {
    if (FONTS.find(f) == FONTS.end()) { //Key doesnt exist
        FONTS[f] = al_load_font(name, size, 0);
        return true;
    } else {
        fprintf(stderr, "That font name (%d) already exists!\n", f);
        return false;
    }
}

bool unloadFont (int f) {
    if (FONTS.find(f) != FONTS.end()) {
        FONTS.erase(FONTS.find(f));
        return true;
    } else {
        fprintf(stderr, "That font name (%d) does not exist!\n", f);
        return false;
    }
}

ALLEGRO_FONT *getFont (int f) {
    if (FONTS.find(f) != FONTS.end()) {
        return FONTS[f];
    }
    return NULL;
}

Renderable::Renderable () {
    pos = new Pos(0, 0, size_x, size_y);
}

bool Renderable::renders (ALLEGRO_DISPLAY *display) {
    return true;
}

bool Renderable::isActive () { return active; }

void Renderable::setActive (bool i) { active = i; }


// Constructor
void Text::init (const char *t, ALLEGRO_FONT *f) {
    setTextType(CENTER);
    setText(t);
    setFont(f);
    color = al_map_rgb(0, 0, 0);
}

Text::Text (const char *t, int f) {
    init(t, ::getFont(f));
}

Text::Text (const char *t, ALLEGRO_FONT *f) : Renderable () {
    init(t, f);
}

Text::Text (const char *t, ALLEGRO_FONT *f, ALLEGRO_COLOR c) : Renderable () {
    align = CENTER;
    text = t;
    font = f;
    color = c;
}

// Setters
void Text::setText(const char *t) { text = t; }
void Text::setColor(ALLEGRO_COLOR c) { color = c; }
void Text::setFont(ALLEGRO_FONT *f) { font = f; }

// Getters
ALLEGRO_COLOR *Text::getColor() { return &color; }
ALLEGRO_FONT *Text::getFont() { return font; }
const char *Text::getText() { return text; }

bool Text::renders (ALLEGRO_DISPLAY *display) {
    int flags;
    if (align == CENTER) {
        flags = ALLEGRO_ALIGN_CENTRE;
    } else if (align == RIGHT) {
        flags = ALLEGRO_ALIGN_RIGHT;
    } else {
        flags = ALLEGRO_ALIGN_LEFT;
    }
    al_draw_text(font, color, pos->x, pos->y, flags, text);
    return true;
}

void Text::setTextType (TextType t) {
    align = t;
}
TextType Text::getTextType() {
    return align;
}