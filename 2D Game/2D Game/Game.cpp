#include "pch.h"
#include "Game.h"

#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define POINT_SOUND_FILEPATH "Music/Point.wav"

//private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->endGame = false;
	this->points = 0;
	this->health = 20;
	this->enemySpawnTimerMax = 20.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "ERROR::GAME::INITFONTS::falied to load font" << endl;
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(Color::White);
	this->uiText.setString("NONE");
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(Vector2f(100.f, 100.f));
	//this->enemy.setScale(Vector2f(0.5f,0.5f));
	this->enemy.setFillColor(Color::Cyan);
	//this->enemy.setOutlineColor(Color::Green);
	//this->enemy.setOutlineThickness(1.f);


}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initEnemies();
}


Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

//Functions

void Game::spawnEnemy()
{
	/*
		@return void

		Spawns enemies and sets their types and colors. Spawns them at radom positions.
		-Sets a random type
		-Sets a random position
		-Sets a random color
		-Adds enemy to the vector
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	//Randomize enemy type
	int type = rand() % 5;

	switch (type)
	{
	case 0: //the hardest type
		this->enemy.setFillColor(Color::Magenta);
		this->enemy.setSize(Vector2f(10.f, 10.f));
		break;
	case 1: //the hardest type
		this->enemy.setFillColor(Color::Blue);
		this->enemy.setSize(Vector2f(30.f, 30.f));
		break;
	case 2: //the hardest type
		this->enemy.setFillColor(Color::Cyan);
		this->enemy.setSize(Vector2f(50.f, 50.f));
		break;
	case 3: //the hardest type
		this->enemy.setFillColor(Color::Red);
		this->enemy.setSize(Vector2f(70.f, 70.f));
		break;
	case 4: //the hardest type
		this->enemy.setFillColor(Color::Yellow);
		this->enemy.setSize(Vector2f(100.f, 100.f));
		break;
	default:
		break;
	}

	//Spawn the enemy
	this->enemies.push_back(this->enemy);

	//Remove enemies at end of screen

}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}

}

void Game::updateMousePositions()
{
	/* 
		Updates the mouse posiions:
		-Mouse position relative to winsow (Vector2i)
	*/

	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateText()
{
	stringstream ss;

	ss << "Points:  " << this->points << endl
		<< "Health:  " << this->health << endl;

 	this->uiText.setString(ss.str());
}

void Game::updateEnemies()
{
	/*
		@return void

		Upates the enemy spawn timer and spawns enemies
		when the total amount of enemies is smaller then the maximum.
		Moves the enemies downwards.
		Removes the enemies at the edgeod the screen //TODO
	*/

	//Updating the timer for enemy spawing
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}

		else
			this->enemySpawnTimer += 1.f;
	}

	//Moving and updating enemies
	for (int i=0;i<this->enemies.size();i++)
	{
		bool deleted = false;

		this->enemies[i].move(0.f, 3.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			cout << "Health: " << this->health << endl;
		}
	}

	//Check if clicked upon
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{

				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					//Gain points
					if(this->enemies[i].getFillColor()==Color::Magenta)
						this->points += 10;
					else if (this->enemies[i].getFillColor() == Color::Blue)
						this->points += 7;
					else if (this->enemies[i].getFillColor() == Color::Cyan)
						this->points += 5;
					else if (this->enemies[i].getFillColor() == Color::Red)
						this->points += 3;
					else if (this->enemies[i].getFillColor() == Color::Green)
						this->points += 1;
					cout << "Points: " << this->points << endl;

					//Delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}

	else
	{
		this->mouseHeld = false;
	}
}

//Functions 
void Game::update()
{
	this->pollEvents();

	if (this->endGame==false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();
 	}

	//End game condition
	if (this->health <= 0)
		this->endGame = true;
}


void Game::renderText(RenderTarget & target)
{
	target.draw(this->uiText);
}

void Game::renderEnemies(RenderTarget& target)
{
	//Rendering all the enemies
	for (auto &e : this->enemies)
	{
		target.draw(e);
	}
}

void Game::render()
{
	/*
		@return void

	   -clear old frame
	   -render objects
	   -display frame in w+the window

	   Renders the game objects.
	*/
	this->window->clear(); //black is default

	//Draw game objects
	this->renderEnemies(*this->window);

	this->renderText(*this->window);

	this->window->display();
}
