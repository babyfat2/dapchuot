#include "ClickMouse.h"

bool ClickMouse(int x, int y, int w, int h)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        int a,b;
        SDL_GetMouseState(&a,&b);
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if ((x<a)&&(a<w)&&(y<b)&&(b<h)) return true;
        }
    }
}

