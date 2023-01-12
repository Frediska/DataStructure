#pragma once

/// @brief Представляет реализацию по представлению узла бинарного дерева.
struct BinaryTreeNode
{
	/// @brief Заначения.
	int Data;

	/// @brief Указатель на левый узел.
	BinaryTreeNode* Left = nullptr;

	/// @brief Указатель на правый узел.
	BinaryTreeNode* Right = nullptr;
};