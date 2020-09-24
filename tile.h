#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

/** \brief Omotač klasa oko SDL_Rect strukture. Služi za opis pojedinačnog dela tileset-a.
 */
class Tile {
private:
    SDL_Rect *tileRect;
public:
    /** \brief Konstruktor klase Tile.
     *
     * \param x X koordinata pravougaonika.
     * \param y Y koordinata pravougaonika.
     * \param w Širina pravougaonika.
     * \param h Visina pravougaonika.
     *
     */
    Tile(int x, int y, int w, int h);
    /** \brief Konstruktor klase Tile.
     *
     * \param inputStream Ulazni tok na osnovu kojeg se konstruiše objekat.
     *
     */
    Tile(istream &inputStream);
    /** \brief Metoda za dobavljanje SDL_Rect strukture.
     *
     * \return Pokazivač na instancu SDL_Rect strukture.
     *
     */
    SDL_Rect* getRect();
    /** \brief Metoda za dobavljanje x koordinate pravougaonika.
     *
     * \return X koordinata pravougaonika.
     *
     */
    int x();
    /** \brief Metoda za dobavljanje y koordinate pravougaonika.
     *
     * \return Y koordinata pravougaonika.
     *
     */
    int y();
    /** \brief Metoda za dobavljanje širine pravougaonika.
     *
     * \return Širina pravougaonika.
     *
     */
    int w();
    /** \brief Metoda za dobavljanje visine pravougaonika.
     *
     * \return Visina pravougaonika.
     *
     */
    int h();
    virtual ~Tile();
};

#endif // TILE_H_INCLUDED
