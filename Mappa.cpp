//
// Created by alessandro on 10/09/18.
//


#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Mappa.h"


void Mappa::draw(sf::RenderTarget &target, sf::RenderStates states) const
{


    int width=40;
    int height=36;
    sf::Clock clock;
    sf::Time elapsedtime = clock.getElapsedTime();
    sf::Texture m_tileset;
    sf::VertexArray m_vertices;
    sf::Vector2u tileSize = sf::Vector2u(32, 32);


    if (!m_tileset.loadFromFile("tilesetmod2.png"))
        return;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = map[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }


        target.draw(m_vertices,&m_tileset); //draw map
        target.draw(*player);
        std::vector<Enemy*>::const_iterator iter;
        int i=0;
        if(!Enemy_vector->empty())
        {
            for (iter = Enemy_vector->begin(); iter != Enemy_vector->end(); iter++)
            {
                target.draw(*Enemy_vector->at(i)); //draw the enemies
                if(i+1<Enemy_vector->size())
                {
                    i++;
                }
                else
                {
                    i=0;
                }
            }

        }


        std::vector<Projectile*>::const_iterator iter1;
        int j=0;
        if(!Projectile_vector->empty())
        {
            for (iter1=Projectile_vector->begin(); iter1!=Projectile_vector->end(); iter1++)
            {
                target.draw(*Projectile_vector->at(j));
                j++;
            }
        }

        std::vector<Coin*>::const_iterator iter2;
        int k=0;
        if(!Coin_vector->empty())
        {
            for (iter2=Coin_vector->begin(); iter2!=Coin_vector->end(); iter2++)
            {
                target.draw(*Coin_vector->at(k));
                k++;
            }
        }

        std::vector<Powerup*>::const_iterator iter3;
        int l=0;
        if(!Powerup_vector->empty())
        {
            for (iter3=Powerup_vector->begin(); iter3!=Powerup_vector->end(); iter3++)
            {
                target.draw(*Powerup_vector->at(l));
                l++;
            }
        }
}

void Mappa::load(std::string fileName,int size)
{
    map = new int[size];
    int value;
    int i = 0;
    std::fstream string(fileName, std::ios::in);

    while (string >> value)
    {
        map[i] = value;
        i++;
    }
}

bool Mappa::isWalkable(int x, int y, int direction)
{


    int width=40;
    int walkableTiles[] = {0, 58, 97};  //Tile Calpestabili
    int s = 3;

    int oldX=x;
    int oldY=y;
    for (int j = 0; j < 4; j++)
    {           //COLLISION!!

        x=oldX;
        y=oldY;

        x += pow(j, 2) * (-14) + 42 * j+2;
        if (j == 0 || j == 1)
            y += 2;
        if (j==2 || j==3)
            y += 30;
        int a = (x / 32);
        int b = (y / 32);
        bool walkable = false;
        for (int i = 0; i < s; i++)
        {
            if (map[(b * width) + a] == walkableTiles[i])
                walkable = true;
        }

        if (!walkable)
        {
            return false;
        }
    }
    return true;
}