#include "App.h"
#include <SDL.h>
#include <stdio.h>
#include "Log.h"

App::App()
{
    eventManager = new EventManager();
    soundManager = new SoundManager();
}

App::~App()
{
    //dtor
}

bool App::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)
    {
        Log::instance()->error("SDL_Init", SDL_GetError());
        success = false;
    }
    else
    {
        Log::instance()->info("App.cpp", "SDL Started successfully");
        //Create window
        window = SDL_CreateWindow( "Simple SDL 2 example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        if( window == NULL )
        {
            Log::instance()->error("SDL_CreateWindow", SDL_GetError());
            success = false;
        }
        else
        {
            Log::instance()->info("App.cpp", "Window created successfully");
            //Get window surface
            screen = SDL_GetWindowSurface( window );
        }
    }

    return success;

}

bool App::loadMedia()
{
    //Loading success flag
    bool success = true;

    // load images
    surfaceBlue = SDL_LoadBMP("C:/code_sources/sdl2/img/blue.bmp");
    surfaceGreen = SDL_LoadBMP("C:/code_sources/sdl2/img/green.bmp");
    surfaceRed = SDL_LoadBMP("C:/code_sources/sdl2/img/red.bmp");
    surfaceYellow = SDL_LoadBMP("C:/code_sources/sdl2/img/yellow.bmp");
    surfaceIntro = SDL_LoadBMP("C:/code_sources/sdl2/img/intro.bmp");
    surfaceCurrent = surfaceIntro;

    // check if there was an error loading the images
    if(surfaceBlue == NULL || surfaceRed == NULL || surfaceGreen == NULL || surfaceYellow == NULL || surfaceIntro == NULL)
    {
        Log::instance()->error("App", SDL_GetError() );
        success = false;
    }

    return success;
}

void App::close()
{

    //Deallocate surface
    SDL_FreeSurface( surfaceBlue );
    surfaceBlue = NULL;

    SDL_FreeSurface( surfaceGreen );
    surfaceGreen = NULL;

    SDL_FreeSurface( surfaceRed );
    surfaceRed = NULL;

    SDL_FreeSurface( surfaceYellow );
    surfaceYellow = NULL;

    SDL_FreeSurface( surfaceIntro );
    surfaceIntro = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    // release the event manager if it is not NULL
    if(eventManager != NULL)
    {
        delete eventManager;
        eventManager = NULL;
    }

    if(soundManager != NULL)
    {
        delete soundManager;
        soundManager = NULL;
    }

    Log::instance()->destroy();

    //Quit SDL subsystems
    SDL_Quit();

}

void App::handleEvent()
{

    // get last event from event manager
    eventCurrent = eventManager->getKeyEvent();



    // check and handle latest event
    switch (eventCurrent)
    {

        case ESCAPE:
            running = false;
            Log::instance()->info("App", "Esc key pressed");
            break;
        case EXIT:
            running = false;
            Log::instance()->info("App", "Exit key pressed");
            break;
        case UP:
            surfaceCurrent = surfaceYellow;
            Log::instance()->info("App", "Up key pressed");
            break;
        case LEFT:
            surfaceCurrent = surfaceBlue;
            Log::instance()->info("App", "Left key pressed");
            break;
        case RIGHT:
            surfaceCurrent = surfaceRed;
            Log::instance()->info("App", "Right key pressed");
            break;
        case DOWN:
            surfaceCurrent = surfaceGreen;
            Log::instance()->info("App", "Down key pressed");
            break;
        case SPACE:
            surfaceCurrent = surfaceIntro;
            Log::instance()->info("App", "Space key pressed");
            break;
    }
}

void App::loop()
{
    running = true;

    while ( running )
    {
        // handle the event in the queue;
        handleEvent();

        //Add the new Image to screen surface
        SDL_BlitSurface( surfaceCurrent, NULL, screen, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( window );

    }

}

void App::start()
{
    bool ready = true;

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );

        ready = false;
    }

    if(! loadMedia() )
    {
        printf( "Failed to load media!\n" );

        ready = false;
    }

    if(ready)
    {
        loop();
    }
    else
    {
        printf( "Could not start App!" );
    }

    //Free resources and close SDL
    close();
}

