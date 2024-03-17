#ifndef TEST_H
#define TEST_H


#include <iostream>

using namespace std;

void helpLogin() {
  int help, no;

  // Menampilkan menu bantuan
        cout << endl;
        cout << ".-----------------------------------." << endl;
        cout << "|         Help / More Info?         |" << endl;
        cout << "'-----------------------------------'" << endl;
        cout << "| Ketik: (1 untuk Ya) / (2 untuk Tidak) " << endl;
        cout << "| " ;
  cin >> help;


  // Memproses pilihan bantuan
  if (help == 1) {
    // Menampilkan daftar pilihan
        cout << "'----------------------------------------------'" << endl;
        cout << "| 1. Ingin Membuat Akun?                       |" << endl;
        cout << "| 2. Ingin Masuk Ke Dalam Aplikasi?            |" << endl;
        cout << "| 3. Lupa Password & Ingin Menggantinya?       |" << endl;
        cout << "'----------------------------------------------'" << endl;
    cout << "|" ;
    cin >> no;

    // Menampilkan informasi berdasarkan pilihan
    switch (no) {
      case 1:
        cout << endl << "Saat Awal Masuk Aplikasi Inputkan Nomor 1 Terlebih Dahulu Untuk Masuk" << endl ;
        break;
      case 2:
        cout << endl << "Saat Awal Masuk Aplikasi Inputkan Nomor 2 Terlebih Dahulu Untuk Masuk" << endl ;
        break;
      case 3:
        cout << endl << "Pilih Menu Untuk Merubah Password Dengan Menginputkan Nomor 3" << endl ;
        break;
      default:
        cout << endl << "Pilihan tidak valid" << endl ;
    }
  } else if (help == 2) {
    // Keluar dari program
  } else {
    // Menampilkan pesan error
    cout << "Pilihan tidak valid" << endl;
  }
}

void helpIn() {
  int help, no;

  // Menampilkan menu bantuan
        cout << endl;
        cout << ".-----------------------------------." << endl;
        cout << "|         Help / More Info?         |" << endl;
        cout << "'-----------------------------------'" << endl;
        cout << "| Ketik: (1 untuk Ya) / (2 untuk Tidak) " << endl;
        cout << "|" ;
  cin >> help;


  // Memproses pilihan bantuan
  if (help == 1) {
    // Menampilkan daftar pilihan
        cout << "'----------------------------------------------'" << endl;
        cout << "| 1. Ingin Menambahkan Password Ke Dalam List? |" << endl;
        cout << "| 2. Ingin Mengubah Password Yang Telah Ada?   |" << endl;
        cout << "| 3. Ingin menghapus password?                 |" << endl;
        cout << "| 4. Bagaimana Cara Melihat List Password?     |" << endl;
        cout << "'----------------------------------------------'" << endl;
    cout << "|" ;
    cin >> no;

    // Menampilkan informasi berdasarkan pilihan
    switch (no) {
      case 1:
        cout << endl << "| Pilih Menu 1 Dengan Menginputkan Nomor 1" ;
        break;
      case 2:
        cout << endl << "| Apabila Sudah Ada Password Yang Disimpan, Anda Dapat Mengubahnya Dengan Menginputkan Nomor 2" ; 
        break;
      case 3:
        cout << endl << "| Untuk Menghapus Password Yanag Sudah Ada, Anda Bisa Menginputkan Nomor 3" ;
        break;
      case 4:
        cout << endl << "| Untuk Menampilkan List Password Anda Cukup Inputkan Nomor 4" ;
        break;
      default:
        cout << "| Pilihan tidak valid" << endl ;
    }
  } else if (help == 2) {
    // Keluar dari program
  } else {
    // Menampilkan pesan error
    cout << "Pilihan tidak valid" << endl;
  }
}
#endif
