//
// Created by user on 18.06.2022.
//

#ifndef MAIN_CPP_PASSWORDPACK_H
#define MAIN_CPP_PASSWORDPACK_H

#include <filesystem>
#include <cstring>
#include <iostream>

class PasswordPack {
    std::string name;
    std::string password;
    std::string category;
    std::string login;
    std::string url;

public:
    PasswordPack()=default;
    PasswordPack(const std::string& n,const std::string& p,const std::string& c,const std::string& u,const std::string& l){
        name = n;
        password = p;
        category = c;
        login = l;
        url = u;
    };
    std::string toString();

    std::string getName();
    std::string getPassword();
    std::string getCategory();
    std::string getLogin();
    std::string getUrl();
};

#endif //MAIN_CPP_PASSWORDPACK_H
