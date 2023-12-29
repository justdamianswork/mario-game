#include "Map.h"
#include <iostream>
Map::Map(){
    texture.loadFromFile("../images/brickblock.png");
    sprite.setTexture(texture);
    sprite.setScale((double)CELL_SIZE / texture.getSize().x, (double)CELL_SIZE / texture.getSize().y);
}
sf::Vector2f Map::LoadFromImageFile(const char *fileName){
    sf::Vector2f marioPosition(50, 50);
    sf::Image image;
    image.loadFromFile(fileName);
    for(int x = 0; x < image.getSize().x; x++){
        Column col;
        for(int y = 0; y < image.getSize().y; y++){
            sf::Color pixelColor = image.getPixel(x, y);
            if(pixelColor == sf::Color::Red){
                marioPosition = sf::Vector2f(x + CELL_SIZE, y + CELL_SIZE);
            }
            col.push_back(pixelColor == sf::Color::Black);
        }
        grid.push_back(col);
    }
    return marioPosition;
}
CollisionResult Map::CheckCollision(float x, float y, float width, float height) {
    CollisionResult collisionResult;
    int columnStart = (int)(x / CELL_SIZE);
    int columnEnd = (int)((x + width) / CELL_SIZE) + 1;
    int rowStart = (int)(y / CELL_SIZE);
    int rowEnd = (int)((y + height) / CELL_SIZE) + 1;
    for(int col = columnStart; col < columnEnd; col++){
        for(int row = rowStart; row < rowEnd; row++){
            if(grid[col][row]){
                collisionResult.collisonCheck = true;
                if(row == rowEnd -1){
                    collisionResult.groundCheck = true;
                }
            }
        }
    }
    return collisionResult;
}
void Map::Draw(sf::RenderWindow &window){
    int x = 0;
    for(Column& col : grid){
        int y = 0;
        for(const bool& draw : col){
            if(draw){
                sprite.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                window.draw(sprite);
            }
            y++;
        }
        x++;
    }
}
