// Create and run the Game class
// Joss Moo-Young
#include <iostream>
#include"Game.h"

Game myGame;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	myGame = Game("Hello Game Class", 800, 600);
	myGame.run();
	getchar();
	return 0;
}


/*
if (sdlEvent->type == SDL_KEYDOWN)
	{
		switch (sdlEvent->key.keysym.sym)
		{
		case SDLK_SPACE:
			myApp->audioMgr->stopAll();
			myApp->initializeGame();
			break;

		case SDLK_UP:
			myApp->transformCulling++;
			printf("Transform culling: %i", myApp->transformCulling);
			break;

		case SDLK_DOWN:
			myApp->transformCulling--;
			printf("Transform culling: %i", myApp->transformCulling);
			break;
		}
	}
*/