#include "Stack.h"

Stack* CreateStack(int size)
{
	Stack* stack = new Stack();

	if (size < 4)
	{
		size = 4;
	}

	stack->Buffer = new int[size];
	stack->Top = 0;
	stack->Capacity = size;

	return stack;
}

void ResizeStack(Stack* stack)
{
	stack->Capacity *= stack->GrowthFactor;

	int* tempArray = new int[stack->Capacity];

	for (int i = 0; i < stack->Top; i++)
	{
		tempArray[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;

	stack->Buffer = tempArray;
}

bool PushStack(Stack* stack, int value)
{
	if (stack->Top >= stack->Capacity)
	{
		return false;
	}
	stack->Buffer[stack->Top] = value;
	stack->Top++;
	return true;
}

int PopStack(Stack* stack)
{
	if (stack->Top > 0)
	{
		stack->Top--;
		return stack->Buffer[stack->Top];
	}
}

void DeleteStack(Stack* stack)
{
	delete[] stack->Buffer;
	delete stack;
}

