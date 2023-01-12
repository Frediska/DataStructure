#pragma once

/// @brief ����� ������.
struct Rib
{
	/// @brief ��������� �� ���������� �����.
	Rib* prev;

	/// @brief �������.
	std::string str;

	/// @brief ������� ��������� ��������� Rib.
	/// @param prev ���������� �����.
	/// @param str �������.
	Rib(Rib* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};