#include "231511066/akun.h"
#include "231511083/listpassword.h"

int main()
{
    int choice, countLine;
    string loggedInUser;
    listPassword list[MAX_PASS];

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
                cout << "Registering..." << endl;
                Register();
                cout << "Registration complete." << endl;
                break;
            case 2:
                cout << "Logging in..." << endl;
                loggedInUser = Login(); // Menyimpan username yang berhasil login
                cout << "Login successful." << endl;
                cout << "Reading list password..." << endl;
                countLine = readListPassword(list, loggedInUser);
                cout << "Menu password..." << endl;
                menuPassword(list, countLine, loggedInUser);
                break;
            case 3:
                cout << "Changing password..." << endl;
                gantiPassword();
                cout << "Password changed." << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
