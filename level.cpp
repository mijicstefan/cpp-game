#include "level.h"

Level::Level(istream &inputStream, Tileset *tileset) : Drawable() {
    this->tileset = tileset;
    int h, w;
    char tileCode;
    inputStream >> h >> w;
    for(int i = 0; i < h; i++) {
        level.push_back(LevelRow());
        for(int j = 0; j < w; j++) {
            inputStream >> tileCode;
            level[i].push_back(tileCode);
        }
    }
}

void Level::draw(SDL_Renderer * renderer) {
    for(size_t i = 0; i < level.size(); i++) {
        for(size_t j = 0; j < level[i].size(); j++) {
            tileset->drawTile(level[i][j], j*32, i*32, renderer);
        }
    }
}

const Level::LevelMatrix& Level::getLevelMatrix() const {
    return level;
}

Level::~Level() {
    delete tileset;
}
