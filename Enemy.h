//
// Created by alessandro on 19/10/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <iostream>
#include <array>
#include "Player.h"
#include "Drawable.h"


class Enemy : public Drawable {
public:
    int y;
    int x;
    int speed;
    int damage;
    int hp;
    bool aggro=false;
    int direction;
    int step;
    bool alive=true;
    Eyes *eyes;
    Player *player;


    Enemy(int x,int y, int speed, int damage, int hp, Eyes *eyes){
        this->x=x;
        this->y=y;
        this->speed=speed;
        this->damage=damage;
        this->hp=hp;
        direction=0;
        step=0;//FIXME enum
        this->eyes = eyes;
    };


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual int  getPositionX();
    virtual int  getPositionY();

    virtual int getDamage();

    virtual bool getAggro();

    virtual bool setAggro(bool aggro);

    virtual int getHp();

    virtual int setHp(int hp);

    void move();

    void follow(int d);

    virtual bool setAlive(bool alive);
    virtual bool getAlive();
};


#endif //PROJECT_ENEMY_H