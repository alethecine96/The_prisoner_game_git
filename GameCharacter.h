//
// Created by francesco on 07/02/19.
//

#ifndef PROJECT_GAMECHARACTER_H
#define PROJECT_GAMECHARACTER_H


#include "Entity.h"

class GameCharacter : public Entity
{
public:
    GameCharacter(int x, int y, int speed, int hp, int damage, int direction):Entity(x,y)
    {
        this->speed=speed;
        this->hp=hp;
        this->damage=damage;
        this->direction=direction;
    };

    virtual int setHp(int hp);
    virtual int getHp();
    virtual int getDirection();
    virtual void setDirection(int direction);
    virtual void setDamage(int damage);
    virtual int  getDamage();
    virtual int getSpeed();
    bool canmove=true;

protected:
    int hp;
    int damage;
    int speed;
    int direction;

};


#endif //PROJECT_GAMECHARACTER_H
