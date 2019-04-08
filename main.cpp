#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include "menu.h"
#include "Mappa.h"
#include "Enemy.h"
#include "Updater.h"
#include "Powerup.h"
#include "Client.h"
#include "Achievement.h"
#include "Observer.h"
#include "Subject.h"
#include <array>
int main()  //TODO fare enumfile con tutti i numeri magici
{
    std::string stringAch;
    std::vector<Projectile*> array_of_bullet;

    std::vector<Coin*> array_of_coin;
    //Strategy strategy;
    //array_of_bullet.push_back(new Projectile(100,100,2,0));
    Keyboard_Movement keyboard;
    Random_Movement random_movement;
    Follow_Movement follow_movement;
    Patrol_Movement patrol_movement;

    Player player(34,50 ,4, 100,5,down, &array_of_bullet, &keyboard);
    std::vector<Enemy*> array_of_enemies; //Vettore DI Entity (qui ci sono tutti gli oggetti disegnabili)
    //riempimento array SE SI AGGIUNGONO NEMICI CAMBIARE NUMENEMIES IN OBSERVER.H
    array_of_enemies.push_back(new Enemy (34,100,1, 10, 1, down, &array_of_bullet, &random_movement, &player, false)); // posX, posY, speed, hp, damage
    array_of_enemies.push_back(new Enemy (450,50,1, 10, 1, down, &array_of_bullet, &random_movement, &player, false));
    array_of_enemies.push_back(new Enemy (450,450,1, 10, 1, down, &array_of_bullet, &patrol_movement, &player, true));
    std::vector<Powerup*> array_of_powerup;
    array_of_powerup.push_back(new Powerup (350,50, true, false));
    array_of_powerup.push_back(new Powerup (514,514,false, true));

    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*height);

    Updater update(&array_of_enemies, &player, &mappa); //oggetto update

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // TODO handle error
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

    sf::Text textKill;
    textKill.setFont(font);
    textLose.setColor(sf::Color::Red);
    textLose.setPosition(350, 450);
    textLose.setScale(2.0f, 2.0f);

    Achievement achievement;
    Client client(&achievement);
    achievement.registerObserver(&client);

    //Create menu window
    sf::RenderWindow windowMenu(sf::VideoMode(window_width,window_height),"Gioco");
    windowMenu.setVerticalSyncEnabled(true);
    int chooseMenu;
    Menu menu(windowMenu.getSize().x, windowMenu.getSize().y);


    //run the MainMenu loop
    while (windowMenu.isOpen())
    {

        //handle events
        sf::Event event;
        while (windowMenu.pollEvent(event))
        {
            switch (event.type)
            {
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
    sf::RenderWindow window(sf::VideoMode(game_window_width,game_window_height), "Game"); //crea la finestra con il gioco


    if(chooseMenu==1)
    {
        sf::Clock gameclock;
        while (window.isOpen())
        {
            sf::Event event;


            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                    case sf::Event::KeyPressed:
                        switch (event.key.code)
                        {
                            case sf::Keyboard::Space:
                                player.shoot();
                                break;
                            case sf::Keyboard::Up:
                                if(mappa.isWalkable(player.getPositionX(),player.getPositionY()-player.getSpeed(),player.getDirection()))
                                {
                                    player.move(up);
                                }
                                break;
                            case sf::Keyboard::Down:
                                if(mappa.isWalkable(player.getPositionX(),player.getPositionY()+player.getSpeed(),player.getDirection()))
                                {
                                    player.move(down);
                                }
                                break;
                            case sf::Keyboard::Left:
                                if(mappa.isWalkable(player.getPositionX()-player.getSpeed(),player.getPositionY(),player.getDirection()))
                                {
                                    player.move(left);
                                }
                                break;
                            case sf::Keyboard::Right:
                                if(mappa.isWalkable(player.getPositionX()+player.getSpeed(),player.getPositionY(),player.getDirection()))
                                {
                                    player.move(right);
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

            //Cancellazione proiettili
            std::vector<Projectile*>::const_iterator iter;
            int i = 0;
            if (!array_of_bullet.empty())
            {
                for (iter = array_of_bullet.begin(); iter != array_of_bullet.end(); iter++)
                {

                    (*array_of_bullet.at(i)).move();

                    if (!(mappa.isWalkable((array_of_bullet.at(i))->getPositionX(),
                                          (array_of_bullet.at(i))->getPositionY(), player.getDirection())))
                    {
                        array_of_bullet.erase(array_of_bullet.begin());
                        break;
                    }
                    i++;
                }
            }
            //std::cout<<gameclock.getElapsedTime().asSeconds()<<std::endl;
            //Funzioni Updater
            int playerlife= update.CollisionPlayer();

            int kill= update.CollisionProjectile(&array_of_bullet, &array_of_coin);
            update.CollisionPickup(&array_of_coin, &array_of_powerup);
            achievement.setState(kill);
            textKill.setString(client.getTextAch());

            std::vector<Enemy *>::const_iterator iterenemy;
            int k = 0;
            if (!array_of_enemies.empty())
            {
                for (iterenemy = array_of_enemies.begin(); iterenemy != array_of_enemies.end(); iterenemy++)
                {
                    if(update.is_in_sight(k)>sight)
                    {
                        array_of_enemies.at(k)->setAggro(false);
                    }
                    if(array_of_enemies.at(k)->getsupervisor() && !array_of_enemies.at(k)->getAggro() && update.is_in_sight(k)>sight)
                    {
                        array_of_enemies.at(k)->setStrategy(&patrol_movement);
                    }
                    else if(!array_of_enemies.at(k)->getAggro() && update.is_in_sight(k)>sight && !array_of_enemies.at(k)->getsupervisor())
                    {
                        array_of_enemies.at(k)->setStrategy(&random_movement);
                    }
                    else if(array_of_enemies.at(k)->getAggro() && update.is_in_sight(k)<sight)
                    {
                        array_of_enemies.at(k)->setStrategy(&follow_movement);
                    }
                    if(array_of_enemies.at(k)->getDirection()==down)
                    {
                        array_of_enemies.at(k)->setCanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX(),array_of_enemies.at(k)->getPositionY()+array_of_enemies.at(k)->getSpeed(),0));
                        array_of_enemies.at(k)->move();
                    }
                    else if(array_of_enemies.at(k)->getDirection()==left)
                    {
                        array_of_enemies.at(k)->setCanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX()-array_of_enemies.at(k)->getSpeed(),array_of_enemies.at(k)->getPositionY(),0));
                        array_of_enemies.at(k)->move();
                    }
                    else if(array_of_enemies.at(k)->getDirection()==right)
                    {
                        array_of_enemies.at(k)->setCanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX()+array_of_enemies.at(k)->getSpeed(),array_of_enemies.at(k)->getPositionY(),0));
                        array_of_enemies.at(k)->move();
                    }
                    else if(array_of_enemies.at(k)->getDirection()==up)
                    {
                        array_of_enemies.at(k)->setCanmove(mappa.isWalkable(array_of_enemies.at(k)->getPositionX(), array_of_enemies.at(k)->getPositionY() - array_of_enemies.at(k)->getSpeed(), 0));
                        array_of_enemies.at(k)->move();
                    }
                    k++;
                }
            }

            window.clear();
            window.draw(mappa);
            window.draw(textKill);
            if(kill == 3)
            {
                sf::View winview;
                winview.setCenter(500,500);
                window.setView(winview);
                window.clear();
                window.draw(textWin);
            }

            if(playerlife <= 0)
            {
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

