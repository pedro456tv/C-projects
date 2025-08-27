#include <iostream>
#include "User.h"

//1.uloha
User::User(const int &age0, const std::string &name0, const std::string &password0, const std::string &location0,
           const std::string &email0) {
    try {
        putConstraints(age0, name0, password0, location0, email0);
    } catch (WrongInput &e) {
        throw WrongInput(e.message());
    }
}

User::User(const std::string &user0) {
    if (user0.empty()) {
        throw WrongInput("Wrong input!");
    }
    try {
        int age0 = std::stoi(user0.substr(0, user0.find(',')));
        std::string user_copy = user0.substr(user0.find(',') + 1, user0.length());
        std::string name0 = user_copy.substr(0, user_copy.find(','));
        user_copy = user_copy.substr(user_copy.find(',') + 1, user_copy.length());
        std::string password0 = user_copy.substr(0, user_copy.find(','));
        user_copy = user_copy.substr(user_copy.find(',') + 1, user_copy.length());
        std::string location0 = user_copy.substr(0, user_copy.find(','));
        user_copy = user_copy.substr(user_copy.find(',') + 1, user_copy.length());
        std::string email0 = user_copy.substr(0, user_copy.find(','));
        putConstraints(age0, name0, password0, location0, email0);
        user_copy = user_copy.substr(user_copy.find(',') + 1, user_copy.length());
        addAttributes(user_copy);
    } catch (WrongInput &e) {
        throw WrongInput(e.message());
    }
}

User::User(const int &age0, const std::string &name0, const std::string &password0, const std::string &location0,
           const std::string &email0, const std::string &attributes0) {
    try {
        putConstraints(age0, name0, password0, location0, email0);
        addAttributes(attributes0);
    } catch (WrongInput &e) {
        throw WrongInput(e.message());
    }
}

void User::putConstraints(const int &age0, const std::string &name0, const std::string &password0,
                          const std::string &location0, const std::string &email0) {
    if (checkAge(age0) && checkLocation(location0)) {
        std::string copy_location = location0;
        transform(copy_location.begin(), copy_location.end(), copy_location.begin(), ::toupper);
        if (!name0.empty() && !location0.empty() && !password0.empty() && !email0.empty()) {
            age = age0;
            name = name0;
            password = password0;
            location = copy_location;
            email = email0;
        } else {
            throw WrongInput("Name or location or password or email is empty!");
        }
    } else {
        throw WrongInput("Wrong age or location!");
    }

}

void User::addAttributes(const std::string &attributes0) {
    if (std::count(attributes0.begin(), attributes0.end(), ',') + 1 > MAX_N_ATT) {
        throw WrongInput("You can have max 5 attributes!");
    }
    std::string separ = attributes0.substr(0, attributes0.find(','));
    std::string attributes_copy = attributes0;
    attributes_copy = attributes_copy.substr(attributes_copy.find(',') + 1, attributes_copy.length());
    while (!separ.empty()) {
        attributes.insert(separ);
        if (attributes_copy == separ) {
            break;
        }
        separ = attributes_copy.substr(0, attributes_copy.find(','));
        attributes_copy = attributes_copy.substr(attributes_copy.find(',') + 1, attributes_copy.length());
    }
}

std::string User::getAttributes() {
    std::string attributes0;
    for (const auto & attribute : attributes) {
        attributes0 += attribute + ',';
    }
    attributes0 = attributes0.substr(0, attributes0.length() - 1);
    return attributes0;
}

std::string User::getLikes() const{
    std::string like;
    for (const auto & i : likes) {
        like += i.email + ',';
    }
    like = like.substr(0, like.length() - 1);
    return like;
}

std::string User::getMatches() const{
    std::string match;
    for (const auto & matche : matches) {
        match += matche.email + ',';
    }
    match = match.substr(0, match.length() - 1);
    return match;
}

bool User::checkLocation(const std::string &location0) {
    std::string copy_location = location0;
    transform(copy_location.begin(), copy_location.end(), copy_location.begin(), ::toupper);
    return std::find(cities.begin(), cities.end(), copy_location) != cities.end();
}

bool User::operator==(const User &user0) const{
    return this->email == user0.email;
}

bool User::operator<(const User &user0) const {
    return this->email < user0.email;
}
