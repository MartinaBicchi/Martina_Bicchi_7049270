//
// Created by Martina on 13/07/2021.
//

#include "ConcreteObserver.h"

void ConcreteObserver::update() {
    std::cout<<"Dopo la modifica nella collezione"<<subject->getName()<<"ci sono:"<<subject->NotesNumber()<<"note"<<std::endl;
}