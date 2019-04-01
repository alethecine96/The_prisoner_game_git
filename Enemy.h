
//
// Created by alessandro on 19/10/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <iostream>
#include <array>
#include "Entity.h"
#include "GameCharacter.h"
#include "Strategy.h"
#include "Player.h"
#include "Powerup.h"

class Enemy : public GameCharacter
{
public:




    Enemy(int x,int y, int speed,int hp, int damage, int direction, std::vector<Projectile*> *Projectile_vector, Strategy *strategy, Player *player, bool supervisor) : GameCharacter(x, y, speed, hp, damage, direction)
    {
        this->damage=damage;
        step=0;//FIXME enum
        this->Projectile_vector=Projectile_vector;
        this->strategy=strategy;
        this->player=player;
        this->supervisor=supervisor;
    };


    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    bool getAggro();
    bool setAggro(bool aggro);
    bool setAlive(bool alive);
    bool getAlive();
    void shoot();
    void move();

    void setCanmove(bool canmove);
    bool getsupervisor();

    void setStrategy(Strategy *strategymove)
    {
        strategy=strategymove;
    }

protected:
    bool aggro=false;
    int step;
    bool alive=true;
    std::vector<Projectile*> *Projectile_vector;
    Strategy *strategy;
    Player *player;
    bool supervisor;
};


#endif //PROJECT_ENEMY_H