#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "playfair.h"

int main()
{
    string key = "WakWaw!123";
    char playfair_table[10][10];
    buatplayfairtable(key, playfair_table);

    string plaintext;
    cout << "Masukkan plaintext yang akan dienkripsi: ";
    cin >> plaintext;

    string encrypted_text = enkripsi_playfair(plaintext, playfair_table);
    cout << "Hasil enkripsi: " << encrypted_text << endl;

    // Simpan hasil enkripsi ke dalam file
    ofstream encrypted_file("encrypted_text.txt");
    if (encrypted_file.is_open())
    {
        encrypted_file << encrypted_text;
        encrypted_file.close();
        cout << "Hasil enkripsi telah disimpan dalam file 'encrypted_text.txt'" << endl;
    }
    else
    {
        cerr << "Gagal menyimpan hasil enkripsi ke dalam file." << endl;
    }

    return 0;
}

void buatplayfairtable(string key, char playfair_table[10][10])
{
    string add_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/`~©ÜüØ ";
    int row = 0, col = 0;

    // Memasukkan key ke dalam tabel Playfair
    for (char c : key)
    {
        playfair_table[row][col] = c;
        col++;
        if (col == 10)
        {
            col = 0;
            row++;
        }
    }

    // Memasukkan karakter tambahan ke dalam tabel Playfair
    for (char c : add_chars)
    {
        if (row == 10)
            break;
        if (key.find(c) == string::npos)
        {
            playfair_table[row][col] = c;
            col++;
            if (col == 10)
            {
                col = 0;
                row++;
            }
        }
    }
}

void cekposisi(char playfair_table[10][10], char c, int &row, int &col)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (playfair_table[i][j] == c)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string enkripsi_playfair(string plaintext, char playfair_table[10][10])
{
    string encrypted_text;
    for (size_t i = 0; i < plaintext.length(); i += 2)
    {
        char c1 = plaintext[i];
        char c2 = (i + 1 < plaintext.length()) ? plaintext[i + 1] : ' ';

        if (c1 != c2)
        {
            int row1, col1, row2, col2;
            cekposisi(playfair_table, plaintext[i], row1, col1);
            cekposisi(playfair_table, plaintext[i + 1], row2, col2);

            if (row1 == row2)
            {
                encrypted_text.push_back(playfair_table[row1][(col1 + 1) % 10]);
                encrypted_text.push_back(playfair_table[row2][(col2 + 1) % 10]);
            }
            else if (col1 == col2)
            {
                encrypted_text.push_back(playfair_table[(row1 + 1) % 10][col1]);
                encrypted_text.push_back(playfair_table[(row2 + 1) % 10][col2]);
            }
            else
            {
                encrypted_text.push_back(playfair_table[row1][col2]);
                encrypted_text.push_back(playfair_table[row2][col1]);
            }
        }
        else
        {
            encrypted_text.push_back(c1);
            encrypted_text.push_back(' ');
        }
        }
    return encrypted_text;
}
