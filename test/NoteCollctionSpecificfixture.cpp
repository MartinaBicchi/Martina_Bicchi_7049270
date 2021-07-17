//
// Created by Martina on 17/07/2021.
//

#include "gtest/gtest.h"
#include "../NotesCollectionSpecific.h"

class NoteCollectionSoecificfixture: public::testing::Test{

protected:
    void SetUp() override{
        notacoll.setName("namecollezionenota");
    }
    NotesCollectionSpecific notacoll;
};

TEST_F(NoteCollectionSoecificfixture, constructor){
    ASSERT_EQ("namecollezionenota",notacoll.getName());
}

TEST_F(NoteCollectionSoecificfixture, addNote){
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    notacoll.addNote(&n);
    ASSERT_EQ(1,notacoll.NotesNumber());
}

TEST_F(NoteCollectionSoecificfixture, removeNote){
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    notacoll.addNote(&n);
    notacoll.removeNote(name);
    ASSERT_EQ(0,notacoll.NotesNumber());
}
