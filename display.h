#ifndef DISPLAY_H
#define DISPLAY_H

#include "global.h"
#include "render.h"
#include <vector> 

class Display {
    private:
        void Init (int w, int h);
        ALLEGRO_DISPLAY *display;
        ALLEGRO_COLOR bgcolor;
        ALLEGRO_EVENT_QUEUE *queue;
        int size_w, size_h;
        std::vector<Renderable *> renderables;

    public:
        Display (int w, int h);
        Display (int w, int h, ALLEGRO_COLOR c);

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