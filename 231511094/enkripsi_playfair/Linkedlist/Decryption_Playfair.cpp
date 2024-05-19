#include "playfair.h"

string decryption(string loggedInUser, string cipherText)
{

    string decrypted_text;
    string character;
    address head;
    int size = 10;
    character = unique(loggedInUser);
    head = createTable(size, character);

    char lastchar;

    if (cipherText.length() % 2 != 0)
    {
        lastchar = cipherText[cipherText.length() - 1];
        cipherText.pop_back();
        decrypted_text = decryptionPlayfair(head, cipherText);
        decrypted_text.push_back(lastchar);
    }
    else
    {
        decrypted_text = decryptionPlayfair(head, cipherText);
    }

    return decrypted_text;
}

// // aturan ketika enkripsi/dekripsi playfair
// // 1. jika di kolom yang sama maka
// // 2. jika di baris yang sama
// // 3. jika di tidak ada yang sama
// // 4. jika kolom dan baris nya sama

/*tempat dimana kata kata di ubah*/
string decryptionPlayfair(address Head, string cipherText)
{
    string decrypted_text;
    address addressC1, addressC2;

    bool col, row;
    char c1, c2;

    for (int i = 0; i < cipherText.length(); i += 2)
    {
        c1 = cipherText[i];
        c2 = cipherText[i + 1];

        addressC1 = searchingNode(Head, c1); // dapet address c1
        addressC2 = searchingNode(Head, c2);

        if (c1 != c2)
        {
            col = checkVertical(addressC1, addressC2);
            row = checkHorizontal(addressC1, addressC2);
            if (row == true) // same row
            {

                decrypted_text += sameRowDecrypt(addressC1);
                decrypted_text += sameRowDecrypt(addressC2);
            }
            else if (col == true) // same col
            {
                decrypted_text += sameColDecrypt(addressC1);
                decrypted_text += sameColDecrypt(addressC2);
            }
            else // no same
            {
                decrypted_text += differentColRow(addressC1, addressC2);
                decrypted_text += differentColRow(addressC2, addressC1);
            }
        }
        else
        {
            decrypted_text += c1;
            decrypted_text += c2;
        }
    }
    return decrypted_text;
}

char sameRowDecrypt(address addressC)
{
    char text;
    address temp = addressC;
    if (temp->left == NULL)
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        text = temp->text;
    }
    else
    {
        text = temp->left->text;
    }
    return text;
}

char sameColDecrypt(address addressC)
{
    char text;
    address temp = addressC;
    if (temp->top == NULL)
    {
        while (temp->down != NULL)
        {
            temp = temp->down;
        }
        text = temp->text;
    }
    else
    {
        text = temp->top->text;
    }
    return text;
}