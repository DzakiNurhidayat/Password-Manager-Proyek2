#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream> // Untuk operasi file
#include <vector>

using namespace std;

bool hasSymbol(char c) {
  return !isalnum(c) && !isspace(c);
}
// Fungsi untuk memeriksa apakah karakter adalah simbol
bool hasSymbol(char c);

// Modul untuk menampilkan informasi lebih lanjut
void helpLogin();
void helpIn();

// Modul untuk memvalidasi dan mengevaluasi kekuatan password
string testPassword();
int checkPasswordStrength(string messagePassword);

// Modul untuk mengecek keunikan password
void uniquePassword();

#endif // TEST_H