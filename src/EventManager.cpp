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
/*
 Method to get an SDL input event.
 This method polls the SDL event queue, and returns
 the last event.
*/
Event EventManager::getKeyEvent()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        // check if x button, on window, is clicked
        if( e.type == SDL_QUIT )
        {
            return EXIT;
        }
        else
        {
            // only handle events if it is Key release
            if(e.key.type != SDL_KEYDOWN)
            {
                // get the SDL key code
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

}
