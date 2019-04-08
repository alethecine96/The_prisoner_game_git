//
// Created by alessandro on 19/10/18.
//

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cmath>
#include <SFML/System/Clock.hpp>
#include "Enemy.h"


void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Texture enemy_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!enemy_tileset.loadFromFile("Guard.png"))   //TODO fare switch con prisoner e guard con relativi tileset
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

    target.draw(vertices, &enemy_tileset);

}
bool Enemy::getAggro()
{
    return aggro;
}

bool Enemy::setAggro(bool aggro)
{
    Enemy::aggro=aggro;
}

bool Enemy::setAlive(bool alive)
{
    Enemy::alive=alive;
}

bool Enemy::getAlive()
{
    return alive;
}

void Enemy::move()
{
    strategy->strategy_move(this->direction,this,player);
    step=(step+1)%3;
}

void Enemy::setCanmove(bool canmove)
{
    Enemy::canmove=canmove;
}

bool Enemy::getsupervisor()
{
    return supervisor;
}
