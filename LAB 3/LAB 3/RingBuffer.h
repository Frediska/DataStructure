#pragma once

/// @brief ��������� ���������� �� ������������� ���������� ������.
struct RingBuffer
{
	/// @brief ��������� ������ � ��������� ������.
	int FreeMemory;

	/// @brief ������� ����� � ��������� ������.
	int UsedMemory;

	/// @brief ��������� �����.
	int* Buffer;

	/// @brief ������ ������.
	int Size;

	/// @brief ������, � ������� ������������ ������.
	int IndexInput;

	/// @brief ������, �� �������� ������������ ������.
	int IndexOutput;

	/// @brief ����� ����� ���������� ������.
	int const GrowthFactor = 2;
};

/// @brief ������� ��������� �����.
/// @param size ������ ���������� ������.
/// @return ���������� ��������� �����.
RingBuffer* InitRingBuffer(int size);

/// @brief �������� ������ ���������� ������.
/// @param ringBuffer ��������� �����.
void ResizeRingBuffer(RingBuffer* ringBuffer);

/// @brief ��������� ������� � ��������� �����.
/// @param ringBuffer ��������� �����.
/// @param value �������� ������������ �������� � ��������� �����.
void PushRingBuffer(RingBuffer* ringBuffer, int value);

/// @brief ����������� ������� �� ���������� ������.
/// @param ringBuffer ��������� �����.
/// @return ���������� �������� ���������� ��������.
int PopRingBuffer(RingBuffer* ringBuffer);

/// @brief ���������� � ��������� �����.
/// @param ringBuffer ��������� �����.
/// @return ���������� ���������� ���������� ����� � ��������� ������.
int FreeMemoryInfo(RingBuffer* ringBuffer);

/// @brief ���������� � ������� �����.
/// @param ringBuffer ��������� �����.
/// @return ���������� ���������� �������� ����� � ��������� ������.
int UsedMemoryInfo(RingBuffer* ringBuffer);