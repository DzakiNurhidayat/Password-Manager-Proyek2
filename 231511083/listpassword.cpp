#include "listpassword.h"
#include "../231511079/kelola.h"

// Saat ini menggunakan Algoritma Bubblesort, algoritma sorting mungkin akan diganti
void sorting (listPassword *list, int countLine, int sortBy) {
    listPassword temp;
    bool swapped;   
    for (int i = 0; i < countLine - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < countLine - i - 1; j++)
        {
            if (sortBy == 1) /* Untuk Fitur Sorting Ascending */
            {
                if (list[j].nama > list[j+1].nama)
                {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                swapped = true;
                }
            }
            else if (sortBy == 2) /* Untuk Fitur Sorting Descending */
            {
                if (list[j].nama < list[j+1].nama)
                {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                swapped = true;
                }
            }
            else
            {
                cout << "Gagal melakukan sorting";
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void lowerCase(string &keyword) {
    for (char &c : keyword) {
        c = tolower(c);
    }
}

void searching(listPassword* list, int countLine, string keyword) {
    bool found;
    string lowerKeyword, lowerNama, lowerUsername, lowerPassword, lowerNote;
    found = false;
    lowerKeyword = keyword;
    lowerCase(lowerKeyword);

    for (int i = 0; i < countLine; i++) {
        // Variabel ini dibuat untuk menampung hasil konversi lowercase
        lowerNama = list[i].nama;
        lowerUsername = list[i].username;
        lowerPassword = list[i].password;
        lowerNote = list[i].note;
        lowerCase(lowerNama);
        lowerCase(lowerUsername);
        lowerCase(lowerPassword);
        lowerCase(lowerNote);

        if (lowerNama.find(lowerKeyword) != string::npos ||
            lowerUsername.find(lowerKeyword) != string::npos ||
            lowerPassword.find(lowerKeyword) != string::npos ||
            lowerNote.find(lowerKeyword) != string::npos) {

            found = true;
            cout << endl;
            cout << "Nama : " << list[i].nama << endl;
            cout << "Username : " << list[i].username << endl;
            cout << "Password : " << list[i].password << endl;
            cout << "Note : " << list[i].note << endl;
        }
    }
    if (found == false) {
        cout << "Data tidak ditemukan.\n";
    }
}


int readListPassword (listPassword *list, string loggedInUser){
    string fileName = (loggedInUser + ".txt"); // Akan dijadikan Modul Terpisah
    ifstream inFile(fileName, ios::binary);
    if (inFile.fail())
    {
        cout << "User belum menambahkan password\n"; 
        // return 0;
    }

    // Deklarasi Variabel Lokal
    int countLine, count_token;
    string line, token, tokens[4];
    countLine = 0;

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
        list[countLine].nama = tokens[0];
        list[countLine].username = tokens[1];
        list[countLine].password = tokens[2];
        list[countLine].note = tokens[3];
        countLine++;
    }
    inFile.close();
    return countLine;
} 

void printListPassword (listPassword *list, int countLine) {
    int i;

    cout << endl;
    i = 0;
    while (i < countLine)
    {
        cout << "Nama = " << list[i].nama << endl;
        cout << "Username = " << list[i].username << endl;
        cout << "Password = " << list[i].password << endl;
        cout << "Note = " << list[i].note << "\n\n";
        i++;
    }
}

void menuSorting (listPassword *list, int countLine) {
    int sortBy;
    cout << "Ascending/Descending\n";
    cout << "(1) Asc\n";
    cout << "(2) Desc\n";
    cout << "(3) Keluar Menu Sort\n";
    cout << "Pilihan = ";
    cin >> sortBy;
    if (sortBy == 1 or sortBy == 2)
    {
        sorting(list, countLine, sortBy);
        printListPassword(list, countLine);
    }
    else if (sortBy == 3)
    {
        return;
    }
    else
    {
        cout << "Gagal melakukan sorting, Tolong Masukkan Angka yang Tersedia\n";
        menuSorting(list, countLine);
    }
}

void menuList(listPassword *list, int countLine) {
    int menu, sortBy;
    string keyword;
    do {
        cout << "\n";
        cout << "(1) Sorting\n";
        cout << "(2) Searching\n";
        cout << "(3) Keluar Menu List Password\n";

        cout << "Pilih hal yang ingin anda lakukan : ";
        cin >> menu;

        switch (menu) {
            case 1:
                menuSorting(list, countLine);
                break;
            case 2:
                cout << "Masukkan Kata Kunci = ";
                cin >> keyword;
                searching(list, countLine, keyword);
                break;
            case 3:
                cout << "Kembali ke Halaman Utama\n";
                return;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (menu != 3);
}

    void menuPassword (listPassword *list, int countLine, string loggedInUser) {
        int menu;
        do
        {
            cout << "\nPassword Manager v1";
            cout << "\n====================\n";
            cout << "1. Tambah Password\n";
            cout << "2. Ubah Password\n";
            cout << "3. Hapus Password\n";
            cout << "4. Buka List Password \n";
            cout << "5. Keluar \n";
            cout << "====================\n";


            cout << "Pilih hal yang ingin anda lakukan : ";
            cin >> menu;

            switch(menu) {
                case 1:
                    cout << "Anda memilih Tambah Password\n";
                    inputPassword(loggedInUser);
                    countLine = readListPassword(list, loggedInUser);
                    break;
                case 2:
                    cout << "Anda memilih Ubah Password\n";
                    // Manggil .h Jihan
                    break;
                case 3:
                    cout << "Anda memilih Hapus Password\n";
                    // Manggil .h Jihan
                    break;
                case 4:
                    if (countLine < 1)
                    {
                        cout << "List Kosong\n";
                    }
                    else
                    {
                        cout << "Anda memilih Buka List Password\n";
                        printListPassword(list, countLine);
                        menuList(list, countLine);
                    }
                    break;
                case 5:
                    cout << "Logout\n";
                    break;
                default:
                    cout << "Pilihan tidak valid\n";
            }
        } while (menu!=5);
    }

// int main(){
//     listPassword list[MAX_PASS];
//     int countLine = readListPassword(list);
//     menuPassword(list, countLine);
//     return 0;
// }