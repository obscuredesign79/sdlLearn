//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
void init();

//Loads media
void loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The surface contained by the window
SDL_Surface *gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface *gHelloWorld = NULL;

void init()
{
	//Initialization flag
	//bool success = true;
	
	//Initialize SDL
	/*
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
	*/
		//Create window
		gWindow = SDL_CreateWindow("Ayan Image SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		/*
		if(gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
		*/
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			/*
		}
	}
	return success;
	*/
}


void loadMedia()
{
	//Loading success flag
	//bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("helloWorld2.bmp");
	/*
	if(gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "helloWorld2.bmp", SDL_GetError());
		success = false;
	}

	return success;
	*/
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);

	//Quit SDL subsystems
	SDL_Quit();
}
int main(int argc, char *args[])
{
	init();
	loadMedia();
	/*
	//Start up SDL and create window
	if(!init())
	{
		printf("Faliled to initialize!\n");
	}
	else
	{
		//Load media
		if(!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
		*/
		//Apply the image
		SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

		//Update the surface
		SDL_UpdateWindowSurface(gWindow);

		//Wait two seconds
		SDL_Delay(2000);
		/*
		}
	}
*/
	//Free resource and close SDL
	close();


	return 0;
}
