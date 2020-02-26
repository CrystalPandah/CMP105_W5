#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

enum AnimationStates
{
	WALK,
	SWIM,
	DUCK
};

class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void handleInput(float dt);
	void update(float dt);

protected:
	Animation	swimAnim,
				walkAnim,
				duckAnim,
				*currentAnim;
	
	bool		isLeft;
	
	AnimationStates	animState;	

	void		initAnims();
};