#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "playfair.h"

int main()
{
    string key = "TESASERACT";
    char playfair_table[5][5];
    buatplayfairtable(key, playfair_table);

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

    string decrypted_text = dekripsi_playfair(ciphertext, playfair_table);
    cout << "Hasil Dekripsi: " << decrypted_text << endl;

    return 0;
}
void buatplayfairtable(string key, char playfairtable[5][5])
{
    string charkey;    // akan digunakan unkt menyimpan char dari KEY
    for (char c : key) // akan mengambil elemen dari variabel key
        if (c != ' ')  // semua yang bukan spasi dimasukan ke charkey
        {
            charkey.push_back(toupper(c)); // charkey di ubah menjadi huruf besar
        }

    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // string alphabet untuk melengkapi tabel playfair
    // Memasukan Key ke tabel playfair
    int row = 0, col = 0;
    for (char c : charkey) // memasukan alphabet yang ada di charkey kedalam c untuk setiap charkey
    {
        if (row * 5 + col == 25) // jikasudah 25(tabel terisi semua) maka keluar dari prosedur ini diselsaikan
            break;

        playfairtable[row][col] = c; // masukan charcter yang telah di ambil dari charkey ke tabel playfair
        col++;
        if (col == 5) // Jika setiap colom telah terpenuhi maka ganti colom dan tambahkan row
        {
            col = 0;
            row++;
        }
    }

    // memaukan alphabet yang tersisa ke dalam tabel
    for (char c : alphabet) // mengambil  character dari alphabet
    {
        if (row * 5 + col == 25) // jikasudah 25(tabel terisi semua) maka keluar dari prosedur ini diselsaikan
            break;

        if (charkey.find(c) == string::npos) // string::npos == konstanta tidak di temukan dalam string (jadi ini menanadakan"Jika tidak ada di char kosong")
        {
            playfairtable[row][col] = c; // Memasukan char ke tabel playfair
            col++;
            if (col == 5) // Jika setiap colom telah terpenuhi maka ganti colom dan tambahkan row
            {
                col = 0;
                row++;
            }
        }
    }
}
void cekposisi(char playfairtable[5][5], char c, int &row, int &col)
{
    if (c == 'J')
    {
        c = 'I';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) // Perbaikan: Perulangan harus untuk iterasi kolom (j), bukan i
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

string dekripsi_playfair(string ciphertext, char playfairtable[5][5])
{
    string decrypted_text;

    for (size_t i = 0; i < ciphertext.length(); i += 2)
    {
        int row1, col1, row2, col2;
        cekposisi(playfairtable, ciphertext[i], row1, col1);
        cekposisi(playfairtable, ciphertext[i + 1], row2, col2);

        // Jika huruf-huruf berada di baris yang sama, ganti dengan huruf di sebelah kiri
        if (row1 == row2)
        {
            decrypted_text.push_back(playfairtable[row1][(col1 + 4) % 5]);
            decrypted_text.push_back(playfairtable[row2][(col2 + 4) % 5]);
        }
        // Jika huruf-huruf berada di kolom yang sama, ganti dengan huruf di atasnya
        else if (col1 == col2)
        {
            decrypted_text.push_back(playfairtable[(row1 + 4) % 5][col1]);
            decrypted_text.push_back(playfairtable[(row2 + 4) % 5][col2]);
        }
        // Jika huruf-huruf membentuk persegi, ganti dengan huruf yang membentuk persegi lain di sampingnya
        else
        {
            decrypted_text.push_back(playfairtable[row1][col2]);
            decrypted_text.push_back(playfairtable[row2][col1]);
        }
    }
    return decrypted_text;
}
