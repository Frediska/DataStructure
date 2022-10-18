﻿#include <iostream>

using namespace std;

struct DynamicArray
{
    int* array;
    int length;
    int capacity;
};

void CreateDynamicArray(DynamicArray* dynamicArray)
{
    int capacity = 8;

    dynamicArray->capacity = capacity;
    dynamicArray->length = 0;
    dynamicArray->array = new int[dynamicArray->capacity];
}

void AddNewElement(DynamicArray* dynamicArray, int element)
{
    dynamicArray->length++;

    if (dynamicArray->length >= dynamicArray->capacity)
    {
        ResizeArray(dynamicArray);
    }

    dynamicArray->array[dynamicArray->length - 1] = element;
}

void RemoveElement(DynamicArray* dynamicArray, int index)
{
    for (int i = index; i < dynamicArray->length - 1; i++)
    {
        dynamicArray->array[i] = dynamicArray->array[i + 1];
    }

    dynamicArray->length--;
}

void InsertElement(DynamicArray* dynamicArray, int element, int index)
{
    dynamicArray->length++;

    if (dynamicArray->length >= dynamicArray->capacity)
    {
        ResizeArray(dynamicArray);
    }

    for (int i = dynamicArray->length - 1; i > index; i--)
    {
        dynamicArray->array[i] = dynamicArray->array[i - 1];
    }

    dynamicArray->array[index] = element;
}

void SortArray(DynamicArray* dynamicArray)
{
    for (int startIndex = 0; startIndex < dynamicArray->length - 1; startIndex++)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < dynamicArray->length; currentIndex++)
        {
            if (dynamicArray->array[currentIndex] < dynamicArray->array[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(dynamicArray->array[startIndex], dynamicArray->array[smallestIndex]);
    }
}

int LinearSearch(DynamicArray* dynamicArray, int element)
{
    for (int i = 0; i < dynamicArray->length; i++)
    {
        if (dynamicArray->array[i] = element)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(DynamicArray* dynamicArray, int element)
{
    int first = 0;
    int last = dynamicArray->length - 1;
    int middle;

    while (first < last)
    {
        middle = (last + first) / 2;

        if (element <= dynamicArray->array[middle])
        {
            last = middle;
        }
        else
        {
            first = middle + 1;
        }
    }
    return (first == dynamicArray->length || dynamicArray->array[first] != element)
        ? -1 : first;
}

void ResizeArray(DynamicArray* dynamicArray)
{
    int capacity = 8;
    dynamicArray->capacity += capacity;

    int* tempArray = new int[dynamicArray->capacity];

    for (int i = 0; i < dynamicArray->length; i++)
    {
        tempArray[i] = dynamicArray->array[i];
    }
    
    delete[] dynamicArray->array;
    dynamicArray->array = tempArray;
}

void GetRandomArray(DynamicArray* dynamicArray, int length)
{
    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        AddNewElement(dynamicArray, rand());
    }
}

void ShowDynamicArray(DynamicArray* dynamicArray)
{
    for (int i = 0; i < dynamicArray->length; i++)
    {
        cout << dynamicArray->array[i] << " ";
    }

    cout << endl;
}

int main()
{
    DynamicArray* array = new DynamicArray;

    int taskNumber;
    cout << "Enter number of action: ";
    cin >> taskNumber;
    cout << "1.Create dynamic array. \n2. Initialize an dynamic array with random numbers."
        "3. Add new element in dynamic array.\n4. Remove element of dynamic array.\n"
        "5. Insert element at index into dynamc array.\n6. Sort dynamic array.\n"
        "7. Linear Search.\n8.Binary search.\n"
        "9. Show dynamic array.\n" << endl;
    cout << endl;

    switch (taskNumber)
    {
    case 1:
        CreateDynamicArray(array);
        break;
    case 2:
        GetRandomArray(array, 4);
        break;
    case 3:
        int element;
        cout << "Enter which element you want to add: ";
        cin >> element;
        AddNewElement(array, element);
        break;
    case 4:
        int index;
        cout << "Enter index which you want to remove: ";
        cin >> index;
        RemoveElement(array, index);
        break;
    case 5:
        index;
        element;
        cout << "Enter the index of the element where you want to insert the element: ";
        cin >> index;
        cout << "Enter which element you want to add: ";
        cin >> element;
        InsertElement(array, element, index);
        break;
    case 6:
        SortArray(array);
        break;
    case 7:
        element;
        cout << "Entee element which you want to find: ";
        cin >> element;
        LinearSearch(array, element);
        break;
    case 8:
        element;
        cout << "Entee element which you want to find: ";
        cin >> element;
        BinarySearch(array, element);
        break;
    case 9:
        ShowDynamicArray(array);
        break;
    }
}

