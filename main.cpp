#include <iostream>
#include <vector>
#include "Display.h"


int main()
{
	Display game;
	game.ConstructConsole(128, 80, 12, 12);
	game.Start();

	return 0;
}