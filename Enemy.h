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
    int direction;
    int step;
    bool aggro=true;
    Eyes *eyes;


    Enemy(int x,int y, int speed, int damage, Eyes *eyes){
        this->x=x;
        this->y=y;
        this->speed=speed;
        this->damage=damage;
        direction=0;
        step=0;//FIXME enum
        this->eyes = eyes;
    };


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual int  getPositionX();
    virtual int  getPositionY();



    void move();

    virtual int getDamage();

    virtual bool getAggro();

};


#endif //PROJECT_ENEMY_H