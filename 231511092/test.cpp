#include "../231511094/enkripsi_playfair/Linkedlist/playfair.h"
#include "test.h"
#include "../treeListPassword.h"


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
         system("pause");
         break;
       case 2:
         cout << endl << "1. Pilih No.2 di menu utama" << endl ;
         cout << endl << "2. Pastikan anda telah memiliki akun terlebih dahulu untuk login" << endl ;
         cout << endl << "3. Masukkan username dan password anda setelah anda masuk pada menu login" << endl ;
         cout << endl << "4. Jika anda belum memiliki akun kembali ke menu utama dan input No. 1" << endl ;
         cout << endl;
         system("pause");
         break;
       case 3:
         cout << endl << "1. Pilih No.3 pada bagian Menu Untuk Merubah Password" << endl ;
         cout << endl << "2. Dengan catatan: harus memasukan username terlebih karena " << endl ;
         cout << endl << "3. Karena case sensitive anda akan disarankan untuk memasukkan jawaban di lower saat membuat akun" << endl ;
         cout << endl << "4. Pastikan password yang anda gunakan terdiri dari maksimal 18 karakter dan minimal 6 karakter" << endl ;
         cout << endl;
         system("pause");
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
         cout << "| " ;
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
     cout << "| " ;
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
         system("pause");
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
         system("pause");
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
         system("pause");
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
         system("pause");
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
         system("pause");
         break;
       case 6:
         cout << endl << "| Input No. 3 pada MENU aplikasi jika anda ingin MENGHAPUS password yang sudah di simpan. " ; 
         cout << endl << "| Pastikan anda sudah memiliki password yang sudah di input pada List" ;
         cout << endl << "| Setelah memilih no. 3 pada menu aplikasi anda akan diberikan list semua password yang pernah anda simpan" ;
         cout << endl << "| Selanjutnya pilih password pada list yang ingin anda HAPUS " ;
         cout << endl << "| Sesuaikan nomor yang anda input dengan nomor password pada list yang ingin anda HAPUS " ; 
         cout << endl << "| " ;
         cout << endl << "| Untuk kembali ke menu aplikasi tekan ENTER" ;
         system("pause");
         break;
       case 7:
         cout << endl << "| Untuk Menampilkan List Password Anda Cukup Inputkan No. 4 pada MENU Aplikasi" ;
         cout << endl << "| Semua pasword yang pernah anda simpan pada list akan ditampilkan" ;
         cout << endl << "| NOTE: Anda akan diberikan pilihan untuk mengurutkan password anda atau ingin mencari password pada list" ;
         cout << endl << "| 1. Peng-Urutan password akan secara Ascending dan Descending" ;
         cout << endl << "| 2. Anda juga dapat melihat dan mencari Password yang pernah ada simpan" ;
         cout << endl << "| " ;
         cout << endl << "| Untuk kembali ke Menu Aplikasi tekan ENTER" ;
         system("pause");
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
     // if (messagePassword.length() <= 6)
 	  // {
     //   cout << "*Password harus minimal 6 karakter!" << endl;
     //   length = messagePassword.length();
     // }

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
   // cout << "| Password : " << messagePassword << endl;
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
  return;
}


// void alloc_listPassword(string nama, string username, string password, string note, string dateCreated, listPassword **newNode) {
//     *newNode = new listPassword;
//     if (*newNode == NULL) {
//         cout << "Memory Sudah Full" << endl;
//     } else {
//         (*newNode)->nama = nama;
//         (*newNode)->username = username;
//         (*newNode)->password = password;
//         (*newNode)->note = note;
//         (*newNode)->dateCreated = dateCreated;
//         (*newNode)->next = NULL;
//     }
// }

void insert_last(filePassword **first, filePassword **last, filePassword *newNode) {
    if (*last != NULL) {
        (*last)->next = newNode;
    }
    *last = newNode;
    if (*first == NULL) {
        *first = newNode;
    }
    newNode->next = NULL;
}

long get_timestamp() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    long timestamp = (long)mktime(timeinfo);

    return timestamp;
}

