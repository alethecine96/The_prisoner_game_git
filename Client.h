//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <iostream>
#include "Observer.h"

class Client: public Observer
{
public:
    const std::string &getTextAch() const;
    void setTextAch(const std::string &textAch);


    explicit Client(int id);

    virtual void update(int kill, std::string ) override;

private:
    std::string textAch;
    int id;
};


#endif //PROJECT_CLIENT_H
