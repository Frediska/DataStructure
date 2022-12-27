#pragma once

/// @brief Структура реализации по представлению кольцевого буфера.
struct RingBuffer
{
	/// @brief Свободное мество в кольцевом буфере.
	int FreeMemory;

	/// @brief Занятое место в кольцевом буфере.
	int UsedMemory;

	/// @brief Кольцевой буфер.
	int* Buffer;

	/// @brief Размер буфера.
	int Size;

	/// @brief Индекс, в который производится запись.
	int IndexInput;

	/// @brief Индекс, из которого производится чтение.
	int IndexOutput;

	/// @brief Число роста кольцевого буфера.
	int const GrowthFactor = 2;
};

/// @brief Создает кольцевой буфер.
/// @param size Размер кольцевого буфера.
/// @return Возвращает кольцевой буфер.
RingBuffer* InitRingBuffer(int size);

/// @brief Изменяет размер кольцевого буфера.
/// @param ringBuffer Кольцевой буфер.
void ResizeRingBuffer(RingBuffer* ringBuffer);

/// @brief Вставляет элемент в кольцевой буфер.
/// @param ringBuffer Кольцевой буфер.
/// @param value Значение вставляемого элемента в кольцевой буфер.
void PushRingBuffer(RingBuffer* ringBuffer, int value);

/// @brief Вытаскивает элемент из кольцевого буфера.
/// @param ringBuffer Кольцевой буфер.
/// @return Возвращает значение достанного элемента.
int PopRingBuffer(RingBuffer* ringBuffer);

/// @brief Информация о свободном месте.
/// @param ringBuffer Кольцевой буфер.
/// @return Возвращает количество свободного места в кольцевом буфере.
int FreeMemoryInfo(RingBuffer* ringBuffer);

/// @brief Информация о занятом месте.
/// @param ringBuffer Кольцевой буфер.
/// @return Возвращает количество занятого места в кольцевом буфере.
int UsedMemoryInfo(RingBuffer* ringBuffer);