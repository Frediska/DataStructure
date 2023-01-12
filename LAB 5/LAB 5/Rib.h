#pragma once

struct Rib
{
	Rib* prev;
	std::string str;

	Rib(Rib* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};