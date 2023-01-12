#pragma once

struct TreapNode
{
	int Data;

	int Priority;

	TreapNode* Left = nullptr;

	TreapNode* Right = nullptr;
};