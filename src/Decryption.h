#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"


void DecryptMess()
{
    Decryption_header();


    unsigned long long d, N;

    // Read Encryption Key <d> from local file
    std::ifstream inFile("DecryptionKey.dat", std::ios::in | std::ios::binary);
    if (inFile)
    {
        unsigned long long tmp;
        inFile.read(reinterpret_cast<char*>(&tmp), sizeof(unsigned long long));
        d = tmp;

        inFile.read(reinterpret_cast<char*>(&tmp), sizeof(unsigned long long));
        N = tmp;

        std::cout << "\n\nDecryption Key : (" << d << ", " << N << ")";
    }
    else
    {
        std::cout << "\n\nThe file containing the Decryption Key could not be opened. Enter the Decryption Key manually.";
        std::cout << "\n\nDecryption Key : (d, N)";
        std::cout << "\nd = "; std::cin >> d;
        std::cout << "\nN = "; std::cin >> N;
    }
    inFile.close();
    

    // Get Decryption Message from binary file
    std::string plain_message;
    std::ifstream inFile2("EncryptedMessage.dat", std::ios::in | std::ios::binary);
    
    if (inFile2)
    {
        unsigned long long ch;

        // Decrypt Message
        // plain_message = pow(cipher_message, d) MOD N
        for (int i = 0; i < sizeof(inFile2)/sizeof(unsigned long long); i++)
        {
            inFile2.read(reinterpret_cast<char*>(&ch), sizeof(ch));
            plain_message[i] = (char) ((unsigned long long)pow(ch, d) % N);
        }
    }
    else
    {
        std::cout << "\nThe file containing the Encrypted Message could not be opened.\n";
        exit(1);
    }
    inFile2.close();


    // Print Decrypted Message on screen
    std::cout << "\n\nDecrypted message : " << plain_message << std::endl << std::endl;

    system("pause");
}