#include "tileset.h"

Tileset::Tileset(istream &inputStream, SDL_Renderer *renderer) {
    string path;
    inputStream >> path;

    SDL_Surface *surface = IMG_Load(path.c_str());

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    while(!inputStream.eof()) {
        char code;
        inputStream >> code;
        tileset[code] = new Tile(inputStream);
    }
    dest = new SDL_Rect;
}

void Tileset::drawTile(char code, int x, int y, SDL_Renderer *renderer) {
    dest->x = x;
    dest->y = y;
    dest->w = tileset[code]->getRect()->w;
    dest->h = tileset[code]->getRect()->h;
    SDL_RenderCopy(renderer, texture, tileset[code]->getRect(), dest);
}
