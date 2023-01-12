#pragma once
#include "TreapNode.h"

struct Treap
{
	TreapNode* Root = nullptr;

	const int MaxPriority = 100;
};