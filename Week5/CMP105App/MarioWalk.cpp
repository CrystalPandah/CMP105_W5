#include "MarioWalk.h"
#include <SFML/System/Vector2.hpp>
#include "Level.h"
#include "Framework/Animation.h"

MarioWalk::MarioWalk()
{
	//Setup walk animation.
	mwalk.addFrame(sf::IntRect(0, 0, 15, 21));
	mwalk.addFrame(sf::IntRect(30, 0, 15, 21));
	mwalk.addFrame(sf::IntRect(45, 0, 15, 21));
	mwalk.addFrame(sf::IntRect(60, 0, 15, 21));

	mwalk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &mwalk;

	// Init input component
	input = nullptr;


}

MarioWalk::~MarioWalk()
{
	currentAnimation = nullptr;

	// Cleanup input
	// delete input;
	//input = nullptr;
}

void MarioWalk::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		//Update x speed
		velocity.x = 70;
	}
	else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
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




void MarioWalk::update(float dt)
{
	/*mwalk.animate(dt);
	setTextureRect(mwalk.getCurrentFrame());*/


	setTextureRect(currentAnimation->getCurrentFrame());

	move(velocity * dt);


	if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &mwalk;
		currentAnimation->setFlipped(false);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &mwalk;
		currentAnimation->setFlipped(true);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());

	}




}
//~MarioWalk();

