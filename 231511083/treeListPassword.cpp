#include "../treeListPassword.h"

void cekAlokasi(string nama, string username, string password, string note, listPassword **newNode) {
    *newNode = new listPassword;
    if (*newNode == NULL) {
        cout << "Memory Sudah Full" << endl;
    } else {
        // cout << "Alokasi berhasil" << endl;
        (*newNode)->nama = nama;
        (*newNode)->username = username;
        (*newNode)->password = password;
        (*newNode)->note = note;
        (*newNode)->left = NULL;
        (*newNode)->right = NULL;
        // cout << (*newNode)->username << " p" << endl;
    }
}

listPassword *entry_data_to_tree(listPassword *root, string nama, string username, string password, string note) {
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
    cekAlokasi(nama, username, password, note, &newNode);
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
    string line, token, tokens[4];
    string nama, username, password, note;
    countLine = 0;

    while (getline(inFile, line)) {        
        stringstream check(line);
        count_token = 0;
        while (getline(check, token, ';')) {
            if (count_token < 4)
            {
                tokens[count_token] = token;
                count_token++;
            }
        }
        if (count_token != 4) {
            continue;
        }
        nama = tokens[0];
        username = tokens[1];
        password = tokens[2];
        note = tokens[3];
        // cout << nama << ", " << username << ", " << password << ", " << note;
        root = entry_data_to_tree(root, nama, username, password, note);
        // decrypPassword = list[countLine].password;
        // messagePassword = decryption(loggedInUser, decrypPassword);
        // list[countLine].password = messagePassword;
        countLine++;
    }
    inFile.close(); 
    return root;
}

listPassword *search_node(listPassword *root, string nilaiCari) {
    if (root == NULL or root->nama == nilaiCari) {
        return root;
    }

    // Jika Nilai yang Dicari Lebih Besar dari Root Saat Ini
    if (root->nama < nilaiCari) {
        search_node(root->right, nilaiCari);
    }
    // Jika Nilai yang Dicari Lebih Kecil dari Root Saat Ini
    else {
        search_node(root->left, nilaiCari);
    }
}

void lowerCase(string &keyword) {
    for (char &c : keyword) {
        c = tolower(c);
    }
}

bool searching(listPassword *root, string keyword) {
    string lowerKeyword, lowerNama, lowerUsername, lowerPassword, lowerNote;
    bool found = false;
    lowerKeyword = keyword;
    lowerCase(lowerKeyword);
    if (root != NULL) {
        searching(root->left, keyword);

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
            cout << "Ada Guys Valorant = " << lowerNama << endl;
        }
        searching(root->right, keyword);
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

void print_tree(listPassword *root, int &nomor, int namaWidth, int userWidth, int passWidth, int noteWidth) {
    listPassword *temp = root;
    string coba = "    ";
    if (temp == NULL) {
        return;
    }
    print_tree(temp->left, nomor, namaWidth, userWidth, passWidth, noteWidth);
    // cout << temp->nama << endl;
    cout << setw(0) << setfill(' ') << setw(10) << left << coba
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
    string keyword = "coc";
    listPassword *root = NULL;
    root = load_data_from_file(root);
    find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
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

    print_tree(root, nomor, namaWidth, userWidth, passWidth, noteWidth); 
    // searching(root, keyword);
    // print_tree_reverse(root);
    // find_max_widths(root, namaWidth, userWidth, passWidth, noteWidth);
    return 0;
}