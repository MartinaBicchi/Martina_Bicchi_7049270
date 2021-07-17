//
// Created by Martina on 13/07/2021.
//

#include "NotesCollectionImportant.h"
void NotesCollectionImportant::addNote(Note* note){
    if(note->isImportant1()) {
        notes.insert(std::make_pair(note->getTitle(), note));
        notify();
    }
    else
        std::cout<<"Non è possibile inserire la nota"<<note->getTitle()<<"nella collezione"<<name<<std::endl;
}

void NotesCollectionImportant::removeNote(const std::string& n){
    auto remove=notes.find(n);
    if(!remove->second->isLocked()) {
        notes.erase(remove);
        notify();
    }
    else
        std::cout<<"Non è possibile rimuovere dalla lista di note "<<name<<" la nota "<<n<< "in quanto ha la cancellazione bloccata"<<std::endl;
}

int NotesCollectionImportant::NotesNumber() {
    return notes.size();
}