#pragma once
#include "TreapNode.h"

struct Treap
{
	TreapNode* Root;

	const int MaxPriority = 100;
};

TreapNode* SearchElement(TreapNode* node, int value);
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);
void Merge(TreapNode*& node, TreapNode* left, TreapNode* right);
void AddElementNotOptimization(TreapNode*& root, int value);
void AddElementOptimization(int value, int priority, TreapNode*& node);
void DeleteNotOptimization(TreapNode*& root, int value);
void DeleteOptimization(int value, TreapNode*& element);
void DeleteTreap(TreapNode* node);