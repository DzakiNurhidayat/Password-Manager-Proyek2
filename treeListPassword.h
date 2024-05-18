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
    infotype nama;
    infotype username;
    infotype password;
    infotype note;
    listPassword *left;
    listPassword *right;
};

listPassword *entry_data_to_tree(listPassword *root, infotype nama, infotype username, infotype password, infotype note);
listPassword *load_data_from_file(listPassword *root);
listPassword *delete_data_from_tree(listPassword *root, infotype nama);
void print_tree(listPassword *root);


#endif // TREELISTPASSWORD_H