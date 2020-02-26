//#include "MarioSwim.h"
//#include <SFML/System/Vector2.hpp>
//#include "Level.h"
//#include "Framework/Animation.h"
//
//MarioSwim::MarioSwim()
//{
//	//Setup swim animation.
//	swim.addFrame(sf::IntRect(0, 0, 16, 20));
//	swim.addFrame(sf::IntRect(32, 0, 16, 20));
//	swim.addFrame(sf::IntRect(48, 0, 16, 20));
//	swim.setFrameSpeed(1.f / 10.f);
//
//	currentAnimation = &swim;
//
//	// Init input component
//	input = nullptr;
//
//
//}
//
//MarioSwim::~MarioSwim()
//{
//	currentAnimation = nullptr;
//
//	// Cleanup input
//	// delete input;
//	//input = nullptr;
//}
//
//void MarioSwim::handleInput(float dt)
//{
//	if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
//	{
//		//Update y speed
//		speed.y = -70;
//	}
//	else if (!input->isKeyDown(sf::Keyboard::Up) && input->isKeyDown(sf::Keyboard::Down))
//	{
//		//Update y speed
//		speed.y = 70;
//	}
//	else
//	{
//		//Update y speed
//		speed.y = 0;
//	}
//
//
//	move(velocity * dt);
//
//}
//
//
//
//void MarioWalk::update(float dt)
//{
//	/*swim.animate(dt);
//	setTextureRect(mwalk.getCurrentFrame());*/
//
//
//	setTextureRect(currentAnimation->getCurrentFrame());
//
//	move(velocity * dt);
//
//	if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
//	{
//		currentAnimation = &swim;
//		currentAnimation->setFlipped(false);
//		currentAnimation->animate(dt);
//		setTextureRect(currentAnimation->getCurrentFrame());
//	}
//	/*else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
//	{
//		currentAnimation = &mwalk;
//		currentAnimation->setFlipped(true);
//		currentAnimation->animate(dt);
//		setTextureRect(currentAnimation->getCurrentFrame());*/
//
//	}
//
//	
//
//}



//~MarioWalk();


