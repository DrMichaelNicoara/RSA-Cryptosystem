#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Functions.h"


void EncryptMess()
{
    Encryption_header;


    // Take Encryption Key <e> from clipboard
    std::cout << "\n\nEncryption Key : ";
    std::cin.ignore(100, '\n');
    unsigned long long e, N;
    scanf_s("(%llu, %llu)", &e, &N);


    // Get plain message from user
    std::cout << "\n\nYour message : ";
    std::cin.ignore(1000, '\n');

    std::string message;
    getline(std::cin, message);


    // Encrypt message
    for (int i = 0; i < message.size(); i++)
    {
        unsigned long long ch = (unsigned long long)pow((int)message[i] - 'A' + 1, e) % N;
        message[i] = (char)(ch + 'A' - 1);
    }


    // Save encrypted message to binary file
    std::ofstream outFile("EncryptedMessage.dat", std::ios::out | std::ios::binary | std::ios::trunc);

    if (outFile)
    {
        outFile.write(reinterpret_cast<const char*>(&message), sizeof(message));
        std::cout << "\n\nYour encrypted message has been saved to file. Send this file to a friend.\n\n";
    }
    outFile.close();

    system("pause");
}