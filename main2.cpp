#include "231511066/akun.h"
#include "231511083/listpassword.h"
#include "231511079/kelola.h"
#include "231511092/test.h"

int main()
{
    int choice, countLine, i;
    string registInUser, loggedInUser, loginResult, isLoginSuccess, kondisi;
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
            i = 0;
            do
            {
                registInUser = Register();
                if (registInUser == "kembali"){
                    break;
                }
                if (!registInUser.empty())
                {
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|              Akun Berhasil Dibuat             |" << endl;
                    cout << "'-----------------------------------------------'" << endl
                         << endl;
                    break;
                }
                else
                {
                    cout << "| Username Telah Digunakan, Harap Gunakan Username Lain |" << endl;
                    cout << "|" << endl;
                    cout << ".-------------------------------------------------------." << endl;
                }
                if (i == 2)
                {
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|     Register gagal setelah 3 kali percobaan.  |" << endl;
                    cout << "|            Silakan coba lagi nanti.           |" << endl;
                    cout << "'-----------------------------------------------'" << endl
                         << endl;
                }
                i++;
            } while (i < 3);
            break;
        case 2:
            i = 0;
            cout << endl;
            cout << ".-----------------------------------." << endl;
            cout << "|          Login Applikasi          |" << endl;
            cout << "'-----------------------------------'" << endl;
            do
            {
                loggedInUser = Login();
                if (!loggedInUser.empty())
                {
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|              Berhasil Login                   |" << endl;
                    cout << "'-----------------------------------------------'" << endl
                         << endl;
                    countLine = readListPassword(list, loggedInUser);
                    int menu, pilihan;
                    do
                    {
                        cout << endl;
                        cout << ".-----------------------------------------------." << endl;
                        cout << "|           Menu Utama Password Manager         |" << endl;
                        cout << "'-----------------------------------------------'" << endl;
                        cout << "| 1. Tambah Password                            |" << endl;
                        cout << "| 2. Ubah Password                              |" << endl;
                        cout << "| 3. Hapus Password                             |" << endl;
                        cout << "| 4. Buka List Password                         |" << endl;
                        cout << "| 5. Bantuan                                    |" << endl;
                        cout << "| 6. Keluar                                     |" << endl;
                        cout << "'-----------------------------------------------'" << endl;
                        cout << "| Pilih Hal Apa Yang Ingin Anda Lakukan : ";
                        cin >> menu;
                        switch (menu)
                        {
                        case 1:
                            cout << endl;
                            cout << ".-------------------------------------------." << endl;
                            cout << "|             Menu Tambah Password          |" << endl;
                            cout << "'-------------------------------------------'" << endl;
                            inputPassword(loggedInUser);
                            countLine = readListPassword(list, loggedInUser);
                            cout << ".-----------------------------------------------." << endl;
                            cout << "| Password Berhasil Ditambahkan Ke Dalam List   |" << endl;
                            cout << "'-----------------------------------------------'" << endl << endl;
                            break;
                        case 2:
                            cout << endl;
                            cout << ".-------------------------------------------." << endl;
                            cout << "|             Menu Ubah Password            |" << endl;
                            cout << "'-------------------------------------------'" << endl;
                            loadPasswordsFromFile(loggedInUser);
                            modifyPassword(list, loggedInUser, countLine);
                            countLine = readListPassword(list, loggedInUser);
                            // Manggil .h Jihan
                            break;
                        case 3:
                            cout << endl;
                            cout << ".-------------------------------------------." << endl;
                            cout << "|             Menu Hapus Password           |" << endl;
                            cout << "'-------------------------------------------'" << endl;
                            loadPasswordsFromFile(loggedInUser);
                            deletePassword(loggedInUser);
                            countLine = readListPassword(list, loggedInUser);
                            cout << ".-------------------------------------------------------." << endl;
                            cout << "|              Password Berhasil Dihapus                |" << endl;
                            cout << "'-------------------------------------------------------'" << endl;
                            // Manggil .h Jihan
                            break;
                        case 4:
                            if (countLine < 1)
                            {
                                cout << endl;
                                cout << ".-------------------------------------------." << endl;
                                cout << "|             List Kosong                   |" << endl;
                                cout << "'-------------------------------------------'" << endl;
                            }
                            else
                            {
                                cout << endl;
                                cout << ".-------------------------------------------." << endl;
                                cout << "|             List Password                 |" << endl;
                                cout << "'-------------------------------------------'" << endl
                                     << endl;
                                printListPassword(list, countLine);
                                int menu, sortBy;
                                string keyword;
                                do
                                {
                                    cout << "\n";
                                    cout << ".-----------------------------------." << endl;
                                    cout << "|              Fitur                |" << endl;
                                    cout << "'-----------------------------------'" << endl;
                                    cout << "| 1. Sorting                        |" << endl;
                                    cout << "| 2. Searching                      |" << endl;
                                    cout << "| 3. Keluar Menu List Password      |" << endl;
                                    // cout << "| 4. Keluar Aplikasi               |" << endl;
                                    cout << "'-----------------------------------'" << endl;
                                    cout << "| Pilih Hal Yang Ingin Anda Lakukan : ";
                                    cin >> menu;

                                    switch (menu)
                                    {
                                    case 1:
                                        cout << "| Ascending/Descending\n";
                                        cout << "| (1) Asc\n";
                                        cout << "| (2) Desc\n";
                                        cout << "| (3) Keluar Menu Sort\n";
                                        cout << "| Pilihan = ";
                                        cin >> sortBy;
                                        if (sortBy == 1 or sortBy == 2)
                                        {
                                            sorting(list, countLine, sortBy);
                                            printListPassword(list, countLine);
                                        }
                                        else if (sortBy == 3)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Gagal melakukan sorting, Tolong Masukkan Angka yang Tersedia\n";
                                        }
                                        break;
                                    case 2:
                                        cout << "| Masukkan Kata Kunci = ";
                                        cin >> keyword;
                                        searching(list, countLine, keyword);
                                        break;
                                    case 3:
                                        cout << "| Kembali ke Halaman Utama\n";
                                        break;
                                        ;
                                    default:
                                        cout << "| Pilihan tidak valid\n";
                                    }
                                } while (menu != 3);
                            }
                            break;

                        case 5:
                            helpIn();
                            break;
                        case 6:
                            cout << "| Logout" << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid\n";
                        }
                    } while (menu != 6);
                    break;
                }
                else
                {
                    cout << "|" << endl;
                    cout << "| *Username / Password Salah !" << (i + 1) << "x |" << endl;
                    cout << ".-------------------------------------------------." << endl
                         << "|" << endl;
                }
                if (i == 2)
                {
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|     Login gagal setelah 3 kali percobaan.     |" << endl;
                    cout << "|            Silakan coba lagi nanti.           |" << endl;
                    cout << "'-----------------------------------------------'" << endl
                         << endl;
                }
                i++;
            } while (i < 3);
            break;
        case 3:
            cout << ".-----------------------------------." << endl;
            cout << "|          Ganti Password           |" << endl;
            cout << "'-----------------------------------'" << endl;
            gantiPassword();
            cout << ".-----------------------------------------------." << endl;
            cout << "|             Ganti Password Berhasil           |" << endl;
            cout << "'-----------------------------------------------'" << endl
                 << endl;
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