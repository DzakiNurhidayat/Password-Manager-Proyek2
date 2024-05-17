#include "test.h"

using namespace std;

int main() 
{
	string password;
	bool valid = false;
	int strength;
	
	cout << "Masukkan Password (minimal 6 karakter): ";
    cin >> password;
	// Meminta input password
	while (!valid) 
	{
    	
    	if (password.length() <= 6)
		{
    		cout << endl << "Password harus minimal 6 karakter!" << endl;
      		continue;
    	}
    	valid = true;
    	bool hasAnySymbol = false;
    	bool hasLetter = false;
    	bool hasNumber = false;
    	for (int i = 0; i < password.length(); i++) 
		{
    		if (hasSymbol(password[i])) 
			{
    			hasAnySymbol = true;
			} 
			else if (isalpha(password[i])) 
			{
        		hasLetter = true;
    		} 
			else if (isdigit(password[i])) 
			{
        		hasNumber = true;
      		}
    	}

    // Hitung level kekuatan password
    	if (hasAnySymbol && hasLetter && hasNumber) 
		{
    		strength = 3;
    	} 
		else if (hasLetter && hasNumber) 
		{
			strength = 2;
    	} 
		else if (hasLetter || hasNumber) 
		{
			strength = 1;
    	} 
		else 
		{
    		strength = 0;
    	}
  	}
  	
  	cout << "Password: " << password << endl;
  	cout << "Level kekuatan: " << strength << endl;

  	return 0;
}

