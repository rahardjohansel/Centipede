
#ifndef CENTIPEDE_MUSHROOM_H
#define CENTIPEDE_MUSHROOM_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Mushroom {
private:
    sf::Sprite mushroom;
    Animation mushroom1Animation;

public:
    Mushroom(sf::Texture& texture);
    void draw(sf::RenderWindow& window);
    void Update();
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);

    sf::Sprite& getSprite();
    Animation getAnimation1()
    {
        return mushroom1Animation;
    }
};


#endif //CENTIPEDE_MUSHROOM_H
