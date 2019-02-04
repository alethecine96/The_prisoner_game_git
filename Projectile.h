//
// Created by alessandro on 16/09/18.
//

#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Drawable.h"
#include "Eyes.h"

class Projectile : public Drawable {

public:
    int x,y;
    int speed;
    int direction;
    Eyes *eyes;
    bool destroy= false;
    Projectile(int x, int y, int speed, Eyes *eyes, int direction){
        this-> x=x;
        this-> y=y;
        this-> speed=speed;
        this-> eyes=eyes;
        this->direction=direction;

    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void move ();
    int getPositionX();
    int getPositionY();
    virtual bool setDestroy(bool destroy);
    virtual bool getDestroy();
};


#endif //PROJECT_PROJECTILE_H
