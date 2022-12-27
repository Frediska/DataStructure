#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "QueueRingBuffer.h"
#include "QueueOfTwoStacks.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "An error has occurred. Try again." << endl;
			continue;
		}

		cin.ignore(32767, '\n');
		if (cin.gcount() > 1)
		{
			cout << "An error has occurred. Try again." << endl;
			continue;
		}
		break;
	}
	return value;
}

void ShowStack(Stack* stack)
{
	cout << "----------------" << endl;
	for (int i = 0; i < stack->Top; i++)
	{
		cout << stack->Buffer[i] << " ";
	}
	cout << endl;
	cout << "----------------" << endl;
}

void ShowRingBuffer(RingBuffer* buffer)
{
	int index = buffer->IndexOutput;

	cout << "----------------" << endl;
	for (int i = 0; i < buffer->UsedMemory; i++)
	{
		cout << buffer->Buffer[index++] << " -> ";

		if (index > buffer->Size - 1)
		{
			index = 0;
		}
	}

	cout << endl;
	cout << "----------------" << endl;
}

void ShowQueueRingBuffer(QueueRingBuffer* queueRingBuffer)
{
	ShowRingBuffer(queueRingBuffer->Buffer);
}

void ShowQueueTwoStacks(QueueOfTwoStacks* queue)
{
	cout << "Input stack: " << endl;

	ShowStack(queue->InputStack);

	cout << endl;
	cout << "Output stack: " << endl;

	ShowStack(queue->OutputStack);

	cout << endl;
}

