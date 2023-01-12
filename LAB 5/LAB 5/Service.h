#pragma once
#include "BinaryTree.h"
#include "Rib.h"
#include "Treap.h"

/// @brief Проверка занчения на целочисленное.
/// @param text Текст задания.
/// @return Возвращает целочисленное значение.
int CheckingForDigit(const char* text);

/// @brief Показать ребро дерева.
/// @param rib Ребро дерева.
void ShowRib(Rib* rib);

/// @brief Показать бинарное дерево.
/// @param root Корни.
/// @param prev Придыдущее ребро.
/// @param isLeft Проверка на то, является ли элемент левым.
void ShowBinaryTree(BinaryTreeNode* root, Rib* prev, bool isLeft);

/// @brief Показать декартово дерево.
/// @param node Узел.
/// @param level Уровень элемента.
void ShowTreap(TreapNode* node, int level);

/// @brief Проверка на то, существует ли бинарное дерево.
/// @param binaryTree Бинарное дерево.
/// @return Возвращает true, если дерево существует, иначе false.
bool BinaryTreeIsEmpty(BinaryTree* binaryTree);

/// @brief Проверка на то, существует ли декартово дерево.
/// @param treap Декартово дерево.
/// @return Возвращает true, если дерево существует, иначе false.
bool TreapIsEmpty(Treap* treap);

/// @brief Проверяет, существует ли вводимый элемент в декартовом дереве.
/// @param value Значение.
/// @param treap Декартово дерево.
/// @param node Узел.
/// @return Возвращает true, если элемент уже существует в дереве, иначе false.
bool CheckElement(int value, Treap* treap, TreapNode* node);