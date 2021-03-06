//
// Created by francesco on 30/01/19.
//

#ifndef PROJECT_POWERUP_H
#define PROJECT_POWERUP_H

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Entity.h"

class Powerup : public Entity
{
public:
    Powerup(int x, int y, bool isHeal, bool isGun):Entity(x,y)
    {
        this->isGun=isGun;
        this->isHeal=isHeal;
    }


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool setDestroy(bool destroy);
    bool getDestroy();
    bool getHeal();
    bool getGun();
    int getPrice();
    virtual int  getPositionX();
    virtual int  getPositionY();

protected:
    int price=50;
    bool destroy=false;
    bool isHeal;
    bool isGun;
};


#endif //PROJECT_POWERUP_H
