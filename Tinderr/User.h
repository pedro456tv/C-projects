#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

const int MAX_N_ATT = 5;
const std::vector<std::string> cities = {"ZILINA","BRATISLAVA","TRENCIN","KOSICE","PRESOV","TRNAVA","NITRA","BANSKA BYSTRICA"};
class WrongInput : public std::exception {
    std::string text;
public:
    explicit WrongInput(std::basic_string<char> v) { text = v; };
    std::string message() const { return text; };
};

class User {
    int age;
    std::string email;
    std::string name;
    std::string location;
    std::string password;
    std::set<std::string> attributes;
    std::set<User> matches;
    std::set<User> likes;
private:
    void putConstraints(const int &age0,const std::string &name0,const std::string &password0,const std::string &location0,const std::string &email0);
    static bool checkAge(const int &age0){ return (age0 > 17 && age0 < 120);};
    static bool checkLocation(const std::string &location0);
public:
    User(const int &age0,const std::string &name0,const std::string &password0, const std::string &location0,const std::string &email0);
    User(const int &age0,const std::string &name0,const std::string &password0,const std::string &location0, const std::string &email0, const std::string &attributes0);
    explicit User(const std::string &user0);
    ~User(){};
    void addAttributes(const std::string &attributes0);
    int getAge() const {return age;};
    std::string getPassword() const {return password;};
    std::string getEmail() const {return email;};
    std::string getLocation() const {return location;};
    std::string getName() const {return name;};
    std::string getAttributes();
    std::set<std::string> getsetAttributes() const {return attributes;};
    int getNumOfLikes() const {return likes.size();};
    int getNumOfmatches()const {return matches.size();};
    std::string getLikes()const;
    std::string getMatches()const;
    std::set<User> getArrayLikes()const {return likes;};
    std::set<User> getArrayMatches()const {return matches;};
    void addLike(const User &user0){likes.insert(user0);};
    void addMatch(const User &user0){matches.insert(user0);};
    void delLike(const User &user0){likes.erase(user0);};
    void delMatch(const User &user0){matches.erase(user0);};
    bool operator==(const User &user0)const;
    bool operator<(const User &user0) const;
};


