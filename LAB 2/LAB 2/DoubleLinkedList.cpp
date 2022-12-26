//TODO remove
#include "DoubleLinkedList.h"
#include <chrono>

using namespace std;

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

bool RemoveElement(DoubleLinkedList* list, int index)
{
	bool flag = true;

	if (index > list->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
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

		flag = true;
	}	
	return flag;
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

bool InsertAfterOfElement(DoubleLinkedList* list, int index, int element)
{
	bool flag = true;

	if (index > list->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
		if (index == list->Length - 1)
		{
			AddNewElement(list, element);
			return flag;
		}

		Node* tempNode = new Node();
		tempNode = list->Head;
		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}

		Node* node = new Node();
		node->Value = element;
		node->Next = tempNode->Next;
		tempNode->Next->Previous = node;
		node->Previous = tempNode;
		tempNode->Next = node;

		list->Length++;

		flag = true;
	}
	return flag;
}

bool InsertBeforeOfElement(DoubleLinkedList* list, int index, int element)
{
	bool flag = true;

	if (index > list->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
		if (index == 0)
		{
			InsertInBeginOfList(list, element);
			return flag;
		}

		Node* tempNode = new Node();

		tempNode = list->Head;
		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}

		Node* node = new Node();
		node->Value = element;
		node->Next = tempNode;
		node->Previous = tempNode->Previous;
		tempNode->Previous->Next = node;
		tempNode->Previous = node;

		list->Length++;

		flag = true;
	}
	return flag;
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
	Node* node = list->Head;
	int index = -1;

	for (int i = 0; i < list->Length; i++)
	{
		if (node->Value == element)
		{
			index = i;
			break;
		}

		node = node->Next;
	}

	return index;
}

void RemoveList(DoubleLinkedList* list)
{
	if (list->Head == nullptr)
	{
		return;
	}

	int index = 0;
	Node* temp = list->Head->Next;

	while (temp != nullptr)
	{
		delete temp->Previous;
		list->Length--;
		temp = temp->Next;
	}

	delete temp;
	list->Length--;
	list->Head = nullptr;
	list->Tail = nullptr;
}

void RandomValues(DoubleLinkedList* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		AddNewElement(list, rand() % 100);
	}
}

