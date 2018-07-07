#ifndef APP_H
#define APP_H
#include <SDL.h>
#include "EventManager.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class App
{
    public:
        App();
        virtual ~App();
        void start();
    protected:

        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;

        //The surface contained by the window
        SDL_Surface* gScreenSurface = NULL;

        // the current surface which should be drawn
        SDL_Surface* surfaceCurrent = NULL;

        // possible surfaces which can be drawn
        SDL_Surface* surfaceRed = NULL;
        SDL_Surface* surfaceBlue = NULL;
        SDL_Surface* surfaceGreen = NULL;
        SDL_Surface* surfaceYellow = NULL;
        SDL_Surface* surfaceIntro = NULL;

        EventManager* eventManager = NULL;

        bool init();
        bool loadMedia();
        void loop();
        void close();
    private:


};

#endif // APP_H
