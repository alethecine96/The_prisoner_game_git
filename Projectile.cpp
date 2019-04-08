//
// Created by alessandro on 16/09/18.
//


#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Projectile.h"
#include <cmath>
#include <iostream>

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    sf::Texture ammo_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!ammo_tileset.loadFromFile("ammo1.png"))
        return;

    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x+tile_dimension, y);
    vertices[2].position = sf::Vector2f(x+tile_dimension, y+tile_dimension);
    vertices[3].position = sf::Vector2f(x, y+tile_dimension);

    // define its 4 texture coordinates

    if(direction==0)
    {//down
        vertices[0].texCoords = sf::Vector2f(origin, tile_dimension);
        vertices[1].texCoords = sf::Vector2f(origin, origin);
        vertices[2].texCoords = sf::Vector2f(tile_dimension, origin);
        vertices[3].texCoords = sf::Vector2f(tile_dimension, tile_dimension);
    }
    if(direction==1)
    {//left
        vertices[0].texCoords = sf::Vector2f(tile_dimension, tile_dimension);
        vertices[1].texCoords = sf::Vector2f(origin, tile_dimension);
        vertices[2].texCoords = sf::Vector2f(origin, origin);
        vertices[3].texCoords = sf::Vector2f(tile_dimension, origin);
    }
    if(direction==2)
    {//right
        vertices[0].texCoords = sf::Vector2f(origin, origin);
        vertices[1].texCoords = sf::Vector2f(tile_dimension, origin);
        vertices[2].texCoords = sf::Vector2f(tile_dimension, tile_dimension);
        vertices[3].texCoords = sf::Vector2f(origin, tile_dimension);
    }
    if(direction==3)
    {//up
        vertices[0].texCoords = sf::Vector2f(tile_dimension, origin);
        vertices[1].texCoords = sf::Vector2f(tile_dimension, tile_dimension);
        vertices[2].texCoords = sf::Vector2f(origin, tile_dimension);
        vertices[3].texCoords = sf::Vector2f(origin, origin);
    }
    target.draw(vertices, &ammo_tileset);

}

void Projectile::move()
{
    float l=4.5;
    int a= -pow(direction,3)+ l*pow(direction,2)-l*direction;
    int b= round(-0.6*direction+0.9);

    int i = this->x + this->speed * a;
    int j = this->y + this->speed * b;

    this->x = i;
    this->y = j;

}

bool Projectile::setDestroy(bool destroy)
{
    Projectile::destroy=destroy;
}

bool Projectile::getDestroy()
{
    return destroy;
}

int Projectile::getDirection()
{
    return direction;
}

void Projectile::setDirection(int direction)
{
    Projectile::direction=direction;
}