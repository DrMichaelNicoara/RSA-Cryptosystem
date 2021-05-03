#pragma once
#include <iostream>

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        std::cout << symbol;
    std::cout << "\n";
}

bool coprime(long long a, long long b)
{
    long long t;
    while (b)
    {
        t = b;
        b = a % t;
        a = t;
    }
    if (a == 1)return true;
    else return false;
}

unsigned long long big_number_mod(unsigned long long x, unsigned long long y, unsigned long long N)
{
    // The number x^y is too big to calculate, so we take the modulus of N multiple times along the way
    unsigned long long result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
        result %= N;
    }
    return result;
}

void intro()
{
    drawLine(60, '_');
    std::cout << "\n\n\n\n\t\tRivest-Shamir-Adleman Cryptosystem\n\n\nMade by : Nicoara Mihai\n";
    drawLine(60, '_');
}

void Main_header()
{
    system("cls");
    std::cout << "\n\n";
    drawLine(80, '_');
    std::cout << "\n\t\t\t\tInstructions\n\n";
    std::cout << "SEND MESSAGE TO FRIEND\n";
    std::cout << "1).Get Encryption Key from friend and copy only the parentheses : (e, N)\n";
    std::cout << "2).Choose option 2, press CTRL+V to paste the Encryption Key and type in your message\n";
    std::cout << "3).A file has been created next to your executable. Send it to your friend\n";

    std::cout << "\nREAD FRIEND'S MESSAGE\n";
    std::cout << "1).Choose option 1 and create Encryption/Decryption Key. The Encryption Key was copied to clipboard. Send it to your friend.\n";
    std::cout << "2).Download friend's EncryptedMessage FILE and PLACE IT NEXT TO YOUR EXECUTABLE\n";
    std::cout << "3).Choose option 3. The Decryption Key will be copied from your DecryptionKey FILE and the decrypted message will appear\n";

    std::cout << "\nTIP : If you accidentally create a new Encryption/Decryption Key, you need to send the new Encryption Key to your friend\n";
    std::cout << "\nDO NOT CHANGE FILE NAMES!\n";
    drawLine(80, '_');
}

void GenerateKeys_header()
{
    system("cls");
    std::cout << "\n\n";
    drawLine(80, '_');
    std::cout << "\n\n\n\n\tGenerate Encryption/Decryption Key\n\n\n\n";
    drawLine(80, '_');
}

void Encryption_header()
{
    system("cls");
    std::cout << "\n\n";
    drawLine(80, '_');
    std::cout << "\n\n\n\n\t\tEncrypt Your Message\n\n\n\n";
    drawLine(80, '_');
}

void Decryption_header()
{
    system("cls");
    std::cout << "\n\n";
    drawLine(80, '_');
    std::cout << "\n\n\n\n\t\tDecrypt Friend's Message\n\n\n\n";
    drawLine(80, '_');
}


