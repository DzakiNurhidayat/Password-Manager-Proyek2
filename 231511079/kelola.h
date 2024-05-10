#ifndef KELOLA_H
#define KELOLA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../231511083/listpassword.h"

using namespace std;


void inputPassword(string loggedinUser);
void modifyPassword(listPassword* list, string loggedInUser, int countLine );
void deletePassword(string loggedInUser);


#endif