#include <iostream>
#include "DynamicArray.h"
using namespace std;

int CheckingForDigit(const char* text)
{
    int element;

    while (true)
    {
        cout << text;
        cin >> element;

        if (!cin.fail())
        {
            cin.ignore(cin.rdbuf()->in_avail());
            return element;
        }

        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Enter correct value! \n";
    }
}

int main()
{
    DynamicArray* array = new DynamicArray;

    cout << "1. Create dynamic array. \n2. Initialize an dynamic array with random numbers. \n"
        "3. Add new element in dynamic array.\n4. Remove element of dynamic array.\n"
        "5. Insert element at index into dynamic array.\n6. Sort dynamic array.\n"
        "7. Linear Search.\n8. Binary search.\n"
        "9. Show dynamic array.\n" << endl;
    
    while (true)
    {
        int taskNumber = CheckingForDigit("Enter number of action: ");

        cout << endl;

        switch (taskNumber)
        {
            case 1:
            {
                CreateDynamicArray(array);
                break;
            }  
            case 2:
            {
                int length = CheckingForDigit("Enter length of your dynamic array: ");
                GetRandomArray(array, length);
                break;
            } 
            case 3:
            {
                int element = CheckingForDigit("Enter which element you want to add: ");
                AddNewElement(array, element);
                break;
            }    
            case 4:
            {
                int index = CheckingForDigit("Enter index which you want to remove: ");
                bool flag;
                flag = RemoveElement(array, index);
                if (flag == false)
                {
                    cout << "Enter incorrect index!" << endl;
                }
                break;
            }   
            case 5:
            {
                int index = CheckingForDigit("Enter the index of the element where you want to insert the element: ");
                int element = CheckingForDigit("Enter which element you want to add: ");
                InsertElement(array, element, index);
                break;
            }    
            case 6:
            {
                SortArray(array);
                break;
            }    
            case 7:
            {
                int element = CheckingForDigit("Enter element which you want to find: ");
                int index;
                index = LinearSearch(array, element);
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
            case 8:
            {
                int element = CheckingForDigit("Enter element which you want to find: ");
                int index;
                index = BinarySearch(array, element);
                if (index == -1)
                {
                    cout << "There is no such value in the array." << endl;
                }
                else
                {
                    cout << "Element which you search " << element << " in index: " << index << endl;
                }
                break;
            }  
            case 9:
            {
                for (int i = 0; i < array->Length; i++)
                {
                    cout << array->Array[i] << " ";
                }

                cout << endl;
                break;
            }
            default:
            {
                cout << "Enter correct value! \n";
                break;
            }
        }
    }
    delete array;
}

