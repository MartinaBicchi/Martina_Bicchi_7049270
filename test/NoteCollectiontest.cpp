//
// Created by Martina on 17/07/2021.
//
#include "gtest/gtest.h"
#include "../NotesCollection.h"
#include "../NotesCollectionImportant.h"
#include "../ConcreteObserver.h"

TEST(NotesCollection,subscribe){
    NotesCollection* col=new NotesCollectionImportant("name");
    Observer* o=new ConcreteObserver(col);
    col->unsubsribe(o);
    ASSERT_EQ(1,col->ContoObserver());
}

TEST(NotesCollection, unsubscribe){
    NotesCollection* col=new NotesCollectionImportant("name");
    Observer* o=new ConcreteObserver(col);
    col->unsubsribe(o);
    col->unsubsribe(o);
    ASSERT_EQ(0,col->ContoObserver());
}