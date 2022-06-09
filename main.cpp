#include <iostream>
#include "Console.h"
#include "PasswordManager.h"

int main() {
    std::cout << PasswordManager::decrypt(1) << std::endl;
    std::cout << PasswordManager::decrypt(2) << std::endl;
    std::cout << PasswordManager::decrypt(3) << std::endl;
    new Console();
    return 0;
}
