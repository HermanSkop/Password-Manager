//
// Created by user on 04.06.2022.
//

#include "PasswordManager.h"
#include "PasswordPack.h"


void PasswordManager::encryptAll(PasswordPack* arr, size_t size) {
    try{
        for (int a = 0; a < size; a++) encryptPack(arr[a]);
    }
    catch(std::exception &e) {
        std::cout << e.what();
    }
}
void PasswordManager::encryptPack(PasswordPack pack) {
    encrypt(pack.getName());
    encrypt(pack.getPassword());
    if(pack.getUrl().empty() && pack.getLogin().empty())encryptln(pack.getCategory());
    else if(pack.getUrl().empty()){
            encrypt(pack.getCategory());
            encryptMarkln(pack.getLogin(), 'L');
        }
    else if(pack.getLogin().empty()){
        encrypt(pack.getCategory());
        encryptMarkln(pack.getUrl(), 'U');
    }
    else{
        encrypt(pack.getCategory());
        encryptMark(pack.getUrl(), 'U');
        encryptMarkln(pack.getLogin(), 'L');
    }
}

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
        write("\n");
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
        write("\n");
        return true;
    }
    catch (std::exception &e){
        return false;
    }
}

PasswordPack PasswordManager::decrypt(int passwordNumber) {
    std::string tempLine = read(passwordNumber);
    std::string name;
    std::string category;
    std::string password;
    std::string url;
    std::string login;

    int pos = 0;
    int tempPos = 0;
    bool nextUrl = false;
    bool nextLogin = false;

    for (tempPos; pos <= tempLine.length(); tempPos++) {
        if(tempLine[pos] != ' ') {
            int num = tempLine[pos] - '0';
            if (num >= 3)pos+=2;
            else pos+=3;
        }
        else break;
    }
    name.resize(tempPos);
    pos++;
    for (tempPos = 0; pos <= tempLine.length(); tempPos++) {
        if(tempLine[pos] != ' ') {
            int num = tempLine[pos] - '0';
            if (num >= 3)pos+=2;
            else pos+=3;
        }
        else break;
    }
    password.resize(tempPos);
    pos++;
    for (tempPos = 0; pos <= tempLine.length(); tempPos++) {
        if(tempLine[pos] != '\n' && tempLine[pos] != 'U' && tempLine[pos] != 'L' && tempLine[pos] != ' ') {
            int num = tempLine[pos] - '0';
            if (num >= 3)pos+=2;
            else pos+=3;
        }
        else if(tempLine[pos] == ' '){
            tempPos--;
            pos++;
        }
        else if(tempLine[pos] == 'U'){
            nextUrl=true;
            pos++;
            break;
        }
        else if(tempLine[pos] == 'L'){
            nextLogin=true;
            pos++;
            break;
        }
        else break;
    }
    category.resize(tempPos);

    if(nextUrl){
        for (tempPos = 0; pos <= tempLine.length(); tempPos++) {
            if(tempLine[pos] != '\n' && tempLine[pos] != ' ') {
                int num = tempLine[pos] - '0';
                if (num >= 3)pos+=2;
                else pos+=3;
            }
            else if(tempLine[pos] == ' '){
                pos+=2;
                nextLogin = true;
                break;
            }
            else break;
        }
        url.resize(tempPos);
    }
    if(nextLogin){
        pos++;
        for (tempPos = 0; pos <= tempLine.length(); tempPos++) {
            if(tempLine[pos] != '\n') {
                int num = tempLine[pos] - '0';
                if (num >= 3)pos+=2;
                else pos+=3;
            }
            else break;
        }
        login.resize(tempPos);
    }

    pos = 0;
    tempPos = 0;
    for (pos; pos <= tempLine.length();) {
        if(tempLine[pos] != ' ') {
            int num = tempLine[pos] - '0';
            if (num >= 3) {
                num*=10;
                num+= tempLine[pos + 1] - '0';
                name[tempPos] = (char)num;
                pos+=2;
                tempPos++;
            }
            else{
                num*=10;
                num+= tempLine[pos + 1] - '0';
                num*=10;
                num+= tempLine[pos + 2] - '0';
                name[tempPos] = (char)num;
                pos+=3;
                tempPos++;
            }
        }
        else break;
    }
    pos++;
    tempPos = 0;
    for (pos; pos <= tempLine.length();) {
        if(tempLine[pos] != ' ') {
            int num = tempLine[pos] - '0';
            if (num >= 3) {
                num*=10;
                num+= tempLine[pos + 1] - '0';
                password[tempPos] = (char)num;
                pos+=2;
                tempPos++;
            }
            else{
                num*=10;
                num+= tempLine[pos + 1] - '0';
                num*=10;
                num+= tempLine[pos + 2] - '0';
                password[tempPos] = (char)num;
                pos+=3;
                tempPos++;
            }
        }
        else break;
    }
    pos++;
    tempPos = 0;
    for (pos; pos <= tempLine.length();) {
        if(tempLine[pos] != '\0' && tempLine[pos] != 'U' && tempLine[pos] != 'L' && tempLine[pos] != ' ') {
            int num = tempLine[pos] - '0';
            if (num >= 3) {
                num*=10;
                num+= tempLine[pos + 1] - '0';
                category[tempPos] = (char)num;
                pos+=2;
                tempPos++;
            }
            else{
                num*=10;
                num+= tempLine[pos + 1] - '0';
                num*=10;
                num+= tempLine[pos + 2] - '0';
                category[tempPos] = (char)num;
                pos+=3;
                tempPos++;
            }
        }
        else if(tempLine[pos] == ' '){
            pos++;
        }
        else if(tempLine[pos] == 'U'){
            pos++;
            break;
        }
        else if(tempLine[pos] == 'L'){
            pos++;
            break;
        }
        else break;
    }

    if(nextUrl){
        tempPos = 0;
        for (pos; pos <= tempLine.length();) {
            if (tempLine[pos] != '\0' && tempLine[pos] != ' '){
                int num = tempLine[pos] - '0';
                if (num >= 3) {
                    num *= 10;
                    num += tempLine[pos + 1] - '0';
                    url[tempPos] = (char) num;
                    pos += 2;
                    tempPos++;
                } else {
                    num *= 10;
                    num += tempLine[pos + 1] - '0';
                    num *= 10;
                    num += tempLine[pos + 2] - '0';
                    url[tempPos] = (char) num;
                    pos += 3;
                    tempPos++;
                }
            }
            else if(tempLine[pos] == ' '){
                nextLogin = true;
                pos+=2;
                break;
            }
            else break;
        }
    }
    if(nextLogin){
        tempPos = 0;
        for (pos; pos <= tempLine.length();) {
            if (tempLine[pos] != '\0'){
                int num = tempLine[pos] - '0';
                if (num >= 3) {
                    num *= 10;
                    num += tempLine[pos + 1] - '0';
                    login[tempPos] = (char) num;
                    pos += 2;
                    tempPos++;
                } else {
                    num *= 10;
                    num += tempLine[pos + 1] - '0';
                    num *= 10;
                    num += tempLine[pos + 2] - '0';
                    login[tempPos] = (char) num;
                    pos += 3;
                    tempPos++;
                }
            }
            else break;
        }
    }

    PasswordPack out(name, password, category, url, login);

    return out;
}
PasswordPack* PasswordManager::decrypt() {
    try {
        int count = countPasswords();

        PasswordPack *arr = new PasswordPack[count];
        for (int i = 1; i <= count; i++) {
            arr[i - 1] = decrypt(i);
        }
        return arr;
    }
    catch(std::exception &e){
        std::cout << "File is empty!" << std::endl;
        return nullptr;
    }
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
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "l") {
                                encrypt(askName());
                                encrypt(generateLowerPassword(length));
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "uns") {
                                encrypt(askName());
                                encrypt(generateUpperNoSpecialPassword(length));
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "lns") {
                                encrypt(askName());
                                encrypt(generateLowerNoSpecialPassword(length));
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "ns") {
                                encrypt(askName());
                                encrypt(generateNoSpecialPassword(length));
                                buildAddsPassword();
                                break;
                            }
                            else if (rule == "no") {
                                encrypt(askName());
                                encrypt(generatePassword(length));
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
    std::getline(std::cin, p);
    if(!existsName(p))return p;
    else {
        std::cout << "Such name is already taken";
        return askName();
    }
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
        password[length] = 33 + rand()%93;
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
        while (temp>=97&&temp<=122)temp = 33 + rand()%93;
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
        while (temp>=91||temp>=58&&temp<=64||temp<=47)temp = 33 + rand()%93;
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
        while (temp>=65&&temp<=90)temp = 33 + rand()%93;
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
        while (temp>=58&&temp<=97||temp<=47||temp>=123)temp = 33 + rand()%93;
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
        while (temp>=58&&temp<=64||temp>=91&&temp<=96||temp<=47||temp>=123)temp = 33 + rand()%93;
        password[length] = temp;
        temp = 58;
    }
    std::cout << "Password: " << password << " is generated" << std::endl;
    return password;
}


