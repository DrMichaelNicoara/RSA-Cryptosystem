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
        inFile.read(reinterpret_cast<char*>(&d), sizeof(unsigned long long));
        inFile.read(reinterpret_cast<char*>(&N), sizeof(unsigned long long));

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
    

    // Get Encrypted Message size
    unsigned long long file_size;
    std::ifstream File("EncryptedMessage.dat", std::ios::in | std::ios::binary);
    File.seekg(0, std::ios::end);
    file_size = File.tellg();
    File.close();

    // Get Encrypted Message from binary file
    std::string message;
    std::ifstream inFile2("EncryptedMessage.dat", std::ios::in | std::ios::binary);
    
    if (inFile2)
    {
        unsigned long long ch;

        // Decrypt Message
        // plain_message = pow(cipher_message, d) MOD N
        for (int i = 0; i < file_size / sizeof(ch); i++)
        {
            inFile2.read(reinterpret_cast<char*>(&ch), sizeof(ch));
            message.resize(message.size() + 1, (char)big_number_mod(ch, d, N));
        }
    }
    else
    {
        std::cout << "\nThe file containing the Encrypted Message could not be opened.\n";
        exit(1);
    }
    inFile2.close();


    // Print Decrypted Message on screen
    std::cout << "\n\nDecrypted message : " << message << std::endl << std::endl;

    system("pause");
}