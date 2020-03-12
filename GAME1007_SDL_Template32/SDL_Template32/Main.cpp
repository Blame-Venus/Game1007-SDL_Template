// Create and run the Game class
// Joss Moo-Young
#include <iostream>
#include"Game.h"

Game myGame;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	std::cout << "Greetings!" << std::endl;
	getchar();
	std::cout << "How are you?" << std::endl;
	getchar();
	std::cout << "Good?" << std::endl;
	getchar();
	std::cout << "Nice weather we're having eh?" << std::endl;
	getchar();
	std::cout << "Starting to really feel ike Spring!" << std::endl;
	getchar();
	std::cout << "My favourite part of Spring is the grey slush that litters the landscape" << std::endl;
	getchar();
	std::cout << "Truly a sight to behold. The perfect blend of snow, ice, dirt, tar, and oil" << std::endl;
	getchar();
	std::cout << "So what are you up to now?" << std::endl;
	getchar();
	std::cout << "Working on your assignment, I presume?" << std::endl;
	getchar();
	std::cout << "That's nice..." << std::endl;
	getchar();

	for (int i = 0; i < 100; i++)
	{
		std::cout << "..." << std::endl;
		getchar();
	}

	myGame = Game("Hello Game Class", 800, 600);
	myGame.run();
	return 0;
}