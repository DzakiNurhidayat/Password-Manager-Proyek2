#include "playfair.h"

/*File ini adalah untuk proses yang ada di enkripsi dan dekripsi*/

//kerangka playfair table (nanti panggil panggil fungsi/ yang di bawah nya)
void buatplayfairtable(string key,node table)
{
    string hasil;
    node q = table;

    hasil = unik(key);
    insert(hasil, &q);

}

//Memasukan character ke tabel playfair
void insert(string key,address lorem)
{
    
}

/*Menjadikan hasil yang unik karakter saja */
string unik(string key)
{
    string karakter;
    string addchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` '~✓®×¢€§×";

    for (char c : key) 
    {
        if (karakter.find(c) == string::npos) // Jika karakter tambahan belum ada di key, masukkan ke dalam tabel
        {
            karakter += c;
        }
    }
    for (char c : addchar)
    {
        if (karakter.find(c) == string::npos)
        {
            karakter += c;
        }
    }

    return karakter;
}

//traversal dan mencari tahu posisi node 
void cekposisi(node p,node q)
{
    
}