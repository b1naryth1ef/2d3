#ifndef SPRITE_H
#define SPRITE_H

#include "global.h"
#include "render.h"
#include "tickable.h"
#include "util.h"

class BaseSprite: public Renderable, public Tickable {
    private:
        Pos *pos;
        ALLEGRO_BITMAP *img;
    public:
        BaseSprite (ALLEGRO_BITMAP *bmp);
        virtual bool renders (ALLEGRO_DISPLAY *display);
        virtual bool tick ();
};

#endif