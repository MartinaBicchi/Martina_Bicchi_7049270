//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_NOTE_H
#define MARTINA_BICCHI_7049270_NOTE_H
#include <iostream>
#include <string>

class Note {
public:
    Note(std::string& title, std::string& text, bool important=false, bool locked=false):title(title), text(text), isImportant(important), locked(locked){}

    const std::string &getTitle() const {
        return title;
    }
    void setTitle(const std::string& titolo) {
        if(!locked)
            title = titolo;
        else
            std::cout<<"Impossibile modificare il titolo della nota"<<title<<std::endl;
    }

    const std::string &getText() const {
        return text;
    }
    void setText(const std::string& testo) {
        if(!locked)
            text = testo;
        else
            std::cout<<"Impossibile modificare il testo della nota"<<title<<std::endl;
    }

    bool isImportant1() const {
        return isImportant;
    }
    void setIsImportant(bool isImportante) {
        if(!locked)
            Note::isImportant = isImportante;
        else
            std::cout<<"Impossibile modificare l'importanza della nota"<<title<<std::endl;
    }

    bool isLocked() const {
        return locked;
    }
    void setLocked(bool islocked) {
        Note::locked = islocked;
    }

    Note(const Note& original);
    Note& operator=(const Note& original);

private:
    std::string title;
    std::string text;
    bool isImportant;
    bool locked;
};


#endif //MARTINA_BICCHI_7049270_NOTE_H
