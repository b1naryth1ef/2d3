#ifndef RENDER_H
#define RENDER_H

#include "global.h"
#include "render.h"

class BaseSprite: public Renderable {
    public:
        bool renders (ALLEGRO_DISPLAY *display);
        virtual bool tick ();

};

#endif