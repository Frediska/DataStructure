#pragma once

/// @brief ������������ ���������� �� ������������� ���� ��������� ������.
struct BinaryTreeNode
{
	/// @brief ���������.
	int Data;

	/// @brief ��������� �� ����� ����.
	BinaryTreeNode* Left = nullptr;

	/// @brief ��������� �� ������ ����.
	BinaryTreeNode* Right = nullptr;
};