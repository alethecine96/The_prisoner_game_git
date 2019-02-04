//
// Created by alessandro on 12/09/18.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <array>
#include "Eyes.h"
#include "Projectile.h"
#include "Drawable.h"
#include <vector>

class Player : public Drawable{

public:
    int x,y;
    int speed;
    int hp;
    int direction;
    int step;
    int damage=5;
    int wallet=95;
    Eyes *eyes;
    std::vector<Drawable*> *array1;

    Player(int x,int y, int speed, int hp, Eyes *eyes,std::vector<Drawable*> *array1){
        this->x=x;
        this->y=y;
        this->speed=speed;
        this->hp=hp;
        direction=0;
        step=0;//FIXME enum
        this->eyes = eyes;
        this->array1=array1;

    };

    virtual int  getPositionX();
    virtual int  getPositionY();
    virtual int  getDirection();

    virtual void move(int a, int b);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    virtual void shoot();

    virtual int getHp();

    virtual int setHp(int hp);

    virtual int getDamage();

    virtual int setDamage(int damage);

private:
};


#endif //PROJECT_PLAYER_H
