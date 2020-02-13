// Displays a ship on screen
// Joss Moo-Young

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

// A pointer points to an object and is denoted by a "*" in declaration. So g_pWindow is a Pointer which *points* to an object of type SDL_Window
SDL_Window* g_pWindow = nullptr;
SDL_Renderer* g_pRenderer = nullptr;
SDL_Texture* g_pSpriteTex = nullptr;

SDL_Rect src;
SDL_Rect dst;

void draw(SDL_Renderer* renderer)
{
	src.x = 0;
	src.y = 0;
	src.w = 154;
	src.h = 221;

	dst.x = 100;
	dst.y = 200;
	dst.w = src.w;
	dst.h = src.h;

	SDL_SetRenderDrawColor(renderer, 255, 205, 90, 255);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, g_pSpriteTex, &src, &dst);

	SDL_RenderPresent(renderer);
}

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	int flags = SDL_INIT_EVERYTHING;

	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		// Create the window
		g_pWindow = SDL_CreateWindow("Hello SDL, nice to meet you!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

		if (g_pWindow != nullptr)
		{
			// Create the renderer
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

			if (g_pRenderer != nullptr)
			{
				IMG_Init(IMG_INIT_PNG);
				g_pSpriteTex = IMG_LoadTexture(g_pRenderer, "ship.png");

				if (g_pSpriteTex == nullptr)
				{
					std::cout << "Could not load sprite!" << std::endl;
				}

				while (true)// the game loop (pretty bad)
				{
					draw(g_pRenderer);
					SDL_Delay(16); // delay 16 milliseconds
				}
			}
		}
	}

	std::cout << "Goodbye World" << std::endl;

	getchar();

	// clean up memory
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyTexture(g_pSpriteTex);

	return 0;
}