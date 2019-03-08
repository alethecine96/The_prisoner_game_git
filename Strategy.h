//
// Created by alessandro on 05/03/19.
//

#ifndef PROJECT_STRATEGY_H
#define PROJECT_STRATEGY_H

#include "GameCharacter.h"


class Strategy {
public:
    virtual void strategy_move(int direction,GameCharacter *whomove)=0;

};

class Keyboard_Movement: public Strategy{
public:
    virtual void strategy_move(int direction, GameCharacter *whomove) override;
};

class Random_Movement: public Strategy{
public:
    virtual void strategy_move(int direction, GameCharacter *whomove) override;
};

#endif //PROJECT_STRATEGY_H
