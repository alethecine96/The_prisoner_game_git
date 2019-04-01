//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_OBSERVE_H
#define PROJECT_OBSERVE_H



#include <iostream>

class Observer  //TODO Observer modalità pull da questo sito esempio: https://dzone.com/articles/observer-pattern
{
public:

    virtual ~Observer() {};
    virtual void update()=0;
};


#endif //PROJECT_OBSERVER_H
