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


