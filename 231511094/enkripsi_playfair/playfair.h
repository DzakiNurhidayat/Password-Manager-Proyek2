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

// SULTHAN
string encryption(string loggedInUser, string plainText);
string encryptionPlayfair(address Head, string plainText);
char sameRowEncrypt(address addressC);
char sameColEncrypt(address addressC);

string decryption(string loggedInUser, string cipherText);
string decryptionPlayfair(address Head, string cipherText);
char sameRowDecrypt(address addressC);
char sameColDecrypt(address addressC);

string unique(string key);
bool checkHorizontal(address current, address current2);
bool checkVertical(address current, address current2);
char differentColRow(address c1, address c2);

// AFRIZA
address searchingNode(address Head, infotype plainText);
address createTable(int size_board, string character);

#endif