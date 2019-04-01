//
// Created by alessandro on 07/12/18.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include <vector>
#include <list>
#include <array>
#include "Player.h"
#include "Entity.h"
#include "Coin.h"
#include "Mappa.h"

class Updater
{
public:
    Updater(std::vector<Enemy*> *Enemy_vector, Player *player, Mappa *mappa)
    {
        this->Enemy_vector=Enemy_vector;
        this->player=player;
        this->mappa=mappa;
    }


    int CollisionPlayer();

    int CollisionProjectile(std::vector<Projectile*> *Projectile_vector, std::vector<Coin*> *Coin_vector);

    void CollisionPickup(std::vector<Coin*> *Coin_vector, std::vector<Powerup*> *Powerup_vector);

    int is_in_sight(int j);

private:
    std::vector<Enemy*> *Enemy_vector;
    Player *player;
    Mappa *mappa;
    int kill=0;



};


#endif //PROJECT_OBSERVER_H
