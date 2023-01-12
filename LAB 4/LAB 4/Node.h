#pragma once
#include <string>

/// @brief Структура представления узла хеш-таблицы.
struct Node
{
	/// @brief Указатель на следующий узел.
	Node* Next;

	/// @brief Значение узла.
	std::string Value;

	/// @brief Ключ узла.
	std::string Key;
};