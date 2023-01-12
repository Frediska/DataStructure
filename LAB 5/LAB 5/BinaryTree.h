#pragma once
#include "BinaryTreeNode.h"

/// @brief Структура бинарного дерева.
struct BinaryTree
{
	/// @brief Корни дерева.
	BinaryTreeNode* Root = nullptr;
};

/// @brief Добавляет элемент в дерево.
/// @param tree Дерево.
/// @param value Значение.
/// @return Возвращает true, если элемент добавлен.
bool AddElement(BinaryTree* binaryTree, int value);

/// @brief Поиск родительского узла.
/// @param node Узел.
/// @param value Значение.
/// @return Возвращает найденного родителя.
BinaryTreeNode* SearchParentNode(BinaryTreeNode* node, int value);

/// @brief Удаление элемента из дерева.
/// @param binaryTree Бинарное дерево.
/// @param value Значение.
/// @return Возвращает удаленный элемент.
BinaryTreeNode* DeleteElement(BinaryTreeNode* binaryTree, int value);

/// @brief Поиск минимального элемента в дереве.
/// @param node Узел.
/// @return Возвращает минимальный элемент.
BinaryTreeNode* SearchMinElement(BinaryTreeNode* node);

/// @brief Поиск максимального элемента в дереве.
/// @param node Узел.
/// @return Возвращает максимальный элемент.
BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node);

/// @brief Поиск элемента в дереве.
/// @param node Узел.
/// @param value Значение.
/// @return Возвращает искомый элемент.
BinaryTreeNode* SearchElement(BinaryTreeNode* node, int value);

/// @brief Удаление бинарного дерева.
/// @param node Узел.
void DeleteBinaryTree(BinaryTreeNode* node);