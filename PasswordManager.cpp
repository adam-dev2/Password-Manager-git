// PasswordManager.cpp
#include "PasswordManager.h"
#include <fstream>
#include <iostream>

std::string PasswordManager::encrypt(const std::string& password) {
    std::string encrypted = password;
    char key = 'K';  // Simple key for XOR (you can improve this)
    for (int i = 0; i < password.size(); i++) {
        encrypted[i] ^= key;
    }
    return encrypted;
}

std::string PasswordManager::decrypt(const std::string& encryptedPassword) {
    return encrypt(encryptedPassword);  // XOR is symmetric
}

void PasswordManager::addPassword(const std::string& website, const std::string& password) {
    passwords[website] = encrypt(password);  // Encrypt before storing
}

std::string PasswordManager::getPassword(const std::string& website) {
    if (passwords.find(website) != passwords.end()) {
        return decrypt(passwords[website]);  // Decrypt before returning
    }
    return "Password not found!";
}

void PasswordManager::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& entry : passwords) {
        outFile << entry.first << " " << entry.second << "\n";  // Save website and encrypted password
    }
    outFile.close();
}

void PasswordManager::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    passwords.clear();  // Clear the existing passwords
    std::string website, encryptedPassword;
    while (inFile >> website >> encryptedPassword) {
        passwords[website] = encryptedPassword;  // Load into the map
    }
    inFile.close();
}

