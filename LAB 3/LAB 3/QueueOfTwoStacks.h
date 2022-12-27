#pragma once
#include "Stack.h"

/// @brief ��������� ���������� �� ������������� ������� �����.
struct QueueOfTwoStacks
{
	/// @brief ����, �������� �������� ��������.
	Stack* InputStack;

	/// @brief ����, �������� ��������� ��������.
	Stack* OutputStack;
};

/// @brief ������� ������� �����.
/// @param size ������ ������� �����.
/// @return ���������� ������� �����.
QueueOfTwoStacks* CreateQueueTwoStacks(int size);

/// @brief �������� ������ ������� �����.
/// @param queueOfTwoStacks ������� �����.
void ResizeQueueOfTwoStacks(QueueOfTwoStacks* queueOfTwoStacks);

/// @brief ��������� ������� � ������� �����.
/// @param queueOfTwoStacks ������� �����.
/// @param value �������� ������������ ��������.
/// @return ���������� true, ���� ������� ��� ��������, ����� false.
bool Enqueue(QueueOfTwoStacks* queueOfTwoStacks, int value);

/// @brief ������� ������� �� ������� �����.
/// @param queueOfTwoStacks ������� �����.
/// @return ���������� �������� ���������� ��������.
int Dequeue(QueueOfTwoStacks* queueOfTwoStacks);

/// @brief ������� ������� �����.
/// @param queueRingBuffer ������� �����.
void DeleteQueueTwoStacks(QueueOfTwoStacks* queueOfTwoStacks);