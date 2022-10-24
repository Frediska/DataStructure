#include <iostream>
using namespace std;

struct DynamicArray
{
    int* Array;
    int Length;
    int Capacity;
};

void CreateDynamicArray(DynamicArray* dynamicArray)
{
    int capacity = 8;

    dynamicArray->Capacity = capacity;
    dynamicArray->Length = 0;
    dynamicArray->Array = new int[dynamicArray->Capacity];
}

void AddNewElement(DynamicArray* dynamicArray, int element)
{
    dynamicArray->Length++;

    //if (dynamicArray->length >= dynamicArray->capacity)
    //{
    //    ResizeArray(dynamicArray);
    //}

    dynamicArray->Array[dynamicArray->Length - 1] = element;
}

void RemoveElement(DynamicArray* dynamicArray, int index)
{
    if (index > dynamicArray->Length - 1 || index < 0)
    {
        cout << "Incorrect value entered!" << endl;
        return;
    }
    else
    {
        for (int i = index; i < dynamicArray->Length - 1; i++)
        {
            dynamicArray->Array[i] = dynamicArray->Array[i + 1];
        }

        dynamicArray->Length--;
    }
}

void InsertElement(DynamicArray* dynamicArray, int element, int index)
{
    dynamicArray->Length++;

    //if (dynamicArray->length >= dynamicArray->capacity)
    //{
    //    ResizeArray(dynamicArray);
    //}

    for (int i = dynamicArray->Length - 1; i > index; i--)
    {
        dynamicArray->Array[i] = dynamicArray->Array[i - 1];
    }

    dynamicArray->Array[index] = element;
}

void SortArray(DynamicArray* dynamicArray)
{
    for (int startIndex = 0; startIndex < dynamicArray->Length - 1; startIndex++)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < dynamicArray->Length; currentIndex++)
        {
            if (dynamicArray->Array[currentIndex] < dynamicArray->Array[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(dynamicArray->Array[startIndex], dynamicArray->Array[smallestIndex]);
    }
}

void LinearSearch(DynamicArray* dynamicArray, int element)
{
    bool flag = false;

    for (int i = 0; i < dynamicArray->Length; i++)
    {
        if (dynamicArray->Array[i] == element)
        {
            cout << "Index of this element: " << i << endl;
            flag = true;
            return;
        }
    }
    if (flag == false)
    {
        cout << "There is no such value in the array." << endl;
    }
}

void BinarySearch(DynamicArray* dynamicArray, int element)
{
    int left = 0;
    int right = dynamicArray->Length;
    int middle;
    bool flag = false;

    while ((left <= right) && (flag != true))
    {
        middle = (left + right) / 2;

        if (dynamicArray->Array[middle] == element)
        {
            flag = true;
        }
        if (dynamicArray->Array[middle] > element)
        {
            right = middle - 1;
        }
        if (dynamicArray->Array[middle] < element)
        {
            left = middle + 1;
        }
    }

    if (flag == true)
    {
        cout << "Element which you search  " << element << " in index: " << middle << endl;
    }
    else
    {
        cout << "There is no such value in the array." << endl;
    }
}

//void ResizeArray(DynamicArray* dynamicArray)
//{
//    dynamicArray->capacity += dynamicArray->capacity;
//
//    int* tempArray = new int[dynamicArray->capacity];
//
//    for (int i = 0; i < dynamicArray->length; i++)
//    {
//        tempArray[i] = dynamicArray->array[i];
//    }
//    
//    delete[] dynamicArray->array;
//    dynamicArray->array = tempArray;
//}

void GetRandomArray(DynamicArray* dynamicArray, int length)
{
    srand(time(0));

    for (int i = 0; i < length; i++)
    {
        AddNewElement(dynamicArray, rand());
    }
}

void ShowDynamicArray(DynamicArray* dynamicArray)
{
    for (int i = 0; i < dynamicArray->Length; i++)
    {
        cout << dynamicArray->Array[i] << " ";
    }

    cout << endl;
}

void ShowHowManyCapacityAndLength(DynamicArray* dynamicArray)
{
    cout << dynamicArray->Capacity << endl;

    cout << dynamicArray->Length << endl;
}

int main()
{
    DynamicArray* array = new DynamicArray;

    cout << "1. Create dynamic array. \n2. Initialize an dynamic array with random numbers. \n"
        "3. Add new element in dynamic array.\n4. Remove element of dynamic array.\n"
        "5. Insert element at index into dynamc array.\n6. Sort dynamic array.\n"
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
            cout << "Enter index which you want to remove: ";
            cin >> index;
            RemoveElement(array, index);
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
            cout << "Enter element which you want to find: ";
            cin >> element;
            LinearSearch(array, element);
            break;
        }    
        case 8:
        {
            int element;
            cout << "Enter element which you want to find: ";
            cin >> element;
            BinarySearch(array, element);
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

