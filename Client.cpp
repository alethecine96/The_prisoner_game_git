//
// Created by alessandro on 15/03/19.
//

#include "Client.h"

void Client::update(int kill, std::string textAch )
{
// Stampa gli Achievement
    const int a=2;
    const int b=1;
    std::cout<<kill<<std::endl;
    if(kill==a || kill==b)
    {
        switch (kill)
        {
            case (a):
                textAch = ("1 KILL!");
                setTextAch(textAch);
                std::cout<<"Una kill per te"<<std::endl;
                break;
            case (b):
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

Client::Client(int id)
{
    this->id = id;
}

const std::string &Client::getTextAch() const
{
    return textAch;
}

void Client::setTextAch(const std::string &textAch)
{
    Client::textAch = textAch;
}
