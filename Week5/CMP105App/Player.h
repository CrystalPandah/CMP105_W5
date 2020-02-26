#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

enum AnimationStates
{
	WALK,
	PUNCH,
	JUMP
};

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);

protected:
	Animation	punchAnim,
				walkAnim,
				jumpAnim,
				*currentAnim;
	
	bool		isLeft;
	
	AnimationStates	animState;	

	void		initAnims();
};