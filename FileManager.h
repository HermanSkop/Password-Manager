//
// Created by user on 04.06.2022.
//

#ifndef MAIN_CPP_FILEMANAGER_H
#define MAIN_CPP_FILEMANAGER_H

#include <filesystem>
#include <cstring>
#include <iostream>
#include "Console.h"

class FileManager {
private:
    static std::string getMainPassword()/**
 * Reads main password from file and returns it.
 * If such file doesn't exist, calls registration().
 * @return main password for all passwords.
 * **/;

    static void registration()/**
 * Creates a new file, where the main password is contained.
 * Also, asks for a new password and saves it to the file.
 * */;

public:
    static bool owner;

    static std::string currentDirectory;
    FileManager(){
        FMCycle();
    };;

    static void FMCycle()/**
 * Asks user for choosing the correct file path.
 * Also, can suggest existing variants.
 * */;

    static bool accessCheck()/**
 * Asks user for main password and checks if it is the correct one.
 * @return true if password is correct, otherwise - false.
 * */;

    static void showDirectory()/**
 * Outputs the whole directory, containing files with passwords.
 * */;

    static void showHelp()/**
 * Outputs possible commands for user
 **/;


    static void clearCurrFile();
};


#endif //MAIN_CPP_FILEMANAGER_H
