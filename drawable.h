#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include <SDL2/sdl.h>

/** \brief Klasa koja opisuje sve objekte koji se mogu iscrtati.
 */
class Drawable {
    public:
    /** \brief Metoda koju moraju implementirati sve klase koje nasledjuju Drawable. U ovoj metodi se navodi postupak iscrtavanja.
     *
     * \param renderer Renderer koji će vršiti iscrtavanje.
     * \return void
     *
     */
    virtual void draw(SDL_Renderer * renderer)=0;
};

#endif // DRAWABLE_H_INCLUDED
