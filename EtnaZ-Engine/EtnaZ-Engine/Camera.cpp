#include "Camera.h"

Camera::Camera(float _lag) {
    myView = sf::View(sf::FloatRect({ 0, 0 }, { WINWIDTH, WINHEIGHT }));
    lag = _lag;
}

void Camera::updateCamera(GameObject* myObject) {
    center = { myObject->getPos().x + myObject->getSize().x / 2, myObject->getPos().y + myObject->getSize().y / 2 };

    if (myObject->getPos().x <= LEVELWIDTH / 3.f) {  // 1920*1080
        center.x = std::clamp(center.x, (float)WINWIDTH / 2.0f, (float)LEVELWIDTH / 3.0f - (float)WINWIDTH / 2.0f);
        center.y = std::clamp(center.y, (float)WINHEIGHT / 2.0f, (float)LEVELHEIGHT / 2.f - (float)WINHEIGHT / 2.0f);
    }
    else if (myObject->getPos().x >= LEVELWIDTH / 3.f && myObject->getPos().x <= LEVELWIDTH / 1.5f) { // 3840*1080
        center.x = std::clamp(center.x, (float)LEVELWIDTH / 3.0f + (float)WINWIDTH / 2.0f, (float)LEVELWIDTH / 1.5f - (float)WINWIDTH / 2.0f);
        center.y = std::clamp(center.y, (float)WINHEIGHT / 2.0f, (float)LEVELHEIGHT / 4.f - (float)WINHEIGHT / 2.0f);
    }
    else if (myObject->getPos().x >= LEVELWIDTH / 1.5f && myObject->getPos().y <= LEVELHEIGHT / 2.f) {
        center.x = std::clamp(center.x, (float)LEVELWIDTH / 1.5f + (float)WINWIDTH / 2.0f, (float)LEVELWIDTH - (float)WINWIDTH / 2.0f); // 5760*2160
        center.y = std::clamp(center.y, (float)WINHEIGHT / 2.0f, (float)LEVELHEIGHT / 2.f - (float)WINHEIGHT / 2.0f);
    }
    else if ((myObject->getPos().y + myObject->getPos().y) >= LEVELHEIGHT / 2.f) { // 5760*4320
        center.x = std::clamp(center.x, (float)WINWIDTH / 2.0f, (float)LEVELWIDTH / 3.f - (float)WINWIDTH / 2.0f);
        center.y = std::clamp(center.y, (float)WINHEIGHT / 2.0f, (float)LEVELHEIGHT - (float)WINHEIGHT / 2.0f);
    }

    /* center.x = std::max(int(win_width) / 2, std::min((int)center.x, level_size_width - win_width / 2));
     center.y = std::max(int(win_height) / 2 , std::min((int)center.y, level_size_heigt - win_height / 2));*/

    sf::Vector2f current = myView.getCenter();
    current.x += (center.x - current.x) * lag;
    current.y += (center.y - current.y) * lag;

    myView.setCenter(center);


}

void Camera::setCamera(sf::RenderWindow* window) {
    window->setView(myView);
}


void Camera::camHUD(sf::RenderWindow* window) {
    window->setView(window->getDefaultView());
}

void Camera::getCameraPos(sf::Vector2f& _pos) const {
    _pos = myView.getCenter();
}