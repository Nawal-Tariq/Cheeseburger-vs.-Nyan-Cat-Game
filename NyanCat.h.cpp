#ifndef NYANCAT_H
#define NYANCAT_H

#include <iostream>
#include <string>
#include <windows.h>
#include "GameObject.h"
#include "Constants.h"

class NyanCat : public GameObject {
private:
    int level;
    float fallSpeed;
    bool isVisible;

public:
    NyanCat(int x, int y, int level);
    void move() override;
    void draw() override;
    void resetPosition();
    int getLevel() const;
    friend class Powerup;
};

#endif // NYANCAT_H
