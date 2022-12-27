#include "HashTable.h"	

HashTable* CreateHashTable(int size)
{
	HashTable* table = new HashTable();

	table->Count = 0;
	table->Size = size;
	table->Array = new Chain * [table->Size];

	for (int i = 0; i < table->Size; i++)
	{
		table->Array[i] = nullptr;
	}

	return table;
}

Node* CreateNode(std::string key, std::string value)
{
	Node* node = new Node;
	node->Key = key;
	node->Value = value;
	node->Next = nullptr;

	return node;
}

bool InsertElement(HashTable* table, Node* node, int index)
{
	Node* currentNode = table->Array[index]->Head;
	while (currentNode != nullptr)
	{
		if (currentNode->Key == node->Key && currentNode->Value == node->Value)
		{
			return false;
		}

		currentNode = currentNode->Next;
	}
	if (table->Array[index]->Head == nullptr)
	{
		table->Array[index]->Head = node;
	}
	else
	{
		//ResolveCollisions(table->Array[index]->Head, node);
	}
	table->Array[index]->Size++;
	//table->CountFilledElements++;
	return true;
}

void ResolveCollisions(Node* first, Node* element)
{
	Node* current = first;
	while (current->Next != nullptr)
	{
		current = current->Next;
	}
	current->Next = element;
}
