//
// Created by alessandro on 07/12/18.
//

#include "Updater.h"
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int Updater::CollisionPlayer()
{

    int i=0;
    int playerlife=player->getHp();
    std::vector<Enemy*>::const_iterator iter;
    bool collision=false;
    for(iter=Enemy_vector->begin(); iter!=Enemy_vector->end(); iter++)
    {

        int Player_x = player->getPositionX();
        int Player_y = player->getPositionY();
        int Enemy_x = Enemy_vector->at(i)->getPositionX();
        int Enemy_y = Enemy_vector->at(i)->getPositionY();

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


            if(Player_x>=Enemy_x && Player_x<=Enemy_x+32)
            {
                if (Player_y >= Enemy_y && Player_y <= Enemy_y + 32)
                {
                    //std::cout << "COLLISIONE" << std::endl;
                    collision = true;
                }
            }
        }
        if(Enemy_vector->at(i)->getAggro())
        {
            if(collision)
            {
                player->setHp(player->getHp() - (*Enemy_vector->at(i)).getDamage());
                //std::cout<<"Il player ha "<<player->getHp()<<" di vita"<<std::endl;
                playerlife=player->getHp();
            }
        }
        i++;
    }
    return playerlife;
}

int Updater::CollisionProjectile(std::vector<Projectile*> *Projectile_vector, std::vector<Coin*> *Coin_vector)
{
    bool collision=false;

    int i=0;

    if(Projectile_vector->empty())
    {}
    else
    {


        std::vector<Enemy*>::const_iterator iter;
        for (iter=Enemy_vector->begin(); iter!=Enemy_vector->end(); iter++)
        {
                int Proj_x = Projectile_vector->at(0)->getPositionX();
                int Proj_y = Projectile_vector->at(0)->getPositionY();
                int Enemy_x = Enemy_vector->at(i)->getPositionX();
                int Enemy_y = Enemy_vector->at(i)->getPositionY();
                for (int j = 0; j < 4; j++)
                {
                    Proj_x += pow(j, 2) * (-14) + 42 * j + 2;
                    if (j == 0 || j == 1)
                    {
                        Proj_y += 2;
                    }
                    if (j == 2 || j == 3)
                    {
                        Proj_y += 30;
                    }

                    if (Proj_x >= Enemy_x && Proj_x <= Enemy_x + 32)
                    {
                        if (Proj_y >= Enemy_y && Proj_y <= Enemy_y + 32)
                        {
                            //std::cout << "COLLISIONE PROIETTILI" << std::endl;
                            collision = true;
                        }
                    }
                }

                std::vector<Projectile*>::const_iterator iter1;
                int projectile_counter = 0;
                for (iter1 = Projectile_vector->begin(); iter1 != Projectile_vector->end(); iter1++)
                {
                    if (collision)
                    {
                        (*Enemy_vector->at(i)).setAggro(true);
                        (*Enemy_vector->at(i)).setHp((*Enemy_vector->at(i)).getHp() - player->getDamage());
                        //std::cout << "Il nemico " << i << " ha " << (Enemy_vector->at(i))->getHp() << " di vita" << std::endl;
                        (*Projectile_vector->at(projectile_counter)).setDestroy(true);
                        collision = false;
                        if ((*Enemy_vector->at(i)).getHp() <= 0)
                        {
                            (*Enemy_vector->at(i)).setAlive(false);
                        }
                    }
                    projectile_counter++;
                }
                i++;
            }
        }

        //Cancellazione proiettili
        std::vector<Projectile*>::const_iterator iter2;
        int projectile_counter=0;
        for(iter2=Projectile_vector->begin(); iter2!=Projectile_vector->end(); iter2++)
        {
            if((*Projectile_vector->at(projectile_counter)).getDestroy()==true)
            {
                Projectile_vector->erase(iter2);
                break;
            }
            projectile_counter++;
        }

        //Cancellazione nemici e drop coin
        int j=0;
        std::vector<Enemy*>::const_iterator iter3;
        for(iter3=Enemy_vector->begin(); iter3!=Enemy_vector->end(); iter3++)
        {
            if(!Enemy_vector->at(j)->getAlive())
            {
                Coin_vector->push_back(new Coin((*Enemy_vector->at(j)).getPositionX(), (*Enemy_vector->at(j)).getPositionY(),5)); //drop coin
                kill=kill+1;
                Enemy_vector->erase(iter3);
                break;
            }
            j++;
        }

    return kill;
    }

