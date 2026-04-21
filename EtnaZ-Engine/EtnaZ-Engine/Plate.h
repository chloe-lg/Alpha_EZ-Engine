#pragma once
#include "GameObject.h"

class Plate : public GameObject {
private:
    
public:
    Plate();
    Plate(float x, float y);
    Plate(float x, float y, float w, float h);
    virtual ~Plate() override = default;

    virtual void render() override;

};