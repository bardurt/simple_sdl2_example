#include "EventManager.h"
#include <SDL.h>

EventManager::EventManager()
{
    //ctor
}

EventManager::~EventManager()
{
    //dtor
}

Event EventManager::getKeyEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {

        if( e.type == SDL_QUIT )
        {
            return EXIT;
        }
        else
        {
            switch (e.key.keysym.sym)
            {
                case SDLK_SPACE:
                    return SPACE;
                case SDLK_ESCAPE:
                    return ESCAPE;
                case SDLK_UP:
                    return UP;
                case SDLK_DOWN:
                    return DOWN;
                case SDLK_LEFT:
                    return LEFT;
                case SDLK_RIGHT:
                    return RIGHT;
                default:
                    return NONE;
            }
        }
    }

}
