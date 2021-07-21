//
// Created by Martina on 17/07/2021.
//

#include "gtest/gtest.h"
#include "../NotesCollectionSpecific.h"

class NoteCollectionSpecificfixture: public::testing::Test{

protected:
    void SetUp() override{
        notacoll.setName("namecollezionenota");
    }
    NotesCollectionSpecific notacoll;
};

TEST_F(NoteCollectionSpecificfixture, constructor){
    notacoll.setName("namecoll");
    ASSERT_EQ("namecollezionenota",notacoll.getName());
}

TEST_F(NoteCollectionSpecificfixture, addNote){
    notacoll.setName("namecoll");
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    notacoll.addNote(&n);
    ASSERT_EQ(1,notacoll.NotesNumber());
}

TEST_F(NoteCollectionSpecificfixture, removeNote){
    notacoll.setName("namecoll");
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    ASSERT_THROW(notacoll.removeNote("ciao"),std::runtime_error);
    notacoll.getNotes().find(name)->second->setLocked(true);
    ASSERT_THROW(notacoll.removeNote(name),std::runtime_error);
    notacoll.getNotes().find(name)->second->setLocked(false);
    notacoll.removeNote(name);
    ASSERT_EQ(0,notacoll.NotesNumber());
}