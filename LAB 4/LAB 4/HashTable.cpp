#include "HashTable.h"	

HashTable* CreateHashTable(int size)
{
	HashTable* table = new HashTable();

	table->Count = 0;
	table->Size = size;
	table->Array = new Chain * [table->Size];

	for (int i = 0; i < table->Size; i++)
	{
		Chain* newChain = new Chain;
		table->Array[i] = newChain;
		table->Array[i]->Size = 0;
		table->Array[i]->Head = nullptr;
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
		ResolveCollisions(table->Array[index]->Head, node);
	}
	table->Array[index]->Size++;
	table->Count++;
	int fullValue = table->Size * 4 / 3;
	if (table->Count == fullValue)
	{
		Rehashing(table);
	}
	return true;
}

bool Resolve1Collisions(Node* first, Node* node)
{
	while (first != nullptr)
	{
		if (first->Key == node->Key && first->Value == node->Value)
		{
			return false;
		}

		if (first->Next == nullptr)
		{
			first->Next = node;
			return true;
		}

		first = first->Next;
	}
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

int HashFunc(std::string key, int tableSize)
{
	int size = key.length();
	int hash = 0;
	for (int i = 0; i < size; i++)
	{
		hash = (hash * (tableSize - 1) + key[i]) % tableSize;
	}

	return abs(hash);
}

void Rehashing(HashTable* table)
{
	int newSize = table->Size;

	if (table->Size == 1)
	{
		newSize++;
	}
	else
	{
		newSize *= table->GrowthFactor;
	}
	HashTable newTable = *CreateHashTable(newSize);
	for (int i = 0; i < table->Size; i++)
	{
		Node* current = table->Array[i]->Head;

		while (current != nullptr)
		{
			int index = HashFunc(current->Key, newTable.Size);
			InsertElement(&newTable, current, index);
			table->Array[i]->Head = current->Next;
			current->Next = nullptr;
			current = table->Array[i]->Head;
		}
	}
	table->Count = newTable.Count;
	table->Array = newTable.Array;
	table->Size = newTable.Size;
}

//HashTable* Rehashing(HashTable* table)
//{
//	HashTable* newTable = CreateHashTable(table->Size * table->GrowthFactor);
//	for (int i = 0; i < table->Size; i++)
//	{
//		Node* current = table->Array[i]->Head;
//
//		while (current != nullptr)
//		{
//			int index = HashFunc(current->Key, newTable->Size);
//			InsertElement(newTable, current, index);
//			table->Array[i]->Head = current->Next;
//			current->Next = nullptr;
//			current = table->Array[i]->Head;
//		}
//	}
//
//	for (int i = 0; i < table->Size; i++)
//	{
//		delete table->Array[i];
//	}
//	delete[] table->Array;
//	delete table;
//	return newTable;
//}

bool FindElement(HashTable* table, std::string key, std::string& data)
{
	int index = HashFunc(key, table->Size);
	Node* current;
	if (!table->Array[index]->Head)
	{
		return false;

	}
	current = table->Array[index]->Head;
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			data.append(current->Value);
			data.push_back(' ');
		}
		current = current->Next;
	}
	if (data.empty())
	{
		return false;
	}
	return true;
}

bool RemoveElement(HashTable* table, std::string key)
{
	int removeIndex = HashFunc(key, table->Size);
	if (table->Array[removeIndex]->Size == 0) return false;
	Node* current = table->Array[removeIndex]->Head;
	int count = 0;
	bool isNeedRemove = false;
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			count++;
			isNeedRemove = true;
		}
		current = current->Next;
	}

	if (isNeedRemove == false)
	{
		return false;
	}
	while (count != 0)
	{
		if (table->Array[removeIndex]->Head->Key == key)
		{
			Node* removeNode = table->Array[removeIndex]->Head;
			table->Array[removeIndex]->Head = table->Array[removeIndex]->Head->Next;
			delete removeNode;
		}
		else
		{
			Node* prevRemoveNode = table->Array[removeIndex]->Head;
			int secondCount = 0;

			while (prevRemoveNode->Next->Key != key)
			{
				secondCount++;
				prevRemoveNode = prevRemoveNode->Next;
			}
			Node* deleteNode = prevRemoveNode->Next;

			if (secondCount == table->Array[removeIndex]->Size - 2)
			{
				prevRemoveNode->Next = nullptr;
			}
			else
			{
				prevRemoveNode->Next = prevRemoveNode->Next->Next;
			}
			delete deleteNode;
		}
		table->Count--;
		table->Array[removeIndex]->Size--;
		count--;
	}
	return true;
}

void DeleteTable(HashTable* table)
{
	for (int i = 0; i < table->Size; i++)
	{
		for (int j = 0; j < table->Array[i]->Size; j++)
		{
			Node* removeNode = table->Array[i]->Head;

			if (table->Array[i]->Head->Next != nullptr)
			{
				table->Array[i]->Head = table->Array[i]->Head->Next;
			}
			delete removeNode;
		}
		delete table->Array[i];
	}
	delete[] table->Array;
	delete table;
}
