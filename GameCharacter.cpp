//
// Created by francesco on 07/02/19.
//

#include "GameCharacter.h"

int GameCharacter::getHp()
{
    return hp;
}

int GameCharacter::setHp(int hp)
{
    GameCharacter::hp=hp;
}

int GameCharacter::getDirection()
{
    return direction;
}

void GameCharacter::setDirection(int direction)
{
    GameCharacter::direction=direction;
}

int GameCharacter::getDamage()
{
    return damage;
}

void GameCharacter::setDamage(int damage)
{
    GameCharacter::damage=damage;
}

int GameCharacter::getSpeed()
{
    return speed;
}