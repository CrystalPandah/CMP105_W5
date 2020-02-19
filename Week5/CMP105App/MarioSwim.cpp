#include "MarioSwim.h"

MarioSwim::MarioSwim()
{
	//Setup swim animation.
	swim.addFrame(sf::IntRect(0, 0, 55, 108));
	swim.addFrame(sf::IntRect(0, 0, 55, 108));
	swim.addFrame(sf::IntRect(0, 0, 55, 108));
	swim.setFrameSpeed(1.f / 10.f);
}

void MarioSwim::update(float dt)
{
	swim.animate(dt);
	setTextureRect(jump.getCurrentFrame());
}
~MarioSwim();