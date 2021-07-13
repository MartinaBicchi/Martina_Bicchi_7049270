//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_NOTESCOLLECTIONSPECIFIC_H
#define MARTINA_BICCHI_7049270_NOTESCOLLECTIONSPECIFIC_H
#include "NotesCollection.h"
#include "Note.h"

class NotesCollectionSpecific: public NotesCollection {
public:
    explicit NotesCollectionSpecific(const std::string& name):NotesCollection(name){};
    ~NotesCollectionSpecific() override=default;
    void addNote(Note* note) override;
    void removeNote(const std::string& n) override;
    int NotesNumber() override;
};


#endif //MARTINA_BICCHI_7049270_NOTESCOLLECTIONSPECIFIC_H
