#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
#define MAX_PASS 100
#define STRUKTUR 30

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

    string fileName = (user + ".txt");
    ifstream inFile(fileName, ios::binary);
    if (inFile.fail())
    {
        cout << "User belum menambahkan password\n";
        return 0;
    }
    
    int count_password = 0;
    string line;
    while (getline(inFile, line)) {
        // Membagi setiap baris menjadi token-token menggunakan stringstream
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ';')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 4) {
            // Jika tidak ada 4 token dalam satu baris, lewati baris tersebut
            continue;
        }
        // Mengisi nilai struct dengan token-token yang sesuai
        list[count_password].nama = tokens[0];
        list[count_password].username = tokens[1];
        list[count_password].password = tokens[2];
        list[count_password].note = tokens[3];
        count_password++;
    }
    // while (inFile >> list[count_password].nama >> list[count_password].username >> list[count_password].password >> list[count_password].note) {
    //     count_password++;
    // }
    inFile.close();
    return count_password;
} 

void printListPassword (listPassword *list, int count_password) {
    int i;
    // for (i = 0; i < 100; i++)
    // {
    //     cout << "=";
    // }
    cout << endl;
    i = 0;
    while (i < count_password)
    {
        cout << "Nama = " << list[i].nama << endl;
        cout << "Username = " << list[i].username << endl;
        cout << "Password = " << list[i].password << endl;
        cout << "Note = " << list[i].note << "\n\n";
        i++;
    }
}

void menuPassword (listPassword *list, int count_password) {
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
            printf("Anda memilih Tambah Password\n");
            break;
        case 2:
            printf("Anda memilih Ubah Password\n");
            break;
        case 3:
            printf("Anda memilih Hapus Password\n");
            break;
        case 4:
            printf("Anda memilih Buka List Password\n");
            printListPassword(list, count_password);
            break;
        default:
            printf("Pilihan tidak valid\n");
    }
}

// void menuList (listPassword *list, int count_password) {
//     cout << "\n";
//     cout << "\n====================\n";
//     cout << "1. Tambah Password\n";
//     cout << "2. Ubah Password\n";

//     int menu;
//     cout << "Pilih hal yang ingin anda lakukan : ";
//     cin >> menu;

//     switch(menu) {
//         case 1:
//             printf("Anda memilih Tambah Password\n");
//             break;
//         case 2:
//             printf("Anda memilih Ubah Password\n");
//             break;
//         case 3:
//             printf("Anda memilih Hapus Password\n");
//             break;
//         case 4:
//             printf("Anda memilih Buka List Password\n");
//             printListPassword(list, count_password);
//         default:
//             printf("Pilihan tidak valid\n");
//     }
// }

int sorting (listPassword *list, int count_password) {
    listPassword temp;
    bool swapped;
    for (int i = 0; i < count_password - 1; i++)
    {
        // cout << "Masuk";
        swapped = false;
        for (int j = 0; j < count_password - i - 1; j++)
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
    int count_password = readListPassword(list);
    menuPassword(list, count_password);
    // printListPassword(list, count_password);
    // sorting(list, count_password);
    // printListPassword(list, count_password);
    return 0;
}