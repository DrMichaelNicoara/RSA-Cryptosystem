#pragma once
//Encryption(e)/Decription(d) key
long long e = 0, d = 0, N, phi;

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void intro()
{
    drawLine(60, '_');
    cout << "\n\n\n\n\t\tRivest-Shamir-Adleman Cryptosystem\n\n\nMade by : Nicoara Mihai\n";
    drawLine(60, '_');
}

bool coprime(long long a, long long b)
{
    long long t;
    while (b)
    {
        t = b;
        b = a % t;
        a = t;
    }
    if (a == 1)return true;
    else return false;
}