#include "spritesheet.h"

SpriteSheet::SpriteSheet(istream &inputStream, SDL_Renderer *renderer) {
    string path;
    string animation;
    int totalFrames;
    inputStream >> path;

    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    while(!inputStream.eof()) {
        inputStream >> animation;
        animations[animation] = Frames();

        inputStream >> totalFrames;
        for(int i = 0; i < totalFrames; i++) {
            animations[animation].push_back(new Frame(inputStream));
        }
    }
}

void SpriteSheet::drawFrame(string animation, int frame, SDL_Rect *dest, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, texture, animations[animation][frame]->getRect(), dest);
}
