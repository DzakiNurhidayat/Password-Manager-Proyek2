#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() 
{
  string passwordInput;
  vector<string> listPassword;
  int countSama;
  bool fileBaru = false;

  cout << "Masukkan password: ";
  cin >> passwordInput;

  // Membuka file yang berisi list password
  ifstream filePassword("password.dat");
  if (!filePassword.is_open()) {
    // File tidak ada, buat file baru
    fileBaru = true;
  }

  // Membaca setiap password dari file dan menambahkannya ke list
  while (getline(filePassword, passwordInput)) {
    listPassword.push_back(passwordInput);
  }

  // Menutup file
  filePassword.close();

  // Menambahkan password baru ke list
  listPassword.push_back(passwordInput);

  // Menulis list password ke file
  ofstream fileOutput("password.dat");
 for (int i = 0; i < listPassword.size(); i++) {
  fileOutput << listPassword[i] << endl;
}

  // Menutup file
  fileOutput.close();

  // Menginisialisasi variabel countSama
  countSama = 0;

  // Melakukan perulangan untuk setiap password dalam list
  for (int i = 0; i < listPassword.size(); i++) 
  {
    // Membandingkan password dengan password yang diinputkan user
    if (listPassword[i] == passwordInput) {
      // Meningkatkan nilai countSama
      countSama++;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah password yang sama dengan password yang Anda masukkan: " << countSama << endl;

  return 0;
}

