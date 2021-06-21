
#ifndef CENTIPEDE_SPIDER_H
#define CENTIPEDE_SPIDER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Spider : public sf::Drawable{
private:
    sf::Sprite spider;
    Animation spiderAnimation;

public:
    //Constructor
    Spider(sf::Texture& texture);
    //Get the desired sprite
    sf::Sprite& getSprite();
    //Set the initial position
    void setPosition(sf::Vector2f pos);
    //Get the current position
    sf::Vector2f getPosition();
    //Set the initial size
    void setSize(sf::Vector2f size);
    //Draw the sprites in the window
    void draw(sf::RenderTarget& window,sf::RenderStates state)const;
    //Summon the Flea to move from 0y to +2000y (up to down)
    void attack(sf::Vector2f speed);
    //Update the animation of the Flea;
    void Update();
};
#endif //CENTIPEDE_SPIDER_H
