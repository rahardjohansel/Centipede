
#include "Player.h"
#include <iostream>

Player::Player(sf::Texture& texture)
{
    blaster.setTexture(texture);
}

void Player::move(sf::Vector2f velocity)
{
    blaster.move(velocity);
}

void Player::setPos(sf::Vector2f pos) //
{
    blaster.setPosition(pos);
}

void Player::setSize(sf::Vector2f size)
{
    blaster.setScale(size);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(blaster);
}

sf::Sprite& Player::getSprite()
{
    return blaster;
}

sf::Vector2f Player::getPosition()
{
    return blaster.getPosition();
}

int Player::getHP()
{
    return HP;
}

void Player::plusHP()
{
    HP++;
}

void Player::minusHP()
{
    HP--;
}
