#include "GameState.h"

GameState::GameState(RenderWindow* window, vector<GameState*>* _states, Input& _input) : window(window), states(_states), input(_input) {

}

void GameState::nextState(vector<GameState*>* states) {
	if (!states->empty()) {
		states->pop_back();
	}
}