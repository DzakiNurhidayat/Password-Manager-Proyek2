#include "test.h"

using namespace std;

bool hasSymbol(char c) {
  return !isalnum(c) && !isspace(c);
}

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

int main()
{
	// MODUL MORE INFO
	int help, no;

	cout << "Help/More info?" << endl;
	cout << "Ketik: 1 untuk Ya / 2 untuk Tidak" << endl;
	cout <<endl;
	cin >> help;
	cout << endl;
	
	if (help == 1) 
	{
    	cout << "1. Lupa password?" << endl;
    	cout << "2. Ingin mengganti password?" << endl;
    	cout<<endl;
    	cin >> no;

    	cout << endl;

    
    	switch (no) 
		{
    		case 1:
        		cout << "Pemulihan password hanya boleh satu kata, dan jawabannya harus sama " << endl;
        		cout << "dengan jawaban yang Anda masukkan saat membuat akun." << endl;
        		break;
      		case 2:
        		cout << "Untuk mengganti password, Anda harus memasukkan username terlebih dahulu." << endl;
        		cout << "Anda akan ditanya pertanyaan pemulihan password."<< endl ;
        		cout << "Pastikan jawaban Anda sama dengan yang Anda masukkan saat membuat akun " << endl;
        		cout << "(huruf besar dan kecil dibedakan)" << endl;
        		cout << "Disarankan untuk memasukkan jawaban dalam huruf kecil " << endl;
        		cout << "saat membuat akun untuk menghindari masalah case-sensitivity." <<endl;
				break;
      		default:
        	cout << "Pilihan tidak valid" << endl;
    	}
  	} 
	else if (help == 2) 
	{
    	return 0;
  	} 
	else 
	{
		cout << "Pilihan tidak valid" << endl;
  	}
  	
  	// MODUL TEST PASSWORD
  	string password;
	bool valid = false;
	int strength;

	while (!valid) 
	{	
    	cout << endl << "Masukkan Password (minimal 6 karakter): ";
    	cin >> password;
		
		if (password.length() < 6)
		{
    		cout << "Password harus minimal 6 karakter!" << endl;
    		continue;
    	}
		
		valid = true;
	    bool hasAnySymbol = false;
    	bool hasLetter = false;
    	bool hasNumber = false;

	    for (int i = 0; i < password.length(); i++) 
		{
    		if (hasSymbol(password[i])) 
			{
    			hasAnySymbol = true;
			} 
			else if (isalpha(password[i])) 
			{
        		hasLetter = true;
    		} 
			else if (isdigit(password[i])) 
			{
        		hasNumber = true;
        	}
    	}

	    if (hasAnySymbol && hasLetter && hasNumber) 
		{
    		strength = 3;
    	} 
		else if (hasLetter && hasNumber) 
		{
			strength = 2;
    	} 
		else if (hasLetter || hasNumber) 
		{
			strength = 1;
    	} 
		else 
		{
    		strength = 0;
    	}
	}

  	cout << "Password: " << password << endl;
  	cout << "Level kekuatan: " << strength << endl;
  	
  	// MODUL UNIK PASSWORD
	string passwordInput;
	vector<string> listPassword;
	int countSama;
	bool fileBaru = false;

	cout << "Masukkan password: ";
	cin >> passwordInput;

	ifstream filePassword("password.dat");
	if (!filePassword.is_open()) 
	{
    	fileBaru = true;
	}

	while (getline(filePassword, passwordInput)) 
	{
    	listPassword.push_back(passwordInput);
	}

	filePassword.close();

	listPassword.push_back(passwordInput);


  ofstream fileOutput("password.dat");
 for (int i = 0; i < listPassword.size(); i++) {
  fileOutput << listPassword[i] << endl;
}

  fileOutput.close();


  countSama = 0;


  for (int i = 0; i < listPassword.size(); i++) 
  {
 
    if (listPassword[i] == passwordInput) {

      countSama++;
    }
  }


  cout << "Jumlah password yang sama dengan password yang Anda masukkan: " << countSama << endl;
  

//MODUL UNIK PASSWORD
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
  countSama = 1;

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
