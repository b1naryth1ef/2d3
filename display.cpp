#include "display.h"

void Display::Init (int w, int h) {
    size_w = w;
    size_h = h;
    display = al_create_display(w, h);
    bgcolor = al_map_rgb(0, 0, 0);
    queue = al_create_event_queue();
}

Display::Display (int w, int h) { Init(w, h); }
Display::Display (int w, int h, ALLEGRO_COLOR c) {
    Init(w, h);
    setBackgroundColor(c);
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

void Display::renderEvents() {}
