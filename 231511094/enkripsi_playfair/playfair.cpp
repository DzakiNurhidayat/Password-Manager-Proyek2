#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Membuat tabel Playfair
void createPlayfairTable(const string& key, char playfairTable[5][5]) {
    string keyWithoutSpaces;
    // Menghapus spasi dari kunci dan mengonversi ke huruf kapital
    for (char c : key) {
        if (c != ' ')
            keyWithoutSpaces.push_back(toupper(c));
    }

    // Mengisi kunci ke dalam tabel
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J dihilangkan karena sudah ada I
    int keyIndex = 0;
    int alphaIndex = 0;
    for (int i = 0; i < 25; ++i) {
        if (keyIndex < keyWithoutSpaces.length()) {
            playfairTable[i / 5][i % 5] = keyWithoutSpaces[keyIndex++];
        } else {
            // Memasukkan sisa abjad ke dalam tabel
            while (keyWithoutSpaces.find(alphabet[alphaIndex]) != string::npos)
                ++alphaIndex;
            playfairTable[i / 5][i % 5] = alphabet[alphaIndex++];
        }
    }
}

// Mencari posisi dari sebuah karakter dalam tabel Playfair
void findPosition(char playfairTable[5][5], char letter, int& row, int& col) {
    if (letter == 'J') letter = 'I'; // Mengganti J dengan I
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (playfairTable[i][j] == letter) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Memproses teks plainteks untuk enkripsi/dekripsi
string processText(const string& text) {
    string processedText;
    for (char c : text) {
        if (isalpha(c))
            processedText.push_back(toupper(c)); // Mengonversi ke huruf kapital
    }
    // Menyisipkan 'X' jika ada dua karakter yang sama bersebelahan atau jumlah karakter ganjil
    for (size_t i = 0; i < processedText.length(); i += 2) {
        if (i + 1 < processedText.length() && processedText[i] == processedText[i + 1]) {
            processedText.insert(i + 1, "X");
        } else if (i + 1 == processedText.length()) {
            processedText.push_back('X');
        }
    }
    return processedText;
}

// Enkripsi teks menggunakan tabel Playfair
string playfairEncrypt(const string& plaintext, char playfairTable[5][5]) {
    string encryptedText;
    string processedText = processText(plaintext);
    for (size_t i = 0; i < processedText.length(); i += 2) {
        int row1, col1, row2, col2;
        findPosition(playfairTable, processedText[i], row1, col1);
        findPosition(playfairTable, processedText[i + 1], row2, col2);

        // Jika huruf-huruf berada di baris yang sama, ganti dengan huruf di sebelah kanan
        if (row1 == row2) {
            encryptedText.push_back(playfairTable[row1][(col1 + 1) % 5]);
            encryptedText.push_back(playfairTable[row2][(col2 + 1) % 5]);
        }
        // Jika huruf-huruf berada di kolom yang sama, ganti dengan huruf di bawahnya
        else if (col1 == col2) {
            encryptedText.push_back(playfairTable[(row1 + 1) % 5][col1]);
            encryptedText.push_back(playfairTable[(row2 + 1) % 5][col2]);
        }
        // Jika huruf-huruf membentuk persegi, ganti dengan huruf yang membentuk persegi lain di sampingnya
        else {
            encryptedText.push_back(playfairTable[row1][col2]);
            encryptedText.push_back(playfairTable[row2][col1]);
        }
    }
    return encryptedText;
}

// Dekripsi teks menggunakan tabel Playfair
string playfairDecrypt(const string& ciphertext, char playfairTable[5][5]) {
    string decryptedText;
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        int row1, col1, row2, col2;
        findPosition(playfairTable, ciphertext[i], row1, col1);
        findPosition(playfairTable, ciphertext[i + 1], row2, col2);

        // Jika huruf-huruf berada di baris yang sama, ganti dengan huruf di sebelah kiri
        if (row1 == row2) {
            decryptedText.push_back(playfairTable[row1][(col1 + 4) % 5]);
            decryptedText.push_back(playfairTable[row2][(col2 + 4) % 5]);
        }
        // Jika huruf-huruf berada di kolom yang sama, ganti dengan huruf di atasnya
        else if (col1 == col2) {
            decryptedText.push_back(playfairTable[(row1 + 4) % 5][col1]);
            decryptedText.push_back(playfairTable[(row2 + 4) % 5][col2]);
        }
        // Jika huruf-huruf membentuk persegi, ganti dengan huruf yang membentuk persegi lain di sampingnya
        else {
            decryptedText.push_back(playfairTable[row1][col2]);
            decryptedText.push_back(playfairTable[row2][col1]);
        }
    }
    return decryptedText;
}

int main() {
    string key;
    cout << "Masukkan kunci (tanpa spasi, huruf kapital): ";
    getline(cin, key);

    // Inisialisasi tabel Playfair
    char playfairTable[5][5];
    createPlayfairTable(key, playfairTable);

    string plaintext;
    cout << "Masukkan plaintext (huruf kapital): ";
    getline(cin, plaintext);

    // Enkripsi plaintext
    string ciphertext = playfairEncrypt(plaintext, playfairTable);
    cout << "Teks terenkripsi: " << ciphertext << endl;

    // Dekripsi ciphertext
    string decryptedText = playfairDecrypt(ciphertext, playfairTable);
    cout << "Teks terdekripsi: " << decryptedText << endl;

    return 0;
}
