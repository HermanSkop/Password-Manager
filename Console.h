//
// Created by user on 01.06.2022.
//

#ifndef UNTITLED_CONSOLE_H
#define UNTITLED_CONSOLE_H


#include <iostream>
#include <fstream>
#include "FilesManager.h"

class Console {
public:
    Console(){
        std::cout << "Hello, would you like to see current directory or input path by yourself?" << std::endl;
        changeDirectory();
        cycle();
    }
    static std::string getData()/**
 * Returns data inputted by user through console.
 * @return user input
 **/{
        std::string x;
        std::cin>>x;
        return x;
    }
    static void cycle()/**
 * Recursively asks for an action and gets it
 * */{
        while (true) {
            std::cout << "'help' to see possible actions:";
            std::string input = getData();
            if (input == "help") showHelp();
            else if (input == "cd") changeDirectory();
        }
    }
    static void changeDirectory(){
        new FilesManager();
    }
    static void showHelp(){
        std::cout << "help - shows this message" << std::endl;
        std::cout << "cd - switches within files" << std::endl;
    }
};


#endif //UNTITLED_CONSOLE_H