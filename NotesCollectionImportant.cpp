//
// Created by Martina on 13/07/2021.
//

#include "NotesCollectionImportant.h"
#include <exception>
void NotesCollectionImportant::addNote(Note* note){
    if(note->isImportant1()) {
        notes.insert(std::make_pair(note->getTitle(), note));
        notify();
    }
    else
        throw std::runtime_error{"non è possibile aggiungere alla lista delle note la nota inserita in quanto si tratta di una nota non importante"};
}

void NotesCollectionImportant::removeNote(const std::string& n){
    auto remove=notes.find(n);
    if(remove!=notes.end()) {
        if (!remove->second->isLocked()) {
            notes.erase(remove);
            notify();
        } else
            throw std::runtime_error{"non è possibile rimuovere dalla lista delle note la nota inserita in quanto si tratta di una nota con la cancellazione bloccata"};
    }
    else
       throw std::runtime_error{"Non è possibile rimuovere la nota inserita in quanto non è presente"};
}

int NotesCollectionImportant::NotesNumber() {
    return notes.size();
}