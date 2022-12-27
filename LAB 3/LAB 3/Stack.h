#pragma once

/// @brief Структура реализации по представлению стека.
struct Stack
{
	/// @brief Буфер.
	int* Buffer;
	
	/// @brief Элемент вершины стека.
	int Top;

	/// @brief Емкость стека.
	int Capacity;

	/// @brief Число роста стека.
	const int GrowthFactor = 2;
};

/// @brief Создает стек.
/// @param size Размер стека.
/// @return Возвращает стек.
Stack* CreateStack(int size);

/// @brief Изменяет размер стека.
/// @param stack Стек.
void ResizeStack(Stack* stack);

/// @brief Вставляет элемент в стек.
/// @param stack Стек.
/// @param value Значение вставляемого элемента.
/// @return Возвращает true, если элемент был вставлен, иначе false.
bool PushStack(Stack* stack, int value);

/// @brief Вытаскивает элемент из стека.
/// @param stack Стек.
/// @return Возвращает значение достанного стека.
int PopStack(Stack* stack);

/// @brief Удаляет стек.
/// @param stack Стек.
void DeleteStack(Stack* stack);