void MenuQueueOfTwoStacks()
{
	QueueOfTwoStacks* queueOfTwoStacks = nullptr;

	cout << "Work with queue of two stacks." << endl;
	while (true)
	{

		cout << "1. Create a queue of two stacks.\n2. Enqueue an element to queue.\n"
			"3. Dequeue element from the queue.\n4. Resize the queue.\n"
			"5. Delete the queue.\n6. Show queue of two stacks.\n"
			"0. Go back.\n";

		int taskNumber = CheckingForDigit("Choose the number of action: ");

		switch (taskNumber)
		{
			case 1:
			{
				if (queueOfTwoStacks == nullptr)
				{
					int size = CheckingForDigit("Enter the length queue of two stacks: ");
					queueOfTwoStacks = CreateQueueTwoStacks(size);
					cout << "Queue of two stacks successfully created:" << endl;
					ShowQueueTwoStacks(queueOfTwoStacks);
				}
				else
				{
					cout << "Queue already created." << endl;
				}
				break;
			}
			case 2:
			{
				if (queueOfTwoStacks != nullptr)
				{
					int value = CheckingForDigit("Enter an element wich you want to add in queue:");
					if (!Enqueue(queueOfTwoStacks, value))
					{
						cout << "Queue overflow." << endl;
					}
					ShowQueueTwoStacks(queueOfTwoStacks);
				}
				else
				{
					cout << "The queue of two stacks has not yet been created." << endl;
				}
				break;
			}
			case 3:
			{
				if (queueOfTwoStacks != nullptr)
				{

					if (queueOfTwoStacks->InputStack->Top || queueOfTwoStacks->OutputStack->Top > 0)
					{
						cout << "Got the element: " << Dequeue(queueOfTwoStacks) << endl;
						ShowQueueTwoStacks(queueOfTwoStacks);
					}
					else
					{
						cout << "Queue is empty." << endl;
					}
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 4:
			{
				if (queueOfTwoStacks != nullptr)
				{
					ResizeQueueOfTwoStacks(queueOfTwoStacks);
					cout << "Queue is resized 2 times more." << endl;
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 5:
			{
				if (queueOfTwoStacks != nullptr)
				{
					DeleteQueueTwoStacks(queueOfTwoStacks);
					delete queueOfTwoStacks;
					queueOfTwoStacks = nullptr;
					cout << "Queue is deleted." << endl;
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 6:
			{
				if (queueOfTwoStacks != nullptr)
				{
					ShowQueueTwoStacks(queueOfTwoStacks);
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 0:
			{
				if (queueOfTwoStacks != nullptr)
				{
					DeleteQueueTwoStacks(queueOfTwoStacks);
					delete queueOfTwoStacks;
				}
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}



void MenuQueueRingBuffer()
{
	QueueRingBuffer* queueRingBuffer = nullptr;

	cout << "Work with queue ring buffer." << endl;

	while (true)
	{
		cout << "1. Create a queue ring buffer.\n2. Enqueue an element to queue ring buffer.\n"
			"3. Dequeue element from the queue.\n4. Resize the queue.\n"
			"5. Delete the queue.\n6. Show queue ring bufer.\n"
			"0. Go back.\n";

		int taskNumber = CheckingForDigit("Choose the number of action: ");

		switch (taskNumber)
		{
			case 1:
			{
				if (queueRingBuffer == nullptr)
				{
					int size = CheckingForDigit("Enter the length queue ring buffer: ");
					queueRingBuffer = CreateQueueRingBuffer(size);
					cout << "Queue ring buffer successfully created:" << endl;
					ShowQueueRingBuffer(queueRingBuffer);
				}
				else
				{
					cout << "Queue already created." << endl;
				}
				break;
			}
			case 2:
			{
				if (queueRingBuffer != nullptr)
				{
					int value = CheckingForDigit("Enter an element wich you want to add in queue:");
					EnqueueRingBuffer(queueRingBuffer, value);
					ShowQueueRingBuffer(queueRingBuffer);
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 3:
			{
				if (queueRingBuffer != nullptr)
				{
					if (LenghtQueueRingBuffer(queueRingBuffer) > 0)
					{
						cout << "Got the element: " << DequeueRingBuffer(queueRingBuffer) << endl;
						ShowQueueRingBuffer(queueRingBuffer);
					}
					else
					{
						cout << "Queue is empty." << endl;
					}
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 4:
			{
				if (queueRingBuffer != nullptr)
				{
					ResizeQueueRingBuffer(queueRingBuffer);
					cout << "Queue is resized 2 times more." << endl;
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 5:
			{
				if (queueRingBuffer != nullptr)
				{
					DeleteQueueRingBuffer(queueRingBuffer);
					delete queueRingBuffer;
					queueRingBuffer = nullptr;
					cout << "Queue is deleted." << endl;
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 6:
			{
				if (queueRingBuffer != nullptr)
				{
					ShowQueueRingBuffer(queueRingBuffer);
				}
				else
				{
					cout << "The queue ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 0:
			{
				if (queueRingBuffer != nullptr)
				{
					DeleteQueueRingBuffer(queueRingBuffer);
					delete queueRingBuffer;
				}
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}



void MenuRingBuffer()
{
	RingBuffer* ringBuffer = nullptr;

	cout << "Work with ring buffer." << endl;

	while (true)
	{
		cout << "1. Create a ring buffer.\n2. Return free memory.\n"
			"3. Return used memory.\n4. Push an element in ring buffer.\n"
			"5. Pop element of ring buffer.\n6. Resize the ring buffer.\n"
			"7. Show the ring buffer.\n0. Go back.\n";

		int taskNumber = CheckingForDigit("Choose the number of action: ");
		
		switch (taskNumber)
		{
			case 1:
			{
				if (ringBuffer == nullptr)
				{
					int size = CheckingForDigit("Enter the length ring buffer: ");
					ringBuffer = InitRingBuffer(size);
					cout << "Ring buffer successfully created:" << endl;
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "Ring buffer already created." << endl;
				}
				break;
			}
			case 2:
			{
				if (ringBuffer != nullptr)
				{
					cout << "Free memory: " << FreeMemoryInfo(ringBuffer) << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 3:
			{
				if (ringBuffer != nullptr)
				{
					cout << "Used memory: " << UsedMemoryInfo(ringBuffer) << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 4:
			{
				if (ringBuffer != nullptr)
				{
					int value = CheckingForDigit("Enter the element you want to add: ");
					PushRingBuffer(ringBuffer, value);
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 5:
			{
				if (ringBuffer != nullptr)
				{
					if (UsedMemoryInfo(ringBuffer) > 0)
					{
						cout << "Got the element: " << PopRingBuffer(ringBuffer) << endl;
						ShowRingBuffer(ringBuffer);
					}
					else
					{
						cout << "Buffer is empty." << endl;
					}
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 6:
			{
				if (ringBuffer != nullptr)
				{
					ResizeRingBuffer(ringBuffer);
					cout << "Ring buffer is resized 2 times more." << endl;
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 7:
			{
				if (ringBuffer != nullptr)
				{
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "The ring buffer has not yet been created." << endl;
				}
				break;
			}
			case 0:
			{
				if (ringBuffer != nullptr)
				{
					delete[] ringBuffer->Buffer;
					delete ringBuffer;
				}
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}

void MenuStack()
{
	Stack* stack = nullptr;

	cout << "Work with stack." << endl;

	while (true)
	{
		cout << "1. Create a stack.\n2. Push an element to the stack.\n"
			"3. Pop element from stack.\n4. Remove stack.\n"
			"5. Resize the stack.\n6. Show the stack.\n"
			"0. Go back.\n";

		int taskNumber = CheckingForDigit("Choose the number of action: ");

		switch (taskNumber)
		{
			case 1:
			{
				if (stack == nullptr)
				{
					int size = CheckingForDigit("Enter the length stack: ");
					stack = CreateStack(size);
					cout << "Stack successfully created:" << endl;
					ShowStack(stack);
				}
				else
				{
					cout << "Stack already created." << endl;
				}
				break;
			}
			case 2:
			{
				if (stack != nullptr)
				{
					int value = CheckingForDigit("Enter the element you want to add: ");
					if (!PushStack(stack, value))
					{
						cout << "Stack if overflow." << endl;
					}
					ShowStack(stack);
				}
				else
				{
					cout << "The stack has not yet been created." << endl;
				}
				break;
			}
			case 3:
			{
				if (stack != nullptr)
				{
					if (stack->Top > 0)
					{
						cout << "Got the element: " << PopStack(stack) << endl;
						ShowStack(stack);
					}
					else
					{
						cout << "Stack is empty." << endl;
					}

				}
				else
				{
					cout << "The stack has not yet been created." << endl;
				}
				break;
			}
			case 4:
			{
				if (stack != nullptr)
				{
					DeleteStack(stack);
					stack = nullptr;
					cout << "Stack successfully deleted." << endl;
				}
				else
				{
					cout << "The stack has not yet been created." << endl;
				}
				break;
			}
			case 5:
			{
				if (stack != nullptr)
				{
					ResizeStack(stack);
					cout << "Stack is resized 2 times more." << endl;
				}
				else
				{
					cout << "The stack has not yet been created." << endl;
				}
				break;
			}
			case 6:
			{
				if (stack != nullptr)
				{
					ShowStack(stack);
				}
				else
				{
					cout << "The stack has not yet been created." << endl;
				}
				break;
			}
			case 0:
			{
				if (stack != nullptr)
				{
					DeleteStack(stack);
				}
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}

}

int main()
{
    while (true)
    {
		cout << "Choose which function you want to use: " << endl;
        cout << "1. Stack.\n2. Ring buffer.\n"
			"3. Queue ring buffer.\n4. Queue of two stacks.\n";

		int taskNumber = CheckingForDigit("Enter function number: ");

		switch (taskNumber)
		{
			case 1:
			{
				system("cls");
				MenuStack();
				break;
			}
			case 2:
			{
				system("cls");
				MenuRingBuffer();
				break;
			}
			case 3:
			{
				system("cls");
				MenuQueueRingBuffer();
				break;
			}
			case 4:
			{
				system("cls");
				MenuQueueOfTwoStacks();
				break;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
    }
}
