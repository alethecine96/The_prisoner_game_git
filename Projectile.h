//
// Created by alessandro on 16/09/18.
//

#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Entity.h"

class Projectile : public Entity {

public:
    int x,y;
    int speed;
    int direction;
    bool destroy= false;
    Projectile(int x, int y, int speed, int direction){
        this-> x=x;
        this-> y=y;
        this-> speed=speed;
        this->direction=direction;

    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void move ();
    int getPositionX();
    int getPositionY();
    bool setDestroy(bool destroy) override;
    bool getDestroy() override;
};


#endif //PROJECT_PROJECTILE_H
