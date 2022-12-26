#pragma once

//TODO: comments

/// @brief ���������� ��������� �� ������������� ���� ������.
struct Node
{
	/// @brief �������� ���� ������.
	int Value;
	/// @brief �������� ���������� ���� ������.
	Node* Next;
	/// @brief ��������� ���������� ���� ������.
	Node* Previous;
};

/// @brief ���������� ��������� �� ������������� ����������� ������.
struct DoubleLinkedList
{
	/// @brief ����� ����������� ������.
	int Length;
	/// @brief ��������� ������ ����������� ������.
	Node* Head;
	/// @brief ��������� ����� ����������� ������.
	Node* Tail;
	
	void List()
	{
		Length = 0;
		Head = nullptr;
		Tail = nullptr;
	}
};

/// @brief ������������� ����������� ������.
/// @param list ���������� ������.
void InitDoubleLinkedList(DoubleLinkedList* list);

/// @brief �������� ����� ������� � ���������� ������.
/// @param list ���������� ������.
/// @param element ����������� �������.
void AddNewElement(DoubleLinkedList* list, int element);

/// @brief ������� �������� �� ����������� ������ �� ��� �������.
/// @param list ���������� ������.
/// @param index ������ ���������� ��������.
/// @return ����������� true ��� false.
bool RemoveElement(DoubleLinkedList* list, int index);

/// @brief ������� �������� � ������ ������.
/// @param list ���������� ������.
/// @param element ����������� �������.
void InsertInBeginOfList(DoubleLinkedList* list, int element);

/// @brief ������� �������� ����� ������� ��������.
/// @param list ���������� ������.
/// @param index ������ ��������, ����� �������� ����������� �����.
/// @param element ����������� �������
/// @return ����������� true ��� false.
bool InsertAfterOfElement(DoubleLinkedList* list, int index, int element);

/// @brief ������� �������� ����� ������ ���������.
/// @param list ���������� ������.
/// @param index ������ ��������, ����� ������� ����������� ������.
/// @param element ����������� �������.
/// @return ����������� true ��� false.
bool InsertBeforeOfElement(DoubleLinkedList* list, int index, int element);

/// @brief ������������ ���������, ������������ ��� ����������.
/// @param list ���������� ������.
/// @param first ������ ����.
/// @param second ������ ����.
void SwapElements(DoubleLinkedList* list, Node* first, Node* second);

/// @brief ���������� ����������� ������ ���������.
/// @param list ���������� ������.
void InsertionSort(DoubleLinkedList* list);

/// @brief �������� ����� �������� � ���������� ������.
/// @param list ���������� ������.
/// @param element ������� �������.
/// @return ����������� ������� �������� �������� ��� -1, ���� ������� �� ������.
int LinearSearch(DoubleLinkedList* list, int element);

/// @brief ������� ���������� ������.
/// @param list ���������� ������.
void RemoveList(DoubleLinkedList* list);

/// @brief ���������� ������ ���������� ����������.
/// @param list ���������� ������.
/// @param count ���������� ��������.
void RandomValues(DoubleLinkedList* list, int count);




