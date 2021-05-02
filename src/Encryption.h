#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Functions.h"


void EncryptMess()
{
    Encryption_header();


    // Take Encryption Key <e> from clipboard
    std::cout << "\n\nEncryption Key : ";
    std::cin.ignore(1000, '\n');
    unsigned long long e, N;
    scanf_s("(%llu, %llu)", &e, &N);


    // Get plain message from user
    std::cout << "\n\nYour message : ";
    std::cin.ignore(1000, '\n');

    std::string plain_message;
    getline(std::cin, plain_message);


    // Save encrypted message to binary file
    std::ofstream outFile("EncryptedMessage.dat", std::ios::out | std::ios::binary | std::ios::trunc);
    if (outFile)
    {
        // Encrypt message
        // ciphier_message = pow(plain_message, e) MOD N
        for (int i = 0; i < plain_message.size(); i++)
        {
            unsigned long long ch = (unsigned long long)pow((int)plain_message[i], e) % N;
            outFile.write(reinterpret_cast<const char*>(&ch), sizeof(ch));
        }
    }
    outFile.close();

    std::cout << "\n\nYour encrypted message has been saved to file. Send this file to a friend.\n\n";

    system("pause");
}