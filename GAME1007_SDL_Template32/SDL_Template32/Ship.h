#pragma once
#include "Sprite.h"
class Ship :
	public Sprite
{
public:
	
	Ship(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames = 1);
	~Ship();

	void update(float deltaTime) override;
	void tryShoot();

	// determine when you can shoot
	float shootInterval = 0.1; // time between shots
	float shootTimer = 0; // timer which
};

