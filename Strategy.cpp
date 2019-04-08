//
// Created by alessandro on 05/03/19.
//

#include <iostream>
#include "Strategy.h"

void Keyboard_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed)
{
    if(direction==down)
    {
        whomove->setDirection(down);
        whomove->setPositionY(whomove->getPositionY()+whomove->getSpeed());
    }
    else if(direction==left)
    {
        whomove->setDirection(left);
        whomove->setPositionX(whomove->getPositionX()-whomove->getSpeed());
    }
    else if(direction==right)
    {
        whomove->setDirection(right);
        whomove->setPositionX(whomove->getPositionX()+whomove->getSpeed());
    }
    else if(direction==up)
    {
        whomove->setDirection(up);
        whomove->setPositionY(whomove->getPositionY()-whomove->getSpeed());
    }
}

void Random_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed)
{
    int i=0;
    if(i==rand()%20)
    {     //Quando non è triggerato deve randomizzare, se aggrato deve seguire quello che si dice
        int v = (rand() % 4);
        whomove->setDirection(v);
    }
    if(!whomove->canmove)
    {
        return;
    }
    else
    {
        if (whomove->getDirection() == down)
        {
            whomove->setPositionY(whomove->getPositionY()+whomove->getSpeed());
        }
        else if (whomove->getDirection() == left)
        {
            whomove->setPositionX(whomove->getPositionX()-whomove->getSpeed());
        }
        else if (whomove->getDirection() == right)
        {
            whomove->setPositionX(whomove->getPositionX()+whomove->getSpeed());
        }
        else if (whomove->getDirection() == up)
        {
            whomove->setPositionY(whomove->getPositionY()-whomove->getSpeed());
        }
    }
}

void Follow_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed)//TODO da cambiare nome al secondo
{
    if (abs(who_is_followed->getPositionX() - whomove->getPositionX())<range)      //nel range di X
    {
        if (who_is_followed->getPositionY() < whomove->getPositionY())
        { //Player sopra al nemico
            whomove->setDirection(up); //UP
            if(!whomove->canmove)
            {
                return;
            }
            whomove->setPositionY(whomove->getPositionY() - whomove->getSpeed());
        } else if (who_is_followed->getPositionY() >= whomove->getPositionY())
        { //Player sotto a nemico
            whomove->setDirection(down); //DOWN
            if(!whomove->canmove)
            {
                return;
            }
            whomove->setPositionY(whomove->getPositionY() + whomove->getSpeed());
        }
    } else if (who_is_followed->getPositionX() < whomove->getPositionX())
    {  //player a sinistra del nemico
        whomove->setDirection(left);
        if(!whomove->canmove)
        {
            return;
        }
        whomove->setPositionX(whomove->getPositionX() - whomove->getSpeed());
    } else if (who_is_followed->getPositionX() > whomove->getPositionX())
    {  //player a destra del nemico
        whomove->setDirection(right);
        if(!whomove->canmove)
        {
            return;
        }
        whomove->setPositionX(whomove->getPositionX() + whomove->getSpeed());
    }
}

void Patrol_Movement::strategy_move(int direction, GameCharacter *whomove, GameCharacter *who_is_followed) {
    if(whomove->getPositionX()<powerupX+double_tile_dimension && whomove->getPositionY()<powerupY-double_tile_dimension)
    {
        whomove->setDirection(right);
    }
    else if(whomove->getPositionX()==powerupX+double_tile_dimension && whomove->getPositionY()<powerupY+double_tile_dimension)
    {
        whomove->setDirection(down);
    }
    else if(whomove->getPositionY() == powerupY+double_tile_dimension && whomove->getPositionX()>powerupX-double_tile_dimension)
    {
        whomove->setDirection(left);
    }
    else if(whomove->getPositionX() == powerupX-double_tile_dimension && whomove->getPositionY()>powerupY-double_tile_dimension)
    {
        whomove->setDirection(up);
    }

    if (whomove->getDirection() == down)
    {
        whomove->setPositionY(whomove->getPositionY()+whomove->getSpeed());
    }
    else if (whomove->getDirection() == left)
    {
        whomove->setPositionX(whomove->getPositionX()-whomove->getSpeed());
    }
    else if (whomove->getDirection() == right)
    {
        whomove->setPositionX(whomove->getPositionX()+whomove->getSpeed());
    }
    else if (whomove->getDirection() == up)
    {
        whomove->setPositionY(whomove->getPositionY()-whomove->getSpeed());
    }

}