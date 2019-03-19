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

    vertices[0].position = sf::Vector2f(x, y+32);
    vertices[1].position = sf::Vector2f(x, y);
    vertices[2].position = sf::Vector2f(x+32, y);
    vertices[3].position = sf::Vector2f(x+32, y+32);

    // define its 4 texture coordinates
    vertices[0].texCoords = sf::Vector2f(0+step*32, 32+this->direction*32);
    vertices[1].texCoords = sf::Vector2f(0+step*32, 0+direction*32);
    vertices[2].texCoords = sf::Vector2f(32+step*32, 0+direction*32);
    vertices[3].texCoords = sf::Vector2f(32+step*32, 32+direction*32);

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

void Enemy::shoot()
{
    //Projectile_vector->push_back(new Projectile(x,y,3,direction));
}

void Enemy::move()
{
    strategy->strategy_move(this->direction,this,player);
    step=(step+1)%3;
}

void Enemy::setcanmove(bool canmove)
{
    Enemy::canmove=canmove;
}