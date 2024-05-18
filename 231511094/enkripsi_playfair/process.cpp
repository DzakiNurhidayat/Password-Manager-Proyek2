#include "playfair.h"

/*File ini adalah untuk proses yang ada di enkripsi dan dekripsi*/

string unique(string key)
{
    string character;
    string addchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/` '~✓®×¢€§×";

    for (char c : key) 
    {
        if (character.find(c) == string::npos) // Jika character tambahan belum ada di key, masukkan ke dalam tabel
        {
            character += c;
        }
    }
    for (char c : addchar)
    {
        if (character.find(c) == string::npos)
        {
            character += c;
        }
    }

    return character;
}


// Membuat tabel sekaligus menginputkan karakter
address createTable(int size_board, string character){
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
                if(index < character.length()){
                newNode->text = character[index];  // Use modulo to cycle through add_chars if necessary
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
address searchingNode(address Head, infotype plainText){
    address rowStart = NULL;
    address node = Head;
    address result = NULL;

    // loop down
    while(node != NULL){
        // loop right
        while(node != NULL){
            if (node -> text == plainText){
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

bool checkVertical(address c1, address c2)
{
    address temp;
    bool first;
    temp = c1;
    first = true;
    while (temp != NULL)
    {
        while (temp != NULL)
        {
            if (temp == c2 && first)
            {
                return true;
            }
            else if (temp == c1 && !first)
            {
                return true;
            }
            else
            {
                temp = temp->down;
            }
        }
        if (first == true)
        {
            cout << endl;
            temp = c2;
            first = false;
        }
        else
        {
            return false;
        }
    }
}

bool checkHorizontal(address c1, address c2)
{
    address temp;
    bool first;
    temp = c1;
    first = true;
    while (temp != NULL)
    {
        while (temp != NULL)
        {
            if (temp == c2 && first)
            {
                return true;
            }
            else if (temp == c1 && !first)
            {
                return true;
            }
            else
            {
                cout << temp->text;
                temp = temp->right;
            }
        }
        if (first == true)
        {
            temp = c2;
            first = false;
        }
        else
        {
            return false;
        }
    }
}

/*Kalau yang di ambil tengah nya waktu dekripsi juga sama aja ya kan?*/
char differentColRow(address c1, address c2)
{
    address temp;
    address tengah;
    bool bawah;
    bawah = true;
    temp = c1;
    tengah = c1;

    while (tengah != NULL)
    {
        temp = temp->right;
        tengah = temp;
        while (temp != NULL)
        {
            if (bawah)
            {
                while (temp != NULL)
                {
                    temp = temp->down;
                    if (temp == c2)
                    {
                        return tengah->text;
                    }
                }
                temp = tengah;
                bawah = false;
            }
            else
            {
                while (temp != NULL)
                {
                    temp = temp->top;
                    if (temp == c2)
                    {
                        return tengah->text;
                    }
                }
                bawah = true;
            }
        }
        temp = tengah;
    }

    temp = c1;
    tengah = temp;

    while (tengah != NULL)
    {
        temp = temp->left;
        tengah = temp;
        while (temp != NULL)
        {
            if (bawah)
            {
                while (temp != NULL)
                {
                    temp = temp->down;
                    if (temp == c2)
                    {
                        return tengah->text;
                    }
                }
                temp = tengah;
                bawah = false;
            }
            else
            {
                while (temp != NULL)
                {
                    temp = temp->top;
                    if (temp == c2)
                    {
                        return tengah->text;
                    }
                }
                bawah = true;
            }
        }
        temp = tengah;
    }
}