void PasswordManager::buildAddsPassword(){
    std::string askAdds;
    std::string category = askCategory();

    while(true){
        std::cout << "Would you like to add URL or Login to your password?(help):";
        std::getline(std::cin, askAdds);
        if(askAdds=="help")showHelpForAddSides();
        else if(askAdds == "no"){
            encryptln(category);
            break;
        }
        else if(askAdds == "url"){
            encrypt(category);
            std::string t = askURL();
            encryptMarkln(t, 'U');
            break;
        }
        else if(askAdds == "log"){
            encrypt(category);
            std::string t = askLogin();
            encryptMarkln(t, 'L');
            break;
        }
        else if(askAdds == "urlog"){
            encrypt(category);
            std::string t = askURL();
            encryptMark(t, 'U');
            t = askLogin();
            encryptMarkln(t, 'L');
            break;
        }
        else std::cout << "Wrong input, try 'help'" << std::endl;
    }
}

void PasswordManager::showPasswords(PasswordPack* arr) {
    int i = 0;
    try {
        while (true) {
            std::cout << arr[i].toString() << std::endl;
            i++;
        }
    }
    catch (std::exception &e){
        std::cout << "Number of passwords in file: " << i << std::endl;
    }
}

PasswordPack* PasswordManager::sortByName(PasswordPack* arr) {
    try {
        int size = countPasswords();

        for (int i = 0; i < size; i++) {
            for (int a = 0; a < size-1; a++) {
                if (arr[a].getName() > arr[a + 1].getName()) {
                    PasswordPack temp = arr[a];
                    arr[a] = arr[a + 1];
                    arr[a + 1] = temp;
                }
            }
        }
    }
    catch(std::exception &e){
        std::cout << "File is empty!" << std::endl;
    }
    return arr;
}
PasswordPack* PasswordManager::sortByCategory(PasswordPack* arr){
    try {
        int size = countPasswords();

        for (int i = 0; i < size; i++) {
            for (int a = 0; a < size - 1; a++) {
                if (arr[a].getCategory() > arr[a + 1].getCategory()) {
                    PasswordPack temp = arr[a];
                    arr[a] = arr[a + 1];
                    arr[a + 1] = temp;
                }
            }
        }
    }
    catch(std::exception &e){
        std::cout << "File is empty!" << std::endl;
    }
    return arr;
}

