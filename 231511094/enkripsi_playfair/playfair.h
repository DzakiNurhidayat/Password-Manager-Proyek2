#ifndef PLAYFAIR_H
#define PLAYFAIR

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef char infotype;
typedef struct node *address;

struct node
{
    infotype text;
    address top;
    address down;
    address right;
    address left;
};

struct playfair
{
    /* data */
};

string encryption(string loggedInUser, string plainText);
string decryption(string loggedInUser, string cipherText);
void buatplayfairtable(string key, char playfairtable[10][10]);
void cekposisi(char playfairtable[10][10], char c, int &row, int &col);
string enkripsi_playfair(string plaintext, char playfairtabel[10][10]);
string dekripsi_playfair(string ciphertext, char playfairtabel[10][10]);

#endif