#include "../231511094/enkripsi_playfair/Linkedlist/playfair.h"
#include "../231511092/test.h"
#include "../treeListPassword.h"

void cek_alokasi(string nama, string username, string password, string note, string dateCreated, listPassword **newNode) {
    *newNode = new listPassword;
    if (*newNode == NULL) {
        cout << "Memory Sudah Full" << endl;
    } else {
        // cout << "Alokasi berhasil" << endl;
        (*newNode)->nama = nama;
        (*newNode)->username = username;
        (*newNode)->password = password;
        (*newNode)->note = note;
        if (dateCreated.empty()) {
            (*newNode)->dateCreated = getCurrentTimestamp();
        } else {
            (*newNode)->dateCreated = dateCreated;
        }
        (*newNode)->left = NULL;
        (*newNode)->right = NULL;
    }
}

string getCurrentTimestamp() {
    // Get the current time point from the system clock
    auto now = chrono::system_clock::now();
    
    // Convert the time point to a time_t which represents time in seconds since epoch
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    
    // Convert the time_t to a tm structure representing local time
    tm now_tm = *localtime(&now_time_t);
    
    // Format the tm structure to a readable string format
    ostringstream oss;
    oss << put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    
    return oss.str();
}

listPassword *entry_data_to_tree(listPassword **root, string nama, string username, string password, string note, string dateCreated) {
    listPassword *parent = NULL;
    listPassword *current = *root;
    listPassword *newNode;
    while (current != NULL) {
        parent = current;
        if (nama < current->nama) {
            current = current->left;
        } else if (nama > current->nama) {
            current = current->right;
        } else {
            return *root;
        }
    }
    cek_alokasi(nama, username, password, note, dateCreated, &newNode);
    if (parent == NULL) {
        *root = newNode;
    } else if (nama < parent->nama) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return *root;
}

listPassword *load_data_from_file(listPassword *root, string loggedInUser) {
    string messagePassword, decrypPassword, nama, username, note, dateCreated;
    string fileName = (loggedInUser + ".txt");
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open()) {
        cout << "User belum menambahkan password\n"; 
        // return root;
    }
    cout << "test5" << endl;
    int countLine, count_token;
    string line, token, tokens[5];
    countLine = 0;

    while (getline(inFile, line)) {        
        stringstream check(line);
        count_token = 0;
        while (getline(check, token, ';')) {
            if (count_token < 5)
            {
                tokens[count_token] = token;
                count_token++;
            }
        }
        if (count_token != 5) {
            continue;
        }
        nama = tokens[0];
        username = tokens[1];
        decrypPassword = tokens[2];
        messagePassword = decryption(loggedInUser, decrypPassword);
        note = tokens[3];
        dateCreated = tokens[4];
        root = entry_data_to_tree(&root, nama, username, messagePassword, note, dateCreated);
        countLine++;
    }
    inFile.close(); 
    return root;
}

void lower_case(string &keyword) {
    for (char &c : keyword) {
        c = tolower(c);
    }
}

bool searching(listPassword *root, string keyword, int namaWidth, int userWidth, int passWidth, int noteWidth) {
    string lowerKeyword, lowerNama, lowerUsername, lowerPassword, lowerNote;
    string space = "    ";
    bool found = false;
    int nomor = 1;
    lowerKeyword = keyword;
    lower_case(lowerKeyword);
    if (root != NULL) {
        searching(root->left, keyword, namaWidth, userWidth, passWidth, noteWidth);

        lowerNama = root->nama;
        lowerUsername = root->username;
        lowerPassword = root->password;
        lowerNote = root->note;

        lower_case(lowerNama);
        lower_case(lowerUsername);
        lower_case(lowerPassword);
        lower_case(lowerNote);

        if (lowerNama.find(lowerKeyword) != string::npos ||
            lowerUsername.find(lowerKeyword) != string::npos ||
            lowerPassword.find(lowerKeyword) != string::npos ||
            lowerNote.find(lowerKeyword) != string::npos) {
            
            found = true;
            cout << setw(0) << setfill(' ') << setw(10) << left << space
                << setw(2) << left << nomor << " | "
                << setw(namaWidth) << left << root->nama << " | "
                << setw(userWidth) << left << root->username << " | " 
                << setw(passWidth) << left << root->password << " | " 
                << setw(noteWidth) << left << root->note << endl;
                }
        searching(root->right, keyword, namaWidth, userWidth, passWidth, noteWidth);
    }
    return found;
}

void find_max_widths(listPassword *node, int &namaWidth, int &userWidth, int &passWidth, int &noteWidth) {
    listPassword *temp = node;
    if (temp == NULL) {
        return;
    }
    namaWidth = max(namaWidth, static_cast<int>(temp->nama.length()));
    userWidth = max(userWidth, static_cast<int>(temp->username.length()));
    passWidth = max(passWidth, static_cast<int>(temp->password.length()));
    noteWidth = max(noteWidth, static_cast<int>(temp->note.length()));
    find_max_widths(temp->left, namaWidth, userWidth, passWidth, noteWidth);
    find_max_widths(temp->right, namaWidth, userWidth, passWidth, noteWidth);
}

