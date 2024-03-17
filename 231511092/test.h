#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// Function prototypes
bool hasSymbol(char c);
bool hasSpecialChar(char c);
int checkPasswordStrength(const string& password);

// Function to check if password exists in the map
bool isPasswordUnique(const string& password, const map<string, string>& passwordMap);

// Function to save password to a map
void savePassword(const string& password, map<string, string>& passwordMap);

#endif

