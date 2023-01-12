#pragma once
#include "HashTable.h"

/// @brief ��������� �������.
struct Dictionary
{
	/// @brief �������.
	HashTable* Table;
};

/// @brief �������� �������.
/// @return ���������� �������.
Dictionary* CreateDictionary();

/// @brief ��������� ������� � �������.
/// @param dictionary �������.
/// @param element �������.
/// @param key ����.
/// @return ���������� true, ���� ������� ��� ������� ��������, ����� false.
bool AddElement(Dictionary* dictionary, Node* element, std::string key);

/// @brief �������� �������� �� �������.
/// @param dictionary �������.
/// @param key ����.
/// @return ���������� true, ���� ������� ��� ������� ������, ����� false.
bool RemoveElement(Dictionary* dictionary, std::string key);

/// @brief ����� �������� �� ��������� ����� � �������.
/// @param dictionary �������.
/// @param key ����.
/// @param value ��������.
/// @return ���������� true, ���� ������� ������, ����� false.
bool FindElement(Dictionary* dictionary, std::string key, std::string& value);

/// @brief ������� �������.
/// @param table �������.
void DeleteDictionary(Dictionary* dictionary);