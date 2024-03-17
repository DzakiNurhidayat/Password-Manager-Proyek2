#include <iostream>
#include <cctype>
#include <string>
#include "../231511083/listpassword.h"

using namespace std;

bool hasSymbol(char c) {
  return !isalnum(c) && !isspace(c);
}

void checkPasswordStrength(string messagePassword) 
{
	string kekuatan;
	bool valid = false;
	int strength;
	

  // Meminta input password
	// while (!valid) 
	// {
    // 	cout << "Masukkan Password (minimal 6 karakter): ";
    // 	cin >> password;

    // Validasi panjang password
    if (messagePassword.length() < 6)
	{
      cout << "Password harus minimal 6 karakter!" << endl;
    }

    valid = true;
    bool hasAnySymbol = false;
    bool hasLetter = false;
    bool hasNumber = false;

    // Periksa keberadaan simbol, huruf, dan nomor pada setiap karakter password
    for (int i = 0; i < messagePassword.length(); i++) 
	{
    	if (hasSymbol(messagePassword[i])) 
		{
    		hasAnySymbol = true;
		} 
		else if (isalpha(messagePassword[i])) 
		{
        	hasLetter = true;
    	} 
		else if (isdigit(messagePassword[i])) 
		{
        	hasNumber = true;
      	}
    }

    // Hitung level kekuatan password
    if (hasAnySymbol && hasLetter && hasNumber) 
	{
    	strength = 3;
		kekuatan = "Kuat";
    } 
	else if (hasLetter && hasNumber) 
	{
		strength = 2;
		kekuatan = "Standar";
    } 
	else if (hasLetter || hasNumber) 
	{
		strength = 1;
		kekuatan = "Lemah";
    } 
	else 
	{
    	strength = 0;
    }
//   }

  // Menampilkan hasil
  cout << "| Password : " << messagePassword << endl;
  cout << "| Level Kekuatan Password : " << strength << endl;
  cout << "| Tipe Kekuatan : " << kekuatan << endl;
}
