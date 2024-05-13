#include "playfair.h"

/*File ini adalah untuk proses yang ada di enkripsi dan dekripsi*/

/*Menjadikan hasil yang unik karakter saja */
string unik(string key)
{
    string karakter;
    string addchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` '~✓®×¢€§×";

    for (char c : key) 
    {
        if (karakter.find(c) == string::npos) // Jika karakter tambahan belum ada di key, masukkan ke dalam tabel
        {
            karakter += c;
        }
    }
    for (char c : addchar)
    {
        if (karakter.find(c) == string::npos)
        {
            karakter += c;
        }
    }

    return karakter;
}


// Membuat tabel sekaligus menginputkan karakter
address createTable(int size_board, string karakter){
    address Head = NULL;
    address rowStart = NULL;
    address upNode = NULL;
    address temp_last = NULL;

    // string add_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` '~✓®×¢€§×";
    int index = 0;  // Index to iterate over add_chars

    for(int i = 1; i <= size_board; i++) {
        for(int j = 1; j <= size_board; j++) {
            address newNode = (address) malloc(sizeof(node));
            if (newNode == NULL) {
                printf("Memory Full\n");
                return NULL; // Exiting if memory allocation fails
            }
            else {
                if(index < karakter.length()){
                newNode->text = karakter[index];  // Use modulo to cycle through add_chars if necessary
                index++;

                newNode->right = NULL;
                newNode->left = NULL;
                newNode->top   = NULL;
                newNode->down = NULL;
                }
                
            }

            if (Head == NULL) {
                Head = newNode;
            }
            if (rowStart == NULL) {
                rowStart = newNode;
            }
            else {
                newNode->left = temp_last;
                temp_last->right = newNode;
            }

            if (upNode != NULL) {
                upNode->down = newNode;
                newNode->top = upNode;
                upNode = upNode->right;
            }
            temp_last = newNode;
        }

        upNode = rowStart;
        rowStart = NULL;
    }

    return Head;
}


//traversal dan mencari tahu posisi node 
address searchingNode(address Head, infotype nilai){
    address rowStart = NULL;
    address node = Head;
    address result = NULL;

    // loop down
    while(node != NULL){
        // loop right
        while(node != NULL){
            if (node -> text == nilai){
                result = node;
                return result;
            }
            
            if (rowStart == NULL){
                rowStart = node;
            }
            node = node -> right;
        }
        node = rowStart -> down;
        rowStart = NULL;
    }
    return result;
}

bool cek_vertikal(address current, address current2)
{

    while (current != NULL)
    {
        if (current->top != current2)
        {
            current = current->down;
        }
        else
        {
            return true;
        }
        
    }

    while (current2 !=NULL)
    {
        if (current2->top != current)
        {
            current2 = current2->down;
        }
        else
        {
            return true;
        }
        
    }
    
    return false;
}

bool cek_horizontal(address current, address current2)
{
    while (current != NULL)
    {
        if (current->top != current2)
        {
            current = current->right;
        }
        else
        {
            return true;
        }
    }

    while (current2 != NULL)
    {
        if (current2->top != current)
        {
            current2 = current2->right;
        }
        else
        {
            return true;
        }
    }

    return false;
}


string encryption(address Head,string plaintext)
{
    string encrypted_text;
    address address1,address2;

    bool col, row;
    char c1, c2;
    int j;
    j = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {
        c1 = plaintext[j];
        c2 = (i + 1 < plaintext.length()) ? plaintext[i + 1] : '\0'; // '\0' character kosong
        // c3 = (i + 2 < plaintext.length()) ? plaintext[i + 2] : '\0';
        // c4 = (i + 3 < plaintext.length()) ? plaintext[i + 3] : '\0';

        address1 = searchingNode(Head,c1);// dapet address c1
        address2 = searchingNode(Head, c2);
        

        if (c1 != c2)
        {
            row = cek_vertikal(address1, address2);   
            col = cek_horizontal(address1,address2);
            
            if (row = true)//same row
            {
                encrypted_text.push_back(address1->right->text);
                encrypted_text.push_back(address2->right->text);
            } 
            else if (col = true)//same col
            {
                encrypted_text.push_back(address1->down->text);
                encrypted_text.push_back(address2->down->text);
            }
            else // no same
            {

            }
        }
        else
        {
            encrypted_text.push_back(c1);
            encrypted_text.push_back(c1);
        }

        

    }
    return encrypted_text;
}

/*Keperluan debugging*/
void display_table(address Head, int size_board)
{
    address current = Head;

    for (int i = 1; i <= size_board; i++)
    {
        for (int j = 1; j <= size_board; j++)
        {
            cout << current->text << " | ";
            current = current->right;
        }
        cout << "\n";
        current = Head;
        for (int k = 0; k < i; k++)
        {
            current = current->down;
        }
    }
}

int main()
{
    int size = 10;
    string pass = "Wakwaw1123 olo";
    string hasil;
    address head;
    hasil = unik(pass);
    head = createTable(size, hasil);

    display_table(head, size);
}