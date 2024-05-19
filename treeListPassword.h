#ifndef TREELISTPASSWORD_H
#define TREELISTPASSWORD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
#define MAX_PASS 100
#define infotype string

struct listPassword {
    string nama;
    string username;
    string password;
    string note;
    listPassword *left;
    listPassword *right;
};

listPassword *entry_data_to_tree(listPassword *root, string nama, string username, string password, string note);
listPassword *load_data_from_file(listPassword *root);
// void print_tree(listPassword *root);


#endif // TREELISTPASSWORD_H