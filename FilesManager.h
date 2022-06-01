//
// Created by user on 01.06.2022.
//

#ifndef UNTITLED_FILESMANAGER_H
#define UNTITLED_FILESMANAGER_H

#include <filesystem>
#include "Console.h"

class FilesManager {
public:
    FilesManager()= default;
    FilesManager(const std::string& input){
        chooseFile(input);
    }
    void chooseFile(const std::string& input){
        if(std::filesystem::exists(input)){
            currentDirectory = input;
            std::cout<< "Current directory is " << input << std::endl;
        }
        else if(input=="sd"){
            showDirectory();
        }
        else std::cout << "no matches" << std::endl;
    }
    static void showDirectory(){
        for (const auto & entry : std::filesystem::directory_iterator("../Passwords"))
            std::cout << entry.path() << std::endl;
    }
private:
    std::string currentDirectory;
};


#endif //UNTITLED_FILESMANAGER_H
