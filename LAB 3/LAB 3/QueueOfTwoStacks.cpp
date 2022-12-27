#include "QueueOfTwoStacks.h"

QueueOfTwoStacks* CreateQueueTwoStacks(int size)
{
	QueueOfTwoStacks* queueOfTwoStacks = new QueueOfTwoStacks();

	queueOfTwoStacks->InputStack = CreateStack(size);
	queueOfTwoStacks->OutputStack = CreateStack(size);

	return queueOfTwoStacks;
}

void ResizeQueueOfTwoStacks(QueueOfTwoStacks* queueOfTwoStacks)
{
	ResizeStack(queueOfTwoStacks->InputStack);
	ResizeStack(queueOfTwoStacks->OutputStack);
}

bool Enqueue(QueueOfTwoStacks* queueOfTwoStacks, int value)
{
	bool isOverflow;
	if (queueOfTwoStacks->InputStack->Top == queueOfTwoStacks->InputStack->Capacity)
	{
		isOverflow = false;
	}
	else
	{
		isOverflow = PushStack(queueOfTwoStacks->InputStack, value);
	}

	return isOverflow;
}

int Dequeue(QueueOfTwoStacks* queueOfTwoStacks)
{
	if (queueOfTwoStacks->OutputStack->Top == 0)
	{
		if (queueOfTwoStacks->InputStack->Top == 0)
		{
			return false;
		}

		while (queueOfTwoStacks->InputStack->Top != 0)
		{
			PushStack(queueOfTwoStacks->OutputStack, (PopStack(queueOfTwoStacks->InputStack)));
		}
	}
	return PopStack(queueOfTwoStacks->OutputStack);
}

void DeleteQueueTwoStacks(QueueOfTwoStacks* queueOfTwoStacks)
{
	DeleteStack(queueOfTwoStacks->InputStack);
	DeleteStack(queueOfTwoStacks->OutputStack);
}