//
// Created by Martina on 13/07/2021.
//

#include "NotesCollectionSpecific.h"

void NotesCollectionSpecific::addNote(Note* note) {
    notes.insert(std::make_pair(note->getTitle(),note));
    notify();
}
void NotesCollectionSpecific::removeNote(const std::string& n) {
    auto remove = notes.find(n);
    if (remove != notes.end()) {
        if (!remove->second->isLocked()) {
            notes.erase(remove);
            notify();
        } else
            throw std::runtime_error{"non è possibile rimuovere dalla lista delle note la nota inserita in quanto si tratta di una nota con la cancellazione bloccata"};
    }
    else
        throw std::runtime_error{"Non è possibile rimuovere la nota inserita in quanto non è presente"};
}

int NotesCollectionSpecific::NotesNumber() {
    return notes.size();
}
