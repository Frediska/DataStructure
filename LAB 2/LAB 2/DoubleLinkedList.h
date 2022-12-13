#pragma once

struct Node
{
	int Value;
	Node* Next;
	Node* Previous;
};

struct DoubleLinkedList
{
	int Length;
	Node* Head;
	Node* Tail;
};

void InitDoubleLinkedList(DoubleLinkedList* list);

void AddNewElement(DoubleLinkedList* list, int element);
void RemoveElement(DoubleLinkedList* list, int index);
void InsertInBeginOfList(DoubleLinkedList* list, int element);
void InsertAfterOfElement(DoubleLinkedList* list, int index, int value);
void InsertBeforeOfElement(DoubleLinkedList* list, int index, int value);
void SwapElements(DoubleLinkedList* list, Node* first, Node* second);
void InsertionSort(DoubleLinkedList* list);
int LinearSearch(DoubleLinkedList* list, int element);
Node* GetElement(DoubleLinkedList* list, int index);




