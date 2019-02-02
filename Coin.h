//
// Created by francesco on 29/01/19.
//

#ifndef PROJECT_COIN_H
#define PROJECT_COIN_H

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Drawable.h"

class Coin : public Drawable {

public:

    Coin(int x, int y){
        this->x=x;
        this->y=y;
    };
    int x;
    int y;
    bool destroy= false;


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool setDestroy(bool destroy);
    bool getDestroy();

    virtual int  getPositionX();
    virtual int  getPositionY();
};


#endif //PROJECT_COIN_H
