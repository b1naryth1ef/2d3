#ifndef RENDER_H
#define RENDER_H

#include "global.h"

int addGlobalImage ();
void rmvGlobalImage ();

class Renderable {
    private:
        bool active;
        char name;
    public:
        int id;
        void setID(int i);
        bool isActive ();
        void setActive (bool i);
        // Overwriteables
        virtual bool renders (ALLEGRO_DISPLAY *display);
};

class TestRenderable: public Renderable {
    public:
        bool renders (ALLEGRO_DISPLAY *display);
};
#endif