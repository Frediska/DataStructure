#pragma once
#include "Stack.h"

/// @brief Структура реализации по представлению очереди стека.
struct QueueOfTwoStacks
{
	/// @brief Стек, хранящий вводимые элементы.
	Stack* InputStack;

	/// @brief Стек, хранящий выводимые элементы.
	Stack* OutputStack;
};

/// @brief Создает очередь стека.
/// @param size Размер очереди стека.
/// @return Возвращает очередь стека.
QueueOfTwoStacks* CreateQueueTwoStacks(int size);

/// @brief Изменяет размер очереди стека.
/// @param queueOfTwoStacks Очередь стека.
void ResizeQueueOfTwoStacks(QueueOfTwoStacks* queueOfTwoStacks);

/// @brief Добавляет элемент в очередь стека.
/// @param queueOfTwoStacks Очередь стека.
/// @param value Значение добавляемого элемента.
/// @return Возвращает true, если элемент был вставлен, иначе false.
bool Enqueue(QueueOfTwoStacks* queueOfTwoStacks, int value);

/// @brief Достает элемент из очереди стека.
/// @param queueOfTwoStacks Очередь стека.
/// @return Возвращает значение достанного элемента.
int Dequeue(QueueOfTwoStacks* queueOfTwoStacks);

/// @brief Удаляет очередь стека.
/// @param queueRingBuffer Очередь стека.
void DeleteQueueTwoStacks(QueueOfTwoStacks* queueOfTwoStacks);