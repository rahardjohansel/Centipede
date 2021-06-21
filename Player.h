
#ifndef CENTIPEDE_PLAYER_H
#define CENTIPEDE_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player {
private:
    sf::Sprite blaster;
    sf::Texture texture;

    std::vector<Bullet> playerBullets;

    int HP = 3;

    int maxHP = 3;


public:

    Player(sf::Texture &texture);

    void move(sf::Vector2f velocity);

    void setPos(sf::Vector2f pos);

    void setSize(sf::Vector2f size);

    void draw(sf::RenderWindow &window);

    int getHP();

    void plusHP();

    void minusHP();

    sf::Sprite &getSprite();

    sf::Vector2f getPosition();

};

#endif //CENTIPEDE_PLAYER_H
