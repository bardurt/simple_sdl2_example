#ifndef APP_H
#define APP_H
#include <SDL.h>
#include "EventManager.h"
#include "SoundManager.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*
 Main program class which will use SDL Library
*/
class App
{
    public:
        App();
        virtual ~App();
        void start();

    protected:

        //Flag to show that the app should loop
        bool running;

        //Keyboard event
        Event eventCurrent;

        //The window we'll be rendering to
        SDL_Window* window = NULL;

        //The surface contained by the window
        SDL_Surface* screen = NULL;

        // the current surface which should be drawn
        SDL_Surface* surfaceCurrent = NULL;

        // possible surfaces which can be drawn
        SDL_Surface* surfaceRed = NULL;
        SDL_Surface* surfaceBlue = NULL;
        SDL_Surface* surfaceGreen = NULL;
        SDL_Surface* surfaceYellow = NULL;
        SDL_Surface* surfaceIntro = NULL;

        // Manager for handling button events
        EventManager* eventManager = NULL;

        SoundManager* soundManager = NULL;

        bool init();
        bool loadMedia();
        void handleEvent();
        void loop();
        void close();
    private:


};

#endif // APP_H
