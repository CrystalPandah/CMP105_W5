#include <SFML/System/Vector2.hpp>
#include "Level.h"
#include "Zombie.h"
#include "Framework/Animation.h"


Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));

	walk.setFrameSpeed(1.f / 10.f);


	currentAnimation = &walk;
	

	
	// Init input component
	input = nullptr;



	

}


Zombie::~Zombie()
{
	currentAnimation = nullptr;

	// Cleanup input
	// delete input;
	//input = nullptr;
}

void Zombie::handleInput(float dt)
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





void Zombie::update(float dt)
{
	
	setTextureRect(currentAnimation->getCurrentFrame());

	move(velocity*dt);


	if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());

	}


	


}
