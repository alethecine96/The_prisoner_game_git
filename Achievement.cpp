//
// Created by alessandro on 15/03/19.
//

#include "Achievement.h"

void Achievement::registerObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Achievement::removeObserver(Observer *observer)
{
    // find the observer
    auto iterator = std::find(observers.begin(), observers.end(), observer);

    if (iterator != observers.end())
    { // observer trovato
        observers.erase(iterator); // rimuove l' observer
    }
}

void Achievement::notifyObservers()
{
    for (Observer *observer : observers)
    { // notifica gli observer
        observer->update();
    }
}

void Achievement::setState(int kill)
{
    _kill = kill;
    notifyObservers();
}

int Achievement::getKill()
{
    return _kill;
}
