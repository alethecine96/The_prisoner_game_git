//
// Created by alessandro on 07/12/18.
//

#include "Observer.h"
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


void Observer::CollisionPlayer()
{

    int i=0;
    std::vector<Drawable*>::const_iterator iter;
    bool collision=false;
    for(iter=array->begin(); iter!=array->end(); iter++)
    {

        int Player_x = player->getPositionX();
        int Player_y = player->getPositionY();
        int Enemy_x = array->at(i)->getPositionX();
        int Enemy_y = array->at(i)->getPositionY();

        for (int j= 0; j < 4; j++)
        {
            Player_x += pow(j, 2) * (-14) + 42 * j + 2;
            if (j == 0 || j == 1)
            {
                Player_y += 2;
            }
            if (j == 2 || j == 3)
            {
                Player_y += 30;
            }


            if(Player_x>=Enemy_x && Player_x<=Enemy_x+32) {
                if (Player_y >= Enemy_y && Player_y <= Enemy_y + 32) {
                    std::cout << "COLLISIONE" << std::endl;
                    collision = true;
                }
            }
        }
        if(array->at(i)->getAggro())
        {
            if(collision)
            {
                player->setHp(player->getHp() - (*array->at(i)).getDamage());
                std::cout<<"Il player ha "<<player->getHp()<<" di vita"<<std::endl;
            }
        }
        i++;
    }

}

void Observer::CollisionProjectile(std::vector<Drawable*> *vector, std::vector<Drawable*> *vector1) {
    bool collision=false;

    int i=0;
    if(vector->empty()){}
    else{


        std::vector<Drawable*>::const_iterator iter;
        for (iter=array->begin(); iter!=array->end(); iter++) {
                int Proj_x = vector->at(0)->getPositionX();
                int Proj_y = vector->at(0)->getPositionY();
                int Enemy_x = array->at(i)->getPositionX();
                int Enemy_y = array->at(i)->getPositionY();
                for (int j = 0; j < 4; j++) {
                    Proj_x += pow(j, 2) * (-14) + 42 * j + 2;
                    if (j == 0 || j == 1) {
                        Proj_y += 2;
                    }
                    if (j == 2 || j == 3) {
                        Proj_y += 30;
                    }

                    if (Proj_x >= Enemy_x && Proj_x <= Enemy_x + 32) {
                        if (Proj_y >= Enemy_y && Proj_y <= Enemy_y + 32) {
                            std::cout << "COLLISIONE PROIETTILI" << std::endl;
                            collision = true;
                        }
                    }
                }

                std::vector<Drawable *>::const_iterator iter1;
                int projectile_counter = 0;
                for (iter1 = vector->begin(); iter1 != vector->end(); iter1++) {
                    if (collision) {
                        (*array->at(i)).setAggro(true);
                        (*array->at(i)).setHp((*array->at(i)).getHp() - player->getDamage());
                        std::cout << "Il nemico " << i << " ha " << (array->at(i))->getHp() << " di vita" << std::endl;
                        (*vector->at(projectile_counter)).setDestroy(true);
                        collision = false;
                        if ((*array->at(i)).getHp() <= 0) {
                            (*array->at(i)).setAlive(false);
                        }
                    }
                    projectile_counter++;

                }

                i++;
            }
        }

        std::vector<Drawable*>::const_iterator iter2;
        int projectile_counter=0;
        for(iter2=vector->begin(); iter2!=vector->end(); iter2++){
            if((*vector->at(projectile_counter)).getDestroy()==true){
                vector->erase(iter2);
                break;
            }
            projectile_counter++;
        }

        int j=0;
        std::vector<Drawable*>::const_iterator iter3;
        for(iter3=array->begin(); iter3!=array->end(); iter3++){
            if(!array->at(j)->getAlive()){
                vector1->push_back(new Coin((*array->at(j)).getPositionX(), (*array->at(j)).getPositionY())); //drop coin
                array->erase(iter3);
                break;
            }
            j++;
        }

    }

