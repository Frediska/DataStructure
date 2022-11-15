#include <iostream>
#include "DynamicArray.h"
using namespace std;

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
        int taskNumber;
        cout << "Enter number of action: ";
        cin >> taskNumber;
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
            int length;
            cout << "Enter length of your dynamic array: ";
            cin >> length;
            GetRandomArray(array, length);
            break;
        } 
        case 3:
        {
            int element;
            cout << "Enter which element you want to add: ";
            cin >> element;
            AddNewElement(array, element);
            break;
        }    
        case 4:
        {
            int index;
            bool flag = true;
            cout << "Enter index which you want to remove: ";
            cin >> index;
            RemoveElement(array, index, flag);
            if (flag == false)
            {
                cout << "Enter incorrect index!" << endl;
            }
            break;
        }   
        case 5:
        {
            int index;
            int element;
            cout << "Enter the index of the element where you want to insert the element: ";
            cin >> index;
            cout << "Enter which element you want to add: ";
            cin >> element;
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
            int element;
            int index;
            cout << "Enter element which you want to find: ";
            cin >> element;
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
            int element;
            bool flag = false;
            int middle;
            cout << "Enter element which you want to find: ";
            cin >> element;
            BinarySearch(array, element, middle, flag);
            if (flag == true)
            {
                cout << "Element which you search " << element << " in index: " << middle << endl;
            }
            else
            {
                cout << "There is no such value in the array." << endl;
            }
            break;
        }  
        case 9:
        {
            ShowDynamicArray(array);
            break;
        }
        case 10:
        {
            ShowHowManyCapacityAndLength(array);
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

