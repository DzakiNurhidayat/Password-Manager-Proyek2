#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "playfair.h"

string decryption(string loggedInUser, string cipherText)
{
    // string key = "WakWaw!123";                          //KEY (nanti di ganti dengan userlogin)
    char playfair_table[10][10];
    char lastchar;
    buatplayfairtable(loggedInUser, playfair_table);
    string decrypted_text;

    if (cipherText.length() % 2 != 0)//jika ganjil char akhir dihapus lalu dimasukan kembali setelah di dekripsi
    {
        lastchar = cipherText[cipherText.length() - 1];
        cipherText.pop_back();
        decrypted_text = dekripsi_playfair(cipherText, playfair_table);
        decrypted_text.push_back(lastchar);
    }
    else
    {
        decrypted_text = dekripsi_playfair(cipherText, playfair_table);
    }

    return decrypted_text;
}

string dekripsi_playfair(string ciphertext, char playfairtable[10][10])
{
    string decrypted_text;

    for (size_t i = 0; i < ciphertext.length(); i += 2)
    {
        char c1 = ciphertext[i];                                          // karakter kesatu
        char c2 = (i + 1 < ciphertext.length()) ? ciphertext[i + 1] : ' '; // Karakter kedua atau spasi jika tidak ada karakter kedua

        if (c1 != c2)
        {
            int row1, col1, row2, col2;
            cekposisi(playfairtable, ciphertext[i], row1, col1);
            cekposisi(playfairtable, ciphertext[i + 1], row2, col2);

            // Jika huruf-huruf berada di baris yang sama, ganti dengan huruf di sebelah kiri
            if (row1 == row2)
            {
                decrypted_text.push_back(playfairtable[row1][(col1 + 9) % 10]);
                decrypted_text.push_back(playfairtable[row2][(col2 + 9) % 10]);
            }
            // Jika huruf-huruf berada di kolom yang sama, ganti dengan huruf di atasnya
            else if (col1 == col2)
            {
                decrypted_text.push_back(playfairtable[(row1 + 9) % 10][col1]);
                decrypted_text.push_back(playfairtable[(row2 + 9) % 10][col2]);
            }
            // Jika huruf-huruf membentuk persegi, ganti dengan huruf yang membentuk persegi lain di sampingnya
            else
            {
                decrypted_text.push_back(playfairtable[row1][col2]);
                decrypted_text.push_back(playfairtable[row2][col1]);
            }
        }//jika ciphertext nya sama huruf tidak di ganti
        else
        {
            decrypted_text.push_back(c1);
            decrypted_text.push_back(c1);
        }
    }
    return decrypted_text;
}