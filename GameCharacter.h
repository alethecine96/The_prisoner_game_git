//
// Created by francesco on 07/02/19.
//

#ifndef PROJECT_GAMECHARACTER_H
#define PROJECT_GAMECHARACTER_H


#include "Entity.h"

class GameCharacter : public Entity {
public:
    GameCharacter(int x, int y, int speed, int hp){
        this->x=x;
        this->y=y;
        this->speed=speed;
        this->hp=hp;
    };
    int hp;
    int x, y;
    int speed;
    int direction;
    virtual int setHp(int hp);
    virtual int getHp();
    virtual int getDirection();
};


#endif //PROJECT_GAMECHARACTER_H
