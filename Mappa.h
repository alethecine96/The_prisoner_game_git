//
// Created by alessandro on 10/09/18.
//

#ifndef PROJECT_MAPPA_H
#define PROJECT_MAPPA_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Powerup.h"
#include "Coin.h"
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

class Mappa : public sf::Drawable {
    // define the level with an array of tile indices
public:




    Mappa(std::vector<Enemy*> *Enemy_vector,std::vector<Projectile*> *Projectile_vector, Player *player, std::vector<Coin*> *Coin_vector, std::vector<Powerup*> *Powerup_vector){
        this->Enemy_vector = Enemy_vector;
        this->Projectile_vector = Projectile_vector;
        this->Coin_vector=Coin_vector;
        this->Powerup_vector=Powerup_vector;
        this->player=player;
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void load(std::string filename, int size);
    bool isWalkable(int x, int y,int direction);


private:
    std::vector<Enemy*> *Enemy_vector;   //nemici
    std::vector<Projectile*> *Projectile_vector;  //proiettili
    std::vector<Coin*> *Coin_vector;  //coin
    std::vector<Powerup*> *Powerup_vector;  //powerup
    Player *player;
    int *map;

};


#endif //PROJECT_MAPPA_H
