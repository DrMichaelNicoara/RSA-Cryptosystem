#pragma once

void EncryptMess()
{
    beginning:
    system("cls");
    cout << "\n\n";
    drawLine(80, '_');
    cout << "\n\n\n\n\t\tEncrypt Your Message\n\n\n\n";
    drawLine(80, '_');

    cout << "\n\nEncryption Key : ";
    if (e)
    {
        char c;
        do {
            cout << e << "\nN = " << N << "\nUse different key(Y/N) : ";
            cin.ignore();
            c = getchar();
            c = toupper(c);
        } while (c != 'Y' && c != 'N');

        if (c == 'Y')
        {
            e = 0;
            goto beginning;
        }
    }
    else
    {
        cin >> e;
        cout << "N = "; cin >> N;
    }

    //string message;
    cout << "\n\nYour message : ";
    cin.ignore(1000, '\n');
    getline(cin, message);

    for (int i = 0; i < message.size(); i++)
        message[i] = (long long)pow((int)message[i], e) % N;

    cout << "\n\nEncrypted message : " << message;
    //clipboard << message;
    //cout << "\nTEXT HAS BEEN AUTOMATICALLY COPIED TO CLIPBOARD.\n\n";

    system("pause");
    menu();
}