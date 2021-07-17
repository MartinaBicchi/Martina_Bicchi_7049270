//
// Created by Martina on 17/07/2021.
//
#include "gtest/gtest.h"
#include "../ConcreteObserver.h"
#include "../NotesCollectionSpecific.h"

TEST(ConcreteObserver, construct){
    NotesCollection* coll=new NotesCollectionSpecific("namecol");
    Observer* ob=new ConcreteObserver(coll);
    ASSERT_EQ(1,dynamic_cast<ConcreteObserver*>(ob)->getSubject()->ContoObserver());
}

