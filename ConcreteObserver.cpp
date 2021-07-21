//
// Created by Martina on 13/07/2021.
//

#include "ConcreteObserver.h"

void ConcreteObserver::update() {
    std::cout<<"Dopo la modifica nella collezione "<<subject->getName()<<" ci sono: "<<subject->NotesNumber()<<" note"<<std::endl;
   int count=0;
    for(auto &itr:subject->getNotes())
    {
        if(itr.second->isLocked())
            count++;
    }
    std::cout<<"Dopo la modifica nella collezione "<<subject->getName()<<" ci sono:"<<count<<"note bloccate"<<std::endl;
}

NotesCollection *ConcreteObserver::getSubject() const {
    return subject;
}
