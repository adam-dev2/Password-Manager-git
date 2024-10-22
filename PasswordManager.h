// PasswordManager.h
#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <string>
#include <map>

class PasswordManager {
private:
    std::map<std::string, std::string> passwords;  // To store website and password
    std::string encrypt(const std::string& password);
    std::string decrypt(const std::string& encryptedPassword);

public:
    void addPassword(const std::string& website, const std::string& password);
    std::string getPassword(const std::string& website);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

#endif
