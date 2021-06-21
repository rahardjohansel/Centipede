
#include "Flea.h"
#include <string>

Flea::Flea(std::string file) {
    sf::Texture fleaTexture;
    fleaTexture.loadFromFile(file);
}

Flea::Flea(sf::Texture& texture) : fleaAnimation(0,0,32,16) {
    flea.setTexture(texture);
    fleaAnimation.ApplyToSprite(flea);
}

sf::Sprite& Flea::getSprite() {
    return flea;
}

void Flea::setPosition(sf::Vector2f pos) {
    flea.setPosition(pos);
}

sf::Vector2f Flea::getPosition() {
    return flea.getPosition();
}

void Flea::setSize(sf::Vector2f size) {
    flea.setScale(size);
}

void Flea::draw(sf::RenderWindow &window) {
    window.draw(flea);
}

void Flea::attack(sf::Vector2f speed) {
    flea.move(speed);
}

void Flea::Update() {
    fleaAnimation.Update();
    fleaAnimation.ApplyToSprite(flea);
    fleaAnimation.animatedUpdate(1.0f/60.0f);
}

