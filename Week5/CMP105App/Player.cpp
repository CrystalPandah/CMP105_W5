#include "Player.h"
#include "Framework/Animation.h"

Player::Player()
{
	// Setup Animations
	initAnims();

	animState = JUMP;
	currentAnim = &jumpAnim;	

	// Init input component
	input = nullptr;

	isLeft = false;
}

Player::~Player()
{
	input = nullptr;
}

void Player::initAnims()
{
	
	//Setup walk animation
	walkAnim.addFrame(sf::IntRect(0, 0, 105, 200));
	walkAnim.addFrame(sf::IntRect(105, 0, 105, 200));
	walkAnim.addFrame(sf::IntRect(210, 0, 105, 200));
	walkAnim.addFrame(sf::IntRect(315, 0, 105, 200));

	walkAnim.setFrameSpeed(1.f / 10.f);

	//Setup punch animation
	punchAnim.addFrame(sf::IntRect(0, 200, 110, 200));
	punchAnim.addFrame(sf::IntRect(110, 200, 110, 200));
	punchAnim.addFrame(sf::IntRect(220, 200, 110, 200));
	punchAnim.addFrame(sf::IntRect(330, 200, 110, 200));
	punchAnim.addFrame(sf::IntRect(440, 200, 110, 200));

	punchAnim.setFrameSpeed(1.f / 10.f);

	//Setup jump animation
	jumpAnim.addFrame(sf::IntRect(10, 400, 100, 200));
	jumpAnim.addFrame(sf::IntRect(110, 400, 100, 200));
	jumpAnim.addFrame(sf::IntRect(220, 400, 100, 200));
	jumpAnim.addFrame(sf::IntRect(330, 400, 100, 200));
	jumpAnim.addFrame(sf::IntRect(440, 400, 100, 200));
	jumpAnim.setLooping(false);


	jumpAnim.setFrameSpeed(4.f / 10.f);

}

void Player::handleInput(float dt)
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

		if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
		{
			animState = JUMP;
		}
		else
		{
			animState = PUNCH;
			//animState = DUCK;

			// Reset duck anim to start after it's been used
			jumpAnim.reset();
			jumpAnim.setPlaying(true);
		}
	}	
}

void Player::update(float dt)
{
	//Switch animation
	switch (animState)
	{
		case WALK:
			currentAnim = &walkAnim;
			break;
		case PUNCH:
			currentAnim = &punchAnim;
			break;
		case JUMP:
			currentAnim = &jumpAnim;
			break;
		default:
			currentAnim = &jumpAnim;
			break;
	};

	currentAnim->setFlipped(isLeft);
	currentAnim->animate(dt);
	setTextureRect(currentAnim->getCurrentFrame());

	// Move character
	move(velocity * dt);
}