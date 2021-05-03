#pragma once
#include "Functions.h"
#include "Clipboard.h"
#include <fstream>
#include <string>
#include <fileapi.h>
#define NUMBER_OF_PRIMES 143  // In the PrimeNumbers.txt

void GenerateKeys()
{
    GenerateKeys_header();
    

    // Choose 2 random prime numbers in the range (100, 1000) from file
    unsigned long long prime1, prime2;

    int nth = rand() % (NUMBER_OF_PRIMES - 1) + 1; // (1, NUMBER_OF_PRIMES)
    std::ifstream inFile("Dependencies/PrimeNumbers.txt", std::ios::in);
    SetFileAttributesA("Dependencies", FILE_ATTRIBUTE_HIDDEN);

    do
    {
        inFile >> prime1;
        nth--;
    } while (nth);

    nth = rand() % (NUMBER_OF_PRIMES - 1) + 1; // (1, NUMBER_OF_PRIMES)
    inFile.seekg(0, std::ios::beg); // Sends the cursor to the beggining of the file
    do
    {
        inFile >> prime2;
        nth--;
    } while (nth);
    inFile.close();

    unsigned long long N = prime1 * prime2;
    unsigned long long phi = (prime1 - 1) * (prime2 - 1);


    /// Encryption Key <e>
    /// Conditions :
    /// 1 < <e> < phi
    /// coprime(<e>, N) && coprime(<e>, phi) => <e> must be odd
    
    unsigned long long e = 3; // First possible value for <e> is 3
    while (!coprime(e, N) || !coprime(e, phi))
    {
        if (e < phi)
            e += 2;
        else GenerateKeys(); // ERROR! Go back and redo everything
    }


    /// Decryption Key <d>
    /// Conditions :
    /// <d>*<e> % phi = 1   <=>   d = if_integer( (phi*i + 1)/<e> ) , where i is a nenul natural number

    unsigned long long d;
    for (int i = 1; ; i++)
    {
        double tmp = (double)(phi * i + 1) / e;
        if (floor(tmp) == tmp) // if is_integer()
        {
            d = tmp;
            break;
        }
    }
   
    std::cout << "\n\nThe encryption(public) key is : (" << e << ", " << N << ")";
    std::cout << "\nThe decryption(private) key is : (" << d << ", " << N << ")";


    // Copy Encryption Key <e> to clipboard
    std::string copy = "Encryption Key : (" + std::to_string(e) + ", " + std::to_string(N) + ")";
    write_clipboard(copy.c_str());

    std::cout << "\n\n\nEncryption Key has been automatically copied to clipboard";


    // Save Decryption Key <d> to binary file
    std::ofstream outFile("DecryptionKey.dat", std::ios::out | std::ios::binary | std::ios::trunc);
    SetFileAttributesA("DecryptionKey.dat", FILE_ATTRIBUTE_HIDDEN);

    if (outFile)
    {
        outFile.write(reinterpret_cast<const char*>(&d), sizeof(d));
        outFile.write(reinterpret_cast<const char*>(&N), sizeof(N));
        std::cout << "\nDecryption Key has been automatically saved locally. DO NOT SHARE THIS KEY!\n\n";
    }
    else std::cout << "\nDecryption Key couldn't been saved locally. Please remember it. DO NOT SHARE THIS KEY!\n\n";
    outFile.close();

    system("pause");
}