//
// Created by alessandro on 05/03/19.
//

#include <iostream>
#include "Strategy.h"


void Keyboard_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed)
{ //0 down,1 left, 2 right, 3 up
    if(direction==down)
    {
        whomove->direction=down;
        whomove->y=whomove->y+whomove->speed;
    }
    else if(direction==left)
    {
        whomove->direction=left;
        whomove->x=whomove->x-whomove->speed;
    }
    else if(direction==right)
    {
        whomove->direction=right;
        whomove->x=whomove->x+whomove->speed;
    }
    else if(direction==up)
    {
        whomove->direction=up;
        whomove->y=whomove->y-whomove->speed;
    }
}

void Random_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed)
{
    int i=0;
    if(i==rand()%20)
    {     //Quando non è triggerato deve randomizzare, se aggrato deve seguire quello che si dice
        int v = (rand() % 4);
        whomove->direction=v;
    }
    if(!whomove->canmove)
    {
        return;
    }
    else
    {
        if (whomove->direction == down)
        {
            whomove->y = whomove->y + whomove->speed;
        }
        else if (whomove->direction == left)
        {
            whomove->x = whomove->x - whomove->speed;
        }
        else if (whomove->direction == right)
        {
            whomove->x = whomove->x + whomove->speed;
        }
        else if (whomove->direction == up)
        {
            whomove->y = whomove->y - whomove->speed;
        }
    }
}

void Follow_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed)//TODO da cambiare nome al secondo
{
    if (who_is_followed->getPositionX() == whomove->getPositionX())      //nel range di X
    {
        if (who_is_followed->getPositionY() < whomove->getPositionY())
        { //Player sopra al nemico
            whomove->setDirection(up); //UP
            whomove->y=whomove->y-whomove->speed;
        }
        else if (who_is_followed->getPositionY() >= whomove->getPositionY())
        { //Player sotto a nemico
            whomove->setDirection(down); //DOWN
            whomove->y=whomove->y+whomove->speed;
        }
    }
    else if (who_is_followed->getPositionX() < whomove->getPositionX())
    {  //player a sinistra del nemico
        whomove->setDirection(left);
        whomove->x=whomove->x-whomove->speed;
    }
    else if (who_is_followed->getPositionX() > whomove->getPositionX())
    {  //player a destra del nemico
        whomove->setDirection(right);
        whomove->x=whomove->x+whomove->speed;
    }
}