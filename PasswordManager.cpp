//
// Created by user on 04.06.2022.
//

#include "PasswordManager.h"

bool PasswordManager::encrypt(const std::string &input) {
    try {
        for (char const &c: input) {
            write((int) c);
        }
        write(" ");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}
bool PasswordManager::encryptMark(const std::string &input, char mark) {
    try {
        write(mark);
        for (char const &c: input) {
            write((int) c);
        }
        write(" ");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}
bool PasswordManager::encryptln(const std::string &input) {
    try {
        for (char const &c: input) {
            write((int) c);
        }
        write(' ');
        write("\n");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}
bool PasswordManager::encryptb(const std::string &input) {
    try {
        write("\b");
        for (char const &c: input) {
            write((int) c);
        }
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}
bool PasswordManager::encryptMarkln(const std::string &input, char mark) {
    try {
        write(mark);
        for (char const &c: input) {
            write((int) c);
        }
        write(' ');
        write("\n");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}
bool PasswordManager::encryptMarklnb(const std::string &input, char mark) {
    try {
        write("\b");
        write(mark);
        for (char const &c: input) {
            write((int) c);
        }
        write(' ');
        write("\n");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}
bool PasswordManager::encryptMarkb(const std::string &input, char mark) {
    try {
        write("\b");
        write(mark);
        for (char const &c: input) {
            write((int) c);
        }
        write(" ");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}

std::string PasswordManager::decrypt(int passwordNumber) {
    std::string tempPassword = read(passwordNumber);
    std::string name;
    std::string category;
    std::string password;
    std::string url;
    std::string login;

    int pos = 0;
    int tempPos = 0;
    for (tempPos; pos<=tempPassword.length(); tempPos++) {
        if(tempPassword[pos]!=' ') {
            int num = tempPassword[pos] - '0';
            if (num >= 3)pos+=2;
            else pos+=3;
        }
        else break;
    }
    name.resize(tempPos);
    pos++;
    for (tempPos = 0; pos<=tempPassword.length(); tempPos++) {
        if(tempPassword[pos]!=' ') {
            int num = tempPassword[pos] - '0';
            if (num >= 3)pos+=2;
            else pos+=3;
        }
        else break;
    }
    password.resize(tempPos);
    pos++;
    bool nextUrl = false;
    bool nextLogin = false;
    for (tempPos = 0; pos<=tempPassword.length(); tempPos++) {
        if(tempPassword[pos]!='\n'&&tempPassword[pos]!='U'&&tempPassword[pos]!='L'&&tempPassword[pos]!=' ') {
            int num = tempPassword[pos] - '0';
            if (num >= 3)pos+=2;
            else pos+=3;
        }
        else if(tempPassword[pos]==' '){
            tempPos--;
            pos++;
        }
        else if(tempPassword[pos]=='U'){
            nextUrl=true;
            pos++;
            break;
        }
        else if(tempPassword[pos]=='L'){
            nextLogin=true;
            pos++;
            break;
        }
        else break;
    }
    category.resize(tempPos);

    if(nextUrl){
        for (tempPos = 0; pos<=tempPassword.length(); tempPos++) {
            if(tempPassword[pos]!='\n' && tempPassword[pos]!=' ') {
                int num = tempPassword[pos] - '0';
                if (num >= 3)pos+=2;
                else pos+=3;
            }
            else if(tempPassword[pos]==' '){
                nextLogin= true;
                pos++;
                break;
            }
            else break;
        }
        url.resize(tempPos);
    }
    if(nextLogin){
        pos++;
        for (tempPos = 0; pos<=tempPassword.length(); tempPos++) {
            if(tempPassword[pos]!='\n') {
                int num = tempPassword[pos] - '0';
                if (num >= 3)pos+=2;
                else pos+=3;
            }
            else break;
        }
        login.resize(tempPos);
    }

    pos = 0;
    tempPos = 0;
    for (pos; pos<=tempPassword.length();) {
        if(tempPassword[pos]!=' ') {
            int num = tempPassword[pos] - '0';
            if (num >= 3) {
                num*=10;
                num+=tempPassword[pos+1]-'0';
                name[tempPos] = (char)num;
                pos+=2;
                tempPos++;
            }
            else{
                num*=10;
                num+=tempPassword[pos+1]-'0';
                num*=10;
                num+=tempPassword[pos+2]-'0';
                name[tempPos] = (char)num;
                pos+=3;
                tempPos++;
            }
        }
        else break;
    }
    pos++;
    tempPos = 0;
    for (pos; pos<=tempPassword.length();) {
        if(tempPassword[pos]!=' ') {
            int num = tempPassword[pos] - '0';
            if (num >= 3) {
                num*=10;
                num+=tempPassword[pos+1]-'0';
                password[tempPos] = (char)num;
                pos+=2;
                tempPos++;
            }
            else{
                num*=10;
                num+=tempPassword[pos+1]-'0';
                num*=10;
                num+=tempPassword[pos+2]-'0';
                password[tempPos] = (char)num;
                pos+=3;
                tempPos++;
            }
        }
        else break;
    }
    pos++;
    tempPos = 0;
    for (pos; pos<=tempPassword.length();) {
        if(tempPassword[pos]!='\0' && tempPassword[pos]!='U' && tempPassword[pos]!='L' && tempPassword[pos]!=' ') {
            int num = tempPassword[pos] - '0';
            if (num >= 3) {
                num*=10;
                num+=tempPassword[pos+1]-'0';
                category[tempPos] = (char)num;
                pos+=2;
                tempPos++;
            }
            else{
                num*=10;
                num+=tempPassword[pos+1]-'0';
                num*=10;
                num+=tempPassword[pos+2]-'0';
                category[tempPos] = (char)num;
                pos+=3;
                tempPos++;
            }
        }
        else if(tempPassword[pos]==' '){
            pos++;
        }
        else if(tempPassword[pos]=='U'){
            pos++;
            break;
        }
        else if(tempPassword[pos]=='L'){
            pos++;
            break;
        }
        else break;
    }
    if(nextUrl){
        tempPos = 0;
        for (pos; pos<=tempPassword.length();) {
            if (tempPassword[pos] != '\0' && tempPassword[pos] != ' '){
                int num = tempPassword[pos] - '0';
                if (num >= 3) {
                    num *= 10;
                    num += tempPassword[pos + 1] - '0';
                    url[tempPos] = (char) num;
                    pos += 2;
                    tempPos++;
                } else {
                    num *= 10;
                    num += tempPassword[pos + 1] - '0';
                    num *= 10;
                    num += tempPassword[pos + 2] - '0';
                    url[tempPos] = (char) num;
                    pos += 3;
                    tempPos++;
                }
            }
            else if(tempPassword[pos] == ' '){
                pos++;
                nextLogin = true;
                break;
            }
            else break;
        }
    }
    if(nextLogin){
        tempPos = 0;
        pos++;
        for (pos; pos<=tempPassword.length();) {
            if (tempPassword[pos] != '\0'){
                int num = tempPassword[pos] - '0';
                if (num >= 3) {
                    num *= 10;
                    num += tempPassword[pos + 1] - '0';
                    login[tempPos] = (char) num;
                    pos += 2;
                    tempPos++;
                } else {
                    num *= 10;
                    num += tempPassword[pos + 1] - '0';
                    num *= 10;
                    num += tempPassword[pos + 2] - '0';
                    login[tempPos] = (char) num;
                    pos += 3;
                    tempPos++;
                }
            }
            else break;
        }
    }

    return name + ' ' + password + ' ' + category + ' ' + url + ' ' + login;
}
std::string PasswordManager::decrypt() {
    return std::string();
}


void PasswordManager::addPassword(const std::string &currDirectory) {
    bool done = false;
    while (!done) {
        std::cout << "Would you like to create your own password?(help)";
        std::string input;
        std::getline(std::cin, input);
        if(input=="yes") {
            encrypt(askName());
            encrypt(askPassword());
            encryptln(askCategory());
            buildAddsPassword();
            done = true;
        }
        else if(input=="no") {
            std::string num;
            std::string rule;
            int length;
            while (true) {
                std::cout << "How many digits it should have?(help)";
                std::getline(std::cin, num);
                try {
                    length = std::stoi(num);
                    if (length > 0 && length <= 20) {
                        while (true) {
                            std::cout << "What it should consist of?(help)";
                            std::getline(std::cin, rule);
                            if (rule == "help")showHelpForRules();
                            else if (rule == "u") {
                                encrypt(askName());
                                encrypt(generateUpperPassword(length));
                                encryptln(askCategory());
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "l") {
                                encrypt(askName());
                                generateLowerPassword(length);
                                encryptln(askCategory());
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "uns") {
                                encrypt(askName());
                                generateUpperNoSpecialPassword(length);
                                encryptln(askCategory());
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "lns") {
                                encrypt(askName());
                                generateLowerNoSpecialPassword(length);
                                encryptln(askCategory());
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "ns") {
                                encrypt(askName());
                                generateNoSpecialPassword(length);
                                encryptln(askCategory());
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "no") {
                                encrypt(askName());
                                generatePassword(length);
                                encryptln(askCategory());
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "back") break;
                            else std::cout << "incorrect input, try 'help'" << std::endl;
                        }
                        done = true;
                        break;
                    }
                    else showHelpForGeneratingPassword();
                }
                catch (std::invalid_argument &e){
                    if(num=="cancel"){
                        done = true;
                        break;
                    }
                    showHelpForGeneratingPassword();
                }
            }
        }
        else if(input == "help")showHelpForAddPassword();
        else if(input=="cancel")done = true;
        else std::cout << "incorrect command, try help" << std::endl;
    }
}

void PasswordManager::showHelpForAddPassword() {
    std::cout << "help - shows this message" << std::endl;
    std::cout << "yes - you will be asked to input your own password" << std::endl;
    std::cout << "no - password will be generated automatically, according to your preferences" << std::endl;
    std::cout << "cancel - returns to main menu" << std::endl;
}
void PasswordManager::showHelpForAddSides() {
    std::cout << "help - shows this message" << std::endl;
    std::cout << "url - adds only URL of website to your password" << std::endl;
    std::cout << "log - adds only login to your password" << std::endl;
    std::cout << "urlog - adds URL and login to your password" << std::endl;
    std::cout << "no - returns to main menu" << std::endl;
}
void PasswordManager::showHelpForGeneratingPassword() {
    std::cout << "help - shows this message" << std::endl;
    std::cout << "cancel - returns to main menu" << std::endl;
    std::cout << "You should input only natural numbers that are >0 and <=20" << std::endl;
}
void PasswordManager::showHelpForRules() {
    std::cout << "help - shows this message" << std::endl;
    std::cout << "u - only uppercase and special symbols" << std::endl;
    std::cout << "l - only lowercase and special symbols" << std::endl;
    std::cout << "uns - only uppercase and NO special symbols" << std::endl;
    std::cout << "lns - only lowercase and NO special symbols" << std::endl;
    std::cout << "ns - lower and upper case, NO special symbols" << std::endl;
    std::cout << "no - no special rules" << std::endl;
    std::cout << "back - returns to the previous stage" << std::endl;
}

std::string PasswordManager::askName(){
    std::cout << "Input name for the password:";
    std::string p;
    std::cin.ignore();
    std::getline(std::cin, p);
    return p;
}
std::string PasswordManager::askPassword(){
    std::string p = " ";
    while (p.find(' ')<184467440737095516) {
        std::cout << "Input your password, no spaces are allowed:";
        std::getline(std::cin, p);
    }
    return p;
}
std::string PasswordManager::askCategory(){
    std::string p;
    std::cout << "Input category for the password:";
    std::getline(std::cin, p);
return p;
}
std::string PasswordManager::askLogin() {
    std::string p;
    std::cout << "Input Login for the password:";
    std::getline(std::cin, p);
    return p;
}
std::string PasswordManager::askURL() {
    std::string p;
    std::cout << "Input URL for the password:";
    std::getline(std::cin, p);
    return p;
}


void PasswordManager::write(const std::string& input) {
    std::ofstream ofs;
    ofs.open(FileManager::currentDirectory, std::ios::app);
    if(ofs.fail())std::cout << "ERROR: cannot open file, try to create it." <<std::endl;
    else {
        ofs << input;
        ofs.close();
    }
}
void PasswordManager::write(char input) {
    std::ofstream ofs;
    ofs.open(FileManager::currentDirectory, std::ios::app);
    if(ofs.fail())std::cout << "ERROR: cannot open file, try to create it." <<std::endl;
    else {
        ofs << input;
        ofs.close();
    }
}
void PasswordManager::write(const int &input) {
    std::ofstream ofs;
    ofs.open(FileManager::currentDirectory, std::ios::app);
    if(ofs.fail())std::cout << "ERROR: cannot open file, try to create it." <<std::endl;
    else {
        ofs << input;
        ofs.close();
    }
}

std::string PasswordManager::read(int line) {
    std::string str;
    std::ifstream ifs(FileManager::currentDirectory);
    if (ifs.is_open()) {
        for (line; line > 0; line--) {
            std::getline(ifs,str);
        }
    }
    return str;
}

std::string PasswordManager::generatePassword(int length) {
    std::string password;
    password.resize(length);
    srand(time(NULL)); //reset rand()
    for(length; length>=0; length--){
        password[length] = 33 + rand()%97;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}
std::string PasswordManager::generateUpperPassword(int length) {
    std::string password;
    password.resize(length);
    srand(time(NULL)); //reset rand()
    int temp = 100;
    for(length; length>=0; length--){
        while (temp>=97&&temp<=122)temp = 33 + rand()%97;
        password[length] = temp;
        temp = 100;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}
std::string PasswordManager::generateUpperNoSpecialPassword(int length) {
    std::string password;
    password.resize(length);
    srand(time(NULL)); //reset rand()
    int temp = 100;
    for(length; length>=0; length--){
        while (temp>=91||temp>=58&&temp<=64||temp<=47)temp = 33 + rand()%97;
        password[length] = temp;
        temp = 100;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}
std::string PasswordManager::generateLowerPassword(int length) {
    std::string password;
    password.resize(length);
    srand(time(NULL)); //reset rand()
    int temp = 70;
    for(length; length>=0; length--){
        while (temp>=65&&temp<=90)temp = 33 + rand()%97;
        password[length] = temp;
        temp = 70;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}
std::string PasswordManager::generateLowerNoSpecialPassword(int length) {
    std::string password;
    password.resize(length);
    srand(time(NULL)); //reset rand()
    int temp = 70;
    for(length; length>=0; length--){
        while (temp>=58&&temp<=97||temp<=47||temp>=123)temp = 33 + rand()%97;
        password[length] = temp;
        temp = 70;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}
std::string PasswordManager::generateNoSpecialPassword(int length) {
    std::string password;
    password.resize(length);
    srand(time(NULL)); //reset rand()
    int temp = 70;
    for(length; length>=0; length--){
        while (temp>=58&&temp<=64||temp>=91&&temp<=96||temp<=47||temp>=123)temp = 33 + rand()%97;
        password[length] = temp;
        temp = 58;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}


std::string PasswordManager::buildAddsPassword(){
    std::string askAdds;
    while(true){
        std::cout << "Would you like to add URL or Login to your password?(help):";
        std::getline(std::cin, askAdds);
        if(askAdds=="help")showHelpForAddSides();
        else if(askAdds == "no"){
            break;
        }
        else if(askAdds == "url"){
            std::string t = askURL();
            encryptMarkln(t, 'U');
            break;
        }
        else if(askAdds == "log"){
            std::string t = askLogin();
            encryptMarkln(t, 'L');
            break;
        }
        else if(askAdds == "urlog"){
            std::string t = askURL();
            encryptMark(t, 'U');
            t = askLogin();
            encryptMarkln(t, 'L');
            break;
        }
        else std::cout << "Wrong input, try 'help'" << std::endl;
    }
}



