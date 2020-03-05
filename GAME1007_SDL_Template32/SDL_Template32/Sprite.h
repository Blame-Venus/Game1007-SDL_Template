#pragma once
#include<SDL_image.h>

class Sprite
{
	SDL_Texture* g_pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;
	float velX = 0;
	float velY = 0;

	Sprite();
	Sprite(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY);
	~Sprite();

	void cleanup();
	void setPosition(int x, int y);
	void setSize(int x, int y);
	void draw(SDL_Renderer* renderer);
};

