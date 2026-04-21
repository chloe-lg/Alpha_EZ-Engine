#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Knife.h"
#include "Plate.h"
#include "Globals.h"
#pragma once
#include <iostream>


class GameEngine;

class Game : public GameState {

private:
    // Variable for scene
    Game();

    static Game* instance;
private:
    // Object in my scene
    // Vec for update
    std::vector<GameObject*> entityCreate;
    std::vector<GameObject*> entityNoCollidable;
    std::vector<GameObject*> entityCollidable;

    // Vec for render
    std::vector<std::vector<GameObject*>> vecRender;

    Player* myPlayer;
    Knife* myKnife;
    Plate* myPlate;

public:
    virtual ~Game() override;

    static GameState* getInstance();

    virtual void manageState() override;
    virtual void update(float& dt) override;
    virtual void render() override;

    // Colision
    void collisions();
    void setCollision();

    // Layer
    void addObjetcInLayer(GameObject* myObject, int Layer);
    void setLayer(int nbrLayer);
};