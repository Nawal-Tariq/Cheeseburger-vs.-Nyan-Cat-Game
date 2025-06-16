#pragma once
#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <string>
#include <windows.h>
#include "GameObject.h"
#include "Constants.h"

class Cheeseburger; // Forward declaration

class Friend : public GameObject {
private:
    std::string name;
    int supportLevel;
    bool isActive;
    int target_x;

public:
    Friend(int x, int y, std::string name, int supportlevel);
    void draw() override;
    void move() override;
    void resetPosition();
    void setTargetX(int newTarget);
    bool collide(GameObject* other);
    void offerHelp(Cheeseburger& burger) const;
    void increasesupportlevel(int increment = 1);
    void setActive(bool active);
};

#endif // FRIEND_H
