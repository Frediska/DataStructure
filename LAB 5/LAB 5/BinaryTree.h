#pragma once
#include "BinaryTreeNode.h"

/// @brief ��������� ��������� ������.
struct BinaryTree
{
	/// @brief ����� ������.
	BinaryTreeNode* Root = nullptr;
};

/// @brief ��������� ������� � ������.
/// @param tree ������.
/// @param value ��������.
/// @return ���������� true, ���� ������� ��������.
bool AddElement(BinaryTree* binaryTree, int value);

/// @brief ����� ������������� ����.
/// @param node ����.
/// @param value ��������.
/// @return ���������� ���������� ��������.
BinaryTreeNode* SearchParentNode(BinaryTreeNode* node, int value);

/// @brief �������� �������� �� ������.
/// @param binaryTree �������� ������.
/// @param value ��������.
/// @return ���������� ��������� �������.
BinaryTreeNode* DeleteElement(BinaryTreeNode* binaryTree, int value);

/// @brief ����� ������������ �������� � ������.
/// @param node ����.
/// @return ���������� ����������� �������.
BinaryTreeNode* SearchMinElement(BinaryTreeNode* node);

/// @brief ����� ������������� �������� � ������.
/// @param node ����.
/// @return ���������� ������������ �������.
BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node);

/// @brief ����� �������� � ������.
/// @param node ����.
/// @param value ��������.
/// @return ���������� ������� �������.
BinaryTreeNode* SearchElement(BinaryTreeNode* node, int value);

/// @brief �������� ��������� ������.
/// @param node ����.
void DeleteBinaryTree(BinaryTreeNode* node);