#ifndef SPRITESHEET_H_INCLUDED
#define SPRITESHEET_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tile.h"

using namespace std;

typedef Tile Frame;
typedef vector<Frame*> Frames;

class SpriteSheet {
private:
    SDL_Texture *texture;
    map<string, Frames> animations;
public:
    SpriteSheet(istream &inputStream, SDL_Renderer* renderer);
    void drawFrame(string animation, int frame, SDL_Rect *dest, SDL_Renderer *renderer);
};

#endif // SPRITESHEET_H_INCLUDED
