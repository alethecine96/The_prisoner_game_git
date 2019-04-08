//
// Created by alessandro on 12/09/18.
//

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Player.h"

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Texture player_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!player_tileset.loadFromFile("prigioniero.png"))
        return;

    vertices[0].position = sf::Vector2f(x, y+tile_dimension);
    vertices[1].position = sf::Vector2f(x, y);
    vertices[2].position = sf::Vector2f(x+tile_dimension, y);
    vertices[3].position = sf::Vector2f(x+tile_dimension, y+tile_dimension);

    // define its 4 texture coordinates
    vertices[0].texCoords = sf::Vector2f(origin+step*tile_dimension, tile_dimension+direction*tile_dimension);
    vertices[1].texCoords = sf::Vector2f(origin+step*tile_dimension, origin+direction*tile_dimension);
    vertices[2].texCoords = sf::Vector2f(tile_dimension+step*tile_dimension, origin+direction*tile_dimension);
    vertices[3].texCoords = sf::Vector2f(tile_dimension+step*tile_dimension, tile_dimension+direction*tile_dimension);

    target.draw(vertices, &player_tileset);

}

void Player::shoot()
{
    Projectile_vector->push_back(new Projectile(x,y,5,direction));
}

void Player::move(int direction)
{
    strategy->strategy_move(direction,this,this);
    step=(step+1)%3;
}
