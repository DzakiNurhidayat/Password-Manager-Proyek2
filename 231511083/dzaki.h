#ifndef DZAKI_H
#define DZAKI_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;
#define MAX_PASS 100

struct listPassword {
    string nama;
    string username;
    string password;
    string note;
};

// Fitur List Password
void sorting (listPassword *list, int countLine, int sortBy);
void searching (listPassword* list, int countLine, string keyword);

// Baca dan Print File
int readListPassword (listPassword *list);
void printListPassword (listPassword *list, int countLine);

// Print Menu
void menuSorting (listPassword *list, int countLine);
void menuList(listPassword *list, int countLine);
void menuPassword (listPassword *list, int countLine);

#endif // DZAKI_H