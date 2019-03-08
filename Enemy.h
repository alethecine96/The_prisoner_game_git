
//
// Created by alessandro on 19/10/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <iostream>
#include <array>
#include "Player.h"
#include "Entity.h"
#include "GameCharacter.h"

class Enemy : public GameCharacter {
public:
    int damage;
    bool aggro=false;
    int direction;
    int step;
    bool alive=true;
    Player *player;
    std::vector<Projectile*> *Projectile_vector;
    Strategy *strategy;


    Enemy(int x,int y, int speed,int hp, int damage, std::vector<Projectile*> *Projectile_vector, Strategy *strategy) : GameCharacter(x, y, speed, hp){
        this->damage=damage;
        direction=0;
        step=0;//FIXME enum
        this->Projectile_vector=Projectile_vector;
        this->strategy=strategy;
    };


    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual int  getPositionX() override;
    virtual int  getPositionY() override;
    bool getAggro();
    bool setAggro(bool aggro);
    void move(bool canmove);
    void follow(int d, bool canmove);
    bool setAlive(bool alive);
    bool getAlive();
    int getSpeed();
    int getDamage();
    int getDirection();
    void shoot();
    void move();
};


#endif //PROJECT_ENEMY_H