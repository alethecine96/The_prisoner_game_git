//
// Created by alessandro on 16/09/18.
//


#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Projectile.h"
#include <cmath>
#include <iostream>

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::Texture ammo_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!ammo_tileset.loadFromFile("ammo1.png"))
        return;

    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x+32, y);
    vertices[2].position = sf::Vector2f(x+32, y+32);
    vertices[3].position = sf::Vector2f(x, y+32);

    // define its 4 texture coordinates

    if(direction==0){//down
        vertices[0].texCoords = sf::Vector2f(0, 32);
        vertices[1].texCoords = sf::Vector2f(0, 0);
        vertices[2].texCoords = sf::Vector2f(32, 0);
        vertices[3].texCoords = sf::Vector2f(32, 32);
    }
    if(direction==1) {//left
        vertices[0].texCoords = sf::Vector2f(32, 32);
        vertices[1].texCoords = sf::Vector2f(0, 32);
        vertices[2].texCoords = sf::Vector2f(0, 0);
        vertices[3].texCoords = sf::Vector2f(32, 0);
    }
    if(direction==2) {//right
        vertices[0].texCoords = sf::Vector2f(0, 0);
        vertices[1].texCoords = sf::Vector2f(32, 0);
        vertices[2].texCoords = sf::Vector2f(32, 32);
        vertices[3].texCoords = sf::Vector2f(0, 32);
    }
    if(direction==3){//up
        vertices[0].texCoords = sf::Vector2f(32, 0);
        vertices[1].texCoords = sf::Vector2f(32, 32);
        vertices[2].texCoords = sf::Vector2f(0, 32);
        vertices[3].texCoords = sf::Vector2f(0, 0);
    }
    target.draw(vertices, &ammo_tileset);

}

void Projectile::move() {

    float l=4.5;
    int a= -pow(direction,3)+ l*pow(direction,2)-l*direction;
    int b= round(-0.6*direction+0.9);

    int i = this->x + this->speed * a;
    int j = this->y + this->speed * b;

    this->x = i;
    this->y = j;

}

int Projectile::getPositionX(){
    return x;
}

int Projectile::getPositionY(){
    return y;
}

bool Projectile::setDestroy(bool destroy) {
    Projectile::destroy=destroy;
}

bool Projectile::getDestroy() {
    return destroy;
}

