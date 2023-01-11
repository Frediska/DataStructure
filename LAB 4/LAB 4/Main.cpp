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

string InputString(string outputString)
{
	if (outputString != "")
	{
		cout << outputString;
	}
	string str;
	cin >> str;
	return str;
}

void ShowHashTable(HashTable* table)
{
	Node* current;
	for (int i = 0; i < table->Size; i++)
	{
		current = table->Array[i]->Head;
		if (current == nullptr)
		{
			cout << "Key: [ ] - Value: [ ]\n";
			continue;
		}
		if (current->Next == nullptr)
		{
			cout << "Key: " << "[" << current->Key << "]" << " - Value: " << "[" << current->Value << "]" << endl;
			continue;
		}
		while (current != nullptr)
		{
			cout << "Key: " << "[" << current->Key << "]" << " - Value: " << "[" << current->Value << "]" << " -> ";
			current = current->Next;
		}
		cout << endl;
	}
	cout << "Count of element:" << table->Count << endl;

	/*Node* current;
	for (int i = 0; i < table->Size; i++)
	{
		current = table->Array[i]->Head;

		if (current != nullptr)
		{
			cout << "[" << i << "] " << current->Key << " : " << current->Value << endl;
			current = current->Next;

			while (current != nullptr)
			{
				cout << " >> ";
				cout << "[" << i << "] " << current->Key << " : " << current->Value << endl;
				current = current->Next;
			}
		}
		else
		{
			cout << "[" << i << "] _ : _" << endl;
		}
	}*/
}

void MenuDictionary()
{
	Dictionary* dictionary = new Dictionary();
	cout << "Work with Hash Table." << endl;

	while (true)
	{
		cout << "1. Add element to dictionary.\n2. Remove element from dictionary.\n"
			"3. Find element by key.\n0. Exit to main menu.\n";
		int taskNumber = CheckingForDigit("Enter number action: ");

		switch (taskNumber)
		{
		case 1:
		{
			string key = InputString("Enter a key: ");
			string value = InputString("Enter a value: ");
			Node* node = CreateNode(key, value);
			if (!InsertElement(dictionary, node, key))
			{
				cout << "This element already exists." << endl;
			}
			ShowHashTable(dictionary->Table);
			break;
		}
		case 2:
		{
			string key = InputString("Enter a key: ");
			if (!RemoveElement(dictionary, key))
			{
				cout << "This element does not exist." << endl;
			}
			ShowHashTable(dictionary->Table);
			break;
		}
		case 3:
		{
			string key = InputString("Enter a key: ");
			string data;
			if (FindElement(dictionary, key, data))
			{
				cout << "Found information: " << data << endl;
			}
			else
			{
				cout << "Not Found." << endl;
			}
			break;
		}
		case 0:
		{
			DeleteDictionary(dictionary);
			system("cls");
			return;
		}
		default:
		{
			cout << "Enter correct number of action." << endl;
			break;
		}
		}
	}
}


void MenuHashTable()
{
	HashTable* table = CreateHashTable(4);

	cout << "Work with Hash Table." << endl;
	
	while (true)
	{
		cout << "1. Add element to hash table.\n2. Remove element from table.\n"
			"3. Find element by key.\n0. Exit to main menu.\n";
		int taskNumber = CheckingForDigit("Enter number action: ");

		switch (taskNumber)
		{
			case 1:
			{
				string key = InputString("Enter a key: ");
				string value = InputString("Enter a value: ");
				Node* node = CreateNode(key, value);
				int index = HashFunc(key, table->Size);
				if (!InsertElement(table, node, index))
				{
					cout << "This element already exists." << endl;
				}
				ShowHashTable(table);
				break;
			}
			case 2:
			{
				string key = InputString("Enter a key: ");
				if (!RemoveElement(table, key))
				{
					cout << "This element does not exist." << endl;
				}
				ShowHashTable(table);
				break;
			}
			case 3:
			{
				string key = InputString("Enter a key: ");
				string data;
				if (FindElement(table, key, data))
				{
					cout << "Found information: " << data << endl;
				}
				else
				{
					cout << "Not Found." << endl;
				}
				break;
			}
			case 0:
			{
				DeleteTable(table);
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}

int main()
{
	cout << "Choose which function you want to use: " << endl;

	while (true)
	{
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
	
}