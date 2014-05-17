#include "sprite.h"

BaseSprite::BaseSprite (ALLEGRO_BITMAP *bmp) {
    img = bmp;
    x = 1;
    y = 1;
}

bool BaseSprite::render(ALLEGRO_DISPLAY *display) {
    al_draw_bitmap(img, pos->x, pos->y, 0);
    return true;
}

bool BaseSprite::tick() {
    return true;
}

AnimatedSprite::AnimatedSprite (ALLEGRO_BITMAP *bmp, float f) : BaseSprite (bmp) {
    frozen = false;
    cur_frame = 0;
    num_frames = 0;
    fps = f;
    last = al_get_time();
}

int AnimatedSprite::findFrame (ALLEGRO_BITMAP *f) {
    for (int i=0; i < frames.size(); i++) {
        if (frames[i] == f) {
            return i;
        }
    }
    return -1;
}

bool AnimatedSprite::render(ALLEGRO_DISPLAY *display) {
    al_draw_bitmap(getCurrentFrame(), pos->x, pos->y, 0);
    return true;
}

bool AnimatedSprite::tick() {
    // If we're frozen, don't bother animation
    if (this->frozen) { return true; }

    if ((al_get_time()-last) > fps) {
        nextFrame();
        last = al_get_time();
    }
    return true;
}

ALLEGRO_BITMAP *AnimatedSprite::addFrame (int x, int y, int w, int h) {
    num_frames++;
    ALLEGRO_BITMAP *f = al_create_sub_bitmap(img, x, y, w, h);
    frames.push_back(f);
    return f;
}

void AnimatedSprite::rmvFrame (ALLEGRO_BITMAP *f) {
    num_frames -= 1;
    frames.erase(frames.begin() + findFrame(f));
}

void AnimatedSprite::nextFrame() {
    if ((cur_frame + 1) >= num_frames) {
        cur_frame = 0;
    } else {
        cur_frame++;
    }
}

ALLEGRO_BITMAP *AnimatedSprite::getFrameAt(int index) {
    return frames[index];
}

ALLEGRO_BITMAP *AnimatedSprite::getCurrentFrame() {
    return frames[cur_frame];
}

void AnimatedSprite::setFrame(int f) {
    if (f > num_frames) {
        throw GenericEngineError(
            UNDEFINED_INPUT,
            "Argument to AnimatedSprite.setFrame can not be more than number of frames. Is %i, max is %i.",
            f, num_frames);
    }
    cur_frame = f;
}
