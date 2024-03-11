#include <stdio.h>
#include <string.h>
#include <ctype.h> // Library untuk fungsi tolower()

#define MAX_STRING_LENGTH 50
#define MAX_STRUCTS 100

// Definisi struktur
struct Informasi {
    char nama[MAX_STRING_LENGTH];
    char username[MAX_STRING_LENGTH];
    char password[MAX_STRING_LENGTH];
    char note[MAX_STRING_LENGTH];
};

// Fungsi untuk mengonversi string menjadi huruf kecil
void toLowerString(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}

// Fungsi untuk mencari kata kunci dalam informasi
void search(struct Informasi arr[], int size, const char* keyword) {
    // Mengonversi keyword menjadi huruf kecil
    char lowerKeyword[MAX_STRING_LENGTH];
    strcpy(lowerKeyword, keyword);
    toLowerString(lowerKeyword);

    printf("Hasil pencarian untuk kata kunci '%s':\n", keyword);
    for (int i = 0; i < size; ++i) {
        // Mengonversi setiap bagian informasi menjadi huruf kecil
        char lowerNama[MAX_STRING_LENGTH], lowerUsername[MAX_STRING_LENGTH], lowerPassword[MAX_STRING_LENGTH], lowerNote[MAX_STRING_LENGTH];
        strcpy(lowerNama, arr[i].nama);
        strcpy(lowerUsername, arr[i].username);
        strcpy(lowerPassword, arr[i].password);
        strcpy(lowerNote, arr[i].note);
        toLowerString(lowerNama);
        toLowerString(lowerUsername);
        toLowerString(lowerPassword);
        toLowerString(lowerNote);

        // Memeriksa jika kata kunci ada dalam setiap bagian informasi
        if (strstr(lowerNama, lowerKeyword) != NULL ||
            strstr(lowerUsername, lowerKeyword) != NULL ||
            strstr(lowerPassword, lowerKeyword) != NULL ||
            strstr(lowerNote, lowerKeyword) != NULL) {
            printf("Informasi ke-%d:\n", i + 1);
            printf("Nama: %s\n", arr[i].nama);
            printf("Username: %s\n", arr[i].username);
            printf("Password: %s\n", arr[i].password);
            printf("Note: %s\n", arr[i].note);
            printf("\n");
        }
    }
}

int main() {
    struct Informasi informasi[MAX_STRUCTS] = {
        {"Dzaki", "dzaki123", "dzakiPass", "Catatan tentang Dzaki"},
        {"Ahmad", "ahmad12", "ahmadPass", "Catatan tentang Ahmad"},
        {"Budi", "budi123", "AhmadPass", "Catatan tentang Budi"}
        // Masukkan lebih banyak informasi di sini jika diperlukan
    };

    int jumlahInformasi = 3; // Jumlah informasi yang ada dalam array

    // Melakukan pencarian untuk kata kunci "dzaki"
    search(informasi, jumlahInformasi, "ahmad");

    return 0;
}
