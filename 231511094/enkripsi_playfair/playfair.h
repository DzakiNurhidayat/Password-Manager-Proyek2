#ifndef PLAYFAIR_H
#define PLAYFAIR
#include <string>
using namespace std;

void buatplayfairtable(string key, char playfairtable[5][5]);
string format_text(const string &text);
void cekposisi(char playfairtable[5][5], char c, int &row, int &col);
string enkripsi_playfair(string plaintext, char playfairtabel[5][5]);
string dekripsi_playfair(string ciphertext, char playfairtabel[5][5]);

#endif