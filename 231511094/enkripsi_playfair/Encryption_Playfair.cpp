// #include "playfair.h"


// // nanti fungsi ini ganti nama jadi main_encrypt 
// string encryption(string loggedInUser, string plainText) 
// {
//     string encrypted_text;
//     char playfair_table[10][10];
//     buatplayfairtable(loggedInUser, playfair_table);
//     char lastchar;
   

//     if (plainText.length() % 2 != 0)
//     {
//         lastchar = plainText[plainText.length() - 1];
//         plainText.pop_back();                                           // Menghapus char terakhir agar jumlahnya genap
//         encrypted_text = enkripsi_playfair(plainText, playfair_table);  // Memasukan teks enkripsi ke variabel encrypted_text
//         encrypted_text.push_back(lastchar);
//     }
//     else
//     {
//         encrypted_text = enkripsi_playfair(plainText, playfair_table);
//     }

//     cout << "| Hasil enkripsi : " << encrypted_text << endl;
//     return encrypted_text;
// }


// // aturan ketika enkripsi/dekripsi playfair
// // 1. jika di kolom yang sama maka
// // 2. jika di baris yang sama
// // 3. jika di tidak ada yang sama
// // 4. jika kolom dan baris nya sama

// string enkripsi_playfair(string message, address playfair_table)
// {
//     string encrypted_text;
    
//     return encrypted_text;
// }