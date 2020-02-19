#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class MarioWalk : public GameObject
{
public:
	MarioWalk();
	~MarioWalk();

	void update(float dt);

protected:
	Animation walk;
};

