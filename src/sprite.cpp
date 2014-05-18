#include "sprite.h"

BaseSprite::BaseSprite (ALLEGRO_BITMAP *bmp) {
    img = bmp;
}

bool BaseSprite::render(ALLEGRO_DISPLAY *display) {
    return true;
}

bool BaseSprite::tick() {
    return true;
}

ALLEGRO_BITMAP *BaseSprite::getImage() {
    return img;
}

AnimatedSprite::AnimatedSprite (ALLEGRO_BITMAP *bmp, float f) : BaseSprite (bmp) {
    frozen = false;
    cur_frame = 0;
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

// bool AnimatedSprite::render(ALLEGRO_DISPLAY *display) {
//     al_draw_bitmap(getCurrentFrame(), pos->x, pos->y, 0);
//     return true;
// }

ALLEGRO_BITMAP *AnimatedSprite::getImage() {
    return getCurrentFrame();
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
    ALLEGRO_BITMAP *f = al_create_sub_bitmap(img, x, y, w, h);
    frames.push_back(f);
    return f;
}

void AnimatedSprite::rmvFrame (ALLEGRO_BITMAP *f) {
    frames.erase(frames.begin() + findFrame(f));
}

void AnimatedSprite::nextFrame() {
    if ((cur_frame + 1) >= frames.size()) {
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
    if (f > frames.size()) {
        throw GenericEngineError(
            UNDEFINED_INPUT,
            "Argument to AnimatedSprite.setFrame can not be more than number of frames. Is %i, max is %i.",
            f, frames.size());
    }
    cur_frame = f;
}
