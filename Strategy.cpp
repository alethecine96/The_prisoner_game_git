//
// Created by alessandro on 05/03/19.
//

#include <iostream>
#include "Strategy.h"


void Keyboard_Movement::strategy_move(int direction, GameCharacter *whomove) { //0 down,1 left, 2 right, 3 up
    if(direction==0)
    {
        whomove->y=whomove->y+whomove->speed;
    }
    else if(direction==1)
    {
        whomove->x=whomove->x-whomove->speed;
    }
    else if(direction==2)
    {
        whomove->x=whomove->x+whomove->speed;
    }
    else if(direction==3)
    {
        whomove->y=whomove->y-whomove->speed;
    }
}

void Random_Movement::strategy_move(int direction, GameCharacter *whomove) {
    if(direction==0)
    {
        whomove->y=whomove->y+whomove->speed;
    }
    else if(direction==1)
    {
        whomove->x=whomove->x-whomove->speed;
    }
    else if(direction==2)
    {
        whomove->x=whomove->x+whomove->speed;
    }
    else if(direction==3)
    {
        whomove->y=whomove->y-whomove->speed;
    }
}

