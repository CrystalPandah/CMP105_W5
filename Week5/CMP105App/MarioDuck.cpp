#include "MarioDuck.h"

MarioDuck::MarioDuck()
{
	//Setup duck animation.
	duck.addFrame(sf::IntRect(0, 0, 55, 108));
	duck.addFrame(sf::IntRect(0, 0, 55, 108));
	duck.setFrameSpeed(1.f / 10.f);
}

void MarioDuck::update(float dt)
{
	duck.animate(dt);
	setTextureRect(jump.getCurrentFrame());
}
~MarioDuck();