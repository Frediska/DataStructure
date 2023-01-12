#pragma once
#include "Chain.h"

/// @brief Структура для хеш-таблицы.
struct HashTable
{
	/// @brief Число роста размера таблицы.
	const int GrowthFactor = 2;

	/// @brief Количество элементов в таблице.
	int Count;

	/// @brief Размер таблицы.
	int Size;

	/// @brief Двумерный динамический массив строк.
	Chain** Array;
};

/// @brief Создание хеш-таблицы.
/// @param size Размер таблицы.
/// @return Возвращает хеш-таблицу.
HashTable* CreateHashTable(int size);

/// @brief Создает узел.
/// @param key Ключ.
/// @param value Значение.
/// @return Возвращает элемент.
Node* CreateNode(std::string key, std::string value);

/// @brief Добавление элемента в хеш-таблицу.
/// @param table Таблица.
/// @param node Узел.
/// @param index Индекс.
/// @return Возвращает true, если элемент был успешно вставлен, иначе false.
bool AddElement(HashTable* table, Node* node, int index);

/// @brief Разрешение столкновений.
/// @param first Первый элемент.
/// @param node Узел.
void ResolveCollisions(Node* first, Node* node);

/// @brief Преобразуйте значение ключа в хеш-сумму.
/// @param key Ключ.
/// @param tableSize Размер таблицы.
/// @return Возвращает хеш-сумму.
int HashFunction(std::string key, int tableSize);

/// @brief Ищет элемент с заданным ключом.
/// @param table Таблица.
/// @param key Ключ.
/// @param data Значение.
/// @return Возвращает true, если элемент найден, иначе false.
bool FindElement(HashTable* table, std::string key, std::string& data);

/// @brief Удаляет элемент с заданным ключом.
/// @param table Таблица.
/// @param key Ключ.
/// @return Возвращает true, если элемент был успешно удален, иначе false.
bool RemoveElement(HashTable* table, std::string key);

/// @brief Удаляет хеш-таблицу.
/// @param table Таблица.
void DeleteTable(HashTable* table);

/// @brief Перехеширование таблицы.
/// @param table Таблица.
void Rehashing(HashTable* table);
