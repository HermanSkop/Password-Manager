//
// Created by user on 04.06.2022.
//

#ifndef MAIN_CPP_PASSWORDMANAGER_H
#define MAIN_CPP_PASSWORDMANAGER_H
#include <filesystem>
#include <iostream>
#include <bitset>
#include <fstream>
#include "FileManager.h"
#include "PasswordPack.h"


class PasswordManager {
private:


    static bool encryptln(const std::string &input)/**
 * Encrypts given string and adds \n to the file
 * @param input is string to encrypt
 * @return if the encryption went well
 */
;
    static bool encrypt(const std::string& input)/**
 * Encrypts given string
 * @param input
 * @return if the encryption went well
 */
;
    static bool encryptMark(const std::string &input, char mark)/**
 * Encrypts given string and adds mark to the file
 * @param input is string to encrypt
 * @param mark to add
 * @return if the encryption went well
 */
    ;
    static bool encryptMarkln(const std::string &input, char mark)/**
 * Encrypts given string, adds mark and \n to the file
 * @param input is string to encrypt
 * @param mark to add
 * @return if the encryption went well
 */
;

    static void write(const std::string& input)/**
 * Writes given input to the file
 * @param input to write
 */
;
    static void write(const int& input)/**
 * Writes given input to the file
 * @param input to write
 */
;

public:
    static void encryptPack(PasswordPack pack)/**
 * Encrypts the whole pack of password and saves to the file
 * @param pack to encrypt
 */
;
    static void encryptAll(PasswordPack *arr, size_t size)/**
 * Encrypts the whole array of packs of passwords and saves to the file
 * @param arr to encrypt
 * @param size size of the array
 */
;


    PasswordManager() = default;

    static void addPassword(const std::string& currDirectory)/**
 * Creates new password, depending on user's choice
 * @param currDirectory directory to add password
 */
;
    static void showHelpForAddPassword()/**
 * Outputs manual for creating password
 */
;
    static std::string askPassword()/**
 * Asks password from user
 * @return password
 */
;
    static std::string askName()/**
 * Asks name from user
 * @return name
 */;

    static std::string askCategory()/**
 * Asks category from user
 * @return category
 */;

    static std::string read(int line)/**
 * Reads line by given number
 * @param line to read
 * @return read line
 */
;

    static PasswordPack* decrypt()/**
 * Decrypts all lines from current file
 * @return array containing password packs from file
 */
;

    static PasswordPack decrypt(int passwordNumber)/**
 * Decrypts given line from file
 * @param passwordNumber is number of line
 * @return pack of the password
 */
;

    static void showHelpForAddSides()/**
 * Outputs manual for adding url and login
 */
;

    static std::string askLogin()/**
 * Asks for login from user
 * @return login
 */
;

    static std::string askURL()/**
 * Asks for url from user
 * @return url
 */
;

    static void write(char input)/**
 * Writes character to the current file
 * @param input char to write
 */
;

    static void showHelpForGeneratingPassword()/**
 * Outputs manual for generating password
 */
;

    static std::string generatePassword(int length)/**
 * Generates random password
 * @param length of the password
 * @return password
 */
;
    static std::string generateUpperPassword(int length)/**
 * Generates random uppercase password
 * @param length of the password
 * @return password
 */
;
    static std::string generateLowerPassword(int length)/**
 * Generates random lowercase password
 * @param length of the password
 * @return password
 */
 ;
    static std::string generateLowerNoSpecialPassword(int length)/**
 * Generates random lowercase password without special symbols
 * @param length of the password
 * @return password
 */
 ;
    static std::string generateUpperNoSpecialPassword(int length)/**
 * Generates random uppercase password without special symbols
 * @param length of the password
 * @return password
 */
 ;

    static std::string generateNoSpecialPassword(int length)/**
 * Generates random password without special symbols
 * @param length of the password
 * @return password
 */
 ;

    static void showHelpForRules()/**
 * Outputs manual for generating password
 */
;

    static void buildAddsPassword()/**
 * Adds url and login depending on user's choice
 */
;

    static void showPasswords(PasswordPack* arr)/**
 * Outputs all passwords from given array
 * @param arr to output
 */
;

    static PasswordPack* sortByName(PasswordPack* arr)/**
 * Sorts array of passwords by name alphabetically
 * @param arr to sort
 * @return sorted array
 */
;
    static PasswordPack* sortByCategory(PasswordPack* arr)/**
Sorts array of passwords by category alphabetically
 * @param arr to sort
 * @return sorted array
 */
;


    static int countPasswords()/**
 * Counts passwords in current file
 * @return count
 */
;

    static PasswordPack editName(PasswordPack pack, std::string name)/**
 * Edits name of given pack
 * @param pack to edit
 * @param name to add instead
 * @return edited PasswordPack
 */
;

    static PasswordPack getByName(const std::string& name)/**
 * Searches for name in file
 * @param name to search
 * @return found PasswordPack
 */
;

    static bool existsName(const std::string& name)/**
 * Checks if the given name exists
 * @param name to check
 * @return if the value exist
 */
;

    static PasswordPack editPassword(PasswordPack pack, std::string password)/**
 * Edits password in given pack
 * @param pack to replace password in
 * @param password to add instead
 * @return edited pack
 */
 ;

    static PasswordPack editCategory(PasswordPack pack, std::string category)/**
 * Edits category in given pack
 * @param pack to replace password in
 * @param category to add instead
 * @return edited pack
 */
;

    static PasswordPack editLogin(PasswordPack pack, std::string login)/**
 * Edits login in given pack
 * @param pack to replace password in
 * @param login to add instead
 * @return edited pack
 */
 ;

    static PasswordPack editUrl(PasswordPack pack, std::string url)/**
 * Edits url in given pack
 * @param pack to replace password in
 * @param url to add instead
 * @return edited pack
 */
 ;

    static void removePassword(const std::string& name)/**
 * Removes password by name
 * @param name to search for password
 */
;
    static PasswordPack editPack(PasswordPack tempPack)/**
 * Edits the whole pack
 * @param tempPack to edit
 * @return edited pack
 */
;

    static PasswordPack *falseDecrypt()/**
 * Decrypts the whole file in the wrong way
 * @return all the passwords decrypted
 */
;

    static PasswordPack falseDecrypt(int i)/**
 * Decrypts given line in wrong way
 * @param i to decrypt
 * @return decrypted pack
 */
;
};


#endif //MAIN_CPP_PASSWORDMANAGER_H
