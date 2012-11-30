#ifndef DISPLAY_H
#define DISPLAY_H

#include "global.h"
#include "render.h"
//#include "engine.h"
#include <vector> 

class Display {
    private:
        void Init (int w, int h);
        ALLEGRO_DISPLAY *display;
        ALLEGRO_COLOR bgcolor;
        int size_w, size_h;     
        std::vector<Renderable *> renderables;

    public:
        bool closed, active;
        Display (int w, int h);
        Display (int w, int h, ALLEGRO_COLOR c);

        //void tick (Game g) {}
        ALLEGRO_DISPLAY* getDisplay();
        bool getClosed ();
        bool getActive ();
        void del ();
        void setBackgroundColor(ALLEGRO_COLOR c);
        int getWidth();
        int getHeight();
        void render();
        void renderEvents();
        // void displayTick();

        int addRenderable(Renderable *r);
        bool rmvRenderable(int id);
        bool rmvRenderable(Renderable *r);
};

#endif