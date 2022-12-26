#include <iostream>
#include "DoubleLinkedList.h"
#include "Service.h"
#include <chrono>

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

int main()
{
	DoubleLinkedList* list = new DoubleLinkedList();

    cout << "1. Print navigation text.\n2. Populate the doublelinked list with random values.\n"
        "3. Add new element in doublelinked list.\n4. Remove element in doublelinked list.\n"
        "5. Insert element in begin of doblelinked list.\n6. Insert element before of the some element.\n"
        "7. Insert element after of the some element.\n8. Sort doublelinked list.\n"
        "9. Linear search.\n10. Show doublelinked list.\n11. Remove doublelinked list.\n"
        "12. Operation for report." << endl;

	while (true)
	{
		int taskNumber = CheckingForDigit("Enter number of action: ");

        switch (taskNumber)
        {
            case 1:
            {
                cout << "1. Print navigation text.\n2. Populate the doublelinked list with random values.\n"
                    "3. Add new element in doublelinked list.\n4. Remove element in doublelinked list.\n"
                    "5. Insert element in begin of doblelinked list.\n6. Insert element before of the some element.\n"
                    "7. Insert element after of the some element.\n8. Sort doublelinked list.\n"
                    "9. Linear search.\n10. Show doublelinked list.\n11. Remove doublelinked list.\n"
                    "12. Operation for report." << endl;
                break;
            }
            case 2:
            {
                int count = CheckingForDigit("Enter count of elements: ");
                RandomValues(list, count);
                break;
            }
            case 3:
            {
                int element = CheckingForDigit("Enter which element you want to add: ");
                AddNewElement(list, element);
                break;
            }
            case 4:
            {
                int index = CheckingForDigit("Enter index which you want to remove: ");
                //TODO: rsdn
                bool isIndexOutOfBounds = RemoveElement(list, index);
                if (!isIndexOutOfBounds)
                {
                    cout << "Enter incorrect index!" << endl;
                }
                break;
            }
            case 5:
            {
                int element = CheckingForDigit("Enter which element you want to insert in begin: ");
                InsertInBeginOfList(list, element);
                break;
            }
            case 6:
            {
                int index = CheckingForDigit("Enter the index of the element before which you want to add a new element: ");
                int element = CheckingForDigit("Enter which element you want to add: ");
                //TODO: rsdn
                bool isIndexOutOfBounds = InsertBeforeOfElement(list, index, element);
                if (!isIndexOutOfBounds)
                {
                    cout << "Enter incorrect index!" << endl;
                }
                break;
            }
            case 7:
            {
                int index = CheckingForDigit("Enter the index of the element after which you want to add a new element: ");
                int element = CheckingForDigit("Enter which element you want to add: ");
                //TODO: rsdn
                bool isIndexOutOfBounds = InsertAfterOfElement(list, index, element);
                if (!isIndexOutOfBounds)
                {
                    cout << "Enter incorrect index!" << endl;
                }
                break;
            }
            case 8:
            {
                InsertionSort(list);
                break;
            }
            case 9:
            {
                int element = CheckingForDigit("Enter element which you want to find: ");
                //TODO: rsdn
                int index = LinearSearch(list, element);
                if (index == -1)
                {
                    cout << "There is no such value in the array." << endl;
                }
                else
                {
                    cout << "Index of this element: " << index << endl;
                }
                break;
            }
            case 10:
            {
                ShowDoubleLinkedList(list);
                break;
            }
            case 11:
            {
                RemoveList(list);
                ShowDoubleLinkedList(list);
                break;
            }
            case 12:
            {
                TestOperations(list);
                break;
            }
            default:
            {
                cout << "Enter correct value! \n";
                break;
            }
        }
	}
}



