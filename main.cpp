#include "231511066/akun.h"
// #include "231511083/listpassword.h"
#include "treeListPassword.h"
// #include "231511079/kelola.h"
#include "231511092/test.h"

int main()
{
    int choice, countLine, i, namaWidth, userWidth, passWidth, noteWidth, nomor;
    bool sort = false;
    char temp;
    string registInUser, loggedInUser, loginResult, isLoginSuccess, kondisi;
    string nama, username, password, note, dateCreated;
    listPassword *root;
    namaWidth = 4;
    userWidth = 4;
    passWidth = 4;
    noteWidth = 4;
    nomor = 1;
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
            cout << "|          Login Aplikasi          |" << endl;
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
                    root = load_data_from_file(root, loggedInUser);
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
                            cout << "| Masukkan Nama : ";
                            getline(cin, nama);
                            cout << "| Masukkan Username : ";
                            getline(cin, username);
                            cout << "| Masukkan Password : ";
                            getline(cin, password);
                            cout << "| Masukkan Catatan : ";
                            getline(cin, note);
                            entry_data_to_tree(root, nama, username, password, note, dateCreated);
                            cout << ".-----------------------------------------------." << endl;
                            cout << "| Password Berhasil Ditambahkan Ke Dalam List   |" << endl;
                            cout << "'-----------------------------------------------'" << endl << endl;
                            break;
                        case 2:
                            cout << endl;
                            cout << ".-------------------------------------------." << endl;
                            cout << "|             Menu Ubah Password            |" << endl;
                            cout << "'-------------------------------------------'" << endl;

                            // edit_data_from_tree(root, edit);
                            // countLine = readListPassword(list, loggedInUser);
                            // Manggil .h Jihan
                            break;
                        case 3:
                            cout << endl;
                            cout << ".-------------------------------------------." << endl;
                            cout << "|             Menu Hapus Password           |" << endl;
                            cout << "'-------------------------------------------'" << endl;
                            
                            // delete_data_from_tree(root, hapus);
                            // deletePassword(loggedInUser);
                            // countLine = readListPassword(list, loggedInUser);
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
                                find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                print_table(namaWidth, userWidth, passWidth, noteWidth);
                                print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
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
                                        if (sort == false)
                                        {
                                            cout << "Print Descended (Y or N)" << endl;
                                            cin >> temp;
                                            if (temp == 'Y')
                                            {
                                                find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                                print_table(namaWidth, userWidth, passWidth, noteWidth);
                                                print_tree_reverse(root, nomor, namaWidth, userWidth, passWidth, noteWidth);
                                                sort = true;
                                            }
                                            else
                                            {
                                                return 0;
                                            }
                                        }
                                        else if (sort == true)
                                        {
                                            cout << "Print Ascended (Y or N)" << endl;
                                            cin >> temp;
                                            if (temp == 'Y')
                                            {
                                                find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                                print_table(namaWidth, userWidth, passWidth, noteWidth);
                                                print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth);
                                                sort = false;
                                            }
                                            else
                                            {
                                                return 0;
                                            }
                                        }
                                        break;
                                    case 2:
                                        cout << "| Masukkan Kata Kunci = ";
                                        getline(cin, keyword);
                                        find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                        print_table(namaWidth, userWidth, passWidth, noteWidth);
                                        searching(root, keyword, namaWidth, userWidth, passWidth, noteWidth);
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
