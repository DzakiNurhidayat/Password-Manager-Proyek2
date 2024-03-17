#ifndef DZAKI_H
#define DZAKI_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;
#define MAX_PASS 100

struct listPassword {
    string nama;
    string username;
    string password;
    string note;
};

// Fitur List Password
void lowerCase(string *keyword);
void sorting (listPassword *list, int countLine, int sortBy);
void searching (listPassword* list, int countLine, string keyword);

// Baca dan Print File
int readListPassword (listPassword *list, string loggedInUser);
void printListPassword (listPassword *list, int countLine);

// Print Menu
void menuSorting (listPassword *list, int countLine);
void menuList(listPassword *list, int countLine);
void menuPassword (listPassword *list, int countLine, string loggedInUser);

#endif // DZAKI_H
