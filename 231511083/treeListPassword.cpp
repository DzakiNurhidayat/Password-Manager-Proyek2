#include "treeListPassword.h"

listPassword *entry_data_to_tree(listPassword *root, infotype nama, infotype username, infotype password, infotype note) {
    listPassword *parent = NULL;
    listPassword *current = root;
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
    
    listPassword *newNode = (listPassword *) malloc(sizeof(listPassword));
    // cout << "test3" << endl;
    newNode->nama = nama;
    newNode->username = username;
    newNode->password = password;
    newNode->note = note;
    newNode->left = NULL;
    newNode->right = NULL;
    // cout << newNode->username << " p" << endl;
    
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
    infotype nama, username, password, note;
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
        root = entry_data_to_tree(root, nama, username, password, note);
        // decrypPassword = list[countLine].password;
        // messagePassword = decryption(loggedInUser, decrypPassword);
        // list[countLine].password = messagePassword;
        countLine++;
    }
    inFile.close(); 
    return root;
}

listPassword *search_node(listPassword *root, infotype nilaiCari) {
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

bool searching(listPassword *root, infotype keyword) {
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

void print_tree(listPassword *root) {
    listPassword *temp = root;
    // cout << "test" << endl;
    if (temp != NULL) {
        print_tree(temp->left);
        cout << temp->nama << endl;
        print_tree(temp->right);
    }
}

void print_tree_reverse(listPassword *root) {
    listPassword *temp = root;
    // cout << "test" << endl;
    if (temp != NULL) {
        print_tree_reverse(temp->right);
        cout << temp->nama << endl;
        print_tree_reverse(temp->left);
    }
}

int main() {
    infotype keyword = "coc";
    listPassword *root = NULL;
    root = load_data_from_file(root);
    print_tree(root); 
    searching(root, keyword);
    print_tree_reverse(root); 
    return 0;
}