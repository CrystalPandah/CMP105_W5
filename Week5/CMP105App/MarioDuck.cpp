#include "MarioDuck.h"
#include <SFML/System/Vector2.hpp>
#include "Level.h"
#include "Framework/Animation.h"

MarioDuck::MarioDuck()
{
	//Setup duck animation.
	duck.addFrame(sf::IntRect(0, 0, 16, 20));
	duck.addFrame(sf::IntRect(32, 0, 16, 20));

	duck.setFrameSpeed(1.f / 10.f);

	currentAnimation = &duck;

	// Init input component
	input = nullptr;


}

MarioDuck::~MarioDuck()
{
	currentAnimation = nullptr;

	// Cleanup input
	// delete input;
	//input = nullptr;
}

void MarioDuck::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Down) && !input->isKeyDown(sf::Keyboard::Up))
	{
		//Update x speed
		velocity.x = 70;
	}
	else if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
	{
		//Update x speed
		velocity.x = -70;
	}
	else
	{
		//Update x speed
		velocity.x = 0;
	}


	move(velocity * dt);

}




void MarioDuck::update(float dt)
{
	/*mwalk.animate(dt);
	setTextureRect(mwalk.getCurrentFrame());*/


	setTextureRect(currentAnimation->getCurrentFrame());

	move(velocity * dt);


	if (input->isKeyDown(sf::Keyboard::Down) && !input->isKeyDown(sf::Keyboard::Up))
	{
		currentAnimation = &duck;
		currentAnimation->setFlipped(false);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
	{
		currentAnimation = &duck;
		currentAnimation->setFlipped(false);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());

	}




}