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
