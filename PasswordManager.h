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
    static bool encryptln(const std::string &input);
    static bool encrypt(const std::string& input);
    static bool encryptMark(const std::string &input, char mark);
    static bool encryptMarkln(const std::string &input, char mark);
    static bool encryptMarklnb(const std::string &input, char mark);

    static void write(const std::string& input);
    static void write(const int& input);

public:
    PasswordManager() = default;
    static void addPassword(const std::string& currDirectory);
    static void showHelpForAddPassword();
    static std::string askPassword();
    static std::string askName();

    static std::string askCategory();

    static std::string read( int line);

    static std::string decrypt();

    static std::string decrypt(int passwordNumber);

    static void showHelpForAddSides();

    static std::string askLogin();

    static std::string askURL();

    static void write(char input);

    static void showHelpForGeneratingPassword();

    static std::string generatePassword(int length);
    static std::string generateUpperPassword(int length);
    static std::string generateLowerPassword(int length);
    static std::string generateLowerNoSpecialPassword(int length);
    static std::string generateUpperNoSpecialPassword(int length);

    static std::string generateNoSpecialPassword(int length);

    static void showHelpForRules();

    static std::string buildAddsPassword();

    static bool encryptb(const std::string &input);

    static bool encryptMarkb(const std::string &input, char mark);
};


#endif //MAIN_CPP_PASSWORDMANAGER_H
