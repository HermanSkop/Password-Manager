//
// Created by user on 04.06.2022.
//

#include "FileManager.h"
bool FileManager::owner = false;

std::string FileManager::currentDirectory = "noway";

std::string FileManager::getMainPassword() {
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

void FileManager::registration() {
        std::cout << "It seems that you have no main password." << std::endl;
        std::ofstream ofs;
        bool done = false;
        std::string password;
        while (!done) {
            std::cout << "Type your new MAIN password that will be used to check access to all the passwords you have." << std::endl;
            std::cout << "No spaces are allowed:";
            std::getline(std::cin, password);
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

void FileManager::FMCycle() {
    bool done = false;
    while (!done) {
        std::cout << "Input exact path to the file or type 'sd' to observe list of them:";
        std::string input;
        std::getline(std::cin, input);
        if(std::filesystem::exists(input)){
            currentDirectory = input;
            std::cout<< "Current directory is " << input << std::endl;
            if(accessCheck()) owner = true;
            else owner = false;
            done= true;
        }
        else if(input=="sd")showDirectory();
        else if(input=="help")showHelp();
        else if(input=="cancel")done = true;
        else std::cout << "incorrect command, try help" << std::endl;
    }
}

bool FileManager::accessCheck() {
    std::string input;
    std::string mainPassword = getMainPassword();
    std::cout << "Input MAIN password to get access:";
    std::getline(std::cin, input);
    if(mainPassword==input)return true;
    else return  false;
}

void FileManager::showDirectory() {
    for (const auto & entry : std::filesystem::directory_iterator("../Passwords"))
        std::cout << entry.path() << std::endl;
}

void FileManager::showHelp(){
    std::cout << "help - shows this message" << std::endl;
    std::cout << "sd - shows possible paths to files" << std::endl;
    std::cout << "cancel - returns to main menu" << std::endl;
}

void FileManager::clearCurrFile(){
    std::fstream clear_file(FileManager::currentDirectory, std::ios::out);
    clear_file.close();
}