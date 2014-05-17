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
        double last;
    public:
        // Represents the rate the frames are iterated through
        float fps;

        // Num frames is the total number of frames, and cur_frame is the current
        //    frame number.
        int num_frames, cur_frame;

        // If true, this sprite will not continue animation
        bool frozen;

        AnimatedSprite (ALLEGRO_BITMAP *bmp, float f);

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
