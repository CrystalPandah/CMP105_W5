#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class MarioDuck : public GameObject
{
public:
	MarioDuck();
	~MarioDuck();

	void update(float dt);

protected:
	Animation duck;
};

