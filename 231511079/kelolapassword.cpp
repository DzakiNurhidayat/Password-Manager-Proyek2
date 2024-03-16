#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Password {
	string nama;
	string username;
	string password;
	string note;
};

vector<Password> listPassword;

void inputPassword(string pengguna) {
	Password PasswordBaru;
	
	cout << "---- Input Password ----" << endl;
	
	cout << "Nama File: ";
	cin >> PasswordBaru.nama;
	
	cout << "Username: ";
	cin >> PasswordBaru.username;
	
	cout << "Input Password: ";
	cin >> PasswordBaru.password;
	
	cout << "Tambahkan Note: ";
	cin.ignore();
	getline(cin, PasswordBaru.note);
	
	listPassword.push_back(PasswordBaru);
	
	cout << "Password berhasil ditambahkan!" << endl;

	ofstream inputFile;
	//Membuka file
	inputFile.open(pengguna + ".txt", std::ios::app);
	//Menyimpan file
	inputFile << PasswordBaru.nama << ";" << PasswordBaru.username << ";" << PasswordBaru.password << ";" << PasswordBaru.note;
	inputFile.close();

}

void deletePassword() {
	int index;

	if (listPassword.empty()) {
		cout << "List password kosong!" << endl;
		return;
	}

	cout << "---- Daftar Password ----" << endl;
	for (int i = 0; i < listPassword.size(); i++) {
		cout << i + 1 << ". " << listPassword[i].nama << endl;
	}

	cout << "Pilih nomor password yang ingin dihapus (1 - " << listPassword.size() << " ): ";
	cin >> index;

	if (index < 1 || index > listPassword.size()) {
		cout << "Nomor password tidak valid!" << endl;
		return;
	}

	listPassword.erase(listPassword.begin() + index - 1);

	cout << "Password berhasil dihapus!" << endl;

}

void modifyPassword() {
	int index;

	if (listPassword.empty()) {
		cout << "List password kosong!" << endl;
		return;
	}

	cout << "---- Daftar Password ----" << endl;
	for (int i = 0; i < listPassword.size(); i++) {
		cout << i + 1 << ". " << listPassword[i].nama << endl;
	}

	cout << "Pilih nomor password yang ingin diubah (1 - " <<listPassword.size() << " ): ";
	cin >> index;

	if (index < 1 || index > listPassword.size()) {
		cout << "Nomor password tidak valid!" << endl;
		return;
	}

	Password PasswordLama = listPassword[index - 1];

	cout << "---- Ubah Password ----" << endl;

	cout << "Nama File: ";
	cin >> PasswordLama.nama;

	cout << "Username: ";
	cin >> PasswordLama.username;

	cout << "Input Password Baru: ";
	cin >> PasswordLama.password;

	cout << "Tambahkan Note: ";
	cin.ignore();
	getline(cin, PasswordLama.note);

	listPassword[index - 1] = PasswordLama;

	cout << "Password berhasil diubah!" << endl;

}

//void simpanData() {
//	ofstream inputFile;
//	//Membuka file;
//	inputFile.open("data-password.txt", std::ios::app);
//	//Menyimpan password
//	for (Password password : listPassword) {
//		inputFile << password.nama << ";" << password.username << ";" << password.password << ";" << password.note << endl;
//	}
//	inputFile.close();
//}

// int main() {
//     inputPassword();  // Call the inputPassword function here
//     return 0;
// }
