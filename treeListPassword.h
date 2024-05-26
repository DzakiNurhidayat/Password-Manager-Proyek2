#ifndef TREELISTPASSWORD_H
#define TREELISTPASSWORD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <chrono>

using namespace std;
#define MAX_PASS 100
#define infotype string

struct listPassword {
    string nama;
    string username;
    string password;
    string note;
    string dateCreated;
    listPassword *left;
    listPassword *right;
};


// DZAKI
void cek_alokasi(string nama, string username, string password, string note, string dateCreated, listPassword **newNode);
string getCurrentTimestamp();
listPassword *entry_data_to_tree(listPassword **root, string nama, string username, string password, string note, string dateCreated);
listPassword *load_data_from_file(listPassword *root, string loggedInUser);
void lower_case(string &keyword);
bool searching(listPassword *root, string keyword, int namaWidth, int userWidth, int passWidth, int noteWidth);
void find_max_widths(listPassword *node, int &namaWidth, int &userWidth, int &passWidth, int &noteWidth);
void print_table(int namaWidth, int userWidth, int passWidth, int noteWidth);
void print_tree(listPassword *root, int &nomor, int namaWidth, int userWidth, int passWidth, int noteWidth);
void print_tree_reverse(listPassword *root, int &nomor, int namaWidth, int userWidth, int passWidth, int noteWidth);
void dealokasi_tree(listPassword* root);
void entry_data_to_file(listPassword* root, string loggedInUser);
void delete_list_infile(string loggedInUser);

// JIHAN
void print_nama_tree(listPassword *root, int &nomor);
listPassword *search_node(listPassword *root, string nilaiCari);
listPassword *delete_data_from_tree(listPassword *root, string nama);
listPassword *edit_data_from_tree(listPassword *root, string nama, string loggedInUser);

#endif // TREELISTPASSWORD_H