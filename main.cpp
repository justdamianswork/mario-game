#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"
#include "Mario.h"
#include "Map.h"
std::vector<Character*> characters;
Map map;
Mario mario;
auto main() -> int{
    sf::RenderWindow window(sf::VideoMode(900, 700), "Mario");
    sf::Clock clock;
    sf::View view = window.getDefaultView();
    mario = Mario(map.LoadFromImageFile("../images/marioMap.png"));
    mario.Init();
    clock.restart();
    while(window.isOpen()){
        sf::Time time = clock.restart();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        mario.Update(time.asSeconds());
        view.setCenter(mario.getFloatRect().left, mario.getFloatRect().top);
        window.setView(view);
        window.clear(sf::Color(135, 206, 235));
        map.Draw(window);
        mario.Draw(window);
        window.display();
    }
}
