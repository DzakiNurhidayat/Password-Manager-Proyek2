#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "playfair.h"

int main()
{
    string key = "TESASERACT";  //Menginisialisasi KEY
    char playfair_tabel[5][5];  //mendeklarasi TABEL 
    buatplayfairtable(key, playfair_tabel); // membuat tabel playfair menggunakan key nya

    string plaintext;           // deklarasi plaintext
    cout << "Masukkan plaintext yang ingin dienkripsi:";
    cin >> plaintext;           // Memasukan plain text

    string encrypted_text = enkripsi_playfair(plaintext, playfair_tabel); // melakukan enkripsi plaifair
    cout << "Hasil Enkripsi: " << encrypted_text << endl;                 //Memnculkan hasil enkripsi

    // Simpan hasil enkripsi ke dalam file
    ofstream encrypted_file("encrypted_text.txt");      //menyimpan text yang sudah di enkripsi ke sebuah file.txt
    if (encrypted_file.is_open())
    {
        encrypted_file << encrypted_text;               // memasukan text yang sudah terenkripsi ke file
        encrypted_file.close();
        cout << "Hasil enkripsi telah disimpan dalam file 'encrypted_text.txt'" << endl;
    }
    else
    {
        cout << "Gagal menyimpan hasil enkripsi ke dalam file." << endl;
    }

    return 0;
}

void buatplayfairtable(string key, char playfairtable[5][5])
{
    string charkey;    // akan digunakan unkt menyimpan char dari KEY
    for (char c : key) // akan mengambil elemen dari variabel key
        if (c != ' ')  // semua yang bukan spasi dimasukan ke charkey
        {
            charkey.push_back(toupper(c));// charkey di ubah menjadi huruf besar
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

string format_text(const string &text)
{
    string formatted;

    /*Alternative
    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            formatted.push_back(toupper(c));
        }
    }*/

    for (char c : text) //mengambil charcter dari plaintext
    {
        if (isalpha(c))
        {
            formatted.push_back(toupper(c)); //mengubah char plaintext huruf kecil menjadi huruf besar
        }
    }
    return formatted; // mengembalikan plaintext yang telah di ubah
}

void cekposisi(char playfairtable[5][5], char c, int &row, int &col)
{
    if (c == 'J')// jika yang di temukan adalah j samakan dengan i(karna J tidak ada di tabel playfair)
    {
        c = 'I';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) 
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

string enkripsi_playfair(string plaintext, char playfairtabel[5][5])
{
    string encryptedtext;
    string formated_text = format_text(plaintext);//memasukan text yang sudah di format

    for (size_t i = 0; i < formated_text.length(); i += 2)
    {
        int row1, col1, row2, col2;
        cekposisi(playfairtabel, formated_text[i], row1, col1);
        cekposisi(playfairtabel, formated_text[i + 1], row2, col2);

        // Jika huruf-huruf berada di baris yang sama, ganti dengan huruf di sebelah kanan
        if (row1 == row2)
        {
            encryptedtext.push_back(playfairtabel[row1][(col1 + 1) % 5]);
            encryptedtext.push_back(playfairtabel[row2][(col2 + 1) % 5]);
        }
        // Jika huruf-huruf berada di kolom yang sama, ganti dengan huruf di bawahnya
        else if (col1 == col2)
        {
            encryptedtext.push_back(playfairtabel[(row1 + 1) % 5][col1]);
            encryptedtext.push_back(playfairtabel[(row2 + 1) % 5][col2]);
        }
        // Jika huruf-huruf membentuk persegi, ganti dengan huruf yang membentuk persegi lain di sampingnya
        else
        {
            encryptedtext.push_back(playfairtabel[row1][col2]);
            encryptedtext.push_back(playfairtabel[row2][col1]);
        }
    }
    return encryptedtext;
}