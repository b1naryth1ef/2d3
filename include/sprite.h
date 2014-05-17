#pragma once

#include "global.h"
#include "render.h"
#include "tickable.h"
#include "util.h"
#include <vector>

class BaseSprite: public Renderable, public Tickable {
    public:
        ALLEGRO_BITMAP *img;
        BaseSprite (ALLEGRO_BITMAP *bmp);
        virtual bool render (ALLEGRO_DISPLAY *display);
        virtual bool tick ();
        int x, y;
};

class AnimatedSprite: public BaseSprite {
    private:
        std::vector<ALLEGRO_BITMAP *> frames;
        int num_frames, cur_frame;
        float fps;
        double last;
    public:
        // If true, this sprite will not continue animatino
        bool frozen;

        AnimatedSprite (ALLEGRO_BITMAP *bmp, float f);

        int getFps ();
        void setFps (int f);

        int findFrame (ALLEGRO_BITMAP *f);
        ALLEGRO_BITMAP *addFrame (int x, int y, int w, int h);
        void setFrame(int f);
        void rmvFrame(ALLEGRO_BITMAP *f);

        bool render (ALLEGRO_DISPLAY *display);
        virtual bool tick ();

        void nextFrame();
        ALLEGRO_BITMAP *getFrameAt(int id);
        ALLEGRO_BITMAP *getCurrentFrame();
};
