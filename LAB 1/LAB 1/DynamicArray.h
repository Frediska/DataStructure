#pragma once

/// @brief ��������� ������������� �������.
struct DynamicArray
{
    int* Array;
    int Length;
    int Capacity;
};

/// @brief �������� ������������� �������.
/// @param dynamicArray ������������ ������.
void CreateDynamicArray(DynamicArray* dynamicArray);

/// @brief ���������� ������ �������� � ����� ������������� �������.
/// @param dynamicArray ������������ ������.
/// @param element �������.
void AddNewElement(DynamicArray* dynamicArray, int element);

/// @brief �������� �������� �� ������������� ������� �� �������.
/// @param dynamicArray ������������ ������.
/// @param index ������ ��������.
/// @param flag ���� ��� ������������ ������.
bool RemoveElement(DynamicArray* dynamicArray, int index);

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
int BinarySearch(DynamicArray* dynamicArray, int element);

/// @brief ��������� ����������� �������.
/// @param dynamicArray ������������ ������.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief ������ ���������� ��������� � ������������ ������.
/// @param dynamicArray ������������ ������.
/// @param length ������ �������.
void GetRandomArray(DynamicArray* dynamicArray, int length);



void Show(DynamicArray* dynamicArray);