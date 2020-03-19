#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt) override;
protected:
	Animation walk;
	Animation swim;
	Animation crouch;
};

