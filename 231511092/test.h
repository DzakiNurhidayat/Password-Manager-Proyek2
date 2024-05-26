#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream> // Untuk operasi file
#include <vector>
#include <ctime>
#include <time.h>
#include <stdio.h>
#define infotype string

using namespace std;


struct listPassword {
    string nama;
    string username;
    string password;
    string note;
    string dateCreated;
    listPassword *left;
    listPassword *right;
    listPassword *next; 
    long timestamp;  
};

typedef struct pointPassword 
{
  listPassword *head;
  listPassword *tail;
} pointPassword;


// typedef struct file
// {
//   char password[100];  // Maksimal panjang password
//   long timestamp;                     // Unix timestamp untuk waktu password
//   struct file *next;           // Pointer ke node berikutnya
// } file;



bool hasSymbol(char c) {
  return !isalnum(c) && !isspace(c);
}
// Fungsi untuk memeriksa apakah karakter adalah simbol
bool hasSymbol(char c);

// Modul untuk menampilkan informasi lebih lanjut
void helpLogin();
void helpIn();

// Modul untuk memvalidasi dan mengevaluasi kekuatan password
// string testPassword();
int checkPasswordStrength(string messagePassword);

// Modul untuk mengecek keunikan password
void uniquePassword();

void insert_last(pointPassword *llPassword, listPassword *newNode);
long get_timestamp();
void insert_order(pointPassword *llPassword, listPassword *newNode);
void trav_preorder(pointPassword *llPreorder, listPassword *root);
void save_to_file(listPassword *head, string loggedInUser);

#endif // TEST_H