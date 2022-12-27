#pragma once
#include "RingBuffer.h"


/// @brief Структура реализации по представлению очереди кольцевого буфера.
struct QueueRingBuffer
{
	/// @brief Кольцевой буфер.
	RingBuffer* Buffer;
};

/// @brief Создает очередь кольцевого буфера.
/// @param size Размер очереди кольцевого буфера.
/// @return Возвращает очередь кольцевого буфера.
QueueRingBuffer* CreateQueueRingBuffer(int size);

/// @brief Изменяет размер очереди кольцевого буфера.
/// @param queueRingBuffer Очередь кольцевого буфера.
void ResizeQueueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief Добавляет элемент в очередь кольцевого буфера.
/// @param queueRingBuffer Очередь кольцевого буфера.
/// @param value Значение вставляемого элемента в очередь кольцевого буфера.
void EnqueueRingBuffer(QueueRingBuffer* queueRingBuffer, int value);

/// @brief Достает элемент из очереди кольцевого буфера.
/// @param queueRingBuffer Очередь кольцевого буфера.
/// @return Возвращает Возвращает значение достанного элемента.
int DequeueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief Удаляет очередь кольцевого буфера.
/// @param queueRingBuffer Очередь кольцевого буфера.
void DeleteQueueRingBuffer(QueueRingBuffer* queueRingBuffer);

/// @brief Возвращает кол-во элементов в очереди кольцевого буфера.
/// @param queueRingBuffer Очередь кольцевого буфера.
int LenghtQueueRingBuffer(QueueRingBuffer* queueRingBuffer);