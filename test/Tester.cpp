//
// Created by alessandro on 04/02/19.
//

#include <gtest/gtest.h>
#include "../Entity.h"
#include "../Enemy.h"
#include "../Player.h"
#include "../Mappa.h"
#include "../Updater.h"
#include "../Strategy.h"

TEST(Mappa, CollisionTest)  //TODO ultimo test player che uccide il nemico da risolvere l'ultima condizione, sempre falsa
{

    int width=40;
    int heigth=36;
    Keyboard_Movement keyboard;
    std::vector<Projectile*> array_of_bullet;
    std::vector<Coin*> array_of_coin;
    Player player(33,50 ,4, 100,5,down, &array_of_bullet, &keyboard);
    std::vector<Enemy*> array_of_enemies;

    std::vector<Powerup*> array_of_powerup;
    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);

    ASSERT_TRUE(mappa.isWalkable(player.getPositionX(),player.getPositionY(),player.getDirection()));
    player.move(left);
    ASSERT_FALSE(mappa.isWalkable(player.getPositionX(),player.getPositionY(),player.getDirection()));
}

TEST(Player_death, Enemy_kill_player)
{
    int width=40;
    int heigth=36;
    Keyboard_Movement keyboard;
    Random_Movement random_movement;
    std::vector<Projectile*> array_of_bullet;
    std::vector<Coin*> array_of_coin;
    Player player(34,50 ,4, 1,5,down, &array_of_bullet, &keyboard);
    std::vector<Enemy*> array_of_enemies;
    array_of_enemies.push_back(new Enemy (34,50,1, 10, 100, down, &array_of_bullet, &random_movement, &player, false));

    std::vector<Powerup*> array_of_powerup;
    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);
    Updater updater(&array_of_enemies, &player, &mappa);
    array_of_enemies.at(0)->setAggro(true);
    ASSERT_FALSE(player.getHp()<=0);
    updater.CollisionPlayer();
    ASSERT_TRUE(player.getHp()<=0);
}

TEST(Enemy_death, Player_kill_Enemy)
{
    int width=40;
    int heigth=36;
    Keyboard_Movement keyboard;
    Random_Movement random_movement;
    std::vector<Projectile*> array_of_bullet;
    std::vector<Coin*> array_of_coin;
    Player player(34,50 ,4, 100,100,down, &array_of_bullet, &keyboard);
    std::vector<Enemy*> array_of_enemies;
    array_of_enemies.push_back(new Enemy(38,66,1, 1, 100, down, &array_of_bullet, &random_movement, &player, false));

    std::vector<Powerup*> array_of_powerup;
    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);
    Updater updater(&array_of_enemies, &player, &mappa);
    ASSERT_FALSE(array_of_enemies.at(0)->getHp()<=0);
    player.shoot();
    std::vector<Projectile*>::const_iterator iter;
    int i = 0;
    if (!array_of_bullet.empty())
    {
        for(int j=0; j<4; j++)
        {
            for (iter = array_of_bullet.begin(); iter != array_of_bullet.end(); iter++)
            {

                array_of_bullet.at(i)->move();

                if (!(mappa.isWalkable((*array_of_bullet.at(i)).getPositionX(),
                                       (*array_of_bullet.at(i)).getPositionY(), player.getDirection())))
                {
                    array_of_bullet.erase(array_of_bullet.begin());
                    break;
                }
            }
        }
    }

    int kill=updater.CollisionProjectile(&array_of_bullet, &array_of_coin);
    //std::cout<<array_of_enemies.at(0)->getHp()<<std::endl;
    ASSERT_TRUE(kill==1);

}

//TODO test per vedere se viene preso il powerup
TEST(Taken_Powerup, Powerup_is_taken)
{
    int width=40;
    int heigth=36;
    Keyboard_Movement keyboard;
    std::vector<Projectile*> array_of_bullet;
    std::vector<Coin*> array_of_coin;
    Player player(34,50,16,100,5,down, &array_of_bullet, &keyboard);
    std::vector<Enemy*> array_of_enemies;
    std::vector<Powerup*> array_of_powerup;
    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);
    array_of_powerup.push_back(new Powerup(70,50,true,false));
    Updater updater(&array_of_enemies,&player,&mappa);
    ASSERT_FALSE(array_of_powerup.empty());
    player.move(right);
    updater.CollisionPickup(&array_of_coin,&array_of_powerup);
    ASSERT_TRUE(array_of_powerup.empty());
}




