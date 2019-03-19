//
// Created by alessandro on 21/11/18.
//

#ifndef PROJECT_DRAWABLE_H
#define PROJECT_DRAWABLE_H


#include <SFML/Graphics/Drawable.hpp>
enum direction{down=0,left=1,right=2,up=3};

class Entity : public sf::Drawable
{
public:

    int x;
    int y;
    Entity(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    virtual void move();
    virtual int getPositionX();
    virtual int getPositionY();
    virtual bool setDestroy(bool destroy);
    virtual bool getDestroy();
    virtual int getPrice();
    virtual bool getHeal();
    virtual bool getGun();
    virtual int getDirection();
    virtual void setDirection(int direction);

};


#endif //PROJECT_DRAWABLE_H
