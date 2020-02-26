#include "Mario.h"
#include "Framework/Animation.h"

Mario::Mario()
{
	// Setup Animations
	initAnims();

	animState = DUCK;
	currentAnim = &duckAnim;	

	// Init input component
	input = nullptr;

	isLeft = false;
}

Mario::~Mario()
{
	input = nullptr;
}

void Mario::initAnims()
{
	//Setup walk animation.
	walkAnim.addFrame(sf::IntRect(0, 0, 15, 21));
	walkAnim.addFrame(sf::IntRect(15, 0, 15, 21));
	walkAnim.addFrame(sf::IntRect(30, 0, 15, 21));
	walkAnim.addFrame(sf::IntRect(45, 0, 15, 21));
	walkAnim.setFrameSpeed(1.f / 10.f);

	//Setup swim animation.
	swimAnim.addFrame(sf::IntRect(0, 21, 16, 20));
	swimAnim.addFrame(sf::IntRect(16, 21, 16, 20));
	swimAnim.addFrame(sf::IntRect(32, 21, 16, 20));
	swimAnim.setFrameSpeed(1.f / 10.f);

	//Setup duck animation.
	duckAnim.addFrame(sf::IntRect(0, 42, 16, 20));
	duckAnim.addFrame(sf::IntRect(16, 42, 16, 20));
	duckAnim.setFrameSpeed(1.f / 10.f);
	duckAnim.setLooping(false);
}

void Mario::handleInput(float dt)
{
	// Early return if no input variable set
	if (!input)
	{
		return;
	}

	if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		//Update x velocity
		velocity.x = 70;

		animState = WALK;

		isLeft = false;
	}
	else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
	{
		//Update x velocity
		velocity.x = -70;

		animState = WALK;

		isLeft = true;
	}
	else
	{
		//Update x velocity
		velocity.x = 0;

		if (input->isKeyDown(sf::Keyboard::Down) && !input->isKeyDown(sf::Keyboard::Up))
		{
			animState = DUCK;
		}
		else
		{
			animState = SWIM;
			//animState = DUCK;

			// Reset duck anim to start after it's been used
			duckAnim.reset();
			duckAnim.setPlaying(true);
		}
	}	
}

void Mario::update(float dt)
{
	//Switch animation
	switch (animState)
	{
		case WALK:
			currentAnim = &walkAnim;
			break;
		case SWIM:
			currentAnim = &swimAnim;
			break;
		case DUCK:
			currentAnim = &duckAnim;
			break;
		default:
			currentAnim = &duckAnim;
			break;
	};

	currentAnim->setFlipped(isLeft);
	currentAnim->animate(dt);
	setTextureRect(currentAnim->getCurrentFrame());

	// Move character
	move(velocity * dt);
}