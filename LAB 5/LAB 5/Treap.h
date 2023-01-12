#pragma once
#include "TreapNode.h"

/// @brief Структура декартова дерева.
struct Treap
{
	/// @brief Корни декартова дерева.
	TreapNode* Root = nullptr;

	/// @brief Максимальный приоритет.
	const int MaxPriority = 100;
};

/// @brief Ищет элемент по значению.
/// @param value Значение.
/// @param priority Приоритет.
/// @param node Узел.
TreapNode* SearchElement(TreapNode* node, int value);

/// @brief Разрезает ветку на две части.
/// @param node Узел.
/// @param key Ключ.
/// @param left Ссылка на левый узел.
/// @param right Ссылка на правильный узел.
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// @brief Соединяет две части ветки.
/// @param node Узел.
/// @param left Параметр слева.
/// @param right Правая часть.
void Merge(TreapNode*& node, TreapNode* left, TreapNode* right);

/// @brief Добавить эелемент не оптимизированным способом.
/// @param root Корни.
/// @param value Значение.
void AddElementNotOptimization(TreapNode*& root, int value);

/// @brief Добавить эелемент оптимизированным способом.
/// @param value Значение.
/// @param priority Приоритет.
/// @param node Узел.
void AddElementOptimization(int value, int priority, TreapNode*& node);

/// @brief Удалить эелемент не оптимизированным способом.
/// @param root Корни.
/// @param value Значение.
void DeleteNotOptimization(TreapNode*& root, int value);

/// @brief Удалить эелемент оптимизированным способом.
/// @param value Значение.
/// @param element Элемент.
void DeleteOptimization(int value, TreapNode*& element);

/// @brief Удалить декартово дерево.
/// @param node Узел.
void DeleteTreap(TreapNode* node);