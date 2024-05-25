#include "../231511094/enkripsi_playfair/Linkedlist/playfair.h"
#include "../treeListPassword.h"
#include "../231511092/test.h"

void print_nama_tree(listPassword *root, int &nomor) {
    if (root == NULL) {
        return;
    }
    // Cetak BST secara inorder traversal   
    print_nama_tree (root -> left, nomor);
    cout << "| " << nomor <<". Nama : " << root->nama << endl;
    nomor++;
    print_nama_tree (root -> right, nomor);
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

listPassword *edit_data_from_tree(listPassword *root, string nama, string loggedInUser) {
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
    string usernameBaru, passwordBaru, noteBaru, encrypPassword, messagePassword;
    cout << "tes" << targetNode->username << endl;
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
            cout << usernameBaru << endl;
            cout << targetNode->username << endl;
            targetNode -> username = usernameBaru;
            cout << ".-----------------------------------------------." << endl;
            cout << "|            Username Berhasil Diubah           |" << endl;
            cout << "'-----------------------------------------------'" << endl;
            cout << targetNode->username << endl;
            break;
        case 2:
        cout << "|" << endl;
            cout << "| Anda Memilih Mengubah Password";
            cout << endl << "| Masukan Password Baru : ";
            getline(cin, passwordBaru);
            checkPasswordStrength(passwordBaru);
	        targetNode -> password = passwordBaru;
            // encrypPassword = encryption(loggedInUser, passwordBaru);
            // targetNode -> password = encrypPassword;
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