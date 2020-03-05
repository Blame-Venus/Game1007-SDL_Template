#pragma once
#include <SDL.h>
#include "Sprite.h"

class Game
{
	// For framerate
	int FRAMERATE = 30;
	int FRAME_DELAY_MS = 1000/FRAMERATE;
	Uint32 frameEndTimeMs;
	Uint32 lastFrameStartTimeMs;
	Uint32 timeSinceLastFrame;

	// for gameplay
	float deltaTime;
	float gameTime = 0;

	// A pointer points to an object and is denoted by a "*" in declaration. So g_pWindow is a Pointer which *points* to an object of type SDL_Window
	SDL_Window* g_pWindow = nullptr;
	SDL_Renderer* g_pRenderer = nullptr;

	// to know when to quit
	bool isRunning;

public:
	Sprite ship;
	Sprite background;

	Game();
	Game(const char* windowName, int windowSizeX, int windowSizeY);
	~Game();

	void run();
	void input();
	void update();
	void draw();
	void waitForNextFrame();
	void quit();
	void cleanup();
};

