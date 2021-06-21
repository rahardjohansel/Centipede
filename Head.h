
#ifndef CENTIPEDE_HEAD_H
#define CENTIPEDE_HEAD_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Head {

private:
    sf::Sprite centipedeHead;
    Animation WalkingLeft;
    Animation WalkingRight;
    Animation WalkingDown;

public:
    Head(sf::Texture& texture);
    sf::Sprite& getHead();
    void move(sf::Vector2f velocity);

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition();
    void setSize(sf::Vector2f size);
    void Update( float dt , sf::Vector2f dir);
    void draw(sf::RenderWindow& window);

};


#endif //CENTIPEDE_HEAD_H
