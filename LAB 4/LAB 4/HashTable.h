#pragma once
#include "Chain.h"

struct HashTable
{
	const int GrowthFactor = 2;

	int Count;

	int Size;

	Chain** Array;
};

HashTable* CreateHashTable(int size);
Node* CreateNode(std::string key, std::string value);
bool InsertElement(HashTable* table, Node* node, int index);
void ResolveCollisions(Node* first, Node* element);
int HashFunc(std::string key, int tableSize);
//HashTable* Rehashing(HashTable* table);
bool FindElement(HashTable* table, std::string key, std::string& data);
bool RemoveElement(HashTable* table, std::string key);
void DeleteTable(HashTable* table);
bool Resolve1Collisions(Node* first, Node* node);
void Rehashing(HashTable* table);
