//
// Created by user on 01.06.2022.
//

#ifndef UNTITLED_FILESMANAGER_H
#define UNTITLED_FILESMANAGER_H

#include <filesystem>
#include <string.h>
#include <iostream>
#include "Console.h"

class FilesManager {
private:
    static std::string getMainPassword()/**
 * Reads main password from file and returns it.
 * If such file doesn't exist, calls registration().
 * @return main password for all passwords.
 * **/ {
        std::ifstream ifs;
        ifs.open("../main.txt",std::ifstream::in);
        if(!ifs){
            registration();
            return getMainPassword();
        }
        else {
            std::string out;
            ifs >> out;
            if(out[0] == '\0'){
                registration();
                return getMainPassword();
            }
            else return out;
        }
    }

    static void registration/**
 * Creates a new file, where the main password is contained.
 * Also, asks for a new password and saves it to the file.
 * */(){
        std::cout << "It seems that you have no main password." << std::endl;
        std::ofstream ofs;
        bool done = false;
        std::string password;
        while (!done) {
            std::cout << "Type your new MAIN password that will be used to check access to all the passwords you have." << std::endl;
            std::cout << "No spaces are allowed:";
            std::cin >> password;
            if(password.find(' '))done = true;
        }
        ofs.open("../main.txt");
        if(ofs.fail())std::cout << "ERROR: cannot open file main.txt, try to create it manually." <<std::endl;
        else {
            ofs << password;
            ofs.close();
        }
        std::cout << "Now your MAIN password is '" << password << '\'' << std::endl;
    }

public:
    std::string* currentDirectory;

    FilesManager(){
        FMCycle();
    };

    void FMCycle()/**
 * Asks user for choosing the correct file path.
 * Also, can suggest existing variants.
 * */{
        bool done = false;
        while (!done) {
            std::cout << "Input exact path to the file or type 'sd' to observe list of them:";
            std::string input;
            std::cin >> input;
            if(std::filesystem::exists(input)){
                currentDirectory = &input;
                std::cout<< "Current directory is " << input << std::endl;
                if(accessCheck()) std::cout << "true"<<std::endl;
                else std::cout << "false"<<std::endl;
                done= true;
            }
            else if(input=="sd")showDirectory();
            else if(input=="cancel")done = true;
            else std::cout << "incorrect command, try help" << std::endl;
        }
    }

    static bool accessCheck()/**
 * Asks user for main password and checks if it is the correct one.
 * @return true if password is correct, otherwise - false.
 * */{
        std::string input;
        std::string mainPassword = getMainPassword();
        std::cout << "Input MAIN password to get access:";
        std::cin >> input;
        std::cout << input << " - " << mainPassword << std::endl;
        if(mainPassword==input)return true;
        else return  false;
    }

    static void showDirectory()/**
 * Outputs the whole directory, containing files with passwords.
 * */{
        for (const auto & entry : std::filesystem::directory_iterator("../Passwords"))
            std::cout << entry.path() << std::endl;
    }
};


#endif //UNTITLED_FILESMANAGER_H
