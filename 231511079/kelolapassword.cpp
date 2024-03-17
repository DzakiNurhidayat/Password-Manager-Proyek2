#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Untuk stringstream
#include <fstream>

#include "kelola.h"
using namespace std;



vector<listPassword> password; // Deklarasi vector global

void inputPassword(string loggedInUser) {
    listPassword PasswordBaru;

    cout << "Masukkan Nama: ";
    cin >> PasswordBaru.nama;
    cout << "Masukkan Username: ";
    cin >> PasswordBaru.username;
    cout << "Masukkan Password: ";
    cin >> PasswordBaru.password;
    cout << "Masukkan Catatan: ";
    cin >> PasswordBaru.note;

    // Menambahkan password baru ke dalam vector
    password.push_back(PasswordBaru);
	
	cout << "Password berhasil ditambahkan!" << endl;

	ofstream inputFile;
	//Membuka file
	inputFile.open(loggedInUser + ".txt", ios::app);
	//Menyimpan file
	inputFile << PasswordBaru.nama << ";" << PasswordBaru.username << ";" << PasswordBaru.password << ";" << PasswordBaru.note << endl;
	inputFile.close();


}


void modifyPassword(listPassword* list, string loggedInUser, int countLine ) {
    int index;
    countLine = readListPassword(list, loggedInUser);


    if (password.empty()) {
        cout << "List password kosong!" << endl;
        return;
    }

    cout << "---- Daftar Password ----" << endl;
    for (size_t i = 0; i < password.size(); i++) {
        cout << i + 1 << ". " << password[i].nama << endl;
    }

    cout << "Pilih nomor password yang ingin diubah (1 - " << password.size() << "): ";
    cin >> index;

    if (index < 1 || index > password.size()) {
        cout << "Nomor password tidak valid!" << endl;
        return;
    }

    listPassword& PasswordLama = password[index - 1]; // Gunakan referensi untuk mengedit langsung
    int menu;
    cout << "\nData Mana Yang Ingin Diubah";
            cout << "\n====================\n";
            cout << "1. Nama\n";
            cout << "2. Username\n";
            cout << "3. Password\n";
            cout << "4. Note \n";
            cout << "5. Keluar \n";
            cout << "====================\n";
            cout << "Pilih hal yang ingin anda lakukan : ";
            cin >> menu;

            switch(menu) {
                case 1:
                    cout << "Anda memilih mengubah nama\n";
                    cin >> PasswordLama.nama;
                    break;
                case 2:
                    cout << "Anda memilih mengubah username\n";
                    cin >> PasswordLama.username;
                    break;
                case 3:
                    cout << "Anda memilih mengubah password\n";
                    cin >> PasswordLama.password;
                    break;
                case 4:
                    cout << "Anda memilih mengubah note\n";
                    cin.ignore();
                    getline(cin, PasswordLama.note);
                    break;
                case 5:
                    cout << "Keluar\n";
                    break;
                default:
                    cout << "Pilihan tidak valid\n";
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


}


void deletePassword(string loggedInUser) {
	int index;

    if (password.empty()) {
        cout << "List password kosong!" << endl;
        return;
    }

    cout << "---- Daftar Password ----" << endl;
    for (size_t i = 0; i < password.size(); i++) {
        cout << i + 1 << ". " << password[i].nama << endl;
    }

    cout << "Pilih nomor password yang ingin diubah (1 - " << password.size() << "): ";
    cin >> index;

	if (index < 1 || index > password.size()) {
		cout << "Nomor password tidak valid!" << endl;
		return;
	}

	password.erase(password.begin() + index - 1);

	cout << "Password berhasil dihapus!" << endl;

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
// 	int choice;
// 	string pengguna = "afriza";
//     // inputPassword(pengguna);  // Call the inputPassword function here
    
// 	do
//     {
//         cout << "1. inpuut\n";
//         cout << "2. delete\n";
//         cout << "3. Ganti\n"; // Opsi baru untuk membaca file user
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//             case 1:
//                 cout << "Registering..." << endl;
//                 countLine = readListPassword(list, loggedInUser);
//                 inputPassword(pengguna);
//                 cout << "Registration complete." << endl;
//                 break;
//             case 2:
//                 cout << "Registering..." << endl;
//                 deletePassword(pengguna);
//                 cout << "delete complete." << endl;
//                 break;
//             case 3:
//                 cout << "Registering..." << endl;
//                 modifyPassword(pengguna);
//                 break;
//             default:
//                 cout << "Invalid option! Please try again.\n";
//         }
//     } while (choice != 3);

	
// 	return 0;
// }
