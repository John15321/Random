
#include <iostream>
#include "MainCircle.h"


int main()
{
	GameLoop game;
	if (game.ConstructConsole(320, 240, 4, 4)) // Create console
		game.Start(); // Start up main loop
	else
		std::wcout << L"Could not construct console" << std::endl;

	return 0;
};