#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

void InitDoubleLinkedList(DoubleLinkedList* list)
{
	list->Length = 0;
	list->Head = nullptr;
	list->Tail = nullptr;
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

void InsertInBeginOfList(DoubleLinkedList* list, int element)
{
	Node* node = new Node();

	node->Value = element;
	node->Previous = nullptr;
	node->Next = list->Head;

	if (list->Head != nullptr)
	{
		list->Head->Previous = node;
	}

	if (list->Tail == nullptr)
	{
		list->Tail = node;
	}

	list->Length++;
	list->Head = node;
}

void InsertAfterOfElement(DoubleLinkedList* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return;
	}

	Node* node = new Node();
	Node* indexNode = GetElement(list, index);

	node->Value = value;

	node->Next = indexNode->Next;
	node->Previous = indexNode;

	if (list->Length - 1 != index)
	{
		indexNode->Next->Previous = node;
	}

	indexNode->Next = node;

	if (list->Length - 1 == index)
	{
		list->Tail = node;
	}

	list->Length++;
}

void InsertBeforeOfElement(DoubleLinkedList* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return;
	}

	Node* node = new Node();
	Node* indexNode = GetElement(list, index);

	node->Value = value;

	node->Next = indexNode;
	node->Previous = indexNode->Previous;

	if (indexNode->Previous != nullptr)
	{
		indexNode->Previous->Next = node;
	}

	indexNode->Previous = node;

	if (index == 0)
	{
		list->Head = node;
	}

	list->Length++;
}

void SwapElements(DoubleLinkedList* list, Node* first, Node* second)
{
	if (first == list->Head)
	{
		list->Head = second;
	}
	else
	{
		first->Previous->Next = second;
	}

	if (second == list->Tail)
	{
		list->Tail = first;
	}
	else
	{
		second->Next->Previous = first;
	}

	first->Next = second->Next;
	second->Previous = first->Previous;
	first->Previous = second;
	second->Next = first;
}

void InsertionSort(DoubleLinkedList* list)
{
	for (Node* iNode = list->Head->Next; iNode != nullptr; iNode = iNode->Next)
	{
		Node* jNode = iNode->Previous;

		while (jNode != nullptr && jNode->Value > jNode->Next->Value)
		{
			SwapElements(list, jNode, jNode->Next);
			jNode = jNode->Previous->Previous;
		}
	}
}

int LinearSearch(DoubleLinkedList* list, int element)
{
	int index = 0;

	for (Node* iNode = list->Head; iNode != nullptr; iNode = iNode->Next, index++)
	{
		if (iNode->Value == element)
		{
			return index;
		}
	}

	return -1;
}

Node* GetElement(DoubleLinkedList* list, int index)
{
	Node* node;

	if (index < list->Length / 2)
	{
		node = list->Head;

		for (int i = 0; i < index; ++i)
		{
			node = node->Next;
		}

		return node;
	}
	else
	{
		node = list->Tail;

		for (int i = list->Length - 1; i > index; i--)
		{
			node = node->Previous;
		}

		return node;
	}
}

