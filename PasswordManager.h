//
// Created by user on 04.06.2022.
//

#ifndef MAIN_CPP_PASSWORDMANAGER_H
#define MAIN_CPP_PASSWORDMANAGER_H
#include <filesystem>
#include <iostream>
#include <bitset>
#include <fstream>
#include "FileManager.h"


class PasswordManager {
private:
    static bool encrypt(const std::string& input);
    static std::string decrypt();
    static void write(const std::string& input);
    static void write(const int& input);

public:
    PasswordManager() = default;
    static void addPassword(const std::string& currDirectory);
    static void showHelpForAddPassword();
    static std::string askPassword();
};


#endif //MAIN_CPP_PASSWORDMANAGER_H
