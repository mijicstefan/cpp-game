#include "keyboardeventlistener.h"

void KeyboardEventListener::listen(SDL_Event &event) {
    if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        listen(event.key);
    }
}
