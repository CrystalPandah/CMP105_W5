#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
//#include "Framework/Animaiton.h"
#include <string>
#include <iostream>
//#include <SFML/System/Vector2.hpp>
//#include <Vector>
#include "Zombie.h"



class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//Level objects
	Zombie zombie;
	sf::Texture zombTexture;
};