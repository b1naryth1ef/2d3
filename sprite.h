#ifndef SPRITE_H
#define SPRITE_H

#include "global.h"
#include "render.h"
//#include "engine.h"

//class Renderable;

class BaseSprite: public Renderable {
    private:
        float x, y;
        ALLEGRO_BITMAP *img;
    public:
        BaseSprite (ALLEGRO_BITMAP *bmp);
        virtual bool renders (ALLEGRO_DISPLAY *display);
        virtual bool tick ();
};

#endif