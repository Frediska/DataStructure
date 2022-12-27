#pragma once
#include "Chain.h"

struct HashTable
{
	const int GrowthFactor = 2;

	int Count;

	int Size;

	Chain** Array;
};