#include "Plate.h"

Plate::Plate() : Plate(0, 0, 50, 50) {

}

Plate::Plate(float x, float y) : Plate(x, y, 50, 50) {

}

Plate::Plate(float x, float y, float w, float h) : GameObject(x, y, w, h) {

}


void Plate::render() {
    GameObject::render();
}