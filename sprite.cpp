#include "sprite.h"

BaseSprite::BaseSprite (ALLEGRO_BITMAP *bmp) {
    img = bmp;
    pos = new Pos (0, 0);
}

bool BaseSprite::renders(ALLEGRO_DISPLAY *display) {
    al_draw_bitmap(img, pos->x, pos->y, 0);
    return true;
}

bool BaseSprite::tick() {
    pos->addX(.01);
    pos->addY(.01);
    return true;
}

AnimatedSprite::AnimatedSprite (ALLEGRO_BITMAP *bmp, float f) : BaseSprite (bmp) { 
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

bool AnimatedSprite::renders(ALLEGRO_DISPLAY *display) {
    al_draw_bitmap(getCurrentFrame(), pos->x, pos->y, 0);
    return true;
}

bool AnimatedSprite::tick() {
    if ((al_get_time()-last) > fps) {
        nextFrame();
        last = al_get_time();
    }
    return true;
}

ALLEGRO_BITMAP *AnimatedSprite::addFrame (int x, int y, int w, int h) {
    num_frames += 1;
    ALLEGRO_BITMAP *f = al_create_sub_bitmap(img, x, y, w, h);
    frames.push_back(f);
    return f;
}

void AnimatedSprite::rmvFrame (ALLEGRO_BITMAP *f) {
    num_frames -= 1;
    frames.erase(frames.begin()+findFrame(f));
}

void AnimatedSprite::nextFrame() {
    if ((cur_frame+1) >= num_frames) {
        cur_frame = 0;
    } else {
        ++cur_frame;
    }
}
ALLEGRO_BITMAP *AnimatedSprite::getFrameAt(int index) {
    return frames[index];
}
ALLEGRO_BITMAP *AnimatedSprite::getCurrentFrame() {
    return frames[cur_frame];
}

void AnimatedSprite::setFps(int f) { fps = f; }

int AnimatedSprite::getFps() { return fps; }
