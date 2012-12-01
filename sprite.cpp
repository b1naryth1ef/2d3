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


int AnimatedSprite::addFrame (int x, int y, int w, int h) {
    int id = getUID();
    frames[id] = al_create_sub_bitmap(img, x, y, w, h);
    return id;
}
void AnimatedSprite::rmvFrame (int index) {}

void AnimatedSprite::nextFrame() {
    if ((cur_frame+1) > num_frames) {
        cur_frame = 0;
    }
}
ALLEGRO_BITMAP *AnimatedSprite::getFrameAt(int index) {
    return frames[index];
}
ALLEGRO_BITMAP *AnimatedSprite::getCurrentFrame() {
    return frames[cur_frame];
}
