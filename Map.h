#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
typedef std::vector<bool> Column;
typedef std::vector<Column> Grid;
struct CollisionResult{
    bool collisonCheck = false; //sprawdzenie czy dotyka czego kolwiek
    bool groundCheck = false; //sprawdzenie czy dotyka podlogi
};
class Map {
public:
    Map();
    sf::Vector2f LoadFromImageFile(const char* fileName);
//    void LoadFromImageFile(const char* fileName);
    void Draw(sf::RenderWindow& window);
    CollisionResult CheckCollision(float x, float y, float width, float height);
private:
    sf::Texture texture;
    sf::Sprite sprite;
    Grid grid;
};
