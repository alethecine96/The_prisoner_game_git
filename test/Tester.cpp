//
// Created by alessandro on 04/02/19.
//

#include <gtest/gtest.h>
#include "../Entity.h"
#include "../Enemy.h"
#include "../Player.h"
#include "../Mappa.h"
#include "../Update.h"


TEST(Mappa, CollisionTest){

    int width=40;
    int heigth=36;
    std::vector<Projectile*> array_of_bullet;
    std::vector<Coin*> array_of_coin;
    Player player(34,50 ,4, 100, &array_of_bullet);
    std::vector<Enemy*> array_of_enemies;

    std::vector<Powerup*> array_of_powerup;
    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);


    Update update(&array_of_enemies, &player, &mappa);
    update.MoveEnemy();
    ASSERT_TRUE(update.Collision(0,0));
    ASSERT_FALSE(update.Collision(-3,0));
}

TEST(Player_death, Enemy_kill_player){
    int width=40;
    int heigth=36;
    std::vector<Projectile*> array_of_bullet;
    std::vector<Coin*> array_of_coin;
    Player player(34,50,4, 1, &array_of_bullet);
    std::vector<Enemy*> array_of_enemies;
    array_of_enemies.push_back(new Enemy (34,50 ,1, 1, 100, &array_of_bullet));

    std::vector<Powerup*> array_of_powerup;
    Mappa mappa(&array_of_enemies, &array_of_bullet,&player, &array_of_coin, &array_of_powerup); //crea oggetto mappa
    mappa.load("mappetta prova",width*heigth);


    Update update(&array_of_enemies, &player, &mappa);
    array_of_enemies.at(0)->setAggro(true);

    update.CollisionPlayer();
    ASSERT_TRUE(player.getHp()<=0);
}



