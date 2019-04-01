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


    Entity(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    virtual void move();
    virtual int getPositionX();
    virtual int getPositionY();
    virtual int setPositionX(int x);
    virtual int setPositionY(int y);
    virtual int getDirection();
    virtual void setDirection(int direction);

protected:
    int x;
    int y;
};


#endif //PROJECT_DRAWABLE_H
