//
// Created by alessandro on 21/11/18.
//

#ifndef PROJECT_DRAWABLE_H
#define PROJECT_DRAWABLE_H


#include <SFML/Graphics/Drawable.hpp>

class Entity : public sf::Drawable {
public:
    int x;
    int y;


    virtual void move();
    virtual int getPositionX();
    virtual int getPositionY();
    virtual int getDirection();
    virtual bool setDestroy(bool destroy);
    virtual bool getDestroy();
    virtual int getPrice();
    virtual bool getHeal();
    virtual bool getGun();
    virtual int setPositionX(int x);
    virtual int setPositionY(int y);

};


#endif //PROJECT_DRAWABLE_H
