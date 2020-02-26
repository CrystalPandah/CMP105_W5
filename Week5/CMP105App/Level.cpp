#include "Level.h"
#include "Player.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

//	marioTexture.loadFromFile("gfx/MarioSheetT.png");
//
//	mario.setSize(sf::Vector2f(100, 100)); //size WxH
//	mario.setPosition(100, 100);
//	mario.setTexture(&marioTexture);
//	mario.setInput(input);

	pandarunTexture.loadFromFile("gfx/SpriteSheet.png");
	player.setSize(sf::Vector2f(105, 200));
	player.setPosition(100, 100);
	player.setTexture(&pandarunTexture);
	player.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Q))
	{
		window->close();
	}

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
		window->draw(player);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}