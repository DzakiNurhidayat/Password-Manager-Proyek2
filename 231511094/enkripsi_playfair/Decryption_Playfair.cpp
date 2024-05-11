// #include "playfair.h"

// // nanti fungsi ini ganti nama jadi main_decrypt
// string decryption(string loggedInUser, string cipherText)
// {
//     char playfair_table[10][10];
//     char lastchar;
//     buatplayfairtable(loggedInUser, playfair_table);
//     string decrypted_text;

//     if (cipherText.length() % 2 != 0)//jika ganjil char akhir dihapus lalu dimasukan kembali setelah di dekripsi
//     {
//         lastchar = cipherText[cipherText.length() - 1];
//         cipherText.pop_back();
//         decrypted_text = dekripsi_playfair(cipherText, playfair_table);
//         decrypted_text.push_back(lastchar);
//     }
//     else
//     {
//         decrypted_text = dekripsi_playfair(cipherText, playfair_table);
//     }

//     return decrypted_text;
// }

// // aturan ketika enkripsi/dekripsi playfair
// // 1. jika di kolom yang sama maka
// // 2. jika di baris yang sama 
// // 3. jika di tidak ada yang sama
// // 4. jika kolom dan baris nya sama

// string dekripsi_playfair(string ciphertext, char playfairtable[10][10])
// {
//     string decrypted_text;

    
//     return decrypted_text;
// }