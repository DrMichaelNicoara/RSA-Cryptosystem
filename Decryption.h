#pragma once

void DecryptMess()
{
    system("cls");
    cout << "\n\n";
    drawLine(80, '_');
    cout << "\n\n\n\n\t\tDecrypt Your Message\n\n\n\n";
    drawLine(80, '_');

    char c = 'N';
    cout << "\n\nDecryption Key : ";
    if (d)
    {
        do {
            cout << d << "\nN = " << N << "\nUse different key(Y/N) : ";
            cin.ignore(1000, '\n');
            c = getchar();
            c = toupper(c);
        } while (c != 'Y' && c != 'N');

        if (c == 'Y')
        {
            d = 0;
            DecryptMess();
        }
    }
    else
    {
        cin >> d;
        cout << "N = "; cin >> N;
    }

//    string message;
    cout << "\n\nYour encrypted message : ";
    if (c == 'N')
    {
       // clipboard >> message;
        cout << message;
    }
    else
    {
        cin.ignore(1000, '\n');
        getline(cin, message);
    }

    for (int i = 0; i < message.size(); i++)
        message[i] = (long long)pow((int)message[i], d) % N;

    cout << "\n\nDecrypted message : " << message;
   // clipboard << message;
    //cout << "\nTEXT HAS BEEN AUTOMATICALLY COPIED TO CLIPBOARD.\n\n";

    system("pause");
    menu();
}