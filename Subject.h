//
// Created by alessandro on 15/03/19.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H

#include "Observer.h"

class Subject
{
public:
    /**
     * Registra un observer
     * @param observer l'oggetto observer da registrare
     */
    virtual void registerObserver(Observer *observer) = 0;

    /**
     * Rimuove un observer
     * @param observer l'oggetto observer da cancellare
     */
    virtual void removeObserver(Observer *observer) = 0;

    /**
     * Notifica tutti gli observer registrati
     */
    virtual void notifyObservers() = 0;

protected:
    virtual ~Subject() {};
};

#endif //PROJECT_SUBJECT_H
