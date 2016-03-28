#include "Home.h"

int main( int argc, char* args[] )
{
    Home home;

	//Start up SDL and create window
	if( !home.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !home.loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
		    home.display();
		}
	}

	//Free resources and close SDL
	home.close();

	return 0;
}
