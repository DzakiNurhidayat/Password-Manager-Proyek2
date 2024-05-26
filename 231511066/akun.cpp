#ifndef AKUN_H
#define AKUN_H

#include "../231511092/test.h"

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

string Register()
{
    User user;
    string input, userPassword;
    int length;

    int i;
    i = 0;
    ofstream fp("user.txt", ios::out | ios::app | ios::binary);
    if (!fp)
    {
        perror("Error opening file");
        exit(1);
    }

    cout << "| *Ketik Kembali Untuk Keluar Dari Registrasi ";
    cout << endl
         << "| Masukan Username : ";
    cin >> user.username;
    if (strcmp(user.username, "kembali") == 0)
    {
        return "kembali";
    }

    ifstream inputFile("user.txt", ios::binary);
    if (!inputFile)
    {
        cerr << "Failed to open file for reading.\n";
        return "";
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
        }
    }

    if (isLoginSuccess == false)
    {
        do
        {
            inputFile.close();
            cout << "| Masukan Password : ";
            cin >> user.password;
            userPassword = user.password;
            length = userPassword.length();
            if (length < 6)
            {
                cout << "* Password harus minimal 6 karakter!" << endl;
            }
        } while (length < 6);
        checkPasswordStrength(userPassword);
        cout << "| Buat Pertanyaan Untuk Lupa Password : ";
        cin >> user.pertanyaan;
        cout << "| Jawaban Untuk Pertanyaan Lupa Password : ";
        cin >> user.jawaban;

        ofstream outputFile("user.txt", ios::binary | ios::app);
        if (!outputFile)
        {
            cout << "Gagal Membuka File Untuk Membacanya\n";
            return "";
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

        return "true";
    }

    return "";
}

string Login()
{
    User user, inputUser;

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

    while (fp.read(reinterpret_cast<char *>(&user), sizeof(User)))
    {
        if (strcmp(user.username, inputUser.username) == 0 && strcmp(user.password, inputUser.password) == 0)
        {
            fp.close();
            string pengguna = user.username;
            return pengguna; // Mengembalikan username
        }
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
    checkPasswordStrength(user.password);

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

#endif