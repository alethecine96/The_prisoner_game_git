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
    vertices[1].position = sf::Vector2f(x+tile_dimension, y);
    vertices[2].position = sf::Vector2f(x+tile_dimension, y+tile_dimension);
    vertices[3].position = sf::Vector2f(x, y+tile_dimension);

    if(isGun==true)
    {
        // define its 4 texture coordinates
        vertices[0].texCoords = sf::Vector2f(origin, origin);
        vertices[1].texCoords = sf::Vector2f(tile_dimension, origin);
        vertices[2].texCoords = sf::Vector2f(tile_dimension, tile_dimension);
        vertices[3].texCoords = sf::Vector2f(origin, tile_dimension);
    }
    else
    {
        // define its 4 texture coordinates
        vertices[0].texCoords = sf::Vector2f(origin, tile_dimension);
        vertices[1].texCoords = sf::Vector2f(tile_dimension, tile_dimension);
        vertices[2].texCoords = sf::Vector2f(tile_dimension, double_tile_dimension);
        vertices[3].texCoords = sf::Vector2f(origin, double_tile_dimension);
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