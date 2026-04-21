#pragma once
#include <iostream>

#include "Globals.h"
#include "Input.h"

#include "GameState.h"
#include "MainMenu.h"

using namespace std;

class GameEngine
{
private:
	RenderWindow* window;
	float dt;
	vector<GameState*>* states;
	Clock clock;
	Input input;

public:
	GameEngine();
	~GameEngine();

	void updateEvent();
	void updateDt();
	void update();
	void render();
	void run();
};

