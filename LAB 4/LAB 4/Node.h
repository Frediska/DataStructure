#pragma once
#include <string>

/// @brief ��������� ������������� ���� ���-�������.
struct Node
{
	/// @brief ��������� �� ��������� ����.
	Node* Next;

	/// @brief �������� ����.
	std::string Value;

	/// @brief ���� ����.
	std::string Key;
};