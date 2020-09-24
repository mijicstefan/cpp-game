#ifndef KEYBOARDEVENTLISTENER_H_INCLUDED
#define KEYBOARDEVENTLISTENER_H_INCLUDED

#include <SDL2/SDL.h>

#include "eventlistener.h"

class KeyboardEventListener : public EventListener {
    virtual void listen(SDL_Event &event);
    virtual void listen(SDL_KeyboardEvent &event)=0;
};

#endif // KEYBOARDEVENTLISTENER_H_INCLUDED
