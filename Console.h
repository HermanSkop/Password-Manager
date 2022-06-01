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
        changeDirectory(getData());
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
    static void cycle() {
        std::cout << "'help' to see possible actions:" << std::endl;
        getData();
        cycle();
    }
    void changeDirectory(std::string input){
        new FilesManager(input);
    }
};


#endif //UNTITLED_CONSOLE_H