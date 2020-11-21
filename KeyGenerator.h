#pragma once

void GenerateKeys()
{
    beginning:
    system("cls");
    cout << "\n\n";
    drawLine(80, '_');
    cout << "\n\n\n\n\tGenerate Encryption/Decryption Key\n\n\n\n";
    drawLine(80, '_');
    /*
    //Choose 2 prime numbers in the range (10^6 , 2*10^6) from file
    long long prime1, prime2;
    int nth;
    nth = rand() % 70434 + 1;
    file.open("PrimeNumbers.txt");
    file.close(); //It fails to read from the file for prime1 otherwise [WHY ?]

    file.open("PrimeNumbers.txt");
    do {
        file >> prime1;
        nth--;
    } while (nth > 0);
    file.close();

    nth = rand() % 70434 + 1;
    file.open("PrimeNumbers.txt");
    do {
        file >> prime2;
        nth--;
    } while (nth > 0);
    file.close();


    N = prime1 * prime2;
    phi = (prime1 - 1) * (prime2 - 1);
    
    //Encryption key
    e = 3;
    while (!coprime(e, N) || !coprime(e, phi))
    {
        if (e < phi)
            e += 2;
        else goto beginning;
    }
    cout << "\n\nThe encryption(public) key is : " << e;

    //Decryption key
    //From the keys that respect the formula, I will choose a random one.
    short iterations = rand() % 10 + 1; //Between 1 and 10
    d = phi/e + 1;
    while (1)
    {
        d--;
        if ((d * e) % phi == 1)
            break;
    }
    //d += phi * iterations; //Just makes the private key bigger
    cout << "\nThe decryption(private) key is : " << d;
    */

    e = 2;
    d = 7;
    N = 14;
    cout << "\n\nThe encryption(public) key is : (" << e << ", " << N << ")";
    cout << "\nThe decryption(private) key is : (" << d << ", " << N << ")";

    cout << "\n\n";
    system("pause");
    menu();
}