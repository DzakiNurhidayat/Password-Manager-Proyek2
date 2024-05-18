#include "playfair.h"


// // nanti fungsi ini ganti nama jadi main_encrypt 
string encryption(string loggedInUser, string plainText) 
{
    string encrypted_text;
    int size = 10;
    string hasil;
    address Head;
    hasil = unik(loggedInUser);
    Head = createTable(size,hasil);
    
    char lastchar;
   

    if (plainText.length() % 2 != 0)
    {
        lastchar = plainText[plainText.length() - 1];
        plainText.pop_back();                                           
        encrypted_text = encryption_playfair(Head, plainText);          
        encrypted_text.push_back(lastchar);
    }
    else
    {
        encrypted_text = encryption_playfair(Head, plainText);
    }

    cout << "| Hasil enkripsi : " << encrypted_text << endl;
    return encrypted_text;
}


// // aturan ketika enkripsi/dekripsi playfair
// // 1. jika di kolom yang sama maka
// // 2. jika di baris yang sama
// // 3. jika di tidak ada yang sama
// // 4. jika kolom dan baris nya sama

/*tempat dimana kata kata di ubah*/
string encryption_playfair(address Head, string plaintext)
{
    string encrypted_text;
    address address1, address2;

    bool col, row;
    char c1, c2;

    for (int i = 0; i < plaintext.length(); i += 2)
    {
        c1 = plaintext[i];
        c2 = plaintext[i + 1];

        address1 = searchingNode(Head, c1);
        address2 = searchingNode(Head, c2);

        if (c1 != c2)
        {
            col = cek_vertikal(address1, address2);
            row = cek_horizontal(address1, address2);
            if (row == true) // same row
            {

                encrypted_text += samerow_enc(address1);
                encrypted_text += samerow_enc(address2);
            }
            else if (col == true) // same col
            {
                encrypted_text += samecol_enc(address1);
                encrypted_text += samecol_enc(address2);
            }
            else // no same
            {
                encrypted_text += kotak(address1, address2);
                encrypted_text += kotak(address2, address1);
            }
        }
        else
        {
            encrypted_text += c1;
            encrypted_text += c2;
        }
    }
    return encrypted_text;
}

char samerow_enc(address c1)
{
    char text;
    address temp = c1;
    if (temp->right == NULL)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        text = temp->text;
    }
    else
    {
        text = temp->right->text;
    }
    return text;
}

char samecol_enc(address c1)
{
    char text;
    address temp = c1;
    if (temp->down == NULL)
    {
        while (temp->top != NULL)
        {
            temp = temp->top;
        }
        text = temp->text;
    }
    else
    {
        text = temp->down->text;
    }
    return text;
}
