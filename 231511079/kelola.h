#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Password {
	string nama;
	string username;
	string password;
	string note;
};

void inputPassword(string pengguna);
void deletePassword();
void modifyPassword();
