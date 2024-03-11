#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#define MAX_PASS 100

struct listPassword {
    string nama;
    string username;
    string password;
    string note;
};


int readListPassword (listPassword *list){
    string user;
    cout << "Masukkan User = ";
    cin >> user; // Nanti diganti dengan user yang ada pada modul akun

    string fileName = (user + ".txt"); // AKan dijadikan Modul Terpisah
    ifstream inFile(fileName, ios::binary);
    if (inFile.fail())
    {
        cout << "User belum menambahkan password\n"; 
        // return 0;
    }

    // Deklarasi Variabel Lokal
    int count_line, count_token;
    string line, token, tokens[4];
    count_line = 0;

    // Mengambil Informasi dari setiap baris pada file
    while (getline(inFile, line)) {        
        stringstream check(line);
        count_token = 0;
        while (getline(check, token, ';')) {
            if (count_token < 4)
            {
                tokens[count_token] = token;
                count_token++;
            }
        }
        if (count_token != 4) {
            continue;
        }
        list[count_line].nama = tokens[0];
        list[count_line].username = tokens[1];
        list[count_line].password = tokens[2];
        list[count_line].note = tokens[3];
        count_line++;
    }
    inFile.close();
    return count_line;
} 

void printListPassword (listPassword *list, int count_line) {
    int i;
    cout << endl;
    i = 0;
    while (i < count_line)
    {
        // cout  << i+1 << ") " << list[i].nama << " " << list[i].username << " " << list[i].password << " " << list[i].note << endl;
        cout << "Nama = " << list[i].nama << endl;
        cout << "Username = " << list[i].username << endl;
        cout << "Password = " << list[i].password << endl;
        cout << "Note = " << list[i].note << "\n\n";
        i++;
    }
}

void menuList (listPassword *list) {
    cout << "\n";
    cout << "(1) Sorting\n";
    cout << "(2) Searching\n";
    cout << "(3) Exit List Password\n";

    int menu;
    cout << "Pilih hal yang ingin anda lakukan : ";
    cin >> menu;

    switch(menu) {
        case 1:
            cout << "Tentukan Parameter";
            break;
        case 2:
            cout << "Masukkan Kata Kunci = ";
            // cin >> amsdmds;
            break;
        case 3:
            printf("Kembali ke Halaman Utama\n");
            break;
        default:
            printf("Pilihan tidak valid\n");
    }
}

void menuPassword (listPassword *list, int count_line) {
    cout << "\nPassword Manager v1";
    cout << "\n====================\n";
    cout << "1. Tambah Password\n";
    cout << "2. Ubah Password\n";
    cout << "3. Hapus Password\n";
    cout << "4. Buka List Password \n";
    cout << "====================\n";

    int menu;
    cout << "Pilih hal yang ingin anda lakukan : ";
    cin >> menu;

    switch(menu) {
        case 1:
            cout << "Anda memilih Tambah Password\n";
            printf("Anda memilih Tambah Password\n");
            break;
        case 2:
            cout << "Anda memilih Ubah Password\n";
            break;
        case 3:
            cout << "Anda memilih Hapus Password\n";
            break;
        case 4:
            cout << "Anda memilih Buka List Password\n";
            printListPassword(list, count_line);
            menuList(list);
            break;
        default:
            printf("Pilihan tidak valid\n");
    }
}

// Algoritma sorting mungkin akan diganti
int sorting (listPassword *list, int count_line) {
    listPassword temp;
    bool swapped;
    for (int i = 0; i < count_line - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < count_line - i - 1; j++)
        {
            if (list[j].nama > list[j+1].nama)
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
    return 0;
}

int main(){
    listPassword list[MAX_PASS];
    int count_line = readListPassword(list);
    menuPassword(list, count_line);
    // printListPassword(list, count_line);
    // sorting(list, count_line);
    // printListPassword(list, count_line);
    return 0;
}