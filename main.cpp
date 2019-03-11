#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include "menu.h"
#include "Mappa.h"
#include "Enemy.h"
#include "Update.h"
#include "Powerup.h"
#include <array>

int main()
{

    int width=40;
    int heigth=36;
    std::vector<Projectile*> array_of_bullet;

    std::vector<Coin*> array_of_coin;
    //Strategy strategy;
    Keyboard_Movement keyboard1;

    Player player(34,50 ,4, 100, &array_of_bullet, &keyboard1);
    //player.SetStrategy(&keyboard1);
    //player.PlayerInterface();
    Keyboard_Movement *keyboard;
    Random_Movement random_movement;

    std::vector<Enemy*> array_of_enemies; //Vettore DI Entity (qui ci sono tutti gli oggetti disegnabili)
    //riempimento array SE SI AGGIUNGONO NEMICI CAMBIARE NUMENEMIES IN OBSERVER.H
    array_of_enemies.push_back(new Enemy (34,100,1, 10, 1, &array_of_bullet, &random_movement)); // posX, posY, speed, hp, damage
    array_of_enemies.push_back(new Enemy (450,50,1, 10, 1, &array_of_bullet, &random_movement));
    array_of_enemies.push_back(new Enemy (850,50,1, 10, 1, &array_of_bullet, &random_movement));
    std::vector<Powerup*> array_of_powerup;
    array_of_powerup.push_back(new Powerup (350,50, true, false));
    array_of_powerup.push_back(new Powerup (450,550,false, true));

    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);
    bool camminabile=mappa.isWalkable(12,12,1);


    Update update(&array_of_enemies, &player, &mappa); //oggetto update


    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }

    sf::Text textWin; //Text Win
    textWin.setFont(font);
    textWin.setColor(sf::Color::Red);
    textWin.setString("YOU WIN");
    textWin.setPosition(350, 450);
    textWin.setScale(2.0f, 2.0f);

    sf::Text textLose;
    textLose.setFont(font);
    textLose.setColor(sf::Color::Red);
    textLose.setString("YOU LOSE");
    textLose.setPosition(350, 450);
    textLose.setScale(2.0f, 2.0f);

    //Create menu window
    sf::RenderWindow windowMenu(sf::VideoMode(1600,900),"Gioco");
    windowMenu.setVerticalSyncEnabled(true);
    int chooseMenu;
    Menu menu(windowMenu.getSize().x, windowMenu.getSize().y);

    //run the MainMenu loop
    while (windowMenu.isOpen()) {

        //handle events
        sf::Event event;
        while (windowMenu.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    chooseMenu=1;
                                    std::cout << "Play button has been pressed" << std::endl;
                                    windowMenu.close();
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    windowMenu.close();
                                    break;
                            }
                            break;
                    }
            }
        }

        windowMenu.clear();
        menu.draw(windowMenu);
        windowMenu.display();
    }


    //Finestra gioco
    sf::RenderWindow window(sf::VideoMode(1280, 704), "Game"); //crea la finestra con il gioco


    if(chooseMenu==1) {
        sf::Clock gameclock;
        while (window.isOpen()) {
            sf::Event event;


            while (window.pollEvent(event)) {

                switch (event.type) {
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Space:
                                player.shoot();
                                break;
                            case sf::Keyboard::Up: //0 down,1 left, 2 right, 3 up
                                player.setDirection(3);
                                if(mappa.isWalkable(player.x,player.y-player.speed,player.direction)) {
                                    player.move(3);
                                }
                                    break;
                            case sf::Keyboard::Down:
                                player.setDirection(0);
                                if(mappa.isWalkable(player.x,player.y+player.speed,player.direction)) {
                                    player.move(0);
                                }
                                break;
                            case sf::Keyboard::Left:
                                player.setDirection(1);
                                if(mappa.isWalkable(player.x-player.speed,player.y,player.direction)) {
                                    player.move(1);
                                }
                                break;
                            case sf::Keyboard::Right:
                                player.setDirection(2);
                                if(mappa.isWalkable(player.x+player.speed,player.y,player.direction)) {
                                    player.move(2);
                                }
                                break;
                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                        }

                        sf::View playerview;
                        playerview.setCenter(sf::Vector2f(player.getPositionX() + 32, player.getPositionY() + 32));
                        playerview.setSize(sf::Vector2f(1150, 640));
                        window.setView(playerview);
                        break;
                }
            }


            /*int j=0;
            if(j<1) {
                std::vector<Enemy *>::const_iterator iterenemy;
                int k = 0;
                if (array_of_enemies.empty()) {}
                else {
                    for (iterenemy = array_of_enemies.begin(); iterenemy != array_of_enemies.end(); iterenemy++) {
                        (*array_of_enemies.at(k)).shoot();
                    }
                    k++;
                }
                j++;
            }*/

            //Cancellazione proiettili
            std::vector<Projectile*>::const_iterator iter;
            int i = 0;
            if (array_of_bullet.empty()) {}
            else {
                for (iter = array_of_bullet.begin(); iter != array_of_bullet.end(); iter++) {

                    (*array_of_bullet.at(i)).move();

                    if (!(mappa.isWalkable((*array_of_bullet.at(i)).getPositionX(),
                                          (*array_of_bullet.at(i)).getPositionY(), player.getDirection()))) {
                        array_of_bullet.erase(array_of_bullet.begin());
                        break;
                    }
                    i++;
                }
            }



            //std::cout<<gameclock.getElapsedTime().asSeconds()<<std::endl;
            //Funzioni Update
            std::vector<Enemy *>::const_iterator iterenemy;
            int k = 0;
            if (array_of_enemies.empty()) {}
            else
                {
                    for (iterenemy = array_of_enemies.begin(); iterenemy != array_of_enemies.end(); iterenemy++)
                    {
                        if(array_of_enemies.at(k)->getDirection()==0)
                        {
                            array_of_enemies.at(k)->setcanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX(),array_of_enemies.at(k)->getPositionY()+array_of_enemies.at(k)->getSpeed(),0));
                            array_of_enemies.at(k)->move();
                        }
                        else if(array_of_enemies.at(k)->getDirection()==1)
                        {
                            array_of_enemies.at(k)->setcanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX()-array_of_enemies.at(k)->getSpeed(),array_of_enemies.at(k)->getPositionY(),0));
                            array_of_enemies.at(k)->move();
                        }
                        else if(array_of_enemies.at(k)->getDirection()==2)
                        {
                            array_of_enemies.at(k)->setcanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX()+array_of_enemies.at(k)->getSpeed(),array_of_enemies.at(k)->getPositionY(),0));
                            array_of_enemies.at(k)->move();
                        }
                        else if(array_of_enemies.at(k)->getDirection()==3)
                        {
                            array_of_enemies.at(k)->setcanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX(), array_of_enemies.at(k)->getPositionY() - array_of_enemies.at(k)->getSpeed(), 0));
                            array_of_enemies.at(k)->move();
                        }
                        k++;
                    }
                }




            int playerlife= update.CollisionPlayer();
            int numEnemies = update.CollisionProjectile(&array_of_bullet, &array_of_coin);
            update.CollisionPickup(&array_of_coin, &array_of_powerup);

            //std::cout<<array_of_enemies.at(0)->getAlive()<<std::endl;
            window.clear();
            window.draw(mappa);
            if(numEnemies == 0){
                sf::View winview;
                winview.setCenter(500,500);
                window.setView(winview);
                window.clear();
                window.draw(textWin);
            }

            if(playerlife <= 0){
                sf::View loseview;
                loseview.setCenter(500,500);
                window.setView(loseview);
                window.clear();
                window.draw(textLose);
            }
            window.display();
        }
        return 0;
    }
}

