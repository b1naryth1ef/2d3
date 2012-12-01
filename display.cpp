#include "display.h"


void Display::Init (int w, int h) {
    closed = false;
    size_w = w;
    size_h = h;
    display = al_create_display(w, h);
    bgcolor = al_map_rgb(0, 0, 0);
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
    strncpy(t, title, 50);
    al_set_window_title(display, t);
}

char *Display::getTitle () {
    return title;
}

void Display::del () {
    al_destroy_display(display);
}

void Display::setBackgroundColor(ALLEGRO_COLOR c){
    bgcolor = c;
}

int Display::getWidth() {
    return size_w;
}

int Display::getHeight() {
    return size_h;
}

void Display::render() {
    al_flip_display();
}

bool Display::getClosed(){
    return closed;
}

bool Display::getActive() {
    return active;
}

void Display::renderEvents() {
    for (int i=0; i < renderables.size(); i++) {
        if (!renderables[i]->renders(display)) {
            printf("A render failed for Renderable w/ id #%d\n", i);
        }
    }
}

int Display::addRenderable(Renderable *r) {
    renderables.push_back(r);
    return renderables.size()-1; //Should be ID
}

bool Display::rmvRenderable(int id) {
    if (id >= renderables.size()) return false;
    renderables[id] = NULL;
    return true;
}

bool Display::rmvRenderable(Renderable *r) {
    return rmvRenderable(r->id);
}
