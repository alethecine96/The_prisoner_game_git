//
// Created by alessandro on 07/12/18.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include <vector>
#include <list>
#include <array>
#include "Player.h"
#include "Drawable.h"
#include "Coin.h"

class Observer {
public:
    Observer(std::vector<Drawable*> *array, Player *player){
        this->array=array;
        this->player=player;
    }


    void CollisionPlayer();

    void CollisionProjectile(std::vector<Drawable*> *vector, std::vector<Drawable*> *vector1);

    void CollisionPickup(std::vector<Drawable*> *vector, std::vector<Drawable*> *vector1);

    void MoveEnemy();

private:
    std::vector<Drawable*> *array;
    Player *player;



};


#endif //PROJECT_OBSERVER_H
