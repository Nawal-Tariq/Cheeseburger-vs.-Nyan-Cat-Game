#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <string>

class GameObject {
protected:
    int x, y;
    int width, height;
    std::string symbol;

public:
    GameObject(int x, int y, int width, int height, std::string Symbol);
    virtual void move() = 0;
    virtual void draw() = 0;

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    bool checkCollision(GameObject& other) const;
};

#endif // GAMEOBJECT_H
#pragma once
