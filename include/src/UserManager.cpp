#include "UserManager.h"
#include <bcrypt.h> // Use an actual bcrypt or another hashing library

UserManager::UserManager() {}

bool UserManager::registerUser(std::string username, std::string password) {
    std::string hashedPassword = bcrypt::generateHash(password);
    users[username] = hashedPassword;
    return true;
}

bool UserManager::loginUser(std::string username, std::string password) {
    if (users.find(username) != users.end()) {
        return bcrypt::validatePassword(password, users[username]);
    }
    return false;
}
