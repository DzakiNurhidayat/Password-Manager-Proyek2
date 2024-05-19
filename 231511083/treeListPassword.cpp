#include "../treeListPassword.h"

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

void cekAlokasi(string nama, string username, string password, string note, string dateCreated, listPassword **newNode) {
    *newNode = new listPassword;
    if (*newNode == NULL) {
        cout << "Memory Sudah Full" << endl;
    } else {
        // cout << "Alokasi berhasil" << endl;
        string tes = "a";
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
        cout << (*newNode)->dateCreated << endl;
    }
}

listPassword *entry_data_to_tree(listPassword *root, string nama, string username, string password, string note, string dateCreated) {
    listPassword *parent = NULL;
    listPassword *current = root;
    listPassword *newNode;
    // cout << "test2" << endl;
    while (current != NULL) {
        parent = current;
        if (nama < current->nama) {
            current = current->left;
        } else if (nama > current->nama) {
            current = current->right;
        } else {
            return root;
        }
    }
    // cout << newNode->username << " p" << endl;
    cekAlokasi(nama, username, password, note, dateCreated, &newNode);
    if (parent == NULL) {
        root = newNode;
    } else if (nama < parent->nama) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return root;
}

listPassword *load_data_from_file(listPassword *root) {
    string messagePassword, decrypPassword;
    // cout << "test4" << endl;
    ifstream inFile("dzaki.txt", ios::binary);
    if (!inFile.is_open()) {
        cout << "User belum menambahkan password\n"; 
        // return root;
    }
    // cout << "test5" << endl;
    int countLine, count_token;
    string line, token, tokens[5];
    string nama, username, password, note, dateCreated;
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
        password = tokens[2];
        note = tokens[3];
        dateCreated = tokens[4];
        // cout << nama << ", " << username << ", " << password << ", " << note;
        root = entry_data_to_tree(root, nama, username, password, note, dateCreated);
        // decrypPassword = list[countLine].password;
        // messagePassword = decryption(loggedInUser, decrypPassword);
        // list[countLine].password = messagePassword;
        countLine++;
    }
    inFile.close(); 
    return root;
}

listPassword *search_node(listPassword *root, string nilaiCari) {
    if (root == NULL) {
        return NULL;
    }

    if (root->nama == nilaiCari)
    {
        return root;
    }
    // Jika Nilai yang Dicari Lebih Besar dari Root Saat Ini
    if (nilaiCari < root->nama) {
        return search_node(root->left, nilaiCari);
    }
    // Jika Nilai yang Dicari Lebih Kecil dari Root Saat Ini
    else {
        return search_node(root->right, nilaiCari);
    }
}

listPassword *delete_data_from_tree(listPassword *root, string nama) {
    // Kasus dasar
    if (root == NULL) {
        return root;
    }
    
    // Jika nama yang akan dihapus lebih kecil dari nama root, maka ia berada di subtree kiri
    if (nama < root -> nama) {  
        root -> left = delete_data_from_tree(root -> left, nama);
    }

    // Jika nama yang akan dihapus lebih besar dari nama root, maka ia berada di subtree kanan
    else if (nama > root -> nama) {
        root -> right = delete_data_from_tree(root -> right, nama);
        return root;
    }

    // Jika nama sama dengan nama root, maka ini adalah node yang akan dihapus
    // Node dengan hanya satu anak atau tidak memiliki anak
    if (root -> left == NULL) {
        listPassword *temp = root -> right;
        delete root;
        return temp;
    }
    else if (root -> right == NULL) {
        listPassword *temp = root -> left;
        delete root;
        return temp;
    }

    // Node dengan dua anak: Dapatkan penerus inorder (terkecil di subtree kanan)
    listPassword *nextSibling = root;
    listPassword *child = root ->right;
    while (child -> left != NULL) {
        nextSibling = child;
        child = child -> left;
    }

    // Salin konten penerus inorder ke node ini
    root -> nama = child -> nama;

    // Hapus penerus inorder
    if (nextSibling -> left == child) {
        nextSibling -> left = child -> right;
    }
    else {
        nextSibling -> right = child -> right;
    }
    
    delete child;
    return root;

}

