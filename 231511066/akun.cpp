#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // Untuk exit()
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

        cout << "Masukan Username: ";
        cin >> user.username;

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
            cout << "Masukan Password: ";
            cin >> user.password;
            cout << "Buat Pertanyaan Untuk Lupa Password: ";
            cin >> user.pertanyaan;
            cout << "Jawaban Untuk Lupa Password: ";
            cin >> user.jawaban;

            ofstream outputFile("user.txt", ios::binary | ios::app);
            if (!outputFile)
            {
                cerr << "Failed to open file for writing.\n";
                return;
            }

            fp.write(reinterpret_cast<const char *>(&user), sizeof(User));
            fp.close();
            cout << "Registration successful!\n";

            // MEMBUAT FILE USER
            string fileName = string(user.username) + ".txt";
            ofstream outFile(fileName.c_str(), ios::out | ios::app | ios::binary);

            if (!outFile)
            {
                cout << "User belum menambahkan password\n";
            }
            else
            {
                outFile << "Username: " << user.username << "\n Password: " << user.password << "\n Pertanyaan: " << user.pertanyaan << "\nPassword: " << user.jawaban << endl;
                outFile.close();
            }
            break;
        }
        else
        {
            cout << "Username Telah Digunakan, Harap Gunakan Username Lain \n"; 
            cout << "Masa Percobaan " << (i + 1) << "x\n";
        }
        i++;
    } while (i < 3);
}

void Login()
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

        cout << "masukan username: ";
        cin >> inputUser.username;
        cout << "masukan password: ";
        cin >> inputUser.password;

        bool isLoginSuccess = false;
        while (fp.read(reinterpret_cast<char *>(&user), sizeof(User)))
        {
            if (strcmp(user.username, inputUser.username) == 0 && strcmp(user.password, inputUser.password) == 0)
            {
                cout << "Login successful!\n";
                isLoginSuccess = true;
                return;
            }
        }

        if (isLoginSuccess == false)
        {
            cout << "===========================\n";
            cout << "Username / Password Salah! (" << (i + 1) << "x)\n";
            cout << "=============================\n";
        }

        i = i + 1;   
    } while (i < 3); 

    if (i == 3)
    {

        cout << "Login gagal setelah 3 kali percobaan. Silakan coba lagi nanti.\n";
    }
}

void lupaPassword()
{
}

int main()
{
    int choice;

    do
    {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Register();
            break;
        case 2:
            Login();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
