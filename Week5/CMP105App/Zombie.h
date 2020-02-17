#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie : public GameObject
{
public:
	Zombie();
	~Zombie();

	void handleInput(float dt);
	void update(float dt);
	//float velocity;
	//sf::Vector2<float>	speed;
	//sf::Vector2<int>	dir;

protected:
	Animation	walk;
		//punch,
		//jump;
	Animation* currentAnimation;
	
};

