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
	//setTextureRect(currentAnimation->getCurrentFrame());

	
	// Init input component
	input = nullptr;

	//void setFlipped(bool flip) { flipped = flip; };

	//bool getFlipped() { return flipped; };

	

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

	//if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
	//{
	//	//Update y speed
	//	velocity.y = -70;
	//}
	//else if (!input->isKeyDown(sf::Keyboard::Up) && input->isKeyDown(sf::Keyboard::Down))
	//{
	//	//Update y speed
	//	velocity.y = 70;
	//}
	//else
	//{
	//	//Update y speed
	//	velocity.y = 0;
	//}
	move(velocity * dt);
	
}





void Zombie::update(float dt)
{
	//currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	move(velocity*dt);

	//(input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	//(input->isKeyDown(sf::Keyboard::Right)
	if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &walk;
		//setFlipped(true);
		//flipped false; 
		//setFlipped(false flip);
		//currentAnimation->reset();
		//getFlipped();
		setFlipped(false flip);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &walk;
		//setFlipped(false);
		//flipped true;
		//setFlipped(true flip);
		//currentAnimation->reset();
		//getFlipped();
		setFlipped(true flip);
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());

	}
	/*if (input->isKeyDown(sf::Keyboard::A))
	{
		currentAnimation = &run;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::R))
	{
		currentAnimation = &punch;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}*/

	


}
