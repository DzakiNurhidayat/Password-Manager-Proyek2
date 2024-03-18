#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream> // Untuk operasi file
#include <vector>

using namespace std;

// Fungsi untuk memeriksa apakah karakter adalah simbol
bool hasSymbol(char c);

// Modul untuk menampilkan informasi lebih lanjut
void helpLogin();
void helpIn();

// Modul untuk memvalidasi dan mengevaluasi kekuatan password
string testPassword();
void checkPasswordStrength(string password);

// Modul untuk mengecek keunikan password
void uniquePassword();

#endif // TEST_H