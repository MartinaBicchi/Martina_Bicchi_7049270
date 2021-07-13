//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_NOTESCOLLECTION_H
#define MARTINA_BICCHI_7049270_NOTESCOLLECTION_H
#include "map"
#include "algorithm"
#include "Note.h"
#include "Subject.h"

class NotesCollection: public subject {
public:
    NotesCollection(std::string nome): name(nome){};
    virtual ~NotesCollection(){};
    virtual void addNote(Note* note)=0;
    virtual void removeNote(const std::string& n)=0;
    virtual int NotesNumber()=0;
    virtual void subscribe(Observer* onew);
    virtual void unsubsribe(Observer* old);
    virtual void notify();

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

protected:
    std::string name;
    std::map<std::string,Note*> notes;
};


#endif //MARTINA_BICCHI_7049270_NOTESCOLLECTION_H
