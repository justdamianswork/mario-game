#pragma once
#include "Character.h"
#include "Animation.h"

class Mario : public Character{
public:
    /*Mario();
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;*/
    Mario(sf::Vector2f position = sf::Vector2f(50, 50));
    void Init();
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;
    sf::FloatRect getFloatRect();
private:
    Animation runAnimation();
    float speed;
    float jumpVelocity;
    float verticalVelocity;
    float gravity;
    bool directionOfMario; //true -> left; false -> right
    bool isOnTheGround;
    sf::Texture texture[5];
    sf::Sprite sprite;
};
