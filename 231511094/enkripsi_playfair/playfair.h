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

typedef struct node
{
    infotype text;
    address top;
    address down;
    address right;
    address left;
};


string encryption(string loggedInUser, string plainText);
string decryption(string loggedInUser, string cipherText);
bool cek_horizontal(address current, address current2);
bool cek_vertikal(address current, address current2);
address searchingNode(address Head, infotype nilai);
address createTable(int size_board, string karakter);
char samerow(address c1);
char samecol(address c1);
string unik(string key);
address createTable(int size_board, string karakter);
address searchingNode(address Head, infotype nilai);

#endif