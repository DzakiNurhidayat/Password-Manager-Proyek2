#include <iostream>
#include <fstream>
#include <stdio.h>
#include "AES.h"
#include <conio.h>
// http://aes.online-domain-tools.com/ cheack AES
using namespace std;

int main()
{
    unsigned char plaintext[] = "Ini adalah text yang akan di enkripsi!"; //massage(plaintext)
    unsigned char key[16] =
    {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12,
    13, 14, 15, 16,
    };

    int originalLen = sizeof(plaintext) - 1; // panjang massage
    int lenOfPaddedMessage = originalLen;

    if(lenOfPaddedMessage % 16 !=0)
    {
        lenOfPaddedMessage = (lenOfPaddedMessage / 16 + 1) * 16;
    }

    unsigned char *paddedMessage = new unsigned char[lenOfPaddedMessage];
    for (int i = 0; i < lenOfPaddedMessage; i++)
    {
        if (i >= originalLen) 
        {
            paddedMessage[i] = 0;
        }
        else
        {
            paddedMessage[i] = plaintext[i];
        }
    }

    AES_Encrypt(plaintext, key);

    //Encrypt padded message:
    for (int i = 0; i < lenOfPaddedMessage; i +=16)
    {
        AES_Encrypt(paddedMessage + i, key);
    }

    cout << "\nEncrypted message:" << endl;
    for (int i = 0; i < lenOfPaddedMessage; i++)
    {
        PrintHex(paddedMessage[i]);
        cout<<" ";
    }
    cout << "\n";
    for (int i = 0; i < lenOfPaddedMessage; i++) // TESTING
    {
        cout << paddedMessage[i];
    }

    _getch();

    delete[] paddedMessage;
    return 0;
}

void AES_Encrypt(unsigned char *plaintexts, unsigned char *key)
{
    unsigned char state[16];
    for (int i = 0; i < 16; i++)
    {
        state[i] = plaintexts[i];
    }
    int Round = 9;
    unsigned char expandedKey[176];
    AddRoundKey(state, key);        //whitening/addRoundKey

    for (int i = 0; i < Round; i++)
    {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state,expandedKey + (16 *(i+1)));
    }

    /*Final round*/
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, expandedKey + 160);

    //copy over the message withe the encrypted message
    for (int i = 0; i < 16; i++)
    {
        plaintexts[i] = state[i];
    }
}

