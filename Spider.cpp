#include "Spider.h"

Spider::Spider(sf::Texture& texture) : spiderAnimation (0,0,15,8){
    spider.setTexture(texture);
    spiderAnimation.ApplyToSprite(spider);
}

sf::Sprite& Spider::getSprite() {
    return spider;
}

void Spider::setPosition(sf::Vector2f pos) {
    spider.setPosition(pos);
}

sf::Vector2f Spider::getPosition() {
    return spider.getPosition();
}

void Spider::setSize(sf::Vector2f size) {
    spider.setScale(size);
}

void Spider::draw(sf::RenderTarget& window,sf::RenderStates state) const {
    window.draw(spider);
}

void Spider::attack(sf::Vector2f speed) {
    spider.move(speed);
}

void Spider::Update() {
    spiderAnimation.Update();
    spiderAnimation.ApplyToSprite(spider);
    spiderAnimation.animatedUpdate(1.0f/60.0f);
}