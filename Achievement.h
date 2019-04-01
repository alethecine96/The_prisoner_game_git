//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_ACHIEVEMENT_H
#define PROJECT_ACHIEVEMENT_H


#include <vector>
#include <algorithm>
#include "Subject.h"
#include "Observer.h"
#include <iostream>

class Achievement : public Subject
{
public:

    Achievement(): _kill(0){}
    std::vector<Observer *> observers; // observer

    void registerObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notifyObservers() ;//override;

    void setState(int kill);

    int getKill();

protected:
    int _kill;
};


#endif //PROJECT_ACHIEVEMENT_H
