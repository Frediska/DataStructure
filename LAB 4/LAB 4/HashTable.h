#pragma once
#include "Chain.h"

/// @brief ��������� ��� ���-�������.
struct HashTable
{
	/// @brief ����� ����� ������� �������.
	const int GrowthFactor = 2;

	/// @brief ���������� ��������� � �������.
	int Count;

	/// @brief ������ �������.
	int Size;

	/// @brief ��������� ������������ ������ �����.
	Chain** Array;
};

/// @brief �������� ���-�������.
/// @param size ������ �������.
/// @return ���������� ���-�������.
HashTable* CreateHashTable(int size);

/// @brief ������� ����.
/// @param key ����.
/// @param value ��������.
/// @return ���������� �������.
Node* CreateNode(std::string key, std::string value);

/// @brief ���������� �������� � ���-�������.
/// @param table �������.
/// @param node ����.
/// @param index ������.
/// @return ���������� true, ���� ������� ��� ������� ��������, ����� false.
bool AddElement(HashTable* table, Node* node, int index);

/// @brief ���������� ������������.
/// @param first ������ �������.
/// @param node ����.
void ResolveCollisions(Node* first, Node* node);

/// @brief ������������ �������� ����� � ���-�����.
/// @param key ����.
/// @param tableSize ������ �������.
/// @return ���������� ���-�����.
int HashFunction(std::string key, int tableSize);

/// @brief ���� ������� � �������� ������.
/// @param table �������.
/// @param key ����.
/// @param data ��������.
/// @return ���������� true, ���� ������� ������, ����� false.
bool FindElement(HashTable* table, std::string key, std::string& data);

/// @brief ������� ������� � �������� ������.
/// @param table �������.
/// @param key ����.
/// @return ���������� true, ���� ������� ��� ������� ������, ����� false.
bool RemoveElement(HashTable* table, std::string key);

/// @brief ������� ���-�������.
/// @param table �������.
void DeleteTable(HashTable* table);

/// @brief ��������������� �������.
/// @param table �������.
void Rehashing(HashTable* table);
