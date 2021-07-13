//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_CONCRETEOBSERVER_H
#define MARTINA_BICCHI_7049270_CONCRETEOBSERVER_H
#include "Observer.h"
#include "NotesCollection.h"

class ConcreteObserver: public Observer{
public:
    explicit ConcreteObserver(NotesCollection* n): subject(n){
        subject->subscribe(this);
    };
    ~ConcreteObserver(){
        subject->unsubsribe(this);
        delete subject;
    }
    void update() override;
private:
    NotesCollection* subject;
};


#endif //MARTINA_BICCHI_7049270_CONCRETEOBSERVER_H
