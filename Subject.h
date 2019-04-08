//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H

#include "Observer.h"

class Subject
{
public:
    //register observer
    virtual void registerObserver(Observer *observer) = 0;

    //remove observer
    virtual void removeObserver(Observer *observer) = 0;

    //notify registered observers
    virtual void notifyObservers() = 0;

protected:
    virtual ~Subject() {};
};

#endif //PROJECT_SUBJECT_H
