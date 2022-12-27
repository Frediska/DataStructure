#include <iostream>
#include "Dictionary.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "An error has occurred. Try again." << endl;
			continue;
		}

		cin.ignore(32767, '\n');
		if (cin.gcount() > 1)
		{
			cout << "An error has occurred. Try again." << endl;
			continue;
		}
		break;
	}
	return value;
}

void MenuHashTable()
{
	HashTable* table = CreateHashTable(4);

	int taskNumber = CheckingForDigit("Enter number action: ");
	
	switch (taskNumber)
	{
		case 1:
		{

		}

		default:
		{
			cout << "Enter correct number of action." << endl;
			break;
		}
		
	}
}

int main()
{
	cout << "Choose which function you want to use: " << endl;
	cout << "1. Hash Table.\n2. Dictionary.\n";

	int taskNumber = CheckingForDigit("Enter function number: ");
	switch (taskNumber)
	{
		case 1:
		{
			system("cls");
			MenuHashTable();
			break;
		}
		case 2:
		{
			system("cls");
			MenuDictionary();
			break;
		}
		default:
		{
			cout << "Enter correct number of action." << endl;
			break;
		}
	}
}