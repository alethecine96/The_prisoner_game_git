//
// Created by francesco on 30/01/19.
//

#ifndef PROJECT_POWERUP_H
#define PROJECT_POWERUP_H

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Drawable.h"

class Powerup : public Drawable{
public:

    Powerup(int x, int y, bool isHeal, bool isGun){
        this->x=x;
        this->y=y;
        this->isGun=isGun;
        this->isHeal=isHeal;
    }
    int x, y;
    int price=50;
    bool destroy=false;
    bool isHeal;
    bool isGun;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool setDestroy(bool destroy);
    bool getDestroy();
    bool getHeal();
    bool getGun();
    int getPrice();

    virtual int  getPositionX();
    virtual int  getPositionY();
};


#endif //PROJECT_POWERUP_H
