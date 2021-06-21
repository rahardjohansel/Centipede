#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Mushroom.h"
#include "Collision.h"
#include "Head.h"
#include "Flea.h"
#include "Spider.h"
#include <cstdlib>

int main() {

    sf::RenderWindow window(sf::VideoMode(2500, 2000, 32), "Centipede");

    bool shoot = false;
    int shootTimer = 75;
    sf::Vector2f centipedeVelocity(0.0f, 0.20f);

    std::vector<Bullet> bullets;

    sf::Texture playerTexture;
    playerTexture.loadFromFile("/Users/limasnursalim/Documents/PCC/CS 008/Centipede/Sprites/blaster.png");

    Player p(playerTexture);
    p.setSize(sf::Vector2f(2.50f, 2.50f));
    p.setPos(sf::Vector2f(window.getSize().x / 2, window.getSize().y - 75));

    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("/Users/limasnursalim/Documents/PCC/CS 008/Centipede/Sprites/bullet.png");

    sf::Texture mushroomTexture;
    mushroomTexture.loadFromFile("/Users/limasnursalim/Documents/PCC/CS 008/Centipede/Sprites/mushroom.png");

    sf::Texture headTexture;
    headTexture.loadFromFile("/Users/limasnursalim/Documents/PCC/CS 008/Centipede/Sprites/centipede_head.png");

    Head centipedeHead(headTexture);
    centipedeHead.setPosition(sf::Vector2f(window.getSize().x/2, 0));
    centipedeHead.setSize(sf::Vector2f(5.0f,5.0f));

    /** FLEA LOAD TEXTURE **/
    sf::Texture fleaTexture;
    fleaTexture.loadFromFile("/Users/limasnursalim/Documents/PCC/CS 008/Centipede/Sprites/flea.png");

    Flea flea(fleaTexture);

    std::vector<Flea> FleasV;
    bool repeat = false;

    sf::Clock clock;
    sf::Time time;

    /** SPIDER LOAD TEXTURE **/
    sf::Texture spiderTexture;
    spiderTexture.loadFromFile("/Users/limasnursalim/Documents/PCC/CS 008/Centipede/Sprites/spider.png");

    Spider spider(spiderTexture);

    std::vector<Spider> SpiderV;
    bool repeat2 = false;
    bool touchGround = false;
    bool touchWall = false;

    /***********************/

   std::vector<Mushroom> level1;
   for (int i = 0; i < 40; i++) {
       Mushroom mushroom(mushroomTexture);
       mushroom.setSize(sf::Vector2f(2.5f, 2.5f));
       mushroom.setPosition(sf::Vector2f(rand() % 1300 + 500 , rand() % 1300 + 200));
       level1.push_back(mushroom);
   }

    while (window.isOpen()) {
        sf::Event event;
        time = clock.getElapsedTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        /******************* PLAYER MOVEMENT ****************/

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            p.move(sf::Vector2f(1.5f, 0.0f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            p.move(sf::Vector2f(-1.5f, 0.0f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            p.move(sf::Vector2f(0.0f, -1.5f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            p.move(sf::Vector2f(0.0f, 1.5f));
        }

        /******************** FLEA ***********************/

        //The speed of the fleas
        sf::Vector2f fleasSpeed(0,2.0f);

        //Increase vector every 5 seconds
        if ((static_cast<int>(time.asSeconds())%5) == 0) {
            if(!repeat) {
                Flea newFlea(fleaTexture);
                newFlea.setPosition(sf::Vector2f(rand()%2000+100,0));
                newFlea.setSize(sf::Vector2f(2.0f,2.0f));
                FleasV.push_back(newFlea);
                repeat = true;
            }
        }

        //To make sure that the vector don't increase as for milliseconds
        if(static_cast<int>(time.asSeconds())%5 != 0) {
            repeat = false;
        }

        //Summon the Feas to the attack the player
        if(FleasV.size() != 0)
            FleasV[FleasV.size()-1].attack(fleasSpeed);

        //Delete the Feas when it collides with the player
        for (int i=0; i < FleasV.size(); i++) {
            if ((Collision::PixelPerfectTest(FleasV[FleasV.size() - 1].getSprite(), p.getSprite()))) {
                FleasV.erase(FleasV.begin() + i);
            }
        }

        /******************** SPIDER **********************/
        //Increase vector every 7 seconds to summon the spider
        if ((static_cast<int>(time.asSeconds())%7) == 0) {
            if(!repeat2) {
                Spider newSpider(spiderTexture);
                newSpider.setPosition(sf::Vector2f(rand()%2000,rand()%2000));
                newSpider.setSize(sf::Vector2f(4.0f,4.0f));
                SpiderV.push_back(newSpider);
                repeat2 = true;
            }
        }

        //To make sure that the vector don't increase as for milliseconds
        if(static_cast<int>(time.asSeconds())%7 != 0) {
            repeat2 = false;
        }

        //Direction of the spider moving
        if (SpiderV[SpiderV.size()-1].getPosition().y >= 2000)
            touchGround = true;
        if (SpiderV[SpiderV.size()-1].getPosition().y <= 0)
            touchGround = false;

        if (SpiderV[SpiderV.size()-1].getPosition().x >= 2000)
            touchWall = true;
        if (SpiderV[SpiderV.size()-1].getPosition().x <= 0)
            touchWall = false;

        //Spider will move and attack
        if (SpiderV.size() > 0) {
            if (touchGround) {
                SpiderV[SpiderV.size() - 1].attack(sf::Vector2f(0, -1.0f));
            } else {
                SpiderV[SpiderV.size() - 1].attack(sf::Vector2f(0, 1.0f));
            }
            if (touchWall) {
                SpiderV[SpiderV.size() - 1].attack(sf::Vector2f(-1.0f, 0));
            } else {
                SpiderV[SpiderV.size() - 1].attack(sf::Vector2f(1.0f, 0));
            }
        }

        if (time.asSeconds()>10) {
            SpiderV.erase(SpiderV.begin() - 1); //
            time = clock.restart();
        }


        //Delete the Spider when it collides with the player
        for (int i=0; i < SpiderV.size(); i++) {
            if ((Collision::PixelPerfectTest(SpiderV[SpiderV.size() - 1].getSprite(), p.getSprite())) && SpiderV.size()>0) {
                SpiderV.erase(SpiderV.begin() + i);
            }
        }

        /*************************************************/

        if (centipedeHead.getPosition().y <= 30.0f)
        {
            centipedeVelocity = sf::Vector2f(0.0f, 2.0f);
            centipedeHead.move(centipedeVelocity);
        }
//        if (centipedeHead.getPosition().x >= 500 && centipedeHead.getPosition().y >= 30.0f)
//        {
//            centipedeVelocity = sf::Vector2f(-2.0f, 0.0f);
//            centipedeHead.move(centipedeVelocity);
//        }

        /************ BULLET ************/
        if (shootTimer < 75) {
            shootTimer++;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 75) {
            Bullet newBullet(bulletTexture);
            newBullet.setPosition(sf::Vector2f(p.getPosition().x, p.getPosition().y));
            newBullet.setSize(sf::Vector2f(2.5f, 2.5f));
            bullets.push_back(newBullet);
            shootTimer = 0;
        }

        for (int i = 0; i < bullets.size(); i++){
            bullets[i].fire(-3);

            if (bullets[i].getSprite().getPosition().y < 0) {
                bullets.erase(bullets.begin() + i);
            }
        }

        for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < level1.size(); j++) {
                if (Collision::PixelPerfectTest(bullets[i].getSprite(), level1[j].getSprite())) {
                    bullets.erase(bullets.begin() + i);
                    level1[j].Update();
                    if (level1[j].getAnimation1().getiFrame() == 4) {
                        level1.erase(level1.begin() + j);
                    }
                }
            }
        }

        /*************************************************/

        //to make the player stop
        if (p.getPosition().x >= window.getSize().x - 50) {
            p.move(sf::Vector2f(-1.5f, 0.0f)); //to make it stop counter the speed
        }
        if (p.getPosition().x <= 0) {
            p.move(sf::Vector2f(1.5f, 0.0f));
        }
        if (p.getPosition().y >= window.getSize().y - 50) {
            p.move(sf::Vector2f(0.0f, -1.5f));
        }

        window.clear();
        p.draw(window);
        centipedeHead.draw(window);

        /*** FLEA DRAW ***/

        for (int i=0; i<FleasV.size(); i++) {
            FleasV[i].draw(window);
        }
        /*** SPIDER DRAW ***/

        for (int i=0; i<SpiderV.size(); i++) {
            window.draw(SpiderV[i]);
        }
        /**************/

        for (int i = 0; i < level1.size(); i++) {
            level1[i].draw(window);
        }

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].draw(window);
        }


            window.display();
        }
        return 0;
}

