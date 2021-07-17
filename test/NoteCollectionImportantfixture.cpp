//
// Created by Martina on 17/07/2021.
//

#include "gtest/gtest.h"
#include "../NotesCollectionImportant.h"

class NotesCollectionImportantSuite:public::testing::Test{
protected:
    void SetUp() override{
        notacoll.setName("namecollezionenota");
    }
    NotesCollectionImportant notacoll;
};

TEST_F(NotesCollectionImportantSuite, constructor){
    ASSERT_EQ("namecollezionenota",notacoll.getName());
}

TEST_F(NotesCollectionImportantSuite, addNote){
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    notacoll.addNote(&n);
    ASSERT_EQ(1,notacoll.NotesNumber());
}

TEST_F(NotesCollectionImportantSuite, removeNote){
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    notacoll.addNote(&n);
    notacoll.removeNote(name);
    ASSERT_EQ(0,notacoll.NotesNumber());
}
