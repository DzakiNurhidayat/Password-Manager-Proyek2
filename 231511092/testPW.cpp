#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool hasSymbol(char c) {
  return !isalnum(c) && !isspace(c);
}

int main() {
  string password;
  bool valid = false;
  int strength;

  while (!valid) {
    cout << "Masukkan Password (minimal 8 karakter, harus mengandung simbol): ";
    cin >> password;

    // Validasi panjang password
    if (password.length() < 8) {
      cout << "Password harus lebih dari 8 karakter!" << endl;
      continue; 
    }

    // Validasi simbol
    bool hasSymbol = false;
    for (int i = 0; i < password.length(); i++) {
      if (!isalnum(password[i]) && !isspace(password[i])) {
        hasSymbol = true;
        break; 
      }
    }

    // Validasi kombinasi huruf dan nomor
    bool hasLetter = false;
    bool hasNumber = false;
    for (int i = 0; i < password.length(); i++) {
      if (isalpha(password[i])) {
        hasLetter = true;
      } else if (isdigit(password[i])) {
        hasNumber = true;
      }
    }

    if (hasSymbol && hasLetter && hasNumber) {
      valid = true;
    } else {
      cout << "Password harus mengandung kombinasi huruf, nomor, dan simbol." << endl;
    }
    
    // Modul level kekuatan password
    if (hasSymbol && hasLetter && hasNumber) {
      strength = 3;
    } else if (hasLetter && hasNumber) {
      strength = 2;
    } else if (hasLetter || hasNumber) {
      strength = 1;
    }

  }

  cout << "Password: " << password << endl;
	cout << "level kekuatan: " << strength;
  return 0;
}