void Updater::CollisionPickup(std::vector<Coin*> *Coin_vector, std::vector<Powerup*> *Powerup_vector)
{

    //COLLISIONE COIN
    bool collision = false;
    if (Coin_vector->empty())
    {}
    else
    {
        int Coin_x = Coin_vector->at(0)->getPositionX();
        int Coin_y = Coin_vector->at(0)->getPositionY();
        int Player_x = player->getPositionX();
        int Player_y = player->getPositionY();
        for (int j = 0; j < 4; j++)
        {
            Coin_x += pow(j, 2) * (-14) + 42 * j + 2;
            if (j == 0 || j == 1)
            {
                Coin_y += 2;
            }
            if (j == 2 || j == 3)
            {
                Coin_y += 30;
            }

            if (Coin_x >= Player_x && Coin_x <= Player_x + 32)
            {
                if (Coin_y >= Player_y && Coin_y <= Player_y + 32)
                {
                    //std::cout << "COLLISIONE COIN" << std::endl;
                    collision = true;
                }
            }
        }
        std::vector<Coin*>::const_iterator iter1;
        int coin_counter = 0;
        for (iter1 = Coin_vector->begin(); iter1 != Coin_vector->end(); iter1++)
        {
            if (collision)
            {
                player->wallet = player->wallet + Coin_vector->at(0)->getValue();
                (*Coin_vector->at(coin_counter)).setDestroy(true);
                collision = false;
            }
            coin_counter++;
        }

        std::vector<Coin*>::const_iterator iter4;
        coin_counter = 0;
        for (iter4 = Coin_vector->begin(); iter4 != Coin_vector->end(); iter4++)
        {
            if ((*Coin_vector->at(coin_counter)).getDestroy() == true)
            {
                Coin_vector->erase(iter4);
                break;
            }
            coin_counter++;
        }

    }

    //COLLISIONE POWERUP
    bool collision1=false;
    int i = 0;
    if (Powerup_vector->empty())
    {}
    else
    {
        std::vector<Powerup*>::const_iterator iter2;
        for (iter2 = Powerup_vector->begin(); iter2 != Powerup_vector->end(); iter2++)
        {
            int Powerup_x = Powerup_vector->at(i)->getPositionX();
            int Powerup_y = Powerup_vector->at(i)->getPositionY();
            int Player_x = player->getPositionX();
            int Player_y = player->getPositionY();
            for (int j = 0; j < 4; j++)
            {
                Powerup_x += pow(j, 2) * (-14) + 42 * j + 2;
                if (j == 0 || j == 1)
                {
                    Powerup_y += 2;
                }
                if (j == 2 || j == 3)
                {
                    Powerup_y += 30;
                }

                if (Powerup_x >= Player_x && Powerup_x <= Player_x + 32)
                {
                    if (Powerup_y >= Player_y && Powerup_y <= Player_y + 32)
                    {
                        //std::cout << "COLLISIONE POWERUP" << std::endl;
                        collision1 = true;
                    }
                }
            }
            std::vector<Powerup*>::const_iterator iter1;
            int powerup_counter = 0;
            for (iter1 = Powerup_vector->begin(); iter1 != Powerup_vector->end(); iter1++)
            {
                if(player->wallet >= Powerup_vector->at(i)->getPrice())
                {
                    if (collision1)
                    {
                        player->wallet=player->wallet-Powerup_vector->at(i)->getPrice();
                        (*Powerup_vector->at(powerup_counter)).setDestroy(true);
                        collision1 = false;
                        if(Powerup_vector->at(i)->getHeal()==true)
                        {
                            player->setHp(100);
                        }
                        if(Powerup_vector->at(i)->getGun()==true)
                        {
                            player->setDamage(10);
                        }
                     }
                    powerup_counter++;
                }
            }
            i++;
        }


        std::vector<Powerup*>::const_iterator iter4;
        int powerup_counter = 0;
        for (iter4 = Powerup_vector->begin(); iter4 != Powerup_vector->end(); iter4++)
        {
            if ((*Powerup_vector->at(powerup_counter)).getDestroy() == true)
            {
                Powerup_vector->erase(iter4);
                break;
            }
            powerup_counter++;
        }
    }
}

int Updater::is_in_sight(int j)
{
    std::vector<Enemy *>::const_iterator iter1;
    int line_of_sight=0;
    for (iter1 = Enemy_vector->begin(); iter1 != Enemy_vector->end(); iter1++)
    {
        line_of_sight = sqrt(pow(player->getPositionX() - Enemy_vector->at(j)->getPositionX(), 2) +
                                        pow(player->getPositionY() - Enemy_vector->at(j)->getPositionY(), 2));
    }
    return line_of_sight;
}