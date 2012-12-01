#ifndef SPRITE_H
#define SPRITE_H

#include "global.h"
#include "render.h"
#include "tickable.h"
#include "util.h"
#include <vector>

class BaseSprite: public Renderable, public Tickable {
    public:
        Pos *pos;
        ALLEGRO_BITMAP *img;
        BaseSprite (ALLEGRO_BITMAP *bmp);
        virtual bool renders (ALLEGRO_DISPLAY *display);
        virtual bool tick ();
};

class AnimatedSprite: public BaseSprite {
    private:
        std::vector<int> frames;
        int num_frames, cur_frame;
    public:
        int addFrame (int x, int y, int w, int h);
        void rmvFrame(int id);

        void nextFrame();
        ALLEGRO_BITMAP *getFrameAt(int id);
        ALLEGRO_BITMAP *getCurrentFrame();
};

#endif