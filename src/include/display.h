#pragma once

#include "global.h"
#include "render.h"
#include <vector>
#include <map>
#include <string>


#define DEFAULT_TITLE "2D3 -- Test Engine"

enum DisplayState {DACTIVE, DINACTIVE, DCLOSED};

class Display {
    private:
        void Init (int w, int h);
        DisplayState dstate;
        ALLEGRO_COLOR bgcolor;
        ALLEGRO_EVENT_QUEUE *queue;
        int size_w, size_h;   
        std::string title;
        std::vector<Renderable *> renderables;

    public:
        Display (int w, int h);
        Display (int w, int h, ALLEGRO_COLOR c);

        ALLEGRO_DISPLAY *display;
        bool closed, active;  

        std::string getTitle() {
            return title;
        }

        void setTitle(std::string t) {
            al_set_window_title(display, t.c_str());
            title = t;
        }

        int getWidth() { return size_w; }
        int getHeight() { return size_h; }
        void setBackgroundColor(ALLEGRO_COLOR c) { bgcolor = c;}

        // Deletes the screen (cleaning things up)
        void del () {
            al_destroy_display(display);
        }

        // Renders the screen
        void render() {
            al_flip_display();
        }

        void tick();
        void renderEvents();

        //Engine State
        void setDisplayState (DisplayState s) { dstate = s; }
        DisplayState getDisplayState () { return dstate; }

        // Renderables
        int findRenderable(Renderable *r);
        void addRenderable(Renderable *r);
        void rmvRenderable(Renderable *r);
};
