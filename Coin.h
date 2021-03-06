//
// Created by francesco on 29/01/19.
//

#ifndef PROJECT_COIN_H
#define PROJECT_COIN_H

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Entity.h"

class Coin : public Entity
{

public:

    Coin(int x, int y, int value) : Entity(x,y)
    {
        this->value=value;
    };

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    int getValue();
    bool setDestroy(bool destroy);
    bool getDestroy();


protected:
    bool destroy= false;
    int value;
};


#endif //PROJECT_COIN_H
