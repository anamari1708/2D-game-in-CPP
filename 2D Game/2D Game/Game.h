#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
 
using namespace sf;
using namespace std;
/*
	Class that acts as the game engine.
	Wrapper class.
*/


class Game
{
private:
	//Variables
	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Mouse positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	//Resources
	Font font;

	//Sounds
	SoundBuffer _pointSoundBuffer;
	Sound _pointSound;

	//Text
	Text uiText;

	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game objects
	vector<RectangleShape> enemies;
	RectangleShape enemy;

	//Private functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();
	
public:
	//Constructors /Destructors
	Game();
	virtual ~Game();

	//Accessors 
	const bool running() const;
	const bool getEndGame() const;

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();
};

