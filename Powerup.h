#pragma once
#ifndef POWERUP_H
#define POWERUP_H

#include <iostream>
#include <string>
#include <windows.h>
#include "GameObject.h"
#include "Constants.h"

class Cheeseburger; // Forward declaration

class Powerup : public GameObject {
private:
    std::string type;
    bool isActive;

public:
    Powerup(int X, int Y, std::string T);
    void draw() override;
    void move() override;
    bool collide(GameObject* object);
    void activate(Cheeseburger& cheeseburger) const;
    void resetPosition();
    void deactivate();
    bool isActivated() const;
    std::string getType() const;
};

#endif // POWERUP_H
