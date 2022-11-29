#pragma once

//TODO: comments
/// @brief ��������� ������������� �������.
struct DynamicArray
{
    /// @brief ������������ ������.
    int* Array;
    /// @brief ����� ������������� �������.
    int Length;
    /// @brief ����������� ������������� �������.
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
/// @param index ������ ��������
/// @return ����������� �������� true ��� false.
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
/// @return ����������� ������� ���������� ��������.
int BinarySearch(DynamicArray* dynamicArray, int element);

/// @brief ��������� ����������� �������.
/// @param dynamicArray ������������ ������.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief ������ ���������� ��������� � ������������ ������.
/// @param dynamicArray ������������ ������.
/// @param length ������ �������.
void GetRandomArray(DynamicArray* dynamicArray, int length);