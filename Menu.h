#pragma once

void menu()
{
    system("cls");
    cout << "\n\n";
    drawLine(80, '_');
    cout << "\n\t\t\t\tTutorial\n\n";
    cout << "1).In order to encrypt/decrypt your message you will need a key that will be generated in the option 1\n";
    cout << "2).Take that key and go to option 2. Here you can type your message and encrypt it with the public key\n";
    cout << "3).Then you can copy the encrypted message and go to option 3 were you can decrypt it\n";
    drawLine(80, '_');

    cout << "\n\n1).Generate encryption/decryption keys";
    cout << "\n2).Encrypt message";
    cout << "\n3).Decrypt message";

    cin.ignore(1000, '\n');
    int opt;
    do {
        cout << "\nI want to go to option : ";
        cin >> opt;
    } while (opt != 1 && opt != 2 && opt != 3);

    switch (opt)
    {
    case 1: GenerateKeys();
        break;
    case 2: EncryptMess();
        break;
    case 3: DecryptMess();
        break;
    }
}