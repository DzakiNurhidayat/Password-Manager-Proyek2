#include "playfair.h"


// // nanti fungsi ini ganti nama jadi main_encrypt 
string encryption(string loggedInUser, string plainText) 
{
    string encrypted_text;
    int size_table = 10;
    string character;
    address Head;
    character = unique(loggedInUser);
    Head = createTable(size_table,character);
    
    char lastchar;
    if (plainText.length() % 2 != 0)
    {
        lastchar = plainText[plainText.length() - 1];
        plainText.pop_back();                                           
        encrypted_text = encryptionPlayfair(Head, plainText);          
        encrypted_text.push_back(lastchar);
    }
    else
    {
        encrypted_text = encryptionPlayfair(Head, plainText);
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
string encryptionPlayfair(address Head, string plainText)
{
    string encrypted_text;
    address addressC1, addressC2;

    bool col, row;
    char c1, c2;

    for (int i = 0; i < plainText.length(); i += 2)
    {
        c1 = plainText[i];
        c2 = plainText[i + 1];

        addressC1 = searchingNode(Head, c1);
        addressC2 = searchingNode(Head, c2);

        if (c1 != c2)
        {
            col = checkVertical(addressC1, addressC2);
            row = checkHorizontal(addressC1, addressC2);
            if (row == true) // same row
            {

                encrypted_text += sameRowEncrypt(addressC1);
                encrypted_text += sameRowEncrypt(addressC2);
            }
            else if (col == true) // same col
            {
                encrypted_text += sameColEncrypt(addressC1);
                encrypted_text += sameColEncrypt(addressC2);
            }
            else // no same
            {
                encrypted_text += differentColRow(addressC1, addressC2);
                encrypted_text += differentColRow(addressC2, addressC1);
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

char sameRowEncrypt(address addressC)
{
    char text;
    address temp = addressC;
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

char sameColEncrypt(address addressC)
{
    char text;
    address temp = addressC;
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
