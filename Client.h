//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "Achievement.h"

class Client: public Observer
{
public:



    Client(Achievement* achievement): _achievement(achievement)
    {
        _achievement->registerObserver(this);
    }
    ~Client()
    {
        _achievement->removeObserver(this);
    }

    virtual void update() override;
    const std::string &getTextAch() const;
    void setTextAch(const std::string &textAch);

private:
    Achievement* _achievement;
    std::string textAch;
};


#endif //PROJECT_CLIENT_H
