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

bool cek_vertikal(address c1, address c2)
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

bool cek_horizontal(address c1, address c2)
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

/*Kalau yang di ambil tengah nya waktu dekripsi juga sama aja ya kan?*/
int kotak(address current, address current2)
{
    char char1, char2;
    int x;
    string result;
    address rowStart = NULL;
    address temp_last = NULL;
    address head = current;
    address head2 = current2;
    address pembanding;

    int x = 0;

    rowStart = head;
    while (current != current2)
    {
        while (rowStart->right != NULL)
        {
            rowStart = rowStart->right;
            temp_last = rowStart;
            x = x + 1;
            while (rowStart->down != NULL)
            {
                rowStart = rowStart->down;
                if (rowStart = current2)
                {
                    return x;
                }
            }

            rowStart = temp_last;
            while (rowStart->top != NULL)
            {
                rowStart = rowStart->top;
                if (rowStart = current2)
                {
                    char1 = temp_last->text;
                    if (current2->left != NULL)
                        return x;
                    // for (int i = 1; i <= x; i++)
                    // {
                    //     current2 = current2->left;
                    // }
                    // char2 = current2->text;

                    // // return result = string(1, char1) + char2;
                    // // return to_string(char1) + to_string(char2);
                }
            }
            rowStart = temp_last;
            temp_last = NULL;
        }
    }
}

char kotakgeserkanan(address current, int kotaks)
{
    char text;
    int i = 1;
        while (current->right != NULL)
        {
            while (i <= kotaks)
            {
                current = current->right;
            }
            text = current->text;
            
        }

    }

char kotakgeserkiri(address current, int kotaks)
{
    char text;
    int i = 1;
        while (current->left != NULL)
        {
            while (i <= kotaks)
            {
                current = current->left;
            }
            text = current->text;
            
        }

}



int main()
{
    int size = 10; // var x var
    string pass = "Wakwaw1123 olo";
    string hasil;
    address head;
    hasil = unik(pass);
    head = createTable(size, hasil);

    display_table(head, size);
}