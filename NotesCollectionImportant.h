//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_NOTESCOLLECTIONIMPORTANT_H
#define MARTINA_BICCHI_7049270_NOTESCOLLECTIONIMPORTANT_H
#include "NotesCollection.h"
#include "Note.h"

class NotesCollectionImportant: public NotesCollection {
public:
    explicit NotesCollectionImportant(const std::string& name): NotesCollection(name){};
    ~NotesCollectionImportant() override=default;
    void addNote(Note* note) override;
    void removeNote(const std::string& n) override;
    int NotesNumber() override;
};


#endif //MARTINA_BICCHI_7049270_NOTESCOLLECTIONIMPORTANT_H
