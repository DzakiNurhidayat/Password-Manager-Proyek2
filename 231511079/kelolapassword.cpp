#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Untuk stringstream
#include <fstream>

#include "kelola.h"
#include "../231511083/listpassword.h"
#include "../231511094/enkripsi_playfair/playfair.h"
#include "../231511092/test.h"
using namespace std;



vector<listPassword> password; // Deklarasi vector global

void loadPasswordsFromFile(string loggedInUser) {
    password.clear(); // Hapus isi vektor terlebih dahulu untuk mencegah duplikasi
    ifstream inputFile(loggedInUser + ".txt");
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        listPassword tempPassword;
        getline(ss, tempPassword.nama, ';');
        getline(ss, tempPassword.username, ';');
        getline(ss, tempPassword.password, ';');
        getline(ss, tempPassword.note);
        password.push_back(tempPassword);
    }
    inputFile.close();
}


void inputPassword(string loggedInUser) {
    listPassword PasswordBaru;
	string messagePassword, encrypPassword;

    cout << "| Masukkan Nama: ";
    cin >> PasswordBaru.nama;
    cout << "| Masukkan Username: ";
    cin >> PasswordBaru.username;
    cout << "| Masukkan Password: ";
    cin >> PasswordBaru.password;
    cout << "| Masukkan Catatan: ";
    cin >> PasswordBaru.note;

    // Menambahkan password baru ke dalam vector
    password.push_back(PasswordBaru);
	cout << ".-----------------------------------------------." << endl;
    cout << "| Password Berhasil Ditambahkan Ke Dalam List   |" << endl;
    cout << "'-----------------------------------------------'" << endl << endl;


	ofstream inputFile;
	//Membuka file
	inputFile.open(loggedInUser + ".txt", ios::app);
	//Menyimpan file
	messagePassword = PasswordBaru.password;
	checkPasswordStrength(messagePassword);
	encrypPassword = encryption(loggedInUser, messagePassword);
	inputFile << PasswordBaru.nama << ";" << PasswordBaru.username << ";" << encrypPassword << ";" << PasswordBaru.note << endl;
	inputFile.close();

    loadPasswordsFromFile(loggedInUser);

}


void modifyPassword(listPassword* list, string loggedInUser, int countLine ) {
    int index;
    countLine = readListPassword(list, loggedInUser);
    if (password.empty()) {
        cout << "List password kosong!" << endl;
        return;
    }
    cout << "|          ---- Daftar Password ----        |" << endl;
    cout << "|                                           |" << endl;
    for (size_t i = 0; i < password.size(); i++) {
        cout << "| " << i + 1 << ". Dengan Nama : " << password[i].nama << endl;
    }

    cout << ".------------------------------------------------." << endl;
    cout << "| Pilih nomor password yang ingin diubah (1 - " << password.size() << "): ";
    cin >> index;

    if (index < 1 || index > password.size()) {
        cout << "Nomor password tidak valid!" << endl;
        return;
    }

    listPassword& PasswordLama = password[index - 1]; // Gunakan referensi untuk mengedit langsung
    int menu;
        cout << "|" << endl;
        cout << "| Data Mana Yang Ingin Diubah :" << endl;
        cout << "| 1. Nama                           |" << endl;
        cout << "| 2. Username                       |" << endl;
        cout << "| 3. Password                       |" << endl;
        cout << "| 4. Note                           |" << endl;
        cout << "| 5. keluar                         |" << endl;
        cout << "'-----------------------------------'" << endl;
        cout << "| Pilih hal yang ingin anda lakukan : ";
            cin >> menu;

            switch(menu) {
                case 1:
                    cout << "|" << endl;
                    cout << "| Anda Memilih Mengubah Nama";
                    cout << endl << "| Masukan Nama Baru : ";
                    cin >> PasswordLama.nama;
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|              Nama Berhasil Diubah             |" << endl;
                    cout << "'-----------------------------------------------'" << endl;
                    break;
                case 2:
                    cout << "|" << endl;
                    cout << "| Anda Memilih Mengubah Username";
                    cout << endl << "| Masukan Username Baru : ";
                    cin >> PasswordLama.username;
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|              Username Berhasil Diubah         |" << endl;
                    cout << "'-----------------------------------------------'" << endl;
                    break;
                case 3:
                    cout << "|" << endl;
                    cout << "| Anda Memilih Mengubah Password";
                    cout << endl << "| Masukan Password Baru : ";
                    cin >> PasswordLama.password;
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|              Password Berhasil Diubah         |" << endl;
                    cout << "'-----------------------------------------------'" << endl;
                    break;
                case 4:
                    cout << "|" << endl;
                    cout << "| Anda Memilih Mengubah Note";
                    cout << endl << "| Masukan Note Baru : ";
                    cin.ignore();
                    getline(cin, PasswordLama.note);
                    cout << ".-----------------------------------------------." << endl;
                    cout << "|              Note Berhasil Diubah             |" << endl;
                    cout << "'-----------------------------------------------'" << endl;
                    break;
                case 5:
                    cout << "|" << endl;
                    cout << "| Keluar\n";
                    break;
                default:
                    cout << "| *Pilihan tidak valid\n";
            }

    ofstream outFile(loggedInUser + ".txt");
    if (!outFile.is_open()) {
        cout << "Tidak bisa membuka file untuk ditulis" << endl;
        return;
    }
    for (const auto& item : password) {
        outFile << item.nama << ";" << item.username << ";" << item.password << ";" << item.note << "\n";
    }
    outFile.close();


    loadPasswordsFromFile(loggedInUser);
}


void deletePassword(string loggedInUser) {
	int index;

    if (password.empty()) {
        cout << "List password kosong!" << endl;
        return;
    }

    cout << "|          ---- Daftar Password ----        |" << endl;
    cout << "|                                           |" << endl;
    for (size_t i = 0; i < password.size(); i++) {
        cout << "| " << i + 1 << ". Dengan Nama : " << password[i].nama << endl;
    }

    cout << ".------------------------------------------------." << endl;
    cout << "| Pilih nomor password yang ingin diubah (1 - " << password.size() << "): ";
    cin >> index;

	if (index < 1 || index > password.size()) {
		cout << "Nomor password tidak valid!" << endl;
		return;
	}

	password.erase(password.begin() + index - 1);

    cout << ".-------------------------------------------------------." << endl;
    cout << "|              Password Berhasil Dihapus                |" << endl;
    cout << "'-------------------------------------------------------'" << endl;

	ofstream outFile(loggedInUser + ".txt");
    if (!outFile.is_open()) {
        cout << "Tidak bisa membuka file untuk ditulis" << endl;
        return;
    }
    for (const auto& password : password) {
        outFile << password.nama << ";" << password.username << ";" << password.password << ";" << password.note << endl;

        // Sesuaikan format penulisan dengan kebutuhan
    }
    outFile.close();
    
    loadPasswordsFromFile(loggedInUser);

}





//void simpanData() {
//	ofstream inputFile;
//	//Membuka file;
//	inputFile.open("data-password.txt", ios::app);
//	//Menyimpan password
//	for (Password password : listPassword) {
//		inputFile << password.nama << ";" << password.username << ";" << password.password << ";" << password.note << endl;
//	}
//	inputFile.close();
//}

// int main() {
// 	string pengguna = "Dzaki";
//     inputPassword(pengguna);  // Call the inputPassword function here
//     return 0;
// }
