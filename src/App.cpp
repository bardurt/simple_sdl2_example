#include "App.h"
#include <SDL.h>
#include <stdio.h>
App::App()
{
    eventManager = new EventManager();
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
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;

}

bool App::loadMedia()
{
    //Loading success flag
    bool success = true;

    surfaceBlue = SDL_LoadBMP("C:/code_sources/sdl2/img/blue.bmp");
    surfaceGreen = SDL_LoadBMP("C:/code_sources/sdl2/img/green.bmp");
    surfaceRed = SDL_LoadBMP("C:/code_sources/sdl2/img/red.bmp");
    surfaceYellow = SDL_LoadBMP("C:/code_sources/sdl2/img/yellow.bmp");
    surfaceIntro = SDL_LoadBMP("C:/code_sources/sdl2/img/intro.bmp");
    surfaceCurrent = surfaceIntro;

    if(surfaceBlue == NULL || surfaceRed == NULL || surfaceGreen == NULL || surfaceYellow == NULL || surfaceIntro == NULL)
    {
        printf( "Error loading images ", SDL_GetError() );
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
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();

    // release the event manager if it is not NULL
    if(eventManager != NULL)
    {
        delete eventManager;
        eventManager = NULL;
    }

}

void App::loop()
{
    bool quit = false;

    Event e;

    while ( !quit )
    {
        // get last event from event manager
        e = eventManager->getKeyEvent();

        // check if ESC is pressed
        switch (e)
        {
            case ESCAPE:
                quit = true;
                break;
            case EXIT:
                quit = true;
                break;
            case UP:
                surfaceCurrent = surfaceYellow;
                break;
            case LEFT:
                surfaceCurrent = surfaceBlue;
                break;
            case RIGHT:
                surfaceCurrent = surfaceRed;
                break;
            case DOWN:
                surfaceCurrent = surfaceGreen;
                break;
            case SPACE:
                surfaceCurrent = surfaceIntro;
                break;
        }

        //Apply the image
        SDL_BlitSurface( surfaceCurrent, NULL, gScreenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );

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
    //Load media
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

