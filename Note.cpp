//
// Created by Martina on 13/07/2021.
//

#include "Note.h"

Note::Note(const Note& original){
    if(locked)
        std::cout<<"L'oggetto non si puo' copiare"<<std::endl;
    else
    {
        this->title=original.getTitle();
        this->text=original.getText();
        this->isImportant=original.isImportant1();
        this->locked=original.isLocked();
    }
}
Note& Note::operator=(const Note& original){
    if(locked)
        std::cout<<"L'oggetto non si puo' copiare"<<std::endl;
    else
    {   if(this!=&original) {
            this->title = original.getTitle();
            this->text = original.getText();
            this->isImportant = original.isImportant1();
            this->locked = original.isLocked();
        }
        return *this;
    }
}