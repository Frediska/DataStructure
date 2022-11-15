#pragma once
//TODO: doxygen комментарии
struct DynamicArray
{
    int* Array;
    int Length;
    int Capacity;
};

void CreateDynamicArray(DynamicArray* dynamicArray);
void AddNewElement(DynamicArray* dynamicArray, int element);
void RemoveElement(DynamicArray* dynamicArray, int index, bool& flag);
void InsertElement(DynamicArray* dynamicArray, int element, int index);
void SortArray(DynamicArray* dynamicArray);
int LinearSearch(DynamicArray* dynamicArray, int element);
void BinarySearch(DynamicArray* dynamicArray, int element, int& middle, bool& flag);
void ResizeArray(DynamicArray* dynamicArray);
void GetRandomArray(DynamicArray* dynamicArray, int length);
void ShowDynamicArray(DynamicArray* dynamicArray);
void Show(DynamicArray* dynamicArray);