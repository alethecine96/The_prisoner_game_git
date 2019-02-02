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
    Eyes *eyes;
    std::vector<Drawable*> *array1;

    Player(int x,int y,int hp, int speed,Eyes *eyes,std::vector<Drawable*> *array1){
        this->x=x;
        this->y=y;
        this->hp=hp;
        this->speed=speed;
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
};


#endif //PROJECT_PLAYER_H
