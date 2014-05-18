#pragma once

#include "global.h"
#include "render.h"
#include "tickable.h"
#include "util.h"
#include <vector>

class BaseSprite: public Tickable {
    public:
        ALLEGRO_BITMAP *img;
        BaseSprite (ALLEGRO_BITMAP *bmp);
        virtual bool render (ALLEGRO_DISPLAY *display);
        virtual bool tick ();

        // getImage is used for rendering the sprite on screen by it's parent.
        //  this should always return the renderable bitmap region of the sprite.
        virtual ALLEGRO_BITMAP *getImage();
};

class AnimatedSprite: public BaseSprite {
    private:
        std::vector<ALLEGRO_BITMAP *> frames;
        double last;
    public:
        // Represents the rate the frames are iterated through
        float fps;

        // cur_frame is the current frame number.
        int cur_frame;

        // If true, this sprite will not continue animation
        bool frozen;

        AnimatedSprite (ALLEGRO_BITMAP *bmp, float f);

        int findFrame (ALLEGRO_BITMAP *f);
        ALLEGRO_BITMAP *addFrame (int x, int y, int w, int h);
        void setFrame(int f);
        void rmvFrame(ALLEGRO_BITMAP *f);

        //bool render (ALLEGRO_DISPLAY *display);
        virtual bool tick ();

        void nextFrame();
        ALLEGRO_BITMAP *getFrameAt(int id);
        ALLEGRO_BITMAP *getCurrentFrame();

        // getImage returns our current frame for this animated sprite.
        virtual ALLEGRO_BITMAP *getImage();
};
