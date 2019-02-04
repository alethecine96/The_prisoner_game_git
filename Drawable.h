//
// Created by alessandro on 21/11/18.
//

#ifndef PROJECT_DRAWABLE_H
#define PROJECT_DRAWABLE_H


#include <SFML/Graphics/Drawable.hpp>

class Drawable : public sf::Drawable {
public:
    int x;
    int y;


    virtual void move(int a, int b);
    virtual void move();
    virtual void follow(int d);
    virtual void shoot();
    virtual int getPositionX();
    virtual int getPositionY();
    virtual int getDirection();
    virtual int getHp();
    virtual int getDamage();
    virtual int setDamage(int damage);
    virtual bool getAggro();
    virtual int setHp(int hp);
    virtual bool setAggro(bool aggro);
    virtual bool setDestroy(bool destroy);
    virtual bool getDestroy();
    virtual bool setAlive(bool alive);
    virtual bool getAlive();
    virtual int getPrice();
    virtual bool getHeal();
    virtual bool getGun();

};


#endif //PROJECT_DRAWABLE_H
