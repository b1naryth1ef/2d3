#include "display.h"


void Display::Init (int w, int h) {
    closed = false;
    size_w = w;
    size_h = h;
    display = al_create_display(w, h);
    bgcolor = al_map_rgb(255, 255, 255);
}

Display::Display (int w, int h) { Init(w, h); }
Display::Display (int w, int h, ALLEGRO_COLOR c) {
    Init(w, h);
    setBackgroundColor(c);
}

ALLEGRO_DISPLAY* Display::getDisplay() {
    return display;
}

void Display::setTitle (char t[50]) {
    strncpy(title, t, 50-1);
    title[50-1] = '\0';
    al_set_window_title(display, title);
}

char *Display::getTitle () { return title; }
void Display::del () { al_destroy_display(display); }
void Display::setBackgroundColor(ALLEGRO_COLOR c) { bgcolor = c; }
int Display::getWidth() { return size_w; }
int Display::getHeight() { return size_h; }
void Display::render() { al_flip_display(); }
bool Display::getClosed() { return closed; }
bool Display::getActive() { return active; }
void Display::setActive(bool v) { active = v; }
void Display::setClosed(bool v) { closed = v; }

void Display::renderEvents() {
    al_clear_to_color(bgcolor);
    for (int i=0; i < renderables.size(); i++) {
        if (!renderables[i]->renders(display)) {
            printf("A render failed for Renderable w/ id #%d\n", i);
        }
    }
}

int Display::findRenderable(Renderable *r) {
    for (int i=0; i < renderables.size(); i++) {
        if (renderables[i] == r) {
            return i;
        }
    }
    return -1;
}

void Display::addRenderable(Renderable *r) {
    renderables.push_back(r);
}

void Display::rmvRenderable(Renderable *r) {
    renderables.erase(renderables.begin()+findRenderable(r));
}

