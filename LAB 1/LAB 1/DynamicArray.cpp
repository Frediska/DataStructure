#include "DynamicArray.h"
#include <iostream>
using namespace std;

void CreateDynamicArray(DynamicArray* dynamicArray)
{
    int capacity = 8;

    dynamicArray->Capacity = capacity;
    dynamicArray->Length = 0;
    dynamicArray->Array = new int[dynamicArray->Capacity];
}

void ResizeArray(DynamicArray* dynamicArray)
{
    dynamicArray->Capacity += dynamicArray->Capacity;

    int* tempArray = new int[dynamicArray->Capacity];

    for (int i = 0; i < dynamicArray->Length; i++)
    {
        tempArray[i] = dynamicArray->Array[i];
    }

    delete[] dynamicArray->Array;
    dynamicArray->Array = tempArray;
}

void AddNewElement(DynamicArray* dynamicArray, int element)
{
    dynamicArray->Length++;

    if (dynamicArray->Length >= dynamicArray->Capacity)
    {
        ResizeArray(dynamicArray);
    }

    dynamicArray->Array[dynamicArray->Length - 1] = element;
}

void RemoveElement(DynamicArray* dynamicArray, int index, bool& flag)
{
    if (index > dynamicArray->Length - 1 || index < 0)
    {
        flag = false;
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

    if (dynamicArray->Length >= dynamicArray->Capacity)
    {
        ResizeArray(dynamicArray);
    }

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

int LinearSearch(DynamicArray* dynamicArray, int element)
{
    int index = -1;
    for (int i = 0; i < dynamicArray->Length; i++)
    {
        if (dynamicArray->Array[i] == element)
        {
            index = i;
            break;
        }
    }
    return index;
}

void BinarySearch(DynamicArray* dynamicArray, int element, int& middle, bool& flag)
{
    int left = 0;
    int right = dynamicArray->Length;

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
}

void GetRandomArray(DynamicArray* dynamicArray, int length)
{
    srand(time(nullptr));

    for (int i = 0; i < length; i++)
    {
        AddNewElement(dynamicArray, rand());
    }
}
//TODO:cout
void ShowDynamicArray(DynamicArray* dynamicArray)
{
    for (int i = 0; i < dynamicArray->Length; i++)
    {
        cout << dynamicArray->Array[i] << " ";
    }

    cout << endl;
}

