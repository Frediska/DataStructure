#include <iostream>

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
    dynamicArray->capacity += 8;

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
    srand(time(0));

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
    std::cout << "Hello World!\n";
}

