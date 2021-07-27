#include <iostream>
#include "Note.h"
#include "NotesCollection.h"
#include "NotesCollectionImportant.h"
#include "NotesCollectionSpecific.h"
#include "ConcreteObserver.h"
#include <memory>

int main() {
    Note* nota1;
    std::string name;
    std::cout<<"Inserire nome della nota numero 1"<<std::endl;
    getline(std::cin,name);
    std::string text;
    std::cout<<"Inserire testo della nota numero 1"<<std::endl;
    getline(std::cin,text);
    std::string importante;
    std::cout<<"Si tratta di una nota importante?        Digitare si/no"<<std::endl;
    getline(std::cin,importante);
    bool important;
    if(importante=="si")
        important= true;
    else
        important=false;
    std::string bloccato;
    std::cout<<"Vuoi bloccare la cancellazione della nota?        Digitare si/no"<<std::endl;
    getline(std::cin,bloccato);
    bool locked;
    if(bloccato=="si")
        locked= true;
    else
        locked=false;
    nota1=new Note(name,text,important,locked);

    Note* nota2;
    std::string name2;
    std::cout<<"Inserire nome della nota numero 2"<<std::endl;
    getline(std::cin,name2);

    std::string text2;
    std::cout<<"Inserire testo della nota numero 2"<<std::endl;
    getline(std::cin, text2);

    std::string importante2;
    std::cout<<"Si tratta di una nota importante?        Digitare si o no"<<std::endl;
    getline(std::cin, importante2);
    bool important2;
    if(importante2=="si")
        important2=true;
    else
        important2=false;

    std::string bloccato2;
    std::cout<<"Vuoi bloccare la cancellazione della nota?          Digitare si o no"<<std::endl;
    getline(std::cin,bloccato2);
    bool locked2;
    if(bloccato2=="si")
        locked2=true;
    else
        locked2=false;
    nota2=new Note(name2,text2,important2,locked2);


    Note* nota3;
    std::string name3;
    std::cout<<"Inserisci nome della nota numero 3"<<std::endl;
    getline(std::cin,name3);

    std::string text3;
    std::cout<<"Inserisci il testo della nota numero 3"<<std::endl;
    getline(std::cin, text3);

    std::string importante3;
    std::cout<<"Si tratta di una nota importante?        Digitare si o no"<<std::endl;
    getline(std::cin,importante3);
    bool important3;
    if(importante3=="si")
        important3=true;
    else
        important3=false;

    std::string bloccato3;
    std::cout<<"Vuoi bloccare la cancellazione della nota?"<<std::endl;
    getline(std::cin,bloccato3);
    bool locked3;
    if(bloccato3=="si")
        locked3=true;
    else
        locked3=false;

    nota3=new Note(name3,text3,important3,locked3);

    NotesCollection* collection1;
    std::string nomecollection;
    std::cout<<"Inserire il nome della collezione delle note"<<std::endl;
    getline(std::cin,nomecollection);
    std::string specificoimportant;
    std::cout << "Vuoi creare una collezione di note specifica o una collezione di note importanti?  Digitare specifica o importanti"
                  << std::endl;
    getline(std::cin,specificoimportant);

    if(specificoimportant=="specifica")
        collection1=new NotesCollectionSpecific(nomecollection);
    else
        collection1=new NotesCollectionImportant(nomecollection);

    std::cout<<"Blocco la cancellazione della nota numero 2"<<std::endl;
    nota2->setLocked(true);

    std::string numeronota;
    std::cout<<"Inserire il numero della nota che si vuole rimuovere (prima/seconda/terza)"<<std::endl;
    getline(std::cin,numeronota);


    try {
        if (numeronota == "prima") {
            collection1->removeNote(nota1->getTitle());
            std::cout << "Rimossa nota numero uno" << std::endl;
            std::cout << std::endl;
        } else if (numeronota == "seconda") {
            collection1->removeNote(nota2->getTitle());
            std::cout << "Rimossa nota numero due" << std::endl;
            std::cout << std::endl;
        } else if (numeronota == "terza") {
            collection1->removeNote(nota3->getTitle());
            std::cout << "Rimossa nota numero tre" << std::endl;
            std::cout << std::endl;
        }
    }
    catch(std::runtime_error& e){
        std::cerr<<e.what()<<std::endl;
    }

try {
    collection1->addNote(nota1);
    collection1->addNote(nota2);
    collection1->addNote(nota3);
}catch(std::runtime_error& e)
{
    std::cout<<e.what()<<std::endl;
}
    std::cout<<"Il numero di note nella collezione  "<<collection1->getName()<<":         "<<collection1->NotesNumber()<<std::endl;

    ConcreteObserver osservatore1(collection1);

    Note* nota4;
    std::string name4;
    std::cout<<"Inserire nome della nota numero 4"<<std::endl;
    getline(std::cin,name4);

    std::string testo4;
    std::cout<<"Inserire il testo della nota numero 4"<<std::endl;
    getline(std::cin,testo4);

    std::string importante4;
    std::cout << "Si tratta di una nota importante?      Digitare si o no" << std::endl;
    getline(std::cin,importante4);

    bool important4;
    if(importante4=="si")
        important4=true;
    else
        important4=false;

    std::string bloccare4;
    std::cout<<"Vuoi bloccare la cancellazione della nota?   Digitare di o no"<<std::endl;
    getline(std::cin,bloccare4);

    bool locked4;
    if(bloccare4=="si")
        locked4=true;
    else
        locked4=false;

    nota4=new Note(name4, testo4, important4,locked4);
    try {
        collection1->addNote(nota4);
    }catch(std::runtime_error& e)
    {
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"Viene bloccata la cancellazione della nota numero 4"<<std::endl;
    nota4->setLocked(true);

    std::cout<<"Provo a rimuovere la nota numero 4 che ha la cancellazione bloccata"<<std::endl;
    try{
    collection1->removeNote(nota4->getTitle());}
    catch(std::runtime_error& e){
        std::cerr<<e.what()<<std::endl;
    }
    try{
    nota4->setIsImportant(true);}catch(std::runtime_error& e)
    {
        std::cerr<<e.what()<<std::endl;
    }


    return 0;
}
