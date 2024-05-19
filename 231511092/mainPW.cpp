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
        cout << endl << "1. Input No.1 di menu utama saat anda baru memasuki aplikasi" << endl ;
        cout << endl << "2. Siapkan username dan password yang akan anda gunakan untuk keamanan akun" << endl ;
        cout << endl << "3. pastikan password yang akan anda gunakan memliki panjang karakter maksimal 18 dan minimal 6 karakter" << endl ;
        cout << endl;
        break;
      case 2:
        cout << endl << "1. Pilih No.2 di menu utama" << endl ;
        cout << endl << "2. Pastikan anda telah memiliki akun terlebih dahulu untuk login" << endl ;
        cout << endl << "3. Masukkan username dan password anda setelah anda masuk pada menu login" << endl ;
        cout << endl << "4. Jika anda belum memiliki akun kembali ke menu utama dan input No. 1" << endl ;
        cout << endl;
        break;
      case 3:
        cout << endl << "1. Pilih No.3 pada bagian Menu Untuk Merubah Password" << endl ;
        cout << endl << "2. Dengan catatan: harus memasukan username terlebih karena " << endl ;
        cout << endl << "3. Karena case sensitive anda akan disarankan untuk memasukkan jawaban di lower saat membuat akun" << endl ;
        cout << endl << "4. Pastikan password yang anda gunakan terdiri dari maksimal 18 karakter dan minimal 6 karakter" << endl ;
        cout << endl;
        break;
      default:
        cout << endl << "Pilihan tidak valid" << endl ;
        cout << endl;
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
        cout << "| 1. Apakah anda ingin menyimpan password baru?|" << endl;
        cout << "| 2. Ingin Mengubah Password Yang Telah Ada?   |" << endl;
        cout << "| 3. Ingin Mengubah Username Pada List Anda?   |" << endl;
        cout << "| 4. Apakah Anda Mau Mengubah Note nya Juga?   |" << endl;
        cout << "| 5. Kenapa? Nama Aplikasinya juga mau diubah? |" << endl;
        cout << "| 6. Ingin menghapus password?                 |" << endl;
        cout << "| 7. Bagaimana Cara Melihat List Password?     |" << endl;
        cout << "'----------------------------------------------'" << endl;
    cout << "|" ;
    cin >> no;

    // Menampilkan informasi berdasarkan pilihan
    switch (no) {
      case 1:
        cout << endl << "| Input No. 1 pada MENU aplikasi" ;
        cout << endl << "| Pastikan password yang akan anda simpan memiliki jumlah karakter maksimal 18 dan minimal 6" ;
        cout << endl << "| hanya bisa menginput password dalam bentuk huruf angka dan juga simbol" ;
        cout << endl << "| Saran: Agar lebih aman gunakan password yang terdiri dari gabungan antara Huruf Angka dan Simbol" ;
        cout << endl << "| " ;
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke menu aplikasi tekan ENTER" ;
        break;
      case 2:
        cout << endl << "| Input No. 2 pada MENU aplikasi jika anda ingin MENGUBAH password yang sudah di simpan. " ; 
        cout << endl << "| Pastikan anda sudah memiliki password yang sudah di input pada List" ;
        cout << endl << "| Setelah memilih no. 2 pada menu aplikasi anda akan diberikan list semua password yang pernah anda simpan" ;
        cout << endl << "| Kemudian anda akan diberikan 3 pilihan kembali untuk meng-Edit List" ;
        cout << endl << "| Pilih menu EDIT Password yaitu nomor 1 untuk mengubah password yang sudah anda simpan pada List" ;
        cout << endl << "| Selanjutnya pilih password pada list yang ingin anda UBAH " ;
        cout << endl << "| Sesuaikan nomor yang anda input dengan nomor password pada list yang ingin anda ubah " ; 
        cout << endl << "| Pastikan tidak ada yang salah lalu Simpan perubahan password anda" ;
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke menu aplikasi takan ENTER" ;
        break;
      case 3:
        cout << endl << "| Kembali ke MENU Aplikasi dan Input No. 2  jika anda ingin MENGUBAH Username dari password yang sudah di simpan pada list. " ; 
        cout << endl << "| Pastikan anda sudah memiliki Username dari password yang sudah di input pada List" ;
        cout << endl << "| Setelah memilih no. 2 pada menu aplikasi anda akan diberikan list semua Username dari password yang pernah anda simpan" ;
        cout << endl << "| Kemudian anda akan diberikan 3 pilihan kembali untuk meng-Edit List" ;
        cout << endl << "| Pilih menu EDIT USERNAME yaitu nomor 2 untuk mengubah username yang sudah anda simpan pada List" ;
        cout << endl << "| Selanjutnya pilih Username pada list yang ingin anda UBAH " ;
        cout << endl << "| Sesuaikan nomor yang anda input dengan nomor Username pada list yang ingin anda ubah " ; 
        cout << endl << "| Setelah Username di ubah jangan lupa untuk di simpan kembali dengan benar :)) " ;
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke MENU Aplikasi tekan ENTER" ;
        break;
      case 4:
        cout << endl << "| Untuk Mengubah Note anda harus kembali ke MENU Aplikasi dan mengInput-kan No. 2  " ; 
        cout << endl << "| Pastikan anda sudah memiliki password yang sudah di input pada List" ;
        cout << endl << "| Setelah memilih no. 2 pada menu aplikasi anda akan diberikan list semua password beserta note yang pernah anda simpan" ;
        cout << endl << "| Kemudian anda akan diberikan 3 pilihan kembali untuk meng-Edit List" ;
        cout << endl << "| Pilih menu EDIT NOTE yaitu nomor 3 untuk mengubah Note yang sudah anda simpan pada List" ;
        cout << endl << "| Selanjutnya pilih nomor dari Note password pada list yang ingin anda UBAH " ;
        cout << endl << "| Sesuaikan nomor yang anda input dengan nomor password pada list yang ingin anda ubah " ; 
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke menu aplikasi takan ENTER" ;
        break;
      case 5:
        cout << endl << "| Mohon maaf anda tidak bisa meng-Ubah NAMA Aplikasinya " ; 
        cout << endl << "| SARAN: Jika anda ingin tetap mengubah nama aplikasinya disarankan untuk menghapus passwordnya terlebih dahulu" ;
        cout << endl << "| kemudian anda meng-Inputkan kembali password baru dengan Benar dan Sesuai" ;
        cout << endl << "| Jika anda tidak tahu cara Menghapus Password maka Kembali ke MENU HELP dan Pilih nomor 6" ;
        cout << endl << "| Pada Menu Nomor 6 Help anda akan diberikan langkah-langkah untuk menghapus password anda" ;
        cout << endl << "| Terimakasih Kembali :))" ;
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke menu aplikasi tekan ENTER" ;
        break;
      case 6:
        cout << endl << "| Input No. 3 pada MENU aplikasi jika anda ingin MENGHAPUS password yang sudah di simpan. " ; 
        cout << endl << "| Pastikan anda sudah memiliki password yang sudah di input pada List" ;
        cout << endl << "| Setelah memilih no. 3 pada menu aplikasi anda akan diberikan list semua password yang pernah anda simpan" ;
        cout << endl << "| Selanjutnya pilih password pada list yang ingin anda HAPUS " ;
        cout << endl << "| Sesuaikan nomor yang anda input dengan nomor password pada list yang ingin anda HAPUS " ; 
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke menu aplikasi tekan ENTER" ;
        break;
      case 7:
        cout << endl << "| Untuk Menampilkan List Password Anda Cukup Inputkan No. 4 pada MENU Aplikasi" ;
        cout << endl << "| Semua pasword yang pernah anda simpan pada list akan ditampilkan" ;
        cout << endl << "| NOTE: Anda akan diberikan pilihan untuk mengurutkan password anda atau ingin mencari password pada list" ;
        cout << endl << "| 1. Peng-Urutan password akan secara Ascending dan Descending" ;
        cout << endl << "| 2. Anda juga dapat melihat dan mencari Password yang pernah ada simpan" ;
        cout << endl << "| " ;
        cout << endl << "| Untuk kembali ke Menu Aplikasi tekan ENTER" ;
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

int checkPasswordStrength(string messagePassword) 
{
	string kekuatan;
	bool valid = false;
	int strength;
	
  // Meminta input password
	while (!valid) 
	{
    // 	cout << "Masukkan Password (minimal 6 karakter): ";
    // 	cin >> password;

    // Validasi panjang password
    if (messagePassword.length() <= 6)
	  {
      cout << "Password harus minimal 6 karakter!" << endl;
    }

    valid = true;
    bool hasAnySymbol = false;
    bool hasLetter = false;
    bool hasNumber = false;

    // Periksa keberadaan simbol, huruf, dan nomor pada setiap karakter password
    for (int i = 0; i < messagePassword.length(); i++) 
	  {
    	if (hasSymbol(messagePassword[i])) 
		  {
    		hasAnySymbol = true;
		  } 
		  else if (isalpha(messagePassword[i])) 
		  {
        hasLetter = true;
    	} 
		  else if (isdigit(messagePassword[i])) 
		  {
      	hasNumber = true;
      }
    }

    // Hitung level kekuatan password
    if (hasAnySymbol && hasLetter && hasNumber) 
	  {
    	strength = 3;
		  kekuatan = "Kuat";
    } 
	  else if (hasLetter && hasNumber) 
	  {
		  strength = 2;
		  kekuatan = "Standar";
    } 
	  else if (hasLetter || hasNumber) 
	  {
		  strength = 1;
		  kekuatan = "Lemah";
    } 
	  else 
	  {
    	strength = 0;
    }
  }

  // Menampilkan hasil
  cout << "| Password : " << messagePassword << endl;
  cout << "| Level Kekuatan Password : " << strength << endl;
  cout << "| Tipe Kekuatan : " << kekuatan << endl;
}

void uniquePassword()
{
  const int MAX_CHARACTERS = 18; 
	char userArray[MAX_CHARACTERS]; 
	
  ifstream inputFile("dzaki.txt"); 

  // Vector untuk menyimpan semua input
  vector<string> allInputs;

	if (inputFile.is_open()) 
	{
    string input;
  	while (getline(inputFile, input)) 
		{
    	allInputs.push_back(input);
  	}

    while (true) 
	  {
  		cout <<endl<< "Masukkan password (maksimum " << MAX_CHARACTERS << " karakter): ";
    	cin.getline(userArray, MAX_CHARACTERS);

    	ofstream outputFile("dzaki.txt", ios::app); 
   	 	if (outputFile.is_open()) 
		  {
      	outputFile << userArray << endl; 
      	outputFile.close();
    	} 
		  else 
		  {
      	cout << "Gagal membuka file." << endl;
      }

    	int count = 0;
      int i=1;
		  for (i = 0; i < allInputs.size(); i++) 
		  {
  			if (allInputs[i] == userArray) 
			  {
  				count++;
				}
		  }

    	cout <<endl<< "Jumlah input yang sama dengan sebelumnya: " << count << endl;

    	char answer;
  		cout <<endl<< "Masih ingin menyimpan password lain? (y/n): ";
    	cin >> answer;
  		cin.ignore(); 

    	if (answer == 'n') 
		  {
    		break;
    	}
  	}

  	inputFile.close(); 
  } 
  else 
  {
  	cout << "Gagal membuka file." << endl;
	}
  return 0;
}


// int main()
// {
// 	// MODUL MORE INFO
// 	int help, no;

// 	cout << "Help/More info?" << endl;
// 	cout << "Ketik: 1 untuk Ya / 2 untuk Tidak" << endl;
// 	cout <<endl;
// 	cin >> help;
// 	cout << endl;
	
// 	if (help == 1) 
// 	{
//     	cout << "1. Lupa password?" << endl;
//     	cout << "2. Ingin mengganti password?" << endl;
//     	cout<<endl;
//     	cin >> no;

//     	cout << endl;

    
//     	switch (no) 
// 		{
//     		case 1:
//         		cout << "Pemulihan password hanya boleh satu kata, dan jawabannya harus sama " << endl;
//         		cout << "dengan jawaban yang Anda masukkan saat membuat akun." << endl;
//         		break;
//       		case 2:
//         		cout << "Untuk mengganti password, Anda harus memasukkan username terlebih dahulu." << endl;
//         		cout << "Anda akan ditanya pertanyaan pemulihan password."<< endl ;
//         		cout << "Pastikan jawaban Anda sama dengan yang Anda masukkan saat membuat akun " << endl;
//         		cout << "(huruf besar dan kecil dibedakan)" << endl;
//         		cout << "Disarankan untuk memasukkan jawaban dalam huruf kecil " << endl;
//         		cout << "saat membuat akun untuk menghindari masalah case-sensitivity." <<endl;
// 				break;
//       		default:
//         	cout << "Pilihan tidak valid" << endl;
//     	}
//   	} 
// 	else if (help == 2) 
// 	{
//     	return 0;
//   	} 
// 	else 
// 	{
// 		cout << "Pilihan tidak valid" << endl;
//   	}
  	
//   	// MODUL TEST PASSWORD
//   	string password;
// 	bool valid = false;
// 	int strength;

// 	while (!valid) 
// 	{	
//     	cout << endl << "Masukkan Password (minimal 6 karakter): ";
//     	cin >> password;
		
// 		if (password.length() < 6)
// 		{
//     		cout << "Password harus minimal 6 karakter!" << endl;
//     		continue;
//     	}
		
// 		valid = true;
// 	    bool hasAnySymbol = false;
//     	bool hasLetter = false;
//     	bool hasNumber = false;

// 	    for (int i = 0; i < password.length(); i++) 
// 		{
//     		if (hasSymbol(password[i])) 
// 			{
//     			hasAnySymbol = true;
// 			} 
// 			else if (isalpha(password[i])) 
// 			{
//         		hasLetter = true;
//     		} 
// 			else if (isdigit(password[i])) 
// 			{
//         		hasNumber = true;
//         	}
//     	}

// 	    if (hasAnySymbol && hasLetter && hasNumber) 
// 		{
//     		strength = 3;
//     	} 
// 		else if (hasLetter && hasNumber) 
// 		{
// 			strength = 2;
//     	} 
// 		else if (hasLetter || hasNumber) 
// 		{
// 			strength = 1;
//     	} 
// 		else 
// 		{
//     		strength = 0;
//     	}
// 	}

//   	cout << "Password: " << password << endl;
//   	cout << "Level kekuatan: " << strength << endl;
  	
//   	// MODUL UNIK PASSWORD
// 	string passwordInput;
// 	vector<string> listPassword;
// 	int countSama;
// 	bool fileBaru = false;

// 	cout << "Masukkan password: ";
// 	cin >> passwordInput;

// 	ifstream filePassword("password.dat");
// 	if (!filePassword.is_open()) 
// 	{
//     	fileBaru = true;
// 	}

// 	while (getline(filePassword, passwordInput)) 
// 	{
//     	listPassword.push_back(passwordInput);
// 	}

// 	filePassword.close();

// 	listPassword.push_back(passwordInput);


//   ofstream fileOutput("password.dat");
//  for (int i = 0; i < listPassword.size(); i++) {
//   fileOutput << listPassword[i] << endl;
// }

//   fileOutput.close();


//   countSama = 0;


//   for (int i = 0; i < listPassword.size(); i++) 
//   {
 
//     if (listPassword[i] == passwordInput) {

//       countSama++;
//     }
//   }


//   cout << "Jumlah password yang sama dengan password yang Anda masukkan: " << countSama << endl;
  

// //MODUL UNIK PASSWORD
//   string passwordInput;
//   vector<string> listPassword;
//   int countSama;
//   bool fileBaru = false;

//   cout << "Masukkan password: ";
//   cin >> passwordInput;

//   // Membuka file yang berisi list password
//   ifstream filePassword("password.dat");
//   if (!filePassword.is_open()) {
//     // File tidak ada, buat file baru
//     fileBaru = true;
//   }

//   // Membaca setiap password dari file dan menambahkannya ke list
//   while (getline(filePassword, passwordInput)) {
//     listPassword.push_back(passwordInput);
//   }

//   // Menutup file
//   filePassword.close();

//   // Menambahkan password baru ke list
//   listPassword.push_back(passwordInput);

//   // Menulis list password ke file
//   ofstream fileOutput("password.dat");
//  for (int i = 0; i < listPassword.size(); i++) {
//   fileOutput << listPassword[i] << endl;
// }
//   // Menutup file
//   fileOutput.close();

//   // Menginisialisasi variabel countSama
//   countSama = 1;

//   // Melakukan perulangan untuk setiap password dalam list
//   for (int i = 0; i < listPassword.size(); i++) 
//   {
//     // Membandingkan password dengan password yang diinputkan user
//     if (listPassword[i] == passwordInput) {
//       // Meningkatkan nilai countSama
//       countSama++;
//     }
//   }

//   // Menampilkan hasil
//   cout << "Jumlah password yang sama dengan password yang Anda masukkan: " << countSama << endl;
//   return 0;
// }
