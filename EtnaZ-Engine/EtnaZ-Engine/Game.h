#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Globals.h"
#include "Camera.h"

class MainMenu;

class Game : public GameState
{
private:
	vector<GameObject*> gameObject;
	bool gOBuild;
	Camera* camera;
public:
	Game() = default;
	Game(RenderWindow * window, vector<GameState*>* states, Input& input);
	~Game() = default;
		
	static void Instance(RenderWindow* window, vector<GameState*>*& states, Input& input);

	void setEntity();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

