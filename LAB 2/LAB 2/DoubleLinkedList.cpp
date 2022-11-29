#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

void InitDoubleLinkedList(DoubleLinkedList* list)
{
	list->Length = 0;
	list->Head = 0;
	list->Tail = 0;
}

void AddNewElement(DoubleLinkedList* list, int element)
{
	Node* node = new Node();

	node->Value = element;
	list->Length++;
	node->Previous = list->Tail;
	node->Next = nullptr;

	if (list->Tail != nullptr)
	{
		list->Tail->Next = node;
	}

	if (list->Head == nullptr)
	{
		list->Head = node;
	}

	list->Tail = node;
}

void RemoveElement(DoubleLinkedList* list, int index)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return;
	}

	Node* node = list->Head;

	for (int i = 0; i != index; i++)
	{
		node = node->Next;
	}

	if (node == list->Head)
	{
		list->Head = node->Next;
	}
	else
	{
		node->Previous->Next = node->Next;
	}

	if (node == list->Tail)
	{
		list->Tail = node->Previous;
	}
	else
	{
		node->Next->Previous = node->Previous;
	}

	list->Length--;
	delete node;
}
