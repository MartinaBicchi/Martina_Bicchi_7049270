//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_SUBJECT_H
#define MARTINA_BICCHI_7049270_SUBJECT_H
#include "NotesCollection.h"
#include "list"
#include "algorithm"
#include "Observer.h"

class Subject{
public:
    virtual ~Subject()=default;
    virtual void subscribe(Observer* onew)=0;
    virtual void unsubscribe(Observer* old)=0;
    virtual void notify()=0;
protected:
    std::list<Observer*> observers;
};
#endif //MARTINA_BICCHI_7049270_SUBJECT_H
