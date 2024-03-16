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

void AES_Decryption(unsigned char *ciphertext,unsigned char *extendedKey)
{
    unsigned char state[16];
    for (int i = 0;i <16 ; i++)
    {
        state[i] = ciphertext[i];
    }
    unsigned char expandedKey[176];

    /*Round 0*/
    //Addroundkey? / Subround key?
    INV_ShifRow(state);
    INV_SubBytes(state);

    int round = 9;
    for (int i = 0; i <round; i++)
    {
        INV_ShifRow(state);
        INV_SubBytes(state);
        AddRoundKey(state, extendedKey); // disinimasukan Key yang sudah di operasikan dengan addroundkey
        INV_MixColumns(state);
    }
    /*Final Round*/
    //addRound key


};

void INV_SubBytes(unsigned state[16])
{
    for (int i = 0; i < 16; i++)
        state[i] = INV_SBOX[state[i]]; /*Mengubah character yang ada di index jadi apa yang ada di SBOX INVERS*/
};
void INV_MixColumns()
{

};
void INV_ShifRow(unsigned char *state) /* melakukan Invers shiftrow di putar ke kanan*/
{
    unsigned char temp[16];
    temp[0] = state[0];
    temp[1] = state[13];
    temp[2] = state[10];
    temp[3] = state[7];

    temp[4] = state[4];
    temp[5] = state[1];
    temp[6] = state[14];
    temp[7] = state[11];

    temp[8] = state[8];
    temp[9] = state[5];
    temp[10] = state[2];
    temp[11] = state[15];

    temp[12] = state[12];
    temp[13] = state[9];
    temp[14] = state[6];
    temp[15] = state[3];
};