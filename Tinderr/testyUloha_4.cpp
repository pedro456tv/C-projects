//
// Created by PC1 on 29. 1. 2023.
//
#include <iostream>
#include "gtest/gtest.h"
#include "User.h"
#include "App.h"
#include "Search.h"
using namespace ::testing;
TEST(TestFourthTask, search) {
    std::map<std::string,User> userovia;
    userovia.insert({"king@cc",User(25,"Dejvo","adawdaw","bratislava","king@cc","sport")});
    userovia.insert({"kg@cc",User(25,"Dejvo","adawdaw","bratislava","kg@cc","kosenie,plavanie")});
    userovia.insert({"g@cc",User(45,"ejvo","adawdaw","bratislava","g@cc","sport,plavanie,kosenie")});
    userovia.insert({"kng@cc",User(25,"Dejo","adawdaw","kosice","kng@cc","sport,plavanie")});
    App tinder(userovia);
    try{
        tinder.findBestMatches("k@cc");
    }catch(WrongInput &e){
        ASSERT_EQ("NOT LOGGED IN OR WRONG USER!",e.message());
    }
    tinder.login("g@cc","adawdaw");
    std::set<std::string> matches = {"kg@cc"};
    ASSERT_EQ(matches,tinder.findBestMatches("g@cc"));
}
TEST(TestFourthTask, search2) {
    std::map<std::string,User> userovia;
    userovia.insert({"king@cc",User(25,"Dejvo","adawdaw","kosice","king@cc","sport,disko,kosenie,plavanie")});
    userovia.insert({"kg@cc",User(25,"Dejvo","adawdaw","bratislava","kg@cc","kosenie,plavanie,sach")});
    userovia.insert({"g@cc",User(45,"ejvo","adawdaw","bratislava","g@cc","sport,plavanie,kosenie")});
    userovia.insert({"kng@cc",User(25,"Dejo","adawdaw","kosice","kng@cc","sport,plavanie,disko")});
    App tinder(userovia);
    tinder.login("g@cc","adawdaw");
    std::set<std::string> matches = {"kg@cc"};
    ASSERT_EQ(matches,tinder.findBestMatches("g@cc"));
    tinder.logout();
    tinder.login("kng@cc","adawdaw");
    matches.clear();
    matches.insert("king@cc");
    ASSERT_EQ(matches,tinder.findBestMatches("kng@cc"));
    User Fero(19,"Fero","abcdefg","zilina","feri@gmail.com","kosenie,plavanie,disko");
    try{
        tinder.findBestMatches("feri@gmail.com");
    }catch(WrongInput &e){
        ASSERT_EQ("NOT LOGGED IN OR WRONG USER!",e.message());
    }
    tinder.addUser(Fero);
    matches.clear();
    tinder.logout();
    tinder.login("feri@gmail.com","abcdefg");
    ASSERT_EQ(matches,tinder.findBestMatches("feri@gmail.com"));
}
TEST(TestFourthTask, write_file) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    tinder.login("king@cc","adawdaw");
    tinder.like("king@cc","kng@cc");
    tinder.logout();
    tinder.login("kng@cc","adawdaw");
    tinder.like("kng@cc","king@cc");
    ASSERT_TRUE(tinder.writeAppToFile("file.txt"));
}
TEST(TestFourthTask, read_file) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    tinder.login("king@cc","adawdaw");
    tinder.like("king@cc","kng@cc");
    tinder.logout();
    tinder.login("kng@cc","adawdaw");
    tinder.like("kng@cc","king@cc");
    ASSERT_TRUE(tinder.writeAppToFile("file.txt"));
    App tinder1;
    ASSERT_TRUE(tinder1.readAppFromFile("file.txt"));
    ASSERT_EQ(tinder.getNumOfUsers(),tinder1.getNumOfUsers());
    ASSERT_EQ(tinder.getNumberOfLikes(),tinder1.getNumberOfLikes());
    ASSERT_EQ(tinder.getUserLikes("kng@cc"),tinder1.getUserLikes("kng@cc"));
    ASSERT_EQ(tinder.getUserLikes("king@cc"),tinder1.getUserLikes("king@cc"));
    ASSERT_EQ(tinder.getUserLikes("g@cc"),tinder1.getUserLikes("g@cc"));
}
TEST(TestFourthTask, read_file_dynamically) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App *tinder = new App(userovia);
    tinder->login("king@cc","adawdaw");
    tinder->like("king@cc","kng@cc");
    tinder->logout();
    tinder->login("kng@cc","adawdaw");
    tinder->like("kng@cc","king@cc");
    ASSERT_TRUE(tinder->writeAppToFile("file.txt"));
    ASSERT_EQ(4,tinder->getNumOfUsers());
    delete tinder;
    tinder = new App(userovia);
    User fero(45,"fero","awdada","bratislava","fero@fero.com");
    tinder->addUser(fero);
    ASSERT_TRUE(tinder->readAppFromFile("file.txt"));
    ASSERT_EQ(5,tinder->getNumOfUsers());
    delete tinder;
}