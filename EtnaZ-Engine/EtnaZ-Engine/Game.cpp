#include "Game.h"
#include "MainMenu.h"

Game::Game(RenderWindow* window, vector<GameState*>* _states, Input& _input) : GameState(window, _states, _input), gOBuild(false) {
	camera = new Camera(0.005);
}

void Game::Instance(RenderWindow* window, vector<GameState*>*& states, Input& input) {
	GameState* mainMenu = new Game(window, states, input);
	states->push_back(mainMenu);
}

void Game::manageState() {
	if (input.isKeyPressed(Keyboard::Key::Escape)) {
		GameState::nextState(states);
		MainMenu::Instance(window, states, input);
	}
}


void Game::setEntity() {
	if (!gOBuild) {

		// Background white
		GameObject* backWhite = new GameObject(0, 0, win_width, win_height);
		backWhite->setColor(Color::White);
		gameObject.push_back(backWhite);

		//Bloc
		GameObject* testBloc = new GameObject(100, 100, 100, 100);
		gameObject.push_back(testBloc);

		// Player
		Player* testPlayer = new Player(100, 100, 100, 100);
		testPlayer->setColor({0,255,0,255});
		gameObject.push_back(testPlayer);

		gOBuild = true;
	}
}

void Game::update(float& dt) {
	setEntity();

	camera->updateCamera(gameObject.back());

	for (auto gO : gameObject) {
		gO->update(dt,input);
	}

}

void Game::render() {

	camera->setCamera(window);

	for (auto gO : gameObject) {
		gO->render(window);
	}
}