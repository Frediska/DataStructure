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

bool AddElement(HashTable* table, Node* node, int index)
{
	const float fillFactor = 4.0 / 3.0;
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
	//TODO: const
	table->Count++;
	int fullValue = table->Size * fillFactor;
	if (table->Count == fullValue)
	{
		Rehashing(table);
	}
	return true;
}

void ResolveCollisions(Node* first, Node* node)
{
	Node* current = first;
	while (current->Next != nullptr)
	{
		current = current->Next;
	}
	current->Next = node;
}

int HashFunction(std::string key, int tableSize)
{
	int size = key.length();
	int hash = 0;
	double A = 0.618033;
	for (int i = 0; i < size; i++)
	{
		hash = (hash + key[i]) % tableSize;
	}

	return abs(hash);
}

void Rehashing(HashTable* table)
{
	HashTable* newTable = CreateHashTable(table->Size * table->GrowthFactor);
	for (int i = 0; i < table->Size; i++)
	{
		Node* current = table->Array[i]->Head;

		while (current != nullptr)
		{
			int index = HashFunction(current->Key, newTable->Size);
			AddElement(newTable, current, index);
			table->Array[i]->Head = current->Next;
			current->Next = nullptr;
			current = table->Array[i]->Head;
		}
	}

	table->Count = newTable->Count;
	table->Array = newTable->Array;
	table->Size = newTable->Size;
}

bool FindElement(HashTable* table, std::string key, std::string& data)
{
	int index = HashFunction(key, table->Size);
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
	int removeIndex = HashFunction(key, table->Size);
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
