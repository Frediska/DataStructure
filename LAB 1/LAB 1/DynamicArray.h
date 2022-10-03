#pragma once


struct DynamicArray
{
	int* array;
	int length;
	int capacity;
};

void CreateDynamicArray(DynamicArray* array);
