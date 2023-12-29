#include "Mario.h"
#include "Global.h"
#include "Map.h"
#include "Animation.h"
#include "Character.h"
extern Map map;
/*Mario::Mario() : speed(600), verticalVelocity(0), gravity(1000), jumpVelocity(-700),
isOnTheGround(false), directionOfMario(false){
    floatRect = sf::FloatRect(50, 50, 60, 60);
    texture.loadFromFile("../images/marioIdle.png");
    sprite = sf::Sprite(texture);

}*/
Mario::Mario(sf::Vector2f position) : speed(300), jumpVelocity(-700), verticalVelocity(0), gravity(1000),
isOnTheGround(false), directionOfMario(false){ //, runAnimation(.45f)
    floatRect = sf::FloatRect(position.x, position.y, 60, 60);
}
sf::FloatRect Mario::getFloatRect() {
    return floatRect;
}

void Mario::Init(){
    /*texture.loadFromFile("../images/marioIdle.png");
    sprite = sf::Sprite(texture);*/
    texture[0].loadFromFile("../images/marioRun1.png");
    texture[1].loadFromFile("../images/marioRun2.png");
    texture[2].loadFromFile("../images/marioRun3.png");
    texture[3].loadFromFile("../images/marioIdle.png");
    texture[4].loadFromFile("../images/marioJump.png");
    runAnimation().addFrame(Frame(&texture[0], .15f)); //adres zdjecia, czas zakonczenia trwania klatki
    runAnimation().addFrame(Frame(&texture[1], .30f));
    runAnimation().addFrame(Frame(&texture[2], .45f));
}
void Mario::Update(float deltaTime) {
    float velocity = 0.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocity = -speed * deltaTime;
        directionOfMario = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity = speed * deltaTime;
        directionOfMario = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnTheGround){
        verticalVelocity = jumpVelocity;
    }
    verticalVelocity += gravity * deltaTime;
    if(map.CheckCollision(floatRect.left + velocity, floatRect.top, floatRect.width, floatRect.height).collisonCheck){
        velocity = 0;
    }
    CollisionResult collisionResult = map.CheckCollision(floatRect.left, floatRect.top + verticalVelocity * deltaTime,
                       floatRect.width, floatRect.height);
    if(collisionResult.collisonCheck){
        verticalVelocity = 0;
    }
    isOnTheGround = collisionResult.groundCheck;
    floatRect.left += velocity;
    floatRect.top += verticalVelocity * deltaTime;
    verticalVelocity += gravity * deltaTime;
    if(!isOnTheGround){
        sprite.setTexture(texture[4]); //4 -> jump mario
    }else if(abs(velocity) > .02f){
        sprite.setTexture(*runAnimation().update(deltaTime)); //0, 1, 2 animacja biegu
    }else{
        sprite.setTexture(texture[3]); //3 -> idle mario
    }
}
void Mario::Draw(sf::RenderWindow& window) {
    sprite.setPosition(floatRect.left, floatRect.top);
    sprite.setScale(floatRect.width / texture[0].getSize().x,
                    floatRect.height / texture[0].getSize().y);
    sprite.setTextureRect(sf::IntRect(texture[3].getSize().x * (directionOfMario ? 1 : 0),0,
                     texture[3].getSize().x * (directionOfMario ? -1 : 1), texture[3].getSize().y));
    window.draw(sprite);
}

Animation Mario::runAnimation() {
    return Animation(0);
}
