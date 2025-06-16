#include "GameObject.h"

GameObject::GameObject(int x, int y, int width, int height, std::string Symbol)
    : x(x), y(y), width(width), height(height), symbol(Symbol) {}

int GameObject::getX() const { return x; }
int GameObject::getY() const { return y; }
int GameObject::getWidth() const { return width; }
int GameObject::getHeight() const { return height; }

bool GameObject::checkCollision(GameObject& other) const {
    return (x < other.x + other.width &&
        x + width > other.x &&
        y < other.y + other.height &&
        y + height > other.y);
}