void print_table(int namaWidth, int userWidth, int passWidth, int noteWidth) {
    cout << setw(9) << "          " << left
         << setw(2) << left << "No" << " | "
         << setw(namaWidth) << left << "Nama" << " | "
         << setw(userWidth) << left << "Username" << " | "
         << setw(passWidth) << left << "Password" << " | "
         << setw(noteWidth) << left << "Note" << endl;

    cout << string(7, ' ') << " +-"
         << string(2, '-') << "-+-"
         << string(namaWidth, '-') << "-+-"
         << string(userWidth, '-') << "-+-"
         << string(passWidth, '-') << "-+-"
         << string(noteWidth, '-') << endl;
}

void print_tree(listPassword *root, int &nomor, int namaWidth, int userWidth, int passWidth, int noteWidth) {
    listPassword *temp = root;
    string space = "    ";
    if (temp != NULL) {
        print_tree(temp->left, nomor, namaWidth, userWidth, passWidth, noteWidth);
        cout << setw(0) << setfill(' ') << setw(10) << left << space
            << setw(2) << left << nomor << " | "
            << setw(namaWidth) << left << temp->nama << " | "
            << setw(userWidth) << left << temp->username << " | " 
            << setw(passWidth) << left << temp->password << " | " 
            << setw(noteWidth) << left << temp->note << endl;
        nomor++;
        print_tree(temp->right, nomor, namaWidth, userWidth, passWidth, noteWidth);
    }
}

void print_tree_reverse(listPassword *root, int &nomor, int namaWidth, int userWidth, int passWidth, int noteWidth) {
    bool check;
    listPassword *temp = root;
    string space = "    ";
    if (temp != NULL) {
        print_tree_reverse(temp->right, nomor, namaWidth, userWidth, passWidth, noteWidth);
        cout << setw(0) << setfill(' ') << setw(10) << left << space
            << setw(2) << left << nomor << " | "
            << setw(namaWidth) << left << temp->nama << " | "
            << setw(userWidth) << left << temp->username << " | " 
            << setw(passWidth) << left << temp->password << " | " 
            << setw(noteWidth) << left << temp->note << endl;
        nomor++;
        print_tree_reverse(temp->left, nomor, namaWidth, userWidth, passWidth, noteWidth);
    }
}

void delete_list_infile(string loggedInUser) {
    ofstream inputFile;
    inputFile.open(loggedInUser + ".txt", ios::ate);
}

void entry_data_to_file(listPassword* root, string loggedInUser) {
    ofstream inputFile;
    string messagePassword, encrypPassword;
    if (root == NULL) {
        return;
    }
    
	//Membuka file
	inputFile.open(loggedInUser + ".txt", ios::app);
	//Menyimpan file
	messagePassword = root->password;
	encrypPassword = encryption(loggedInUser, messagePassword);
	inputFile << root->nama << ";" <<root->username << ";" << encrypPassword << ";" << root->note << ";" << root->dateCreated;
	inputFile.close();
    entry_data_to_file(root->left, loggedInUser);
    entry_data_to_file(root->right, loggedInUser);
}

void dealokasi_tree(listPassword* root) {
    if (root == NULL) {
        return;
    }
    dealokasi_tree(root->left);
    dealokasi_tree(root->right);
    delete root;
}

// int main() {
//     int namaWidth = 4;
//     int userWidth = 4;
//     int passWidth = 4;
//     int noteWidth = 4;
//     int nomor = 1;
//     string nama, username, password, note, dateCreated;
//     string keyword = "coc";
//     string hapus = "Idstagram";
//     string edit = "Kkk";
//     listPassword *root = NULL;
//     root = load_data_from_file(root);
//     find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
//     print_table(namaWidth, userWidth, passWidth, noteWidth);

//     print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
//     nomor = 1;

//     delete_data_from_tree(root, hapus);
//     cout << endl;
//     print_table(namaWidth, userWidth, passWidth, noteWidth);
//     print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
//     cout << endl;
//     nomor = 1;
//     nama = "Zomli";
//     username = "Akmal123";
//     password = "Womli222";
//     note = "Anak Romli dan Siti";
//     entry_data_to_tree(root, nama, username, password, note, dateCreated);
//     edit_data_from_tree(root, edit);
//     print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
//     print_table(namaWidth, userWidth, passWidth, noteWidth);
//     searching(root, keyword, namaWidth, userWidth, passWidth, noteWidth);
//     // print_tree_reverse(root);
//     // find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
//     return 0;
// }