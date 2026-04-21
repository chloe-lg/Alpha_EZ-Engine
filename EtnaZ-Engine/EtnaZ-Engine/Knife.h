#pragma once
#include "GameObject.h"

class Knife : public GameObject {
private:
    float speed;
public:
    Knife();
    Knife(float x, float y);
    Knife(float x, float y, float w, float h);
    virtual ~Knife() override = default;

    float getSpeed();

    void setSpeed(float nSpeed);


    virtual void update(float& dt) override;
    virtual void render() override;

};