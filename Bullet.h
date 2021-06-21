
#ifndef CENTIPEDE_BULLET_H
#define CENTIPEDE_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:

    Bullet(sf::Texture& texture);
    void fire(int speed);
    sf::Sprite& getSprite();
    void draw(sf::RenderWindow& window);
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);

private:
    sf::Sprite bullet;
//    sf::Texture texture;

};


#endif //CENTIPEDE_BULLET_H
