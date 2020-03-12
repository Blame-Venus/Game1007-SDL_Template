#include "Game.h"
#include <iostream>
#include <SDL_image.h>

Game::Game()
{
}

Game::Game(const char* windowName, int windowSizeX, int windowSizeY)
{
	int flags = SDL_INIT_EVERYTHING;

	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		// Create the window
		pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);

		if (pWindow != nullptr)
		{
			// Create the renderer
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

			if (pRenderer != nullptr)
			{
				IMG_Init(IMG_INIT_PNG);
			}
		}
	}
}

Game::~Game()
{
}

void Game::run()
{
	// load assets (sourced from https://opengameart.org/), credit goes to Kenny.nl
	shipBullet = new Bullet(pRenderer, "Assets/SpaceShooterRedux/PNG/Power-ups/pill_red.png", 10, 10, 500);
	asteroid = new Sprite(pRenderer, "Assets/SpaceShooterRedux/PNG/Meteors/meteorBrown_big1.png", 100, 100);
	ship = new Sprite(pRenderer, "Assets/SpaceShooterRedux/PNG/playerShip1_blue.png", 64, 64);
	background = new Sprite(pRenderer, "Assets/SpaceShooterRedux/Backgrounds/purple.png", 800, 600);

	//spriteManager.sprites.push_back(background);
	spriteManager.sprites.push_back(shipBullet);
	spriteManager.sprites.push_back(asteroid);
	spriteManager.sprites.push_back(ship);

	background->setPosition(0,0);
	ship->setPosition(400, 400);
	asteroid->setPosition(500, 200);



	isRunning = true;
	
	// set initial delta time
	deltaTime = 1.0f / targetFramerate;
	lastFrameStartTimeMs = SDL_GetTicks();

	while (isRunning)
	{
		input();
		update();
		draw();
		waitForNextFrame();
	}

	cleanup();
}

void Game::input()
{
	SDL_Event sdlEvent;

	float movementSpeed = 200;

	while (SDL_PollEvent(&sdlEvent))
	{
		std::cout << "spam" << std::endl;
		if (sdlEvent.type == SDL_KEYDOWN)
		{
			switch (sdlEvent.key.keysym.sym)
			{
			case(SDLK_SPACE):
			{
				shipBullet->dst.x = ship->dst.x;
				shipBullet->dst.y = ship->dst.y;
				break;
			}
			case(SDLK_LEFT):
			{
				break;
			}
			case(SDLK_RIGHT):
			{
				ship->dst.y += movementSpeed * deltaTime;
				break;
			}
			case(SDLK_UP):
			{
				ship->dst.x += movementSpeed * deltaTime;
				break;
			}
			case(SDLK_DOWN):
			{
				ship->dst.y -= movementSpeed * deltaTime;
				ship->dst.x -= movementSpeed * deltaTime;
				break;
			}

			case(SDLK_ESCAPE):
			{
				quit();
				break;
			}
			}
		}
		
	}
}

void Game::update()
{
	spriteManager.updateAll(deltaTime);

	if (ship->isCollidingWith(*asteroid))
	{
		std::cout << "more spam" << std::endl;
	}

	if (gameTime > 120)
	{
		quit();
	}
}

void Game::draw()
{
	SDL_SetRenderDrawColor(pRenderer, 255, 205, 90, 255);
	//SDL_RenderClear(pRenderer);
	
	spriteManager.drawAll();
	
	SDL_RenderPresent(pRenderer);
}

void Game::waitForNextFrame()
{
	Uint32 gameTimeMs = SDL_GetTicks();
	timeSinceLastFrame = gameTimeMs - lastFrameStartTimeMs;

	if (timeSinceLastFrame < frameDelayMs)
	{
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	frameEndTimeMs = SDL_GetTicks();
	deltaTime = (frameEndTimeMs - lastFrameStartTimeMs)/1000.f;
	gameTime = frameEndTimeMs / 1000.f;
	lastFrameStartTimeMs = frameEndTimeMs;
	std::cout << "spammity" << deltaTime << std::endl;
}

void Game::quit()
{
	isRunning = false;
}

void Game::cleanup()
{
	spriteManager.cleanup();
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	std::cout << "Goodbye World" << std::endl;
}
