//
// Created by alessandro on 05/03/19.
//

#ifndef PROJECT_STRATEGY_H
#define PROJECT_STRATEGY_H

#include "GameCharacter.h"

class Strategy
{
public:
    virtual void strategy_move(int direction,GameCharacter *whomove, GameCharacter *who_is_followed)=0;

};

class Keyboard_Movement: public Strategy
{
public:
    void strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed) override;
};

class Random_Movement: public Strategy
{
public:
    void strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed) override;
};

class Follow_Movement: public Strategy
{
public:
    void strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed) override;
};

class Patrol_Movement: public Strategy
{
    void strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed) override;
};

#endif //PROJECT_STRATEGY_H
