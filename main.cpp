#include <iostream>
#include "Note.h"
#include "NotesCollection.h"
#include "NotesCollectionImportant.h"
#include "NotesCollectionSpecific.h"
#include "ConcreteObserver.h"

int main() {
    Note* nota1;
    std::string name="visita";
    std::string testo="Ricordarsi il dottore domani alle 18:00";
    nota1=new Note (name,testo,true);
    Note* nota2;
    name="viaggio";
    testo=" Prenotare l'albergo per il viaggio in Spagna";
    nota2=new Note (name,testo,true);
    Note* nota3;
    name="Netflix";
    testo="Fare abbonamento mensile";
    nota3=new Note (name,testo,true);
    NotesCollection* collection1;
    collection1=new NotesCollectionSpecific("Collezione note Martina");
    collection1->addNote(nota1);
    collection1->addNote(nota2);
    collection1->addNote(nota3);
    std::cout<<"Il numero di note nella collezione:"<<collection1->getName()<<"è di:"<<collection1->NotesNumber()<<std::endl;
    ConcreteObserver osservatore1(collection1);
    name="mare";
    testo="ricordarsi di fare la valigia per il mare";
    Note* nota4;
    nota4=new Note(name, testo, true);
    collection1->addNote(nota4);
    std::cout<<"Il numero di note nella collezione:"<<collection1->getName()<<"è di:"<<collection1->NotesNumber()<<std::endl;
    nota4->setLocked(true);
    collection1->removeNote("viaggio");
    collection1->removeNote("mare");
    std::cout<<"Il numero di note nella collezione:"<<collection1->getName()<<"è di:"<<collection1->NotesNumber()<<std::endl;
    return 0;
}
