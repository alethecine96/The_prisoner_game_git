//
// Created by alessandro on 16/09/18.
//

#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Entity.h"

class Projectile : public Entity
{

public:
    Projectile(int x, int y, int speed, int direction):Entity(x,y)
    {
        this->speed=speed;
        this->direction=direction;
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void move() override;
    bool setDestroy(bool destroy);
    bool getDestroy();
    int getDirection();
    void setDirection(int direction);

protected:
    int speed;
    int direction;
    bool destroy=false;
};


#endif //PROJECT_PROJECTILE_H
