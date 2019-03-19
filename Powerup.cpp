//
// Created by francesco on 30/01/19.
//

#include "Powerup.h"

void Powerup::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Texture ammo_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!ammo_tileset.loadFromFile("powerup.png"))
        return;

    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x+32, y);
    vertices[2].position = sf::Vector2f(x+32, y+32);
    vertices[3].position = sf::Vector2f(x, y+32);

    if(isGun==true)
    {
        // define its 4 texture coordinates
        vertices[0].texCoords = sf::Vector2f(0, 0);
        vertices[1].texCoords = sf::Vector2f(32, 0);
        vertices[2].texCoords = sf::Vector2f(32, 32);
        vertices[3].texCoords = sf::Vector2f(0, 32);
    }
    else
    {
        // define its 4 texture coordinates
        vertices[0].texCoords = sf::Vector2f(0, 32);
        vertices[1].texCoords = sf::Vector2f(32, 32);
        vertices[2].texCoords = sf::Vector2f(32, 64);
        vertices[3].texCoords = sf::Vector2f(0, 64);
    }

    target.draw(vertices, &ammo_tileset);

}

bool Powerup::setDestroy(bool destroy)
{
    Powerup::destroy=destroy;
}

bool Powerup::getDestroy()
{
    return destroy;
}

bool Powerup::getHeal()
{
    return isHeal;
}

bool Powerup::getGun()
{
    return isGun;
}

int Powerup::getPrice()
{
    return price;
}

int Powerup::getPositionX()
{
    return x;
}

int Powerup::getPositionY()
{
    return y;
}