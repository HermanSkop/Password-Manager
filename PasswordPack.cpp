//
// Created by user on 18.06.2022.
//

#include "PasswordPack.h"

std::string PasswordPack::toString() {
    return "name: " + name + "; password: " + password +"; category: " + category
                +"; url: " + url +"; login: " + login;
}

std::string PasswordPack::getName() {
    return name;
}

std::string PasswordPack::getPassword() {
    return password;
}

std::string PasswordPack::getCategory() {
    return category;
}

std::string PasswordPack::getLogin() {
    return login;
}

std::string PasswordPack::getUrl() {
    return url;
}

void PasswordPack::setName(std::string n) {
    name = n;
}

void PasswordPack::setPassword(std::string p) {
    password = p;
}

void PasswordPack::setCategory(std::string c) {
    category = c;
}

void PasswordPack::setLogin(std::string l) {
    login = l;
}

void PasswordPack::setUrl(std::string u) {
    url = u;
}
