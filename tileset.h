#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include <iostream>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tile.h"

using namespace std;

/** \brief Klasa kojom se opisuje celokupan tileset.
 */
class Tileset {
private:
    map<char, Tile*> tileset;
    SDL_Texture *texture;
    SDL_Rect *dest;
public:
    /** \brief Konstruktor klase Tileset.
     *
     * Konstruisanje se vrši na osnovu ulaznog toka koji sadrži podatke o Tileset-u i renderera.
     * Renderer je neophodan u postupku kreiranja teksture.
     *
     * \param inputStream Ulazni tok na osnovu kojeg se konstruiše Tileset objekat.
     * \param renderer Renderer koji će biti upotrebljen za kreiranje teksture.
     *
     */
    Tileset(istream &inputStream, SDL_Renderer *renderer);
    /** \brief Metoda za iscrtavanje jednog elementa iz tileset-a.
     *
     * \param code Identifikator elementa kojeg treba iscrtati.
     * \param x X koordinata na kojoj element treba iscrtati.
     * \param y Y koordinata na kojoj element treba iscrtati.
     * \param renderer Renderer pomoću kojeg se element iscrtava.
     * \return void
     *
     */
    void drawTile(char code, int x, int y, SDL_Renderer *renderer);
};

#endif // TILESET_H_INCLUDED
