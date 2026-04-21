#include "Knife.h"


Knife::Knife() : Knife(0, 0, 50, 50) {

}

Knife::Knife(float x, float y) : Knife(x, y, 50, 50) {

}

Knife::Knife(float x, float y, float w, float h) : GameObject(x, y, w, h) {
    speed = 400.0f;
}

float Knife::getSpeed() {
    return speed;
}

void Knife::setSpeed(float nSpeed) {
    speed = nSpeed;
}

void Knife::update(float& dt) {
}

void Knife::render() {
    GameObject::render();
}
