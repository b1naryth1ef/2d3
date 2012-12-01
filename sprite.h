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
        std::vector<ALLEGRO_BITMAP *> frames;
        int num_frames, cur_frame, fps;
        double last;
    public:
        AnimatedSprite (ALLEGRO_BITMAP *bmp, int f);

        int getFps ();
        void setFps (int f);

        int findFrame (ALLEGRO_BITMAP *f);
        ALLEGRO_BITMAP *addFrame (int x, int y, int w, int h);
        void rmvFrame(ALLEGRO_BITMAP *f);

        bool renders (ALLEGRO_DISPLAY *display);
        bool tick ();

        void nextFrame();
        ALLEGRO_BITMAP *getFrameAt(int id);
        ALLEGRO_BITMAP *getCurrentFrame();
};

#endif