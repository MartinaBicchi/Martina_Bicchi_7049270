//
// Created by Martina on 13/07/2021.
//

#include "NotesCollectionSpecific.h"

void NotesCollectionSpecific::addNote(Note* note) {
    notes.insert(std::make_pair(note->getTitle(),note));
    notify();
}
void NotesCollectionSpecific::removeNote(const std::string& n){
    auto remove=notes.find(n);
    if(!remove->second->isLocked()) {
        notes.erase(remove);
        notify();
    }
    else
        std::cout<<"Non è possibile rimuovere dalla lista di note"<<name<<" la nota "<<n<<std::endl;
}

int NotesCollectionSpecific::NotesNumber() {
    return notes.size();
}
