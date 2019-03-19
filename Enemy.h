
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

class Enemy : public GameCharacter
{
public:
    int damage;
    bool aggro=false;
    int step;
    bool alive=true;
    std::vector<Projectile*> *Projectile_vector;
    Strategy *strategy;
    Player *player;



    Enemy(int x,int y, int speed,int hp, int damage, int direction, std::vector<Projectile*> *Projectile_vector, Strategy *strategy, Player *player) : GameCharacter(x, y, speed, hp, damage, direction)
    {
        this->damage=damage;
        step=0;//FIXME enum
        this->Projectile_vector=Projectile_vector;
        this->strategy=strategy;
        this->player=player;
    };


    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    bool getAggro();
    bool setAggro(bool aggro);
    bool setAlive(bool alive);
    bool getAlive();
    void shoot();
    void move();

    void setcanmove(bool canmove);

    void SetStrategy(Strategy *strategymove)
    {
        strategy=strategymove;
    }
};


#endif //PROJECT_ENEMY_H