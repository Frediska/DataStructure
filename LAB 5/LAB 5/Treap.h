#pragma once
#include "TreapNode.h"

/// @brief ��������� ��������� ������.
struct Treap
{
	/// @brief ����� ��������� ������.
	TreapNode* Root = nullptr;

	/// @brief ������������ ���������.
	const int MaxPriority = 100;
};

/// @brief ���� ������� �� ��������.
/// @param value ��������.
/// @param priority ���������.
/// @param node ����.
TreapNode* SearchElement(TreapNode* node, int value);

/// @brief ��������� ����� �� ��� �����.
/// @param node ����.
/// @param key ����.
/// @param left ������ �� ����� ����.
/// @param right ������ �� ���������� ����.
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// @brief ��������� ��� ����� �����.
/// @param node ����.
/// @param left �������� �����.
/// @param right ������ �����.
void Merge(TreapNode*& node, TreapNode* left, TreapNode* right);

/// @brief �������� �������� �� ���������������� ��������.
/// @param root �����.
/// @param value ��������.
void AddElementNotOptimization(TreapNode*& root, int value);

/// @brief �������� �������� ���������������� ��������.
/// @param value ��������.
/// @param priority ���������.
/// @param node ����.
void AddElementOptimization(int value, int priority, TreapNode*& node);

/// @brief ������� �������� �� ���������������� ��������.
/// @param root �����.
/// @param value ��������.
void DeleteNotOptimization(TreapNode*& root, int value);

/// @brief ������� �������� ���������������� ��������.
/// @param value ��������.
/// @param element �������.
void DeleteOptimization(int value, TreapNode*& element);

/// @brief ������� ��������� ������.
/// @param node ����.
void DeleteTreap(TreapNode* node);