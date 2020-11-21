#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
string message;

#include "Clipboard.h"
CClipboardXX clipboard;
ifstream file("PrimeNumbers.txt");


#include "Functions.h"
void GenerateKeys();
void EncryptMess();
void DecryptMess();
#include "Menu.h"
#include "KeyGenerator.h"
#include "Encryption.h"
#include "Decryption.h"

int main()
{
	//intro();
	//Sleep(5000);
	
	srand(time(0));
	menu();

	return 0;
}