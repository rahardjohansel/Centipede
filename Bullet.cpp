
#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture)
{
    bullet.setTexture(texture);
}

void Bullet::fire(int speed)
{
    bullet.move(0, speed);
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(bullet);
}

sf::Sprite& Bullet::getSprite()
{
    return bullet;
}

void Bullet::setPosition(sf::Vector2f pos)
{
    bullet.setPosition(pos);
}

void Bullet::setSize(sf::Vector2f size)
{
    bullet.setScale(size);
}