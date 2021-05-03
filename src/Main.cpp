#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <fstream>

#include "KeyGenerator.h"
#include "Encryption.h"
#include "Decryption.h"
#include "Functions.h"
#include "Clipboard.h"


int main()
{	
    intro();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	srand(time(0));

	while (1)
	{
        Main_header();
        

        // Options
        std::cout << "\n\n1).Generate Encryption/Decryption Keys";
        std::cout << "\n2).Encrypt message";
        std::cout << "\n3).Decrypt message";
        std::cout << "\n4).Exit";


        // MENU
        int opt;
        do {
            std::cout << "\n\nI want to go to option : ";
            std::cin >> opt;
        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);

        switch (opt)
        {
        case 1: GenerateKeys();
            break;
        case 2: EncryptMess();
            break;
        case 3: DecryptMess();
            break;
        case 4: 
            system("cls");
            std::cout << "Program has been canceled.\n";
            exit(0);
        }
	}

	return 0;
}