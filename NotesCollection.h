//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_NOTESCOLLECTION_H
#define MARTINA_BICCHI_7049270_NOTESCOLLECTION_H
#include "map"
#include "algorithm"
#include "Note.h"

class NotesCollection {
public:
    NotesCollection(std::string nome): name(nome){};
    virtual void addNote(Note* note)=0;
    virtual void removeNote(const std::string& n)=0;

    const std::string &getName() const {
        return name;
    }
    void setName(const std::string &name) {
        NotesCollection::name = name;
    }

    const std::map<std::string, Note *> &getNotes() const {
        return notes;
    }
    void setNotes(const std::map<std::string, Note *> &notes) {
        NotesCollection::notes = notes;
    }

private:
    std::string name;
    std::map<std::string,Note*> notes;
};


#endif //MARTINA_BICCHI_7049270_NOTESCOLLECTION_H
