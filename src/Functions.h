#pragma once
#include <iostream>

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
    std::cout << "\n\t\t\t\tTutorial\n\n";
    std::cout << "1).In order to encrypt/decrypt your message you will need a key that will be generated in the option 1\n";
    std::cout << "2).Take that key and go to option 2. Here you can type your message and encrypt it with the public key\n";
    std::cout << "3).Then you can copy the encrypted message and go to option 3 were you can decrypt it\n";
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
    std::cout << "\n\n\n\n\t\tDecrypt Your Message\n\n\n\n";
    drawLine(80, '_');
}


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
