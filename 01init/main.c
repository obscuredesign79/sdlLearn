#include "SDL.h"
#include <stdio.h>

struct playerStruct
{
	int x, y;
	short life;
	char *name;
};

struct playerStruct player;

int main(int argc, char *argv[])
{
	SDL_Window *window;			//declare a window
	SDL_Renderer *renderer;		//declare a renderer

	SDL_Init(SDL_INIT_VIDEO);	//initialize SDL2

	//create an application window with the following settings:
	window = SDL_CreateWindow("Game Window",			//window title
							SDL_WINDOWPOS_UNDEFINED,	//initial x pos
							SDL_WINDOWPOS_UNDEFINED,	//initial y pos
							640,						//width pixels
							480,						//height pixels
							0							//flags
			);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	//clear the screen to blue
	SDL_RenderClear(renderer);

	//set the drawing color to ping because arvin is gay 
	SDL_SetRenderDrawColor(renderer, 220, 25, 170, 255);

	SDL_Rect rect = {220, 140, 200, 200};
	SDL_RenderFillRect(renderer, &rect);

	//we are done drawing, "present" or show to the screen what we've drawn
	SDL_RenderPresent(renderer);

	//wait a few second before quitting
	SDL_Delay(2000);

	//close and destroy the window
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);

	//clean up
	SDL_Quit();
	return 0;
}
