#include "Home.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Home::Home()
{

}

Home::~Home()
{
    //dtor
}

bool Home::init()
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

bool Home::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gXOut = SDL_LoadBMP( "hello_world.bmp" );
	if( gXOut == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void Home::close()
{
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Home::display()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Apply the image
        SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
    }
}
