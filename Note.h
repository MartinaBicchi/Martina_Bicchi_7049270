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
            throw std::runtime_error{"Impossibile modificare il titolo della nota"};
    }

    const std::string &getText() const {
        return text;
    }
    void setText(const std::string& testo) {
        if(!locked)
            text = testo;
        else
            throw std::runtime_error{"Impossibile modificare il testo della nota"};
    }

    bool isImportant1() const {
        return isImportant;
    }
    void setIsImportant(bool isImportante) {
        if(!locked)
            Note::isImportant = isImportante;
        else
            throw std::runtime_error{"Impossibile modificare l'importanza della nota"};
    }

    bool isLocked() const {
        return locked;
    }
    void setLocked(bool islocked) {
        Note::locked = islocked;
    }

private:
    std::string title;
    std::string text;
    bool isImportant;
    bool locked;
};


#endif //MARTINA_BICCHI_7049270_NOTE_H