void AddRoundKey(unsigned char *state, unsigned char *roundKey) 
{
    for (int i = 0; i < 16; i++)
    {
        state[i] ^= roundKey[i];    /*operasi xor*/
    }
    
}
void SubBytes(unsigned char* state)
{
    for (int i = 0; i < 16; i++)
    {
        state[i] = SBOX[state[i]];/*Mengubah character yang ada di index jadi apa yang ada di SBOX*/
    }
    
}
void ShiftRows(unsigned char *state) /* Melakukan Shifrows*/
{
    unsigned char temp[16];

    temp[0] = state[0];
    temp[1] = state[5];
    temp[2] = state[10];
    temp[3] = state[15];

    temp[4] = state[4];
    temp[5] = state[9];
    temp[6] = state[14];
    temp[7] = state[3];

    temp[8] = state[8];
    temp[9] = state[13];
    temp[10] = state[2];
    temp[11] = state[7];

    temp[12] = state[12];
    temp[13] = state[1];
    temp[14] = state[6];
    temp[15] = state[11];

    for (int i = 0; i < 16; i++)
        state[i] = temp[i];
}
void MixColumns(unsigned char* state)
{ /*Explanation https://youtu.be/dRYHSf5A4lw?si=nc_Drx7G8ZSYg6xG*/
    // Dot product and byte mod of state

    unsigned char tmp[16];
    // Column 1 entries
    tmp[0] = (unsigned char)(mul2[state[0]] ^ mul3[state[1]] ^ state[2] ^ state[3]);
    tmp[1] = (unsigned char)(state[0] ^ mul2[state[1]] ^ mul3[state[2]] ^ state[3]);
    tmp[2] = (unsigned char)(state[0] ^ state[1] ^ mul2[state[2]] ^ mul3[state[3]]);
    tmp[3] = (unsigned char)(mul3[state[0]] ^ state[1] ^ state[2] ^ mul2[state[3]]);

    // Column 2 entries
    tmp[4] = (unsigned char)(mul2[state[4]] ^ mul3[state[5]] ^ state[6] ^ state[7]);
    tmp[5] = (unsigned char)(state[4] ^ mul2[state[5]] ^ mul3[state[6]] ^ state[7]);
    tmp[6] = (unsigned char)(state[4] ^ state[5] ^ mul2[state[6]] ^ mul3[state[7]]);
    tmp[7] = (unsigned char)(mul3[state[4]] ^ state[5] ^ state[6] ^ mul2[state[7]]);

    // Column 3 entries
    tmp[8] = (unsigned char)(mul2[state[8]] ^ mul3[state[9]] ^ state[10] ^ state[11]);
    tmp[9] = (unsigned char)(state[8] ^ mul2[state[9]] ^ mul3[state[10]] ^ state[11]);
    tmp[10] = (unsigned char)(state[8] ^ state[9] ^ mul2[state[10]] ^ mul3[state[11]]);
    tmp[11] = (unsigned char)(mul3[state[8]] ^ state[9] ^ state[10] ^ mul2[state[11]]);

    // Column 4 entries
    tmp[12] = (unsigned char)(mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15]);
    tmp[13] = (unsigned char)(state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15]);
    tmp[14] = (unsigned char)(state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]]);
    tmp[15] = (unsigned char)(mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]]);

    for (int i = 0; i < 16; i++)
        state[i] = tmp[i];
}

void KeyExpansionCore(unsigned char* in, unsigned char i)
{
    //rotate left:
    unsigned int *q = (unsigned int*)in;
    *q = (*q >> 8) | ((*q & 0xff) << 24);

    /*alternative
    unsigned char t = in[0];
    in[0] = in[1];
    in[1] = in[2];
    in[2] = in[3];
    in[3] = y;
    */

    in[0] = SBOX[in[0]];
    in[1] = SBOX[in[1]];
    in[2] = SBOX[in[2]];
    in[3] = SBOX[in[3]];

    //  RCon XOR
    in[0] ^= rcon[i];
}
void Keyexpansion(unsigned char *inputKey, unsigned char *expandedKeys)
{
    //The first 16 bytes are the original key:
    for (int i = 0; i < 16; i++)
    {
        expandedKeys[i] = inputKey[i];
    }
    int bytesGenerated = 16;// yang telah tergenerate adalah 16 bytes
    int rconIteration = 1;  //Rcon mulai dari 1
    unsigned char temp[4];  // temp storage untuk core

    while(bytesGenerated < 176)
        {
            for (int i = 0; i < 4; i++)
            {
                temp[i] = expandedKeys[i + bytesGenerated - 4];
            }
            if(bytesGenerated % 16 == 0)
            {
                KeyExpansionCore(temp, rconIteration++);
            }

        //XOR temp [bytesGenerate-16], and store in expandedKeys:
            for (unsigned char a = 0; a < 4;a++){
                expandedKeys[bytesGenerated] =
                    expandedKeys[bytesGenerated - 16] ^ temp[a];
                bytesGenerated++;
            }
        }
}
void PrintHex(unsigned char x)
{
    if (x / 16 < 10)
    {
        cout << (char)((x / 16) + '0');
    }
    if (x / 16 >= 10)
    {
        cout << (char)((x / 16 - 10) + 'A');
    }
    if (x % 16 < 10) // Corrected the condition here
    {
        cout << (char)((x % 16) + '0'); // Corrected the operation here
    }
    if (x % 16 >= 10) // Corrected the condition here
    {
        cout << (char)((x % 16 - 10) + 'A'); // Corrected the operation here
    }
}