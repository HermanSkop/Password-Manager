//
// Created by user on 04.06.2022.
//

#include "PasswordManager.h"

bool PasswordManager::encrypt(const std::string &input) {
    try {
        for (char const &c: input) {
            write((int) c);
            write(" ");
        }
        std::cout << std::endl;
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}

std::string PasswordManager::decrypt() {
    return "a";
}

void PasswordManager::addPassword(const std::string &currDirectory) {
    bool done = false;
    while (!done) {
        std::cout << "Would you like to create your own password?(help)";
        std::string input;
        std::cin >> input;
        if(input=="yes") {
            std::string tempPassword = askPassword();
            if(encrypt(tempPassword))std::cout << "Password is well-encrypted!";
            else std::cout << "Something went wrong";
            std::cout << std::endl;
            done = true;
        }
        else if(input == "help")showHelpForAddPassword();
        else if(input=="cancel")done = true;
        else std::cout << "incorrect command, try help" << std::endl;
    }
}

void PasswordManager::showHelpForAddPassword() {
    std::cout << "help - shows this message" << std::endl;
    std::cout << "yes - you will be asked to input your own password" << std::endl;
    std::cout << "no - password will be generated automatically, according to your preferences" << std::endl;
    std::cout << "cancel - returns to main menu" << std::endl;
}

std::string PasswordManager::askPassword(){
    std::cout << "Input your password, no spaces are allowed:";
    std::string p;
    std::cin >> p;
    return p;
}

void PasswordManager::write(const std::string& input) {
    std::ofstream ofs;
    ofs.open(FileManager::currentDirectory, std::ios::app);
    if(ofs.fail())std::cout << "ERROR: cannot open file, try to create it." <<std::endl;
    else {
        ofs << input;
        ofs.close();
    }
}

void PasswordManager::write(const int &input) {
    std::ofstream ofs;
    ofs.open(FileManager::currentDirectory, std::ios::app);
    if(ofs.fail())std::cout << "ERROR: cannot open file, try to create it." <<std::endl;
    else {
        ofs << input;
        ofs.close();
    }
}
