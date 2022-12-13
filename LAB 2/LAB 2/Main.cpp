#include <iostream>
#include "DoubleLinkedList.h"

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
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cout << "" << endl;
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "" << endl;
			continue;
		}

		break;
	}

	return value;
}

int main()
{
	DoubleLinkedList* list = new DoubleLinkedList();

	while (true)
	{
		int number = CheckingForDigit(" ");
	}
}