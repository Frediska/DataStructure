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

void LinearSearch(DynamicArray* array, int element)
{

}

int main()
{
    std::cout << "Hello World!\n";
}

