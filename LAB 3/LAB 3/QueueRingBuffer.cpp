#include "QueueRingBuffer.h"

QueueRingBuffer* CreateQueueRingBuffer(int size)
{
	QueueRingBuffer* queueRingBuffer = new QueueRingBuffer();

	queueRingBuffer->Buffer = InitRingBuffer(size);

	return queueRingBuffer;
}

void ResizeQueueRingBuffer(QueueRingBuffer* queueRingBuffer)
{
	ResizeRingBuffer(queueRingBuffer->Buffer);
}

void EnqueueRingBuffer(QueueRingBuffer* queueRingBuffer, int value)
{
	PushRingBuffer(queueRingBuffer->Buffer, value);
}

int DequeueRingBuffer(QueueRingBuffer* queueRingBuffer)
{
	if (queueRingBuffer->Buffer->UsedMemory > 0)
	{
		return PopRingBuffer(queueRingBuffer->Buffer);
	}
}

void DeleteQueueRingBuffer(QueueRingBuffer* queueRingBuffer)
{
	delete[] queueRingBuffer->Buffer->Buffer;
	delete queueRingBuffer->Buffer;
}

int LenghtQueueRingBuffer(QueueRingBuffer* queueRingBuffer)
{
	return queueRingBuffer->Buffer->UsedMemory;
}