void Observer::CollisionPickup(std::vector<Drawable *> *vector, std::vector<Drawable*> *vector1) {

    //COLLISIONE COIN
    bool collision = false;
    if (vector->empty()) {}
    else {
        int Coin_x = vector->at(0)->getPositionX();
        int Coin_y = vector->at(0)->getPositionY();
        int Player_x = player->getPositionX();
        int Player_y = player->getPositionY();
        for (int j = 0; j < 4; j++) {
            Coin_x += pow(j, 2) * (-14) + 42 * j + 2;
            if (j == 0 || j == 1) {
                Coin_y += 2;
            }
            if (j == 2 || j == 3) {
                Coin_y += 30;
            }

            if (Coin_x >= Player_x && Coin_x <= Player_x + 32) {
                if (Coin_y >= Player_y && Coin_y <= Player_y + 32) {
                    std::cout << "COLLISIONE COIN" << std::endl;
                    collision = true;
                }
            }
        }
        std::vector<Drawable *>::const_iterator iter1;
        int coin_counter = 0;
        for (iter1 = vector->begin(); iter1 != vector->end(); iter1++) {
            if (collision) {
                player->wallet = player->wallet + 5;
                (*vector->at(coin_counter)).setDestroy(true);
                collision = false;
            }
            coin_counter++;
        }

        std::vector<Drawable *>::const_iterator iter4;
        coin_counter = 0;
        for (iter4 = vector->begin(); iter4 != vector->end(); iter4++) {
            if ((*vector->at(coin_counter)).getDestroy() == true) {
                vector->erase(iter4);
                break;
            }
            coin_counter++;
        }

    }

    //COLLISIONE POWERUP
    bool collision1=false;
    int i = 0;
    if (vector1->empty()) {}
    else {
        std::vector<Drawable *>::const_iterator iter2;
        for (iter2 = vector1->begin(); iter2 != vector1->end(); iter2++) {
            int Powerup_x = vector1->at(i)->getPositionX();
            int Powerup_y = vector1->at(i)->getPositionY();
            int Player_x = player->getPositionX();
            int Player_y = player->getPositionY();
            for (int j = 0; j < 4; j++) {
                Powerup_x += pow(j, 2) * (-14) + 42 * j + 2;
                if (j == 0 || j == 1) {
                    Powerup_y += 2;
                }
                if (j == 2 || j == 3) {
                    Powerup_y += 30;
                }

                if (Powerup_x >= Player_x && Powerup_x <= Player_x + 32) {
                    if (Powerup_y >= Player_y && Powerup_y <= Player_y + 32) {
                        std::cout << "COLLISIONE POWERUP" << std::endl;
                        collision1 = true;
                    }
                }
            }
            std::vector<Drawable *>::const_iterator iter1;
            int powerup_counter = 0;
            for (iter1 = vector1->begin(); iter1 != vector1->end(); iter1++) {
                if(player->wallet >= vector1->at(i)->getPrice()) {
                    if (collision1) {
                        player->wallet=player->wallet-vector1->at(i)->getPrice();
                        (*vector1->at(powerup_counter)).setDestroy(true);
                        collision1 = false;
                        if(vector1->at(i)->getHeal()==true){
                            player->hp=100;
                        }
                        if(vector1->at(i)->getGun()==true){
                            player->setDamage(10);
                        }
                     }
                    powerup_counter++;
                }
            }
            i++;
        }


        std::vector<Drawable *>::const_iterator iter4;
        int powerup_counter = 0;
        for (iter4 = vector1->begin(); iter4 != vector1->end(); iter4++) {
            if ((*vector1->at(powerup_counter)).getDestroy() == true) {
                vector1->erase(iter4);
                break;
            }
            powerup_counter++;
        }
    }
}

void Observer::MoveEnemy(){
    //Movimento nemici
    std::vector<Drawable *>::const_iterator iter1;
    int range=75;
    int direction;
    int j=0;
    int i=0;
    for (iter1 = array->begin(); iter1 != array->end(); iter1++) {
        if(array->at(j)->getAggro()==false)
            (array->at(j))->move();
        else{
            if(player->getPositionX() == array->at(j)->getPositionX()){  //nel range di X
                if(player->getPositionY() < array->at(j)->getPositionY()){ //Player sopra al nemico
                    direction=3; //UP
                    (array->at(j))->follow(direction);
                }
                else if(player->getPositionY() >= array->at(j)->getPositionY()){ //Player sotto a nemico
                    direction=0; //DOWN
                    (array->at(j))->follow(direction);
                }
            }

            else if(player->getPositionX() < array->at(j)->getPositionX()){
                direction=1;
                (array->at(j))->follow(direction);
            }
            else if(player->getPositionX() > array->at(j)->getPositionX()){
                direction=2;
                (array->at(j))->follow(direction);
            }
        }
        if (i < array->size()) {
            j++;
        } else {
            j = 1;
        }
    }
}

