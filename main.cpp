#include <iostream>
#include "Note.h"
#include "NotesCollection.h"
#include "NotesCollectionImportant.h"
#include "NotesCollectionSpecific.h"
#include "ConcreteObserver.h"

int main() {
   Note* nota1;
    std::cout<<"Inserire nome della nota numero 1"<<std::endl;
    std::string name;
    getline(std::cin,name);
    std::string testo;
    std::cout<<"Inserire il testo della nota numero 1"<<std::endl;
    getline(std::cin,testo);
    std::cout << "Si tratta di una nota importante?      Digitare si o no" << std::endl;
    std::string importante;
    std::cin >> importante;

    bool important;
    if(importante=="si")
        important=true;
    else
        important=false;

    std::string bloccare;
    std::cout<<"Vuoi bloccare la cancellazione della nota?   Digitare di o no"<<std::endl;
    std::cin >> bloccare;

    bool locked;
    if(bloccare=="si")
        locked=true;
    else
        locked=false;
    nota1=new Note (name,testo,important,locked);


   std::string name2;
   std::cout<<"Inserire nome della nota numero 2"<<std::endl;
   getline(std::cin,name2);
    std::string testo2;
    std::cout<<"Inserire testo della nota numero 2"<<std::endl;
    getline(std::cin,testo2);
    std::string importante2;
    std::cout<<"Si tratta di una nota importante?         Digitare si o no"<<std::endl;
    getline(std::cin,importante2);
    bool important2;
    if(importante2=="si")
        important2=true;
    else
        important2=false;
    std::string bloccato;
    std::cout<<"Vuoi bloccare la cancellazione della nota?   Digitare si o no"<<std::endl;
    getline(std::cin,bloccato);
    bool locked2;
    if(bloccato=="si")
        locked2=true;
    else
        locked2=false;

    Note* nota2;
    nota2=new Note(name2,testo2,important2,locked2);

    Note* nota3;
    std::string name3;
    std::cout<<"Inserire nome della nota numero 3"<<std::endl;
    getline(std::cin,name3);
    std::string testo3;
    std::cout<<"Inserire il testo della nota numero 3"<<std::endl;
    getline(std::cin,testo3);
    std::cout << "Si tratta di una nota importante?      Digitare si o no" << std::endl;
    std::string importante3;
    std::cin >> importante3;

    bool important3;
    if(importante3=="si")
        important3=true;
    else
        important3=false;


    std::cout<<"Vuoi bloccare la cancellazione della nota?   Digitare si o no"<<std::endl;
    std::string bloccare3;
    std::cin >> bloccare3;

    bool locked3;
    if(bloccare3=="si")
        locked3=true;
    else
        locked3=false;

    nota3=new Note (name3,testo3,important3,locked3);


    NotesCollection* collection1;
    std::string nomecollection;
    std::cout<<"Inserire il nome della collezione delle note"<<std::endl;
    getline(std::cin,nomecollection);
    std::string specificoimportant;
    do {
        std::cout << "Vuoi creare una collezione di note specifica o una collezione di note importanti?  Digitare s o i"
                  << std::endl;
        std::cin>>specificoimportant;
    }while(specificoimportant!="s" || specificoimportant!="i");
    if(specificoimportant=="s")
        collection1=new NotesCollectionSpecific(nomecollection);
    else
        collection1=new NotesCollectionImportant(nomecollection);

    collection1->addNote(nota1);
    collection1->addNote(nota2);
    collection1->addNote(nota3);
    std::cout<<"Il numero di note nella collezione:"<<collection1->getName()<<"è di:"<<collection1->NotesNumber()<<std::endl;

    ConcreteObserver osservatore1(collection1);

    Note* nota4;
    std::string name4;
    std::cout<<"Inserire nome della nota numero 4"<<std::endl;
    getline(std::cin,name4);
    std::string testo4;
    std::cout<<"Inserire il testo della nota numero 4"<<std::endl;
    getline(std::cin,testo4);
    std::cout << "Si tratta di una nota importante?      Digitare si o no" << std::endl;
    std::string importante4;
    std::cin >> importante4;

    bool important4;
    if(importante4=="si")
        important4=true;
    else
        important4=false;

    std::cout<<"Vuoi bloccare la cancellazione della nota?   Digitare di o no"<<std::endl;
    std::string bloccare4;
    std::cin >> bloccare4;

    bool locked4;
    if(bloccare4=="si")
        locked4=true;
    else
        locked4=false;

    nota4=new Note(name4, testo4, important4,locked4);
    collection1->addNote(nota4);

    nota4->setLocked(true);
    collection1->removeNote(nota4->getTitle());
    std::string numeronota;
    std::cout<<"Inserire il numero della nota che si vuole rimuovere (prima/seconda/terza/quarta)"<<std::endl;
    std::cin>>numeronota;

    if(numeronota=="prima")
        collection1->removeNote(nota1->getTitle());
    else if(numeronota=="seconda")
        collection1->removeNote(nota2->getTitle());
    else if(numeronota=="terza")
        collection1->removeNote(nota3->getTitle());
    else if(numeronota=="quarta")
        collection1->removeNote(nota4->getTitle());

    return 0;
}
