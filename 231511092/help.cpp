#include <iostream>

using namespace std;

int main() {
  int help, no;

  // Menampilkan menu bantuan
  cout << "Help/More info?" << endl;
  cout << "Ketik: 1 untuk Ya / 2 untuk Tidak" << endl;
  cout <<endl;
  cin >> help;
  cout << endl;

  // Memproses pilihan bantuan
  if (help == 1) {
    // Menampilkan daftar pilihan
    cout << "1. Bagaimana cara melihat list password?" << endl;
    cout << "2. Ingin merubah password?" << endl;
    cout << "3. Ingin menghapus password?" << endl;
    cout<<endl;
    cin >> no;

    cout << endl;

    // Menampilkan informasi berdasarkan pilihan
    switch (no) {
      case 1:
        cout << "Ketik menu saat awal masuk aplikasi dan input nomor 3 saat memilih password library" << endl;
        break;
      case 2:
        cout << "Pilih menu untuk merubah password" << endl;
        break;
      case 3:
        cout << "Pilih menu untuk menghapus password" << endl;
        break;
      default:
        cout << "Pilihan tidak valid" << endl;
    }
  } else if (help == 2) {
    // Keluar dari program
    return 0;
  } else {
    // Menampilkan pesan error
    cout << "Pilihan tidak valid" << endl;
  }

  return 0;
}