void insert_order(filePassword **first, filePassword **last, string nama, string username, string password, string note, string dateCreated) 
{
    filePassword *newNode;
    // cout << "Test Yanto Gay";
    alloc_listPassword(nama, username, password, note, dateCreated, &newNode);
    if (*first == NULL && *last == NULL) 
	{
        *first = newNode;
        *last = newNode;
    } else if (*first == *last) 
	{
        if (newNode->dateCreated > (*first)->dateCreated) {
            insert_last(first, last, newNode);
        } else {
            newNode->next = *first;
            *first = newNode;
        }
    } else if (newNode->dateCreated < (*first)->dateCreated) {
        newNode->next = *first;
        *first = newNode;
    } else if (newNode->dateCreated >= (*last)->dateCreated) {
        insert_last(first, last, newNode);
    } else {
        filePassword *temp = *first;
        while (temp->next != NULL && temp->next->dateCreated < newNode->dateCreated) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void entry_to_linkedlist(filePassword **first, filePassword **last, listPassword *root) {
    if (root == NULL) {
        return;
    }
    cout << "Test Hafiz Gay";
    insert_order(first, last, root->nama, root->username, root->password, root->note, root->dateCreated);
    // cout << "Nama: " << root->nama << ", Username: " << root->username << ", Password: " << root->password << ", Note: " << root->note << ", Date Created: " << root->dateCreated << endl;
    entry_to_linkedlist(first, last, root->left);
    entry_to_linkedlist(first, last, root->right);
}

// Fungsi untuk menyimpan linked list ke dalam file
void save_to_file(filePassword* first, string &loggedInUser) {
    ofstream outputFile;
    string messagePassword, encrypPassword;
    outputFile.open((loggedInUser + ".txt").c_str(), ios::trunc);
    
    if (!outputFile.is_open()) {
        cout << "Error!! file tidak dapat dibuka" << endl;
        return;
    }
  
    while (first != NULL) {
      messagePassword = first->password;
	    encrypPassword = encryption(loggedInUser, messagePassword);
      outputFile << first->nama << ";" << first->username << ";" << encrypPassword << ";"  << first->note << ";" << first->dateCreated;
        
		first = first->next;
    }
    outputFile.close();
}

void entry_to_file(filePassword* first, string &loggedInUser) {
    ofstream outputFile;
    string messagePassword, encrypPassword;
    outputFile.open((loggedInUser + ".txt").c_str(), ios::app);
    
    if (!outputFile.is_open()) {
        cout << "Error!! file tidak dapat dibuka" << endl;
        return;
    }

    while (first->next != NULL) {
        first = first->next;
    }
    messagePassword = first->password;
	  encrypPassword = encryption(loggedInUser, messagePassword);
    outputFile << first->nama << ";" << first->username << ";" << encrypPassword << ";"  << first->note << ";" << first->dateCreated << "\n";
    outputFile.close();
}

//Alokasi memori pada linked list
void alloc_listPassword (string nama, string username, string password, string note, string dateCreated, filePassword **newNode) {
    *newNode = new filePassword;
    if (*newNode == NULL) {
        cout << "Memory Sudah Full" << endl;
    }
    else {
        (*newNode) -> nama = nama;
        // cout << "Nama : " << (*newNode)->nama;
        (*newNode) -> username = username;
        (*newNode) -> password = password;
        (*newNode) -> note = note;
        (*newNode) -> dateCreated = dateCreated;
        (*newNode) -> next = NULL;
    }
}

//Dealokasi memori pada linked  list
filePassword* dealloc_listPassword(filePassword** head) {
    filePassword* current = *head;
    filePassword* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *head = NULL; // Mengatur head menjadi NULL setelah dealokasi
    return *head;
}


//void addNodeToTree(TreeNode* &root) {
//    string nama, username, password, note, dateCreated;
//    
//    cout << "Masukkan nama: ";
//    cin >> nama;
//    cout << "Masukkan username: ";
//    cin >> username;
//    cout << "Masukkan password: ";
//    cin >> password;
//    cout << "Masukkan note: ";
//    cin.ignore();
//    getline(cin, note);
//    cout << "Masukkan date created (YYYY-MM-DD): ";
//    cin >> dateCreated;
//    
//    root = insertToTree(root, nama, username, password, note, dateCreated);
//}
//
//TreeNode* insertToTree(TreeNode *root, string nama, string username, string password, string note, string dateCreated) {
//    if (root == NULL) {
//        TreeNode *newNode = new TreeNode;
//        newNode->nama = nama;
//        newNode->username = username;
//        newNode->password = password;
//        newNode->note = note;
//        newNode->dateCreated = dateCreated;
//        newNode->left = NULL;
//        newNode->right = NULL;
//        return newNode;
//    }
//
//    if (nama < root->nama) {
//        root->left = insertToTree(root->left, nama, username, password, note, dateCreated);
//    } else {
//        root->right = insertToTree(root->right, nama, username, password, note, dateCreated);
//    }
//    return root;
//}
