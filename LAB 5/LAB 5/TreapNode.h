#pragma once

/// @brief ��������� ���� ��������� ������.
struct TreapNode
{
	/// @brief ��������.
	int Data;

	/// @brief ���������.
	int Priority;

	/// @brief ��������� �� ����� ����.
	TreapNode* Left;

	/// @brief ��������� �� ������ ����.
	TreapNode* Right;
};