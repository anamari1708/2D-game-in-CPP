// 2D Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Game.h"
#include<iostream>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
using namespace sf;

int main()
{
	//Init srand
	srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	Game game;

	//Game loop
	while (game.running() && !game.getEndGame())
	{
		
		//Update
		game.update();

		//Render
		game.render(); 

	}
	return EXIT_SUCCESS;
}
