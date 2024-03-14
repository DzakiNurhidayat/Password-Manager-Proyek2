#include <iostream>
#include "Sulthan.h"
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
    unsigned char ciphertext[] = ""; //masukan cipher text
    unsigned char key[16] =
    {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12,
    13, 14, 15, 16,
    };
}

void AES_Decryption()
{

};

void INV_SubBytes(unsigned state[16])
{
    for (int i = 0; i < 16; i++)
        state[i] = INV_SBOX[state[i]]; /*Mengubah character yang ada di index jadi apa yang ada di SBOX INVERS*/
};
void INV_MixColumns()
{

};
void INV_ShifRows()
{

};