//
// Created by Martina on 16/07/2021.
//
#include "gtest/gtest.h"
#include "../Note.h"
TEST(Note, Constructor)
{
    std::string name="name";
    std::string text="text";
    Note n(name,text);
    ASSERT_FALSE(n.isImportant1());
    ASSERT_FALSE(n.isLocked());
}
TEST(Note, setTitle){
    std::string name="name";
    std::string text="text";
    Note n(name,text,false,false);
    n.setTitle("ciao");
    ASSERT_EQ("ciao",n.getTitle());
    n.setLocked(true);
    ASSERT_THROW(n.setTitle("ciao1"),std::runtime_error);
}

TEST(Note, setText){
    std::string name="name";
    std::string text="text";
    Note n(name,text,false,false);
    n.setText("ciao sono io");
    ASSERT_EQ("ciao sono io",n.getText());
    n.setLocked(true);
    ASSERT_THROW(n.setText("ciao sei tu"),std::runtime_error);
}


TEST(Note, setImportant){
    std::string name="name";
    std::string text="text";
    Note n(name,text,false,false);
    n.setIsImportant(true);
    ASSERT_TRUE(n.isLocked());
    n.setLocked(true);
    ASSERT_THROW(n.setIsImportant(false),std::runtime_error);
}


TEST(Note, setLocked){
    std::string name="name";
    std::string text="text";
    Note n(name,text,false,false);
    n.setLocked(true);
    ASSERT_TRUE(n.isLocked());
}
