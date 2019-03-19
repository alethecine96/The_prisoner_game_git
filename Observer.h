//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_OBSERVE_H
#define PROJECT_OBSERVE_H



#include <iostream>

class Observer
{
public:
    virtual void update(int kill, std::string)=0;
};


#endif //PROJECT_OBSERVER_H
