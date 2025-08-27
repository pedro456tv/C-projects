// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "User.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, Zly_vek) {
    try{
        User Roderik(4,"Roderik Antol","wadawda","ZILINA","rod@gmail.com");
    }catch(WrongInput &e){
        ASSERT_EQ("Wrong age or location!", e.message());
    }
}
TEST(TestFirstTask, Dobry_vek) {
    User Rojdo(45, "Rojdo xDD","awdaw","bratislava","rod@gmail.com");
    ASSERT_EQ(45, Rojdo.getAge());
}
TEST(TestFirstTask, Konstruktor_s_atributmi) {
    User Rojdo(45,"Rojdik","awdawdawd","banska bystrica","rod@gmail.com","plavanie,gym,fajter,skolak");
    ASSERT_EQ(45, Rojdo.getAge());
    Rojdo.addAttributes("panter");
    ASSERT_EQ("fajter,gym,panter,plavanie,skolak",Rojdo.getAttributes());
}
TEST(TestFirstTask, ZleMenoOrLokacia) {
    try {
        User Rojdo(45, "", "awdadawd","kosice", "rod@gmail.com""plavanie,gym,fajter,skolak");
    }catch (WrongInput &e){
        ASSERT_EQ("Name or location or password or email is empty!", e.message());
    }
}
TEST(TestFirstTask, ZleVek) {
    try {
        User Rojdo(8, "", "awdawda","pardubice", "rod@gmail.com","");
    }catch (WrongInput &e){
        ASSERT_EQ("Wrong age or location!", e.message());
    }
}
TEST(TestFirstTask, getnumLike_Match) {
    User Rojdo(28, "sergej", "awdawdada","kosice", "rod@gmail.com","");
    ASSERT_EQ(0, Rojdo.getNumOfLikes());
    ASSERT_EQ(0, Rojdo.getNumOfmatches());
}
TEST(TestFirstTask, empty_likes) {
    User Rojdo(38, "puskin", "adawdawdaw","kosice", "rod@gmail.com","");
    ASSERT_EQ("", Rojdo.getLikes());
    ASSERT_EQ("", Rojdo.getMatches());
}
TEST(TestFirstTask, location) {
    User Rojdo(38, "puskin", "adawdawdaw","kosice", "rod@gmail.com","");
    User agnezka(25,"adwad","awdawdawdaw","kosice","agn@gmail.com");
    ASSERT_EQ("KOSICE",Rojdo.getLocation());
    ASSERT_EQ("KOSICE",agnezka.getLocation());
}
TEST(TestFirstTask, equality) {
    User Rojdo(38, "puskin", "adawdawdaw","kosice", "rod@gmail.com");
    User agnezka(25,"adwad","awdawdawdaw","kosice","agn@gmail.com");
    ASSERT_TRUE(Rojdo == Rojdo);
    ASSERT_FALSE(Rojdo == agnezka);
}


