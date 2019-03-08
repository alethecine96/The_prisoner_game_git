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

class Player : virtual public GameCharacter{

public:
    Player(int x,int y, int speed, int hp, std::vector<Projectile*> *Projectile_vector, Strategy *strategy) : GameCharacter(x, y, speed, hp){
        direction=0;
        step=0;//FIXME enum
        this->Projectile_vector=Projectile_vector;
        this->strategy=strategy;
    };
    //attributi
    int direction;
    int step;
    int damage=5;
    int wallet=95;
    bool movement=true;
    std::vector<Projectile*> *Projectile_vector;
    Strategy *strategy;


    virtual int  getPositionX() override;
    virtual int  getPositionY() override;

    void move(int a, int b);
    void move(int direction);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void shoot();

    int setDamage(int damage);
    int getDamage();

    int getDirection();
    void setDirection(int direction);

    void SetStrategy(Strategy *strategymove)
    {
        strategy=strategymove;
    }

private:
};


#endif //PROJECT_PLAYER_H
