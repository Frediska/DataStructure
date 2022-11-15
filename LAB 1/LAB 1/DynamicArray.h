#pragma once

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
void LinearSearch(DynamicArray* dynamicArray, int element, bool& flag);
void BinarySearch(DynamicArray* dynamicArray, int element);
void ResizeArray(DynamicArray* dynamicArray);
void GetRandomArray(DynamicArray* dynamicArray, int length);
void ShowDynamicArray(DynamicArray* dynamicArray);
void ShowHowManyCapacityAndLength(DynamicArray* dynamicArray);