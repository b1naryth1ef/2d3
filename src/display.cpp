#include "display.h"
#include <string>

/*
    This file handles functions related to the display class
*/

/*
    Loads a new display  
*/
void Display::Init (int w, int h) {
    active = false;
    closed = false;
    size_w = w;
    size_h = h;
    queue = al_create_event_queue();
    display = al_create_display(w, h);
    bgcolor = al_map_rgb(255, 255, 255);
    al_register_event_source(queue, al_get_display_event_source(display));
}

/*
    Constructor Methods
*/
Display::Display (int w, int h) { Init(w, h); }
Display::Display (int w, int h, ALLEGRO_COLOR c) {
    Init(w, h);
    setBackgroundColor(c);
}

/*
    This function handles clearing the screen and drawing all the renderable
    objects on screen in order.

    TOOD: add priority to renderables
*/
void Display::renderEvents() {
    al_clear_to_color(bgcolor);
    for (int i=0; i < renderables.size(); i++) {
        renderables[i]->renders(display);
    }
}

/*
    This function handles "ticking" the display. This mostly entails handling
    events passed in by allegro, which is done in a batch way, allowing for
    long pauses inbetween ticks without too much weird behaivor.
*/
void Display::tick () {
    ALLEGRO_EVENT ev;
    while (!al_is_event_queue_empty(queue)) {
        al_get_next_event(queue, &ev);
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                DEBUG("Display was closed");
                setDisplayState(DCLOSED);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                if (getDisplayState() != DINACTIVE) {
                    DEBUG("Lost display focus");
                    setDisplayState(DINACTIVE);
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                if (getDisplayState() != DACTIVE) {
                    DEBUG("Gained display focus");
                    setDisplayState(DACTIVE);
                }
                break; 
        }
    }
}

void Display::addRenderable(Renderable *r) { renderables.push_back(r); }
void Display::rmvRenderable(Renderable *r) { renderables.erase(renderables.begin()+findRenderable(r)); }

int Display::findRenderable(Renderable *r) {
    for (int i=0; i < renderables.size(); i++) {
        if (renderables[i] == r) {
            return i;
        }
    }
    return -1;
}