int PasswordManager::countPasswords() {
    int count = 0;
    std::string s;
    std::fstream fs(FileManager::currentDirectory);

    while (std::getline(fs, s)) count++;

    return count;
}

PasswordPack PasswordManager::editName(PasswordPack pack, std::string name){
    pack.setName(name);
    return pack;
}
PasswordPack PasswordManager::editPassword(PasswordPack pack, std::string password){
    pack.setPassword(password);
    return pack;
}
PasswordPack PasswordManager::editCategory(PasswordPack pack, std::string category){
    pack.setCategory(category);
    return pack;
}
PasswordPack PasswordManager::editLogin(PasswordPack pack, std::string login){
    pack.setLogin(login);
    return pack;
}
PasswordPack PasswordManager::editUrl(PasswordPack pack, std::string url){
    pack.setUrl(url);
    return pack;
}

bool PasswordManager::existsName(const std::string& name) {
    int size = countPasswords();
    PasswordPack* arr = decrypt();

    for (int i = 0; i < size; i++) {
        if (arr[i].getName() == name) {
            return true;
        }
    }
    return false;
}

PasswordPack PasswordManager::getByName(const std::string& name) {
    int size = countPasswords();
    PasswordPack* arr = decrypt();

    for (int i = 0; i < size; i++) {
        if (arr[i].getName() == name) {
            return arr[i];
        }
    }
}

void PasswordManager::removePassword(const std::string& name) {
    int size = countPasswords();
    PasswordPack* allPasswords = decrypt();
    PasswordPack leftPasswords[size-1];

    int t = 0;

    for (int i = 0; i < size; i++) {
        if (allPasswords[i].getName() != name) {
            leftPasswords[t] = allPasswords[i];
            t++;
        }
    }

    FileManager::clearCurrFile();

    encryptAll(leftPasswords, size-1);
}

PasswordPack PasswordManager::editPack(PasswordPack tempPack) {
    tempPack = PasswordManager::editName(tempPack, PasswordManager::askName());
    tempPack = PasswordManager::editPassword(tempPack, PasswordManager::askPassword());
    tempPack = PasswordManager::editCategory(tempPack, PasswordManager::askCategory());
    if(!tempPack.getUrl().empty()) tempPack = PasswordManager::editUrl(tempPack, PasswordManager::askURL());
    if(!tempPack.getLogin().empty()) tempPack = PasswordManager::editLogin(tempPack, PasswordManager::askLogin());
    return tempPack;
}
