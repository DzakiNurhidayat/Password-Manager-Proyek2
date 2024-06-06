#ifndef TEST_H
#define TEST_H

#include "../treeListPassword.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Struktur data untuk linked list
struct filePassword {
    string nama;
    string username;
    string password;
    string note;
    string dateCreated;
    filePassword *next;
};


// Fungsi-fungsi yang digunakan dalam program
bool hasSymbol(char c);
void helpLogin();
void helpIn();
int checkPasswordStrength(string messagePassword);
void uniquePassword();
void insert_last(filePassword **first, filePassword **last, filePassword *newNode);
void insert_order(filePassword **first, filePassword **last, string nama, string username, string password, string note, string dateCreated);
void entry_to_linkedlist(filePassword **first, filePassword **last, listPassword *root);
void save_to_file(filePassword *first, string &loggedInUser);
void entry_to_file(filePassword* first, string &loggedInUser);

// Punya Jihan
void alloc_listPassword (string nama, string username, string password, string note, string dateCreated, filePassword **newNode);
filePassword* dealloc_listPassword (filePassword **first);
// void alloc_listPassword(string nama, string username, string password, string note, string dateCreated, listPassword **newNode);
// void insert_last(listPassword **first, listPassword **last, listPassword *newNode);
// long get_timestamp();
// void insert_order(listPassword **first, listPassword **last, string nama, string username, string password, string note, string dateCreated);
// void trav_preorder(listPassword **first, listPassword **last, TreeNode *root);
// void save_to_file(listPassword *first, string &loggedInUser);
#endif

// Struktur data untuk binary tree
//struct TreeNode {
//    string nama;
//    string username;
//    string password;
//    string note;
//    string dateCreated;
//    TreeNode *left;
//    TreeNode *right;
//};
//void addNodeToTree(TreeNode* &root);
//TreeNode* insertToTree(TreeNode *root, string nama, string username, string password, string note, string dateCreated);

