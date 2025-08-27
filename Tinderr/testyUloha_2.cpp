//
// Created by PC1 on 19. 12. 2022.
//
#include <iostream>
#include "gtest/gtest.h"
#include "User.h"
#include "App.h"

using namespace ::testing;
TEST(TestSecondTask, push_users) {
    std::map<std::string,User> userovia;
    userovia.insert({"king@cc",User(25,"Dejvo","adawdaw","kosice","king@cc")});
    userovia.insert({"kg@cc",User(25,"Dejvo","adawdaw","kosice","king@cc")});
    userovia.insert({"g@cc",User(45,"ejvo","adawdaw","kosice","king@cc")});
    userovia.insert({"kng@cc",User(25,"Dejo","adawdaw","kosice","king@cc")});
    App tinder(userovia);
    ASSERT_EQ(4,tinder.getNumOfUsers());
    ASSERT_EQ(0,tinder.getNumberOfLikes());
    ASSERT_EQ(0,tinder.getNumberOfMatches());
}
TEST(TestSecondTask, check_users) {
    std::map<std::string,User> userovia;
    User john(19, "john", "adawdaw","bratislava","john@");
    userovia.insert({john.getEmail(),john});
    App tinder(userovia);
    ASSERT_EQ(0, tinder.getUserLikes("john@").size());
}
TEST(TestSecondTask, add_user) {
    std::map<std::string,User> userovia;
    User john(19, "john", "adawdaw","bratislava","john@H");
    userovia.insert({"gl@.com",User(25,"Dejvo","adawdaw","bratislava","gl@.com")});
    userovia.insert({"glo@.com",User(25,"Dejvo","adawdaw","bratislava","glo@.com")});
    userovia.insert({"gla@.com",User(45,"ejvo","adawdaw","bratislava","gla@.com")});
    userovia.insert({"gwl@.com",User(25,"Dejo","adawdaw","bratislava","gwl@.com")});
    App tinder(userovia);
    ASSERT_EQ(4,tinder.getNumOfUsers());
    tinder.addUser(john);
    ASSERT_EQ(0, tinder.getUserLikes("john@H").size());
    ASSERT_EQ(5,tinder.getNumOfUsers());
}
TEST(TestSecondTask, empty_app) {
    App tinder;
    ASSERT_EQ(0,tinder.getNumOfUsers());
    User john(19, "john", "adawdaw","bratislava","John@h");
    tinder.addUser(john);
    ASSERT_EQ(1,tinder.getNumOfUsers());
}
TEST(TestSecondTask, like) {
    App tinder;
    ASSERT_EQ(0,tinder.getNumOfUsers());
    User john(19, "john", "adawdaw","bratislava","jojhnk@aw");
    tinder.addUser(john);
    User agnezka(25,"agnezka","adawdaw","bratislava","agnes@.com");
}
TEST(TestSecondTask, deluser0) {
    App tinder;
    ASSERT_EQ(0,tinder.getNumOfUsers());
    User john(19, "john", "adawdaw","bratislava","johnyD@.com");
    tinder.addUser(john);
    ASSERT_TRUE(tinder.delUser(john));
    ASSERT_FALSE(tinder.delUser(john));
}
TEST(TestSecondTask, deluser1) {
    App tinder;
    ASSERT_EQ(0,tinder.getNumOfUsers());
    User john(19, "john", "adawdaw","bratislava","Johnz@derv.com");
    tinder.addUser(john);
    User agnezka(25,"agnezka","adawdaw","bratislava","agnes@is.sk");
    ASSERT_FALSE(tinder.delUser(agnezka));
}
TEST(TestSecondTask, delusers) {
    App tinder;
    ASSERT_EQ(0,tinder.getNumOfUsers());
    User john(19, "john", "adawdaw","bratislava","newyea@plot.com");
    tinder.addUser(john);
    ASSERT_EQ(1,tinder.getNumOfUsers());
    ASSERT_TRUE(tinder.delUser(john));
    ASSERT_FALSE(tinder.delUser(john));
    ASSERT_EQ(0,tinder.getNumOfUsers());
}
