#ifndef DISPLAY_H
#define DISPLAY_H

#include "global.h"
#include "render.h"
#include <vector> 

#define DEFAULT_TITLE "2D3 -- Test Engine"

class Display {
    private:
        void Init (int w, int h);
        ALLEGRO_DISPLAY *display;
        ALLEGRO_COLOR bgcolor;
        int size_w, size_h;     
        char title [50];
        std::vector<Renderable *> renderables;

    public:
        bool closed, active;
        Display (int w, int h);
        Display (int w, int h, ALLEGRO_COLOR c);

        ALLEGRO_DISPLAY* getDisplay();
        void setTitle(char t[50]);
        char *getTitle();
        bool getClosed ();
        bool getActive ();
        void del ();
        void setBackgroundColor(ALLEGRO_COLOR c);
        int getWidth();
        int getHeight();
        void render();
        void renderEvents();

        int addRenderable(Renderable *r);
        bool rmvRenderable(int id);
        bool rmvRenderable(Renderable *r);
};

#endif