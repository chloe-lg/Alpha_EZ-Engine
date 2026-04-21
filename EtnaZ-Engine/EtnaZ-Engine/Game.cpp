#include "Game.h"
#include "Textures.h"

#include <SFML/Window/Keyboard.hpp>

#include "GameEngine.h"

Game* Game::instance = nullptr;

Game::Game() {
    myPlayer = new Player(0, 0, 80, 80);
    myKnife = new Knife(50, 50, 300, 54);
    myPlate = new Plate(100, 100, 180, 180);

    GameObject* myGameObjectC = new GameObject(1000, 500, 100, 100);
    GameObject* myGameObject = new GameObject(500, 500, 100, 100);
    GameObject* green = new GameObject(500, 500, 50, 50);

    myGameObject->setColor(sf::Color::White);
    green->setColor(sf::Color::Green);
    myGameObjectC->setColor(sf::Color::Blue);

    myPlayer->setTexture((&Textures :: getTexturesManager()->getTexture(Textures:: texturesIndices:: sushi_s)));
    myKnife->setTexture((&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::knife)));
    myPlate->setTexture((&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::plate_w)));


    Collider* myCollider = new Collider(myPlayer);
    myPlayer->setCollider(myCollider);

    entityCreate.push_back(myGameObjectC);
    entityCreate.push_back(myPlayer);
    entityCreate.push_back(myKnife);
    entityCreate.push_back(myPlate);

    setLayer(3);
    addObjetcInLayer(myGameObjectC, 1);
    addObjetcInLayer(myPlayer, 2);
    addObjetcInLayer(myKnife, 1);
    addObjetcInLayer(myPlate, 1);

    setCollision();
}

Game::~Game() {
    entityCreate.clear();
    entityNoCollidable.clear();
    entityCollidable.clear();
    instance = nullptr;
}

GameState* Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

void Game::manageState() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        nextState();
        GameEngine::activeStates.push_back(Menu::getInstance());
    }
}

void Game::update(float& dt) {
    collisions();
    for (auto& e : entityNoCollidable) {
        e->update(dt);
    }
    for (auto& e : entityCollidable) {
        e->update(dt);
    }
}

void Game::render() {
    for (auto& vR : vecRender) {
        for (auto& e : vR) {
            e->render();
        }
    }
}

void Game::collisions() {
    if (myPlayer->getCollider() != nullptr) {
        for (auto& eC : entityCollidable) {
            if (eC != myPlayer && myPlayer->getCollider()->isColliding(eC)){
                myPlayer->getCollider()->resolveCollision(eC);
            }
            
        }
    }
}

void Game::setCollision() {
    if (!entityCreate.empty()) {
        for (auto& e : entityCreate) {
            if (e->getCollider() != nullptr && e->getCollider()->isCollidable()) {
                entityCollidable.push_back(e);
            }
            else {
                entityNoCollidable.push_back(e);
            }
        }
    }
}

void Game::addObjetcInLayer(GameObject* myObject, int Layer) {
    if (!vecRender.empty() && Layer < vecRender.size()) {
        vecRender[Layer].push_back(myObject);
    }
}

void Game::setLayer(int _nbrLayer) {
    for (int X = 0; X < _nbrLayer; X++) {
        std::vector<GameObject*>  layer;
        vecRender.push_back(layer);
    }
}