listPassword *edit_data_from_tree(listPassword *root, string nama) {
    // Cetak BST secara inorder traversal
    cout << "|          ---- Daftar Password ----        |" << endl;
    cout << "|                                           |" << endl;
    // print_tree(root);

    //Cari node dengan nama yang diberikan
    listPassword *targetNode = search_node(root, nama);
    if (targetNode == NULL) {
        cout << "Nama " << nama << " tidak ditemukan." << endl;
        return root;
    }
    
    //Pilih informasi yang ingin diubah
    int pilihan;
    string usernameBaru, passwordBaru, noteBaru;
    cout << "|" << endl;
    cout << "| Data Mana Yang Ingin Diubah :" << endl;
    cout << "| 1. Username                       |" << endl;
    cout << "| 2. Password                       |" << endl;
    cout << "| 3. Note                           |" << endl;
    cout << "| 4. keluar                         |" << endl;
    cout << "'-----------------------------------'" << endl;
    cout << "| Pilih hal yang ingin anda lakukan : ";
    cin >> pilihan;
    cin.ignore();

    //Ubah informasi yang dipilih
    switch (pilihan) {
        case 1:
        cout << "|" << endl;
            cout << "| Anda Memilih Mengubah Username";
            cout << endl << "| Masukan Username Baru : ";
            getline(cin, usernameBaru);
            targetNode -> username = usernameBaru;
            cout << ".-----------------------------------------------." << endl;
            cout << "|            Username Berhasil Diubah           |" << endl;
            cout << "'-----------------------------------------------'" << endl;
            break;
        case 2:
        cout << "|" << endl;
            cout << "| Anda Memilih Mengubah Password";
            cout << endl << "| Masukan Password Baru : ";
            getline(cin, passwordBaru);
            targetNode -> password = passwordBaru;
            cout << ".-----------------------------------------------." << endl;
            cout << "|            Password Berhasil Diubah           |" << endl;
            cout << "'-----------------------------------------------'" << endl;
            break;
        case 3:
        cout << "|" << endl;
            cout << "| Anda Memilih Mengubah Note";
            cout << endl << "| Masukan Note Baru : ";
            getline(cin, noteBaru);
            targetNode -> note = noteBaru;
            cout << ".-----------------------------------------------." << endl;
            cout << "|              Username Berhasil Diubah             |" << endl;
            cout << "'-----------------------------------------------'" << endl;
            break;
        case 4:
            cout << "|" << endl;
            cout << "| Keluar\n";
            break;
        default:
            cout << "| *Pilihan tidak valid\n";
    }
    return root;
}

void lowerCase(string &keyword) {
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
    lowerCase(lowerKeyword);
    if (root != NULL) {
        searching(root->left, keyword, namaWidth, userWidth, passWidth, noteWidth);

        lowerNama = root->nama;
        lowerUsername = root->username;
        lowerPassword = root->password;
        lowerNote = root->note;

        lowerCase(lowerNama);
        lowerCase(lowerUsername);
        lowerCase(lowerPassword);
        lowerCase(lowerNote);

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
    // Mencetak header
    cout << setw(9) << "          " << left
         << setw(2) << left << "No" << " | "
         << setw(namaWidth) << left << "Nama" << " | "
         << setw(userWidth) << left << "Username" << " | "
         << setw(passWidth) << left << "Password" << " | "
         << setw(noteWidth) << left << "Note" << endl;

    // Mencetak garis pemisah
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
    if (temp == NULL) {
        return;
    }
    print_tree(temp->left, nomor, namaWidth, userWidth, passWidth, noteWidth);
    // cout << temp->nama << endl;
    cout << setw(0) << setfill(' ') << setw(10) << left << space
        << setw(2) << left << nomor << " | "
        << setw(namaWidth) << left << temp->nama << " | "
        << setw(userWidth) << left << temp->username << " | " 
        << setw(passWidth) << left << temp->password << " | " 
        << setw(noteWidth) << left << temp->note << endl;
    nomor++;
    print_tree(temp->right, nomor, namaWidth, userWidth, passWidth, noteWidth);

}

void print_tree_reverse(listPassword *root) {
    bool check;
    listPassword *temp = root;
    // cout << "test" << endl;
    if (temp != NULL) {
        print_tree_reverse(temp->right);
        cout << temp->nama << endl;
        print_tree_reverse(temp->left);
    }
}

int main() {
    int namaWidth = 4;
    int userWidth = 4;
    int passWidth = 4;
    int noteWidth = 4;
    int nomor = 1;
    string nama, username, password, note, dateCreated;
    string keyword = "coc";
    string hapus = "Idstagram";
    string edit = "Kkk";
    listPassword *root = NULL;
    root = load_data_from_file(root);
    find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
    print_table(namaWidth, userWidth, passWidth, noteWidth);

    print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
    nomor = 1;

    delete_data_from_tree(root, hapus);
    cout << endl;
    print_table(namaWidth, userWidth, passWidth, noteWidth);
    print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
    cout << endl;
    nomor = 1;
    nama = "Zomli";
    username = "Akmal123";
    password = "Womli222";
    note = "Anak Romli dan Siti";
    entry_data_to_tree(root, nama, username, password, note, dateCreated);
    edit_data_from_tree(root, edit);
    print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
    print_table(namaWidth, userWidth, passWidth, noteWidth);
    searching(root, keyword, namaWidth, userWidth, passWidth, noteWidth);
    // print_tree_reverse(root);
    // find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
    return 0;
}