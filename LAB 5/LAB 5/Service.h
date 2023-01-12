#pragma once
#include "BinaryTree.h"
#include "Rib.h"
#include "Treap.h"

/// @brief �������� �������� �� �������������.
/// @param text ����� �������.
/// @return ���������� ������������� ��������.
int CheckingForDigit(const char* text);

/// @brief �������� ����� ������.
/// @param rib ����� ������.
void ShowRib(Rib* rib);

/// @brief �������� �������� ������.
/// @param root �����.
/// @param prev ���������� �����.
/// @param isLeft �������� �� ��, �������� �� ������� �����.
void ShowBinaryTree(BinaryTreeNode* root, Rib* prev, bool isLeft);

/// @brief �������� ��������� ������.
/// @param node ����.
/// @param level ������� ��������.
void ShowTreap(TreapNode* node, int level);

/// @brief �������� �� ��, ���������� �� �������� ������.
/// @param binaryTree �������� ������.
/// @return ���������� true, ���� ������ ����������, ����� false.
bool BinaryTreeIsEmpty(BinaryTree* binaryTree);

/// @brief �������� �� ��, ���������� �� ��������� ������.
/// @param treap ��������� ������.
/// @return ���������� true, ���� ������ ����������, ����� false.
bool TreapIsEmpty(Treap* treap);

/// @brief ���������, ���������� �� �������� ������� � ���������� ������.
/// @param value ��������.
/// @param treap ��������� ������.
/// @param node ����.
/// @return ���������� true, ���� ������� ��� ���������� � ������, ����� false.
bool CheckElement(int value, Treap* treap, TreapNode* node);