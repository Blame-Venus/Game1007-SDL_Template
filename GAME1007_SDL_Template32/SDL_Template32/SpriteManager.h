#pragma once
#include <vector>
#include "Sprite.h"

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	std::vector<Sprite*> sprites;

	void cleanup();
	void updateAll(float deltaTime);
	void drawAll();
};

