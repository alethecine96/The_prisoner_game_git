#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include "menu.h"
#include "Mappa.h"
#include "MapLoader.h"
#include "Enemy.h"
#include "Observer.h"
#include "Powerup.h"
#include <array>

int main()
{

    int width=40;
    int heigth=36;
    int tileSize=32;

    int caricatore_proiettili=10;

  //  Menu menu;

//    menu.start();
    MapLoader mapLoader;
    int* mapArray = mapLoader.load("mappetta prova",width*heigth); //carica mappetta prova in mapArray

    Eyes eyes(mapArray,width);  //gli occhi sono gli stessi per tutti

    std::vector<Drawable*> array_of_bullet;

    std::vector<Drawable*> array_of_coin;

    Player player(250,50 ,4, 100, &eyes, &array_of_bullet);

    std::vector<Drawable*> array_of_enemies; //Vettore DI Drawable (qui ci sono tutti gli oggetti disegnabili)
    //riempimento array SE SI AGGIUNGONO NEMICI CAMBIARE NUMENEMIES IN OBSERVER.H
    array_of_enemies.push_back(new Enemy (50,50 ,1, 1, 10, &eyes)); // posX, posY, speed, damage, hp
    array_of_enemies.push_back(new Enemy (450,50,1, 1, 10, &eyes));
    array_of_enemies.push_back(new Enemy (850,50,1, 1, 10, &eyes));

    std::vector<Drawable*> array_of_powerup;
    array_of_powerup.push_back(new Powerup (350,50, true, false));
    array_of_powerup.push_back(new Powerup (450,550,false, true));

    Mappa mappa(&array_of_enemies, &array_of_bullet, mapArray, &player, &array_of_coin, &array_of_powerup); //crea oggetto mappa

    Observer observer(&array_of_enemies, &player); //oggetto observer

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

        // draw the map
        windowMenu.clear();
        menu.draw(windowMenu);
        windowMenu.display();
    }


    //Finestra gioco
    sf::RenderWindow window(sf::VideoMode(1280, 704), "Mappa"); //crea la finestra con il gioco

    if(chooseMenu==1) {
        while (window.isOpen()) {
            sf::Event event;


            while (window.pollEvent(event)) {

                switch (event.type) {
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Space:
                                player.shoot();
                                break;
                            case sf::Keyboard::Up:
                                player.move(0, -1);
                                break;
                            case sf::Keyboard::Down:
                                player.move(0, +1);
                                break;
                            case sf::Keyboard::Left:
                                player.move(-1, 0);
                                break;
                            case sf::Keyboard::Right:
                                player.move(1, 0);
                                break;
                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                        }

                        //std::cout<<(*array_of_bullet.at(0)).getPositionX()<<std::endl;

                        sf::View playerview;
                        //sf::View mapview;
                        //sf::View minimapview;
                        playerview.setCenter(sf::Vector2f(player.getPositionX() + 32, player.getPositionY() + 32));
                        playerview.setSize(sf::Vector2f(1150, 640));
                        //mapview.setViewport(sf::FloatRect(0, 0, 1 , 1));
                        //minimapview.setViewport(sf::FloatRect(0.75, 0, 0.25, 0.25));
                        window.setView(playerview);
                        //window.setView(minimapview);
                        //window.setView(mapview);

                        break;

                }
            }

            //Cancellazione proiettili
            std::vector<Drawable *>::const_iterator iter;
            int i = 0;
            if (array_of_bullet.empty()) {}
            else {
                for (iter = array_of_bullet.begin(); iter != array_of_bullet.end(); iter++) {

                    (*array_of_bullet.at(i)).move();

                    if (!(eyes.isWalkable((*array_of_bullet.at(i)).getPositionX(),
                                          (*array_of_bullet.at(i)).getPositionY(), player.getDirection()))) {
                        array_of_bullet.erase(array_of_bullet.begin());
                        break;
                    }
                    i++;
                }
            }
            //Funzioni Update
            observer.MoveEnemy();
            int playerlife= observer.CollisionPlayer();
            int numEnemies = observer.CollisionProjectile(&array_of_bullet, &array_of_coin);
            observer.CollisionPickup(&array_of_coin, &array_of_powerup);

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

