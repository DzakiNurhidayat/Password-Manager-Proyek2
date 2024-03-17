#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "playfair.h"

int main()
{
    string key = "WakWaw!123";
    string encrypted_text;
    char playfair_table[10][10];
    buatplayfairtable(key, playfair_table);
    char lastchar;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j  < 10; j++)
        {
            cout << playfair_table[i][j] << " | ";
        }
        cout << "\n";
        }
    
    string plaintext;
    cout << "Masukkan plaintext yang akan dienkripsi: ";
    cin >> plaintext;

    // mengambil char akhir jika total plaintext nya ganjil

    if (plaintext.length() % 2 != 0)
    {
        lastchar = plaintext[plaintext.length() - 1];
        cout << "\nlast char = " << lastchar << "\n";
        plaintext.pop_back();                                           // Menghapus char terakhir agar jumlahnya genap
        encrypted_text = enkripsi_playfair(plaintext, playfair_table);  // Memasukan teks enkripsi ke variabel encrypted_text
        encrypted_text.push_back(lastchar);
    }
    else
    {
        encrypted_text = enkripsi_playfair(plaintext, playfair_table);
    }

    cout << "Hasil enkripsi: " << encrypted_text << endl;

    // Simpan hasil enkripsi ke dalam file txt
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
    string add_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` ~©ÜüØö÷æ×Ø";
    // Alternatif add_char = !@#&*()cdefLMSTUVWXYZghijkl$%^mn+NOPQR-=[]{}|op ABGHIJK1234abqrstuCDEFvwxyz056789_;:,.<>?/`~©ÜüØö÷æ×Ø; //(di shuffle dikit)
    int row = 0, col = 0; 

    //Menghapus duplikat karakter dalam key
    string uniqueKey;
    for (char c : key)
    {
        if (uniqueKey.find(c) == string::npos)
        {
            uniqueKey += c;
        }
    }

    // Memasukkan key ke dalam tabel Playfair
    for (char c : uniqueKey)
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
    for (char c : add_chars) // Loop untuk setiap karakter tambahan
    {
        if (row == 10)
            break;
        if (key.find(c) == string::npos) // Jika karakter tambahan belum ada di key, masukkan ke dalam tabel
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
    for (size_t i = 0; i < plaintext.length(); i += 2)// Loop untuk setiap dua karakter dalam plaintext
    {
        char c1 = plaintext[i];                                          // karakter kesatu
        char c2 = (i + 1 < plaintext.length()) ? plaintext[i + 1] : ' '; // Karakter kedua atau spasi jika tidak ada karakter kedua

        if (c1 != c2)
        {
            int row1, col1, row2, col2;
            cekposisi(playfair_table, plaintext[i], row1, col1);        // cek dimana karakter ke satu
            cekposisi(playfair_table, plaintext[i + 1], row2, col2);    // cek dimana karakter ke dua

            // Jika huruf-huruf berada di baris yang sama, ganti dengan huruf di sebelah kanannya
            if (row1 == row2)
            {
                encrypted_text.push_back(playfair_table[row1][(col1 + 1) % 10]); 
                encrypted_text.push_back(playfair_table[row2][(col2 + 1) % 10]);
            }
            // Jika huruf-huruf berada di kolom yang sama, ganti dengan huruf di bawahnya
            else if (col1 == col2)
            {
                encrypted_text.push_back(playfair_table[(row1 + 1) % 10][col1]);
                encrypted_text.push_back(playfair_table[(row2 + 1) % 10][col2]);
            }
            // Jika keduanya berbeda baris dan kolom(dapat membentuk persegi) tukar kiri kanan
            else
            {
                encrypted_text.push_back(playfair_table[row1][col2]);
                encrypted_text.push_back(playfair_table[row2][col1]);
            }
        }
        // Jika dua karakter berturut-turut sama
        else
        {
            encrypted_text.push_back(c1); // masukan karakter pertama
            encrypted_text.push_back(c1); // masukan karakter pertama
        }
        }
    return encrypted_text;
}
// TODO LIST
// char ganda deskripsi problem = testing
// buat documentation (mungkin seperti tracing agar lenih mudah dimengerti)