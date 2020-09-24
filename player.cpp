#include "player.h"

Player::Player(Sprite *sprite) : Drawable(), Movable(), KeyboardEventListener() {
    this->sprite = sprite;

}

void Player::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void Player::move() {
    sprite->move();
}

void Player::move(int dx, int dy) {
    sprite->move(dx, dy);
}

void Player::listen(SDL_KeyboardEvent &event) {
    if(event.type == SDL_KEYDOWN) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()|Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()|Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()|Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()|Sprite::DOWN);
        }
    } else if (event.type == SDL_KEYUP) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()&~Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()&~Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()&~Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()&~Sprite::DOWN);
        }
    }

}
