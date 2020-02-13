#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


// A pointer points to an object and is denoted by a "*" in declaration. So g_pWindow is a Pointer which *points* to an object of type SDL_Window
SDL_Window* g_pWindow = nullptr;
SDL_Renderer* g_pRenderer = nullptr;
SDL_Texture* g_pSpriteTex;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	int flags = SDL_INIT_EVERYTHING;

	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		g_pWindow = SDL_CreateWindow("Hello SDL, nice to meet you!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

		if (g_pWindow != nullptr)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
			
			if (g_pRenderer != nullptr)
			{
				if (IMG_Init(IMG_INIT_PNG) == 0)
				{
					g_pSpriteTex = IMG_LoadTexture(g_pRenderer, "ship.png");
				}
			}
		}
	}

	std::cout << "Hello World" << std::endl;
	//getchar();
	//system("pause");
	int lol;
	std::cin >> lol;

	return 0;
}