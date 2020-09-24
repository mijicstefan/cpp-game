#include "sprite.h"

Sprite::Sprite(SpriteSheet *sheet, int width, int height) : Drawable(), Movable() {
    state = Sprite::STOP;
    speed=1;
    this->sheet = sheet;
    currentFrame = 0;
    frameCounter = 0;
    frameSkip = 1;

    spriteRect = new SDL_Rect();
    spriteRect->x = 0;
    spriteRect->y = 0;
    spriteRect->w = width;
    spriteRect->h = height;
}

int Sprite::getFrameSkip() {
    return frameSkip;
}

void Sprite::setFrameSkip(int frameSkip) {
    if(frameSkip < 0) {
        frameSkip = 0;
    }

    this->frameSkip = frameSkip+1;
}

short int Sprite::getState() {
    return state;
}

void Sprite::setState(short int state) {
    this->state = state;
}

void Sprite::draw(SDL_Renderer *renderer) {
    if(state&LEFT) {
        sheet->drawFrame("walk_left", currentFrame, spriteRect, renderer);
    } else if(state&RIGHT) {
        sheet->drawFrame("walk_right", currentFrame, spriteRect, renderer);
    } else if(state&UP) {
        sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
    } else if(state&DOWN) {
        sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
    } else if(state == STOP) {
        sheet->drawFrame("walk_down", 0, spriteRect, renderer);
    }

    frameCounter++;
    if(frameCounter%frameSkip == 0) {
        currentFrame++;
        if(currentFrame >= 9) {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}

void Sprite::move(int dx, int dy) {
    spriteRect->x += dx*speed;
    spriteRect->y += dy*speed;
}

void Sprite::move() {
    if(state != 0) {
        if(state & 1) {
            move(-1, 0);
        }
        if(state & 2) {
            move(1, 0);
        }
        if(state & 4) {
            move(0, -1);
        }
        if(state & 8) {
            move(0, 1);
        }
    }
}
