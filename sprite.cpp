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
