// main.cpp
#include "PasswordManager.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Add Password\n";
    std::cout << "2. Retrieve Password\n";
    std::cout << "3. Save Passwords to File\n";
    std::cout << "4. Load Passwords from File\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    PasswordManager pm;
    int choice;
    std::string website, password, filename;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter website: ";
                std::cin >> website;
                std::cout << "Enter password: ";
                std::cin >> password;
                pm.addPassword(website, password);
                std::cout << "Password added successfully!\n";
                break;
            case 2:
                std::cout << "Enter website: ";
                std::cin >> website;
                std::cout << "Password: " << pm.getPassword(website) << "\n";
                break;
            case 3:
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                pm.saveToFile(filename);
                std::cout << "Passwords saved to " << filename << "\n";
                break;
            case 4:
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                pm.loadFromFile(filename);
                std::cout << "Passwords loaded from " << filename << "\n";
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option, try again.\n";
        }
    }
}
