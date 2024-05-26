#include "231511066/akun.h"
// #include "231511083/listpassword.h"
#include "treeListPassword.h"
// #include "231511079/kelola.h"
#include "231511092/test.h"

int main()
{
    int choice, countLine, i, namaWidth, userWidth, passWidth, noteWidth, nomor;
    bool sort = false;
    bool found = false;
    char temp;
    string registInUser, loggedInUser, loginResult, isLoginSuccess, kondisi;
    string nama, username, password, note, dateCreated, keyword;
    listPassword *root;
    string space = "    "; // nilai pembantu ketika niali search tidak ada
    namaWidth = 2;
    userWidth = 2;
    passWidth = 2;
    noteWidth = 2;
    nomor = 1;
    do
    {
        // system("cls");
        root = NULL;
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
                        system("cls");
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
                                cin.ignore();
                                cout << "| Masukkan Nama : ";
                                getline(cin, nama);
                                cout << "| Masukkan Username : ";
                                getline(cin, username);
                                cout << "| Masukkan Password : ";
                                getline(cin, password);
                                cout << "| Masukkan Catatan : ";
                                getline(cin, note);
                                entry_data_to_tree(&root, nama, username, password, note, dateCreated);
                                cout << ".-----------------------------------------------." << endl;
                                cout << "| Password Berhasil Ditambahkan Ke Dalam List   |" << endl;
                                cout << "'-----------------------------------------------'" << endl << endl;
                                break;
                            case 2:
                                cout << endl;
                                cout << ".-------------------------------------------." << endl;
                                cout << "|             Menu Ubah Password            |" << endl;
                                cout << "'-------------------------------------------'" << endl;

                                cout << "|          ---- Daftar Password ----        |" << endl;
                                cout << "|-------------------------------------------|" << endl;
                                print_nama_tree(root, nomor);
                                nomor = 1;
                                cout << endl << "Masukkan Nama yang akan di edit (Ketikkan Namanya) = ";
                                cin.ignore();
                                getline(cin, nama);
                                edit_data_from_tree(root, nama, loggedInUser);
                                break;
                            case 3:
                                cout << endl;
                                cout << ".-------------------------------------------." << endl;
                                cout << "|             Menu Hapus Password           |" << endl;
                                cout << "'-------------------------------------------'" << endl;
                                print_nama_tree(root, nomor);
                                nomor = 1;
                                cout << endl << "Masukkan Nama yang akan di edit (Ketikkan Namanya) = ";
                                cin.ignore();
                                getline(cin, nama);
                                delete_data_from_tree(root, nama);
                                cout << ".-------------------------------------------------------." << endl;
                                cout << "|              Password Berhasil Dihapus                |" << endl;
                                cout << "'-------------------------------------------------------'" << endl;
                                break;
                            case 4:
                                cout << endl;
                                cout << "       .-------------------------------------------." << endl;
                                cout << "       |             List Password                 |" << endl;
                                cout << "       '-------------------------------------------'" << endl
                                        << endl;
                                find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                print_table(namaWidth, userWidth, passWidth, noteWidth);
                                print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth);
                                nomor = 1; 
                                int menu, sortBy;
                                do
                                {
                                    cout << "\n";
                                    cout << ".-----------------------------------." << endl;
                                    cout << "|              Fitur                |" << endl;
                                    cout << "'-----------------------------------'" << endl;
                                    if (sort == false)
                                    {
                                        cout << "| 1. Sorting Descended              |" << endl;
                                    }
                                    else {
                                        cout << "| 1. Sorting Ascended               |" << endl;
                                    }                    
                                    cout << "| 2. Searching                      |" << endl;
                                    cout << "| 3. Keluar Menu List Password      |" << endl;
                                    cout << "'-----------------------------------'" << endl;
                                    cout << "| Pilih Hal Yang Ingin Anda Lakukan : ";
                                    cin >> menu;

                                    switch (menu)
                                    {
                                    case 1:
                                        if (sort == false)
                                        {
                                            cout << endl;
                                            find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                            print_table(namaWidth, userWidth, passWidth, noteWidth);
                                            print_tree_reverse(root, nomor, namaWidth, userWidth, passWidth, noteWidth);
                                            nomor = 1;
                                            sort = true;
                                        }
                                        else if (sort == true)
                                        {
                                            cout << endl;
                                            find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                            print_table(namaWidth, userWidth, passWidth, noteWidth);
                                            print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth);
                                            nomor = 1;
                                            sort = false;
                                        }
                                        break;
                                    case 2:
                                        cin.ignore();
                                        cout << "| Masukkan Kata Kunci = ";
                                        getline(cin, keyword);
                                        cout << endl;
                                        find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
                                        print_table(namaWidth, userWidth, passWidth, noteWidth);
                                        found = searching(root, keyword, namaWidth, userWidth, passWidth, noteWidth);
                                        if (found == false)
                                        {
                                            cout << setw(0) << setfill(' ') << setw(10) << left << space << "Nilai yang Dicari Tidak Ada";
                                        }
                                        
                                        nomor = 1;
                                        break;
                                    case 3:
                                        cout << "| Kembali ke Halaman Utama\n";
                                        break;
                                        ;
                                    default:
                                        cout << "| Pilihan tidak valid\n";
                                    }
                                } while (menu != 3);

                                break;

                            case 5:
                                helpIn();
                                break;
                            case 6:
                                cout << "| Logout" << endl;
                                delete_list_infile(loggedInUser);
                                entry_data_to_file(root, loggedInUser);
                                dealokasi_tree(root);
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
