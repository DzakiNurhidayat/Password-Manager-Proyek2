#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Struktur data untuk linked list
struct listPassword {
    string nama;
    string username;
    string password;
    string note;
    string dateCreated;
    long timestamp;
    listPassword *next;
};


// Fungsi-fungsi yang digunakan dalam program
bool hasSymbol(char c);
void helpLogin();
void helpIn();
int checkPasswordStrength(string messagePassword);
void uniquePassword();
void alloc_listPassword(string nama, string username, string password, string note, string dateCreated, listPassword **newNode);
void insert_last(listPassword **head, listPassword **tail, listPassword *newNode);
long get_timestamp();
void insert_order(listPassword **head, listPassword **tail, string nama, string username, string password, string note, string dateCreated);
void trav_preorder(listPassword **head, listPassword **tail, TreeNode *root);
void save_to_file(listPassword *head, string &loggedInUser);
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

