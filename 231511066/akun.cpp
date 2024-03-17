#ifndef AKUN_H
#define AKUN_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct
{
    char username[30];
    char password[30];
    char pertanyaan[30];
    char jawaban[30];
} User;

void Register()
{
    User user;
    string input;
    int i;
    i = 0;
    do
    {
        ofstream fp("user.txt", ios::out | ios::app | ios::binary);
        if (!fp)
        {
            perror("Error opening file");
            exit(1);
        }

        cout << "| *Ketik Kembali Untuk Keluar Dari Registrasi ";
        cout  << endl << "| Masukan Username : " ;
        cin >> user.username;
        if (strcmp(user.username, "kembali") == 0) {
        return;
    }
        ifstream inputFile("user.txt", ios::binary);
        if (!inputFile)
        {
            cerr << "Failed to open file for reading.\n";
            return;
        }

        User existingUser;
        bool isLoginSuccess = false;
        while (inputFile.read(reinterpret_cast<char *>(&existingUser), sizeof(User)))
        {
            if (strcmp(existingUser.username, user.username) == 0)
            {
                inputFile.close();
                isLoginSuccess = true;
                break;
                ;
            }
        }

        if (isLoginSuccess == false)
        {
            inputFile.close();
            cout << "| Masukan Password : ";
            cin >> user.password;
            cout << "| Buat Pertanyaan Untuk Lupa Password : ";
            cin >> user.pertanyaan;
            cout << "| Jawaban Untuk Pertanyaan Lupa Password : ";
            cin >> user.jawaban;



            ofstream outputFile("user.txt", ios::binary | ios::app);
            if (!outputFile)
            {
                cerr << "Gagal Membuka File Untuk Membacanya\n";
                return;
            }

            fp.write(reinterpret_cast<const char *>(&user), sizeof(User));
            fp.close();

            // MEMBUAT FILE USER
            string fileName = string(user.username) + ".txt";
            ofstream outFile(fileName.c_str(), ios::out | ios::app | ios::binary);

            if (!outFile)
            {
                cout << "Pengguna Belum Menambahkan Password\n";
            }
            cout << ".-----------------------------------------------." << endl;
            cout << "|              Akun Berhasil Dibuat             |" << endl;
            cout << "'-----------------------------------------------'" << endl << endl;
            break;
        }
        else
        {
            cout << "| Username Telah Digunakan, Harap Gunakan Username Lain |" << endl;
            cout << "|" << endl;
            cout << ".-------------------------------------------------------." << endl;
            // cout << "Masa Percobaan " << (i + 1) << "x\n";
        }


        i++;

    if (i == 3)
    {
        cout << "| Buat Akun Gagal, Cobalagi \n";
    }

    } while (i < 3);
}

string Login()
{
    User user, inputUser;
    int i;
    i = 0;
    do
    {
        ifstream fp("user.txt", ios::binary);

        if (!fp)
        {
            perror("Error opening file");
            exit(1);
        }

        cout << "| Masukan Username : ";
        cin >> inputUser.username;
        cout << "| Masukan Password : ";
        cin >> inputUser.password;

        bool isLoginSuccess = false;
        while (fp.read(reinterpret_cast<char *>(&user), sizeof(User)))
        {
            if (strcmp(user.username, inputUser.username) == 0 && strcmp(user.password, inputUser.password) == 0)
            {
            cout << ".-----------------------------------------------." << endl;
            cout << "|              Berhasil Login                   |" << endl;
            cout << "'-----------------------------------------------'" << endl << endl;
                fp.close();
                string pengguna = user.username;
                return pengguna; // Mengembalikan username
            }
        }

        cout << "|" << endl;
        cout << "| *Username / Password Salah !"  << (i + 1) << "x |" << endl;
        cout << ".-------------------------------------------------." << endl << endl;
        i = i + 1;

    } while (i < 3);


    if (i == 3)
    {
        cout << "Login gagal setelah 3 kali percobaan. Silakan coba lagi nanti.\n";
        // return "FAILED";
        string pengguna = "FAILED";
        return pengguna; 
    }

    return ""; // Mengembalikan string kosong jika login gagal
}



void gantiPassword()
{
    char username[30];
    cout << "| Masukan Username : ";
    cin >> username;

    ifstream inputFile("user.txt", ios::binary);
    if (!inputFile)
    {
        cerr << "Gagal Membuka File Untuk Membacanya\n";
        return;
    }

    User user;
    bool userFound = false;
    while (inputFile.read(reinterpret_cast<char *>(&user), sizeof(User)))
    {
        if (strcmp(user.username, username) == 0)
        {
            userFound = true;
            break;
        }
    }
    inputFile.close();

    if (!userFound)
    {
        cout << "Username Tidak Ditemukan\n";
        return;
    }

    char jawaban[30];
    cout << "| Pertanyaan Lupa Password : " << user.pertanyaan << endl;
    cout << "| Masukan Jawaban : ";
    cin >> jawaban;

    if (strcmp(user.jawaban, jawaban) != 0)
    {
    cout << "| Jawaban Untuk Lupas Password Salah\n";
        return;
    }

    cout << "| Masukan Jawaban Baru : ";
    cin >> user.password;
    cout << "| Password Berhasil Diubah" << endl;

    // Update password user di file
    fstream file("user.txt", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cerr << "Failed to open file for updating.\n";
        return;
    }


    User tempUser;
    long pos = 0;
    while (file.read(reinterpret_cast<char *>(&tempUser), sizeof(User)))
    {
        if (strcmp(tempUser.username, username) == 0)
        {
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<const char *>(&user), sizeof(User));
            break;
        }
        pos += sizeof(User);
    }
    file.close();

}

// void ReadUserFile(const string& username)
// {
//     string fileName = username + ".txt"; // Membentuk nama file dari username
//     ifstream userFile(fileName.c_str(), ios::in);
//     if (!userFile)
//     {
//         cerr << "Tidak dapat membuka file untuk user: " << username << "\n";
//         return;
//     }

//     string line;
//     while (getline(userFile, line)) // Membaca setiap baris dari file
//     {
//         cout << line << endl;
//     }

//     userFile.close();
// }


#endif