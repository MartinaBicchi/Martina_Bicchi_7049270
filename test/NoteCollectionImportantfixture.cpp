//
// Created by Martina on 17/07/2021.
//

#include "gtest/gtest.h"
#include "../NotesCollectionImportant.h"

class NotesCollectionImportantSuite:public::testing::Test{
protected:
    NotesCollectionImportant notacoll;
};

TEST_F(NotesCollectionImportantSuite, constructor){
    notacoll.setName("namecoll");
    ASSERT_EQ("namecollezionenota",notacoll.getName());
}

TEST_F(NotesCollectionImportantSuite, addNote){
    notacoll.setName("namecoll");
    notacoll.setName("Nomecoll");
    std::string name="name";
    std::string text="text";
    Note n(name,text,true);
    notacoll.addNote(&n);
    ASSERT_EQ(1,notacoll.NotesNumber());
    std::string name2="name2";
    std::string text2="text2";
    Note n2(name2,text2,false);
    ASSERT_THROW(notacoll.addNote(&n2),std::runtime_error);
}

TEST_F(NotesCollectionImportantSuite, removeNote){
    notacoll.setName("namecoll");
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    notacoll.addNote(&n);
    ASSERT_THROW(notacoll.removeNote("ciao"),std::runtime_error);
    notacoll.getNotes().find(name)->second->setLocked(true);
    ASSERT_THROW(notacoll.removeNote(name),std::runtime_error);
    notacoll.getNotes().find(name)->second->setLocked(false);
    notacoll.removeNote(name);
    ASSERT_EQ(0,notacoll.NotesNumber());
}
