#include "231511066/akun.h"
#include "231511083/listpassword.h"
#include "231511092/test.h"

int main()
{
    int choice, countLine;
    string loggedInUser, loginResult;
    listPassword list[MAX_PASS];

    do
    {
        cout << ".-----------------------------------." << endl;
        cout << "|     Aplikasi Password Manager     |" << endl;
        cout << "'-----------------------------------'" << endl;
        cout << "| 1. Buat Akun                      |" << endl;
        cout << "| 2. Masuk                          |" << endl;
        cout << "| 3. Ganti Password                 |" << endl;
        cout << "| 4. Keluar Aplikasi                |" << endl;
        cout << "| 5. Bantuan                        |" << endl;
        cout << "'-----------------------------------'" << endl;
        cout << "| Masukan Pilihan Anda : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << endl;
                cout << ".-----------------------------------." << endl;
                cout << "|             Membuat Akun          |" << endl;
                cout << "'-----------------------------------'" << endl;
                Register();

                break;
            case 2:
                cout << endl;
                cout << ".-----------------------------------." << endl;
                cout << "|          Masuk Applikasi          |" << endl;
                cout << "'-----------------------------------'" << endl;
                loggedInUser = Login();
                if (loggedInUser == "FAILED") {
                break;
                }
                countLine = readListPassword(list, loggedInUser);
                menuPassword(list, countLine, loggedInUser);
                break;
            case 3:
                cout << ".-----------------------------------." << endl;
                cout << "|          Ganti Password           |" << endl;
                cout << "'-----------------------------------'" << endl;
                gantiPassword();
                break;
            case 4:
                cout << "| Keluar..." << endl;
                break;
            case 5:
                helpLogin();
                break;
            default:
                cout << "Tolong Masukan Pilihan Yang Benar\n";
        }
    } while (choice != 4);

    return 0;
}
