//
// Created by alessandro on 10/09/18.
//

#ifndef PROJECT_MAPPA_H
#define PROJECT_MAPPA_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <array>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>

class Mappa : public Drawable {
    // define the level with an array of tile indices
public:
    Mappa(std::vector<Drawable*> *array,std::vector<Drawable*> *array1, int * m, Player *player, std::vector<Drawable*> *array2, std::vector<Drawable*> *array3){
        this->array = array;
        this->array1 = array1;
        this->array2=array2;
        this->array3=array3;
        my_array=m;
        this->player=player;
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    int *my_array;
    std::vector<Drawable*> *array;   //nemici
    std::vector<Drawable*> *array1;  //proiettili
    std::vector<Drawable*> *array2;  //coin
    std::vector<Drawable*> *array3;  //powerup
    Player *player;
};


#endif //PROJECT_MAPPA_H
