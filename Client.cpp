//
// Created by alessandro on 15/03/19.
//

#include "Client.h"

void Client::update()
{
// Stampa gli Achievement
    int kill=_achievement->getKill();
    if(kill==1 || kill==2)
    {
        switch (kill)
        {
            case (1):
                textAch = ("1 KILL!");
                setTextAch(textAch);
                break;
            case (2):
                textAch = ("2 KILL");
                setTextAch(textAch);
                break;
                /*case (false):
                    textAch = ("");
                    setTextAch(textAch);
                    break;*/
        }
    }
    else
    {
        textAch = ("");
        setTextAch(textAch);
    }
}

/*Client::Client(int id)
{
    this->id = id;
}*/

const std::string &Client::getTextAch() const
{
    return textAch;
}

void Client::setTextAch(const std::string &textAch)
{
    Client::textAch = textAch;
}
