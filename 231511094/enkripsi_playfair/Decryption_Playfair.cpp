#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "playfair.h"

int main()
{
    string key = "WakWaw!123";                          //KEY (nanti di ganti dengan userlogin)
    char playfair_table[10][10];
    char lastchar;
    buatplayfairtable(key, playfair_table);
    string decrypted_text;

    // Membaca teks terenkripsi dari file
    ifstream encrypted_file("encrypted_text.txt");
    string ciphertext;
    if (encrypted_file.is_open())
    {
        getline(encrypted_file, ciphertext);
        encrypted_file.close();
    }
    else
    {
        cerr << "Gagal membuka file terenkripsi." << endl;
        return 1;
    }

    if (ciphertext.length() % 2 != 0)//jika ganjil char akhir dihapus lalu dimasukan kembali setelah di dekripsi
    {
        lastchar = ciphertext[ciphertext.length() - 1];
        ciphertext.pop_back();
        decrypted_text = dekripsi_playfair(ciphertext, playfair_table);
        decrypted_text.push_back(lastchar);
    }
    else
    {
        decrypted_text = dekripsi_playfair(ciphertext, playfair_table);
    }

    // Munculkan tabel
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << playfair_table[i][j] << " | ";
    //     }
    //     cout << "\n";
    // }

    cout << "Hasil Dekripsi: " << decrypted_text << endl;

    return 0;
}

void buatplayfairtable(string key, char playfair_table[10][10])
{
    string add_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` ~©ÜüØö÷æ×Ø";
    // Alternatif add_char = !@#&*()cdefLMSTUVWXYZghijkl$%^mn+NOPQR-=[]{}|op ABGHIJK1234abqrstuCDEFvwxyz056789_;:,.<>?/`~©ÜüØö÷æ×Ø; //(di shuffle dikit)
    int row = 0, col = 0;

    // Menghapus duplikat karakter dalam key (agar Key nya )
    string uniqueKey;
    for (char c : key) // Loop untuk setiap karakter key (dan element dari variabel key diambil lalu dimasukan ke variabel c)
    {
        if (uniqueKey.find(c) == string::npos) // Jika karakter tambahan belum ada di key, masukkan ke dalam tabel
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

void cekposisi(char playfairtable[10][10], char c, int &row, int &col)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) 
        {
            if (playfairtable[i][j] == c)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
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