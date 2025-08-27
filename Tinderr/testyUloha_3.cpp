//
// Created by PC1 on 21. 1. 2023.
//
#include <iostream>
#include "gtest/gtest.h"
#include "User.h"
#include "App.h"
#include "Search.h"
using namespace ::testing;

TEST(TestThirdTask, push_users) {
    std::map<std::string,User> userovia;
    userovia.insert({"king@cc",User(25,"Dejvo","adawdaw","bratislava","king@cc")});
    userovia.insert({"kg@cc",User(25,"Dejvo","adawdaw","bratislava","kg@cc")});
    userovia.insert({"g@cc",User(45,"ejvo","adawdaw","bratislava","g@cc")});
    userovia.insert({"kng@cc",User(25,"Dejo","adawdaw","kosice","kng@cc")});
    App tinder(userovia);
    ASSERT_EQ(4,tinder.getNumOfUsers());
    ASSERT_EQ(0,tinder.getNumberOfLikes());
    ASSERT_EQ(0,tinder.getNumberOfMatches());
    ASSERT_TRUE(tinder.login("g@cc","adawdaw"));
    ASSERT_FALSE(tinder.login("g@cc","adawdaw"));
}
TEST(TestThirdTask, login) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    ASSERT_TRUE(tinder.login("g@cc", "adawdaw"));
    ASSERT_TRUE(tinder.logout());
    ASSERT_TRUE(tinder.logout());
    User Fero(25, "Fero", "adawdaw", "bratislava", "kings@cc");
    try {
        tinder.login("kings@cc", "adawdaw");
    } catch (WrongInput &e) {
        ASSERT_EQ("email or password incorrect or you are not registered", e.message());
    }
    tinder.addUser(Fero);
    ASSERT_TRUE(tinder.login("kings@cc", "adawdaw"));
    ASSERT_FALSE(tinder.login("kings@cc", "adawdaw"));
    ASSERT_FALSE(tinder.login("g@cc","adawdaw"));
}
TEST(TestThirdTask, del_login) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    User Fero(25, "Fero", "adawdaw", "bratislava", "kings@cc");
    try {
        tinder.login("kings@cc", "adawdaw");
    } catch (WrongInput &e) {
        ASSERT_EQ("email or password incorrect or you are not registered", e.message());
    }
    tinder.addUser(Fero);
    ASSERT_EQ(5,tinder.getNumOfUsers());
    ASSERT_TRUE(tinder.login("kings@cc", "adawdaw"));
    tinder.delUser(Fero);
    ASSERT_EQ(4,tinder.getNumOfUsers());
    ASSERT_TRUE(tinder.login("kng@cc","adawdaw"));
}

TEST(TestThirdTask, delUser) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    User Fero(25, "Fero", "adawdaw", "bratislava", "kings@cc");
    ASSERT_FALSE(tinder.delUser(Fero));
    tinder.addUser(Fero);
    ASSERT_TRUE(tinder.delUser(Fero));
    ASSERT_TRUE(tinder.login("kng@cc","adawdaw"));
    ASSERT_TRUE(tinder.delUser("kng@cc"));
}
TEST(TestThirdTask, deluserlikes) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    User Fero(25, "Fero", "adawdaw", "bratislava", "kings@cc");
    ASSERT_FALSE(tinder.delUser(Fero));
    tinder.addUser(Fero);
    tinder.login("kings@cc","adawdaw");
    ASSERT_FALSE(tinder.like("kng@cc","kings@cc"));
    ASSERT_TRUE(tinder.like("kings@cc","kng@cc"));
    ASSERT_EQ(1,tinder.getNumberOfLikes());
    ASSERT_TRUE(tinder.delUser(Fero));
    ASSERT_EQ(0,tinder.getNumberOfLikes());

}
TEST(TestThirdTask, likes_matches) {
    std::map<std::string, User> userovia;
    userovia.insert({"king@cc", User(25, "Dejvo", "adawdaw", "bratislava", "king@cc")});
    userovia.insert({"kg@cc", User(25, "Dejvo", "adawdaw", "bratislava", "kg@cc")});
    userovia.insert({"g@cc", User(45, "ejvo", "adawdaw", "bratislava", "g@cc")});
    userovia.insert({"kng@cc", User(25, "Dejo", "adawdaw", "kosice", "kng@cc")});
    App tinder(userovia);
    tinder.login("king@cc","adawdaw");
    tinder.like("king@cc","kng@cc");
    ASSERT_FALSE(tinder.like("kng@cc","king@cc"));
    tinder.logout();
    tinder.login("kng@cc","adawdaw");
    tinder.like("kng@cc","king@cc");
    ASSERT_EQ(2,tinder.getNumberOfLikes());
    ASSERT_EQ(1,tinder.getNumberOfMatches());
    ASSERT_TRUE(tinder.delUser("kng@cc"));
    ASSERT_EQ(0,tinder.getNumberOfLikes());
    ASSERT_EQ(0,tinder.getNumberOfMatches());
}