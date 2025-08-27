#include "App.h"
class Search : public App{
    User user;
    App &app;
public:
    Search(const User &user0,App &app0):user(user0),app(app0){};
    ~Search(){};
    static double Similarity(const std::set<std::string>& set1, const std::set<std::string>& set2);
    std::vector<User> nearbyUsers() const;
};
