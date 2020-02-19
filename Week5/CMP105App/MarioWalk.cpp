#include "MarioWalk.h"

MarioWalk::MarioWalk()
{
	//Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
}

void MarioWalk::update(float dt)
{
	walk.animate(dt);
	setTextureRect(jump.getCurrentFrame());
}
~MarioWalk();