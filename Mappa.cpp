//
// Created by alessandro on 10/09/18.
//


#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "Mappa.h"



void Mappa::draw(sf::RenderTarget &target, sf::RenderStates states) const{



    sf::Clock clock;
    sf::Time elapsedtime = clock.getElapsedTime();
    sf::Texture m_tileset;
    sf::VertexArray m_vertices;
    int width=40;
    int height=36;
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
            int tileNumber = my_array[i + j * width];

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
        std::vector<Drawable*>::const_iterator iter;
        int i=0;
        if(array->empty()){}
        else {
            for (iter = array->begin(); iter != array->end(); iter++) {
                target.draw(*array->at(i)); //draw the enemies
                if(i+1<array->size()) {
                    i++;
                }
                else{
                    i=0;
                }
            }

        }


        std::vector<Drawable*>::const_iterator iter1;
        int j=0;
        if(array1->empty()){}
        else {

        for (iter1=array1->begin(); iter1!=array1->end(); iter1++) {

            target.draw(*array1->at(j));
            j++;
            }
        }

        std::vector<Drawable*>::const_iterator iter2;
        int k=0;
        if(array2->empty()){}
        else {

            for (iter2=array2->begin(); iter2!=array2->end(); iter2++) {

                target.draw(*array2->at(k));
                k++;
            }
        }

        std::vector<Drawable*>::const_iterator iter3;
        int l=0;
        if(array3->empty()){}
        else {

            for (iter3=array3->begin(); iter3!=array3->end(); iter3++) {

                target.draw(*array3->at(l));
                l++;
            }
        }




}