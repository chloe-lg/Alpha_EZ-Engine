#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	float speed;
public:
	Player() = default;
	Player(float x, float y);
	Player(float x, float y, float w, float h);
	virtual ~Player() override = default;

	void setSpeed(float nSpeed);

	void controlKeayboard(float& dt, Input& input);
	void clampInScreen();

	virtual void update(float& dt, Input& input) override;
	virtual void render(RenderWindow* window) override;
};

