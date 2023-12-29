#pragma once
#include <SFML/Graphics.hpp>
struct Frame{
    Frame(sf::Texture* texture, float time) : texture(texture), time(time){

    }
    sf::Texture* texture;
    float time;
};
class Animation {
public:
    Animation(float length);
    void addFrame(Frame frame);
    sf::Texture* update(float deltaTime);
private:
    std::vector<Frame> frames;
    float length;
    float time;
};