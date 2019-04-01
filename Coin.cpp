//
// Created by francesco on 29/01/19.
//

#include "Coin.h"


void Coin::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    sf::Texture ammo_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!ammo_tileset.loadFromFile("coin.png"))
        return;

    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x+32, y);
    vertices[2].position = sf::Vector2f(x+32, y+32);
    vertices[3].position = sf::Vector2f(x, y+32);

    // define its 4 texture coordinates
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(32, 0);
    vertices[2].texCoords = sf::Vector2f(32, 32);
    vertices[3].texCoords = sf::Vector2f(0, 32);

    target.draw(vertices, &ammo_tileset);

}

bool Coin::setDestroy(bool destroy)
{
    Coin::destroy=destroy;
}

bool Coin::getDestroy()
{
    return destroy;
}

int Coin::getValue(){
    return value;
}
