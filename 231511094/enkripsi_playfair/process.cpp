#include "playfair.h"

/*File ini adalah untuk proses yang ada di enkripsi dan dekripsi*/

//kerangka playfair table (nanti panggil panggil fungsi/ yang di bawah nya)
void buatplayfairtable(address lorem)
{
    string add_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` '~✓®×¢€§×";

    
}

//Memasukan character unik ke tabel playfair
void unik(string key,address lorem /*masuk ke linked list*/)
{
    string uniqueKey;
    for (char c : key) // Loop untuk setiap karakter key (dan element dari variabel key diambil lalu dimasukan ke variabel c)
    {
        if (uniqueKey.find(c) == string::npos) // Jika karakter tambahan belum ada di key, masukkan ke dalam tabel
        {
            uniqueKey += c;
        }
    }
}

void deletecommon()
{

}


//traversal dan mencari tahu posisi node 
void cekposisi(char playfair_table[10][10], char c, int &row, int &col)
{
    
}