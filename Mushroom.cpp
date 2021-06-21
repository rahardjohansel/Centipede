
#include "Mushroom.h"

Mushroom::Mushroom(sf::Texture& texture) : mushroom1Animation(0,0,16,16)
{
    mushroom.setTexture(texture);
    mushroom1Animation.ApplyToSprite(mushroom);

}


void Mushroom::draw(sf::RenderWindow &window)
{
    window.draw(mushroom);

}

void Mushroom::Update()
{
    mushroom1Animation.Update();
    mushroom1Animation.ApplyToSprite(mushroom);
}

void Mushroom::setPosition(sf::Vector2f pos)
{
    mushroom.setPosition(pos);
}

void Mushroom::setSize(sf::Vector2f size)
{
    mushroom.setScale(size);
}

sf::Sprite& Mushroom::getSprite()
{
    return mushroom;
}