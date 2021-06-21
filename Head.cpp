
#include "Head.h"

Head::Head(sf::Texture& texture) : WalkingDown(32,8, 8, 8), WalkingLeft(0,0,8,8)
{
    centipedeHead.setTexture(texture);
    WalkingDown.ApplyToSprite(centipedeHead);

}

sf::Sprite& Head::getHead()
{
    return centipedeHead;
}

void Head::move(sf::Vector2f velocity)
{
    centipedeHead.move(velocity);
}

sf::Vector2f Head::getPosition()
{
    return centipedeHead.getPosition();
}

void Head::setPosition(sf::Vector2f pos)
{
    centipedeHead.setPosition(pos);
}

void Head::setSize(sf::Vector2f size)
{
    centipedeHead.setScale(size);
}


void Head::draw(sf::RenderWindow &window)
{
    window.draw(centipedeHead);
}


