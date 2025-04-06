#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <map>

class UserManager {
public:
    UserManager();
    bool registerUser(std::string username, std::string password);
    bool loginUser(std::string username, std::string password);

private:
    std::map<std::string, std::string> users;
};

#endif // USERMANAGER_H
