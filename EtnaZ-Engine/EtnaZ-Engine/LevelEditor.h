#pragma once
#include "SFML/Graphics.hpp"
//#include "nlohmann/png.hpp"
#include <fstream>


class GameObject;

class LevelEditor {
private:
    // Vec for collision
    std::vector<GameObject*> entityCreate;
    std::vector<GameObject*> entityNoCollidable;
    std::vector<GameObject*> entityCollidable;

    // Vec for render
    std::vector<std::vector<GameObject*>> vecRender;
public:
    LevelEditor();
    ~LevelEditor();

    void loadLevel();
};