#ifndef HOME_H
#define HOME_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

class Home
{
    public:
        Home();
        virtual ~Home();
        bool loadMedia();
        bool init();
        void close();
        void display();

    protected:

    private:
        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;

        //The surface contained by the window
        SDL_Surface* gScreenSurface = NULL;

        //The image we will load and show on the screen
        SDL_Surface* gXOut = NULL;
};

#endif // HOME_H
