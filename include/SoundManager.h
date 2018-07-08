#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SDL.h>
#include <SDL_mixer.h>


class SoundManager
{
    public:
        SoundManager();
        virtual ~SoundManager();
        bool loadSound();
        void playButtonClick();
    protected:
        Mix_Chunk* btnSound = NULL;

    private:
};

#endif // SOUNDMANAGER_H
