#include "akun.h"


int main()
{
    int choice;
    string loggedInUser;

    do
    {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Ganti Password\n"; // Opsi baru untuk membaca file user
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                Register();
                break;
            case 2:
                loggedInUser = Login(); // Menyimpan username yang berhasil login
                break;
            case 3:
                gantiPassword();
            break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            // case 5:
            //     if (!loggedInUser.empty()) // Memastikan user telah login
            //     {
            //         // Fungsi untuk membaca file berdasarkan loggedInUser
            //         ReadUserFile(loggedInUser);
            //     }
            //     else
            //     {
            //         cout << "Silakan login terlebih dahulu.\n";
            //     }
            //     break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

