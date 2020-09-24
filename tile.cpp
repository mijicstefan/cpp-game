#include "tile.h"

Tile::Tile(int x, int y, int w, int h) {
    tileRect = new SDL_Rect;
    tileRect->x = x;
    tileRect->y = y;
    tileRect->w = w;
    tileRect->h = h;
}

Tile::Tile(istream &inputStream) {
    int x, y, w, h;
    inputStream >> x >> y >> w >> h;
    tileRect = new SDL_Rect;
    tileRect->x = x;
    tileRect->y = y;
    tileRect->w = w;
    tileRect->h = h;
}

SDL_Rect* Tile::getRect() {
    return tileRect;
}

int Tile::x() {
    return tileRect->x;
}

int Tile::y() {
    return tileRect->y;
}

int Tile::w() {
    return tileRect->w;
}

int Tile::h() {
    return tileRect->h;
}

Tile::~Tile() {
    delete tileRect;
}
