#include "RingBuffer.h"

RingBuffer* InitRingBuffer(int size)
{
	RingBuffer* ringBuffer = new RingBuffer();

	ringBuffer->Size = size;
	ringBuffer->FreeMemory = size;
	ringBuffer->UsedMemory = 0;
	ringBuffer->Buffer = new int[size];
	ringBuffer->IndexInput = ringBuffer->IndexOutput = 0;

	return ringBuffer;
}

void ResizeRingBuffer(RingBuffer* ringBuffer)
{
	int oldSize = ringBuffer->Size;

	int* tempArray = new int[ringBuffer->Size *= ringBuffer->GrowthFactor];

	for (int i = 0; i < ringBuffer->UsedMemory; i++)
	{
		tempArray[i] = ringBuffer->Buffer[ringBuffer->IndexOutput++];

		if (ringBuffer->IndexOutput > oldSize - 1)
		{
			ringBuffer->IndexOutput = 0;
		}
	}

	ringBuffer->IndexOutput = 0;
	ringBuffer->IndexInput = ringBuffer->UsedMemory;
	ringBuffer->FreeMemory = ringBuffer->Size - ringBuffer->UsedMemory;

	delete[] ringBuffer->Buffer;
	ringBuffer->Buffer = tempArray;
}

void PushRingBuffer(RingBuffer* ringBuffer, int value)
{
	if (ringBuffer->IndexInput > ringBuffer->Size - 1)
	{
		ringBuffer->IndexInput = 0;
	}

	if (ringBuffer->IndexInput == ringBuffer->IndexOutput &&
		UsedMemoryInfo(ringBuffer) > 0)
	{
		ringBuffer->IndexOutput++;

		if (ringBuffer->IndexOutput > ringBuffer->Size - 1)
		{
			ringBuffer->IndexOutput = 0;
		}
	}

	ringBuffer->Buffer[ringBuffer->IndexInput++] = value;

	if (FreeMemoryInfo(ringBuffer) > 0)
	{
		ringBuffer->FreeMemory--;
		ringBuffer->UsedMemory++;
	}
}

int PopRingBuffer(RingBuffer* ringBuffer)
{
	if (UsedMemoryInfo(ringBuffer) > 0)
	{
		ringBuffer->FreeMemory++;
		ringBuffer->UsedMemory--;

		int item = ringBuffer->Buffer[ringBuffer->IndexOutput++];

		if (ringBuffer->IndexOutput > ringBuffer->Size - 1)
		{
			ringBuffer->IndexOutput = 0;
		}

		return item;
	}
}

int FreeMemoryInfo(RingBuffer* ringBuffer)
{
	return ringBuffer->FreeMemory;
}
int UsedMemoryInfo(RingBuffer* ringBuffer)
{
	return ringBuffer->UsedMemory;
}