//
// Created by alessandro on 12/09/18.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <array>
#include "Projectile.h"
#include "Entity.h"
#include <vector>
#include "GameCharacter.h"
#include "Strategy.h"
class Player : public GameCharacter
{

public:
    Player(int x,int y, int speed, int hp, int damage, int direction, std::vector<Projectile*> *Projectile_vector, Strategy *strategy) : GameCharacter(x, y, speed, hp, damage, direction)
    {
        step=0;//FIXME enum
        this->Projectile_vector=Projectile_vector;
        this->strategy=strategy;
    };
    //attributi
    int step;
    int wallet=95;
    std::vector<Projectile*> *Projectile_vector;
    Strategy *strategy;

    void move(int direction);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void shoot();

    void SetStrategy(Strategy *strategymove)
    {
        strategy=strategymove;
    }

private:
};


#endif //PROJECT_PLAYER_H
