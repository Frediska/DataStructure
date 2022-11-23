#pragma once
//TODO: doxygen �����������

struct DynamicArray
{
    int* Array;
    int Length;
    int Capacity;
};

/// @brief �������� ������������� �������.
/// @param dynamicArray 
void CreateDynamicArray(DynamicArray* dynamicArray);

/// @brief ���������� ������ �������� � ����� ������������� �������.
/// @param dynamicArray ������������ ������.
/// @param element �������.
void AddNewElement(DynamicArray* dynamicArray, int element);

/// @brief �������� �������� �� ������������� ������� �� �������.
/// @param dynamicArray ������������ ������.
/// @param index ������ ��������.
/// @param flag ���� ��� ������������ ������.
void RemoveElement(DynamicArray* dynamicArray, int index, bool& flag);

/// @brief ���������� �������� � ������������ ������ �� �������.
/// @param dynamicArray ������������ ������.
/// @param element �������.
/// @param index ������ ��������.
void InsertElement(DynamicArray* dynamicArray, int element, int index);

/// @brief ���������� ������� �� �����������.
/// @param dynamicArray ������������ ������.
void SortArray(DynamicArray* dynamicArray);

/// @brief �������� ����� ��������.
/// @param dynamicArray ������������ ������.
/// @param element �������.
/// @return ����������� ������� ���������� ��������.
int LinearSearch(DynamicArray* dynamicArray, int element);

/// @brief �������� ����� ��������.
/// @param dynamicArray ������������ ������.
/// @param element �������.
/// @param middle ������ ���������� ��������.
/// @param flag ���� ��� ������������ �������.
void BinarySearch(DynamicArray* dynamicArray, int element, int& middle, bool& flag);

/// @brief ��������� ����������� �������.
/// @param dynamicArray ������������ ������.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief ������ ���������� ��������� � ������������ ������.
/// @param dynamicArray ������������ ������.
/// @param length ������ �������.
void GetRandomArray(DynamicArray* dynamicArray, int length);

void Show(DynamicArray* dynamicArray);