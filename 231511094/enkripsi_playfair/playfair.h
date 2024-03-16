#ifndef PLAYFAIR_H
#define PLAYFAIR
#include <string>
using namespace std;

void buatplayfairtable(string key, char playfairtable[10][10]);
string format_text(const string &text);
void cekposisi(char playfairtable[10][10], char c, int &row, int &col);
string enkripsi_playfair(string plaintext, char playfairtabel[10][10]);
string dekripsi_playfair(string ciphertext, char playfairtabel[10][10]);

#endif