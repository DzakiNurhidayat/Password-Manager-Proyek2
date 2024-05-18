#include "playfair.h"

string decryption(string loggedInUser, string cipherText)
{

    string decrypted_text;
    string hasil;
    address head;
    int size = 10;
    hasil = unik(loggedInUser);
    head = createTable(size, hasil);

    char lastchar;

    if (cipherText.length() % 2 != 0)
    {
        lastchar = cipherText[cipherText.length() - 1];
        cipherText.pop_back();
        decrypted_text = decryption_playfair(head, cipherText);
        decrypted_text.push_back(lastchar);
    }
    else
    {
        decrypted_text = decryption_playfair(head, cipherText);
    }

    return decrypted_text;
}

string decryption_playfair(address Head, string ciphertext)
{
    string decrypted_text;
    address address1, address2;

    bool col, row;
    char c1, c2;

    for (int i = 0; i < ciphertext.length(); i += 2)
    {
        c1 = ciphertext[i];
        c2 = ciphertext[i + 1];

        address1 = searchingNode(Head, c1); // dapet address c1
        address2 = searchingNode(Head, c2);

        if (c1 != c2)
        {
            col = cek_vertikal(address1, address2);
            row = cek_horizontal(address1, address2);
            cout << " col = " << col << endl;
            cout << " row = " << row << endl;
            if (row == true) // same row
            {

                decrypted_text += samerow_dec(address1);
                decrypted_text += samerow_dec(address2);
            }
            else if (col == true) // same col
            {
                decrypted_text += samecol_dec(address1);
                decrypted_text += samecol_dec(address2);
            }
            else // no same
            {
                decrypted_text += kotak(address1, address2);
                decrypted_text += kotak(address2, address1);
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

char samerow_dec(address c1)
{
    char text;
    address temp = c1;
    if (temp->left == NULL)
    {
        while (temp->right != NULL)
        {
            c1 = temp->right;
        }
        text = temp->text;
    }
    else
    {
        text = temp->left->text;
    }
    return text;
}

char samecol_dec(address c1)
{
    char text;
    address temp = c1;
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