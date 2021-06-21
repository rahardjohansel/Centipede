#ifndef CENTIPEDE_FLEA_H
#define CENTIPEDE_FLEA_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Flea {
private:
    sf::Sprite flea;
    Animation fleaAnimation;

public:
    //Constructor
    Flea(std::string file);
    Flea(sf::Texture& texture);
    //Get the desired sprite
    sf::Sprite& getSprite();
    //Set the initial position
    void setPosition(sf::Vector2f pos);
    //Get the current position
    sf::Vector2f getPosition();
    //Set the initial size
    void setSize(sf::Vector2f size);
    //Draw the sprites in the window
    void draw(sf::RenderWindow& window);
    //Summon the Flea to move from 0y to +2000y (up to down)
    void attack(sf::Vector2f speed);
    //Update the animation of the Flea;
    void Update();

};

#endif //CENTIPEDE_FLEA_H
