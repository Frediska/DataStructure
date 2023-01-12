#include "Treap.h"
#include <ctime>
#include <stdlib.h>

bool AddElement(Treap* treap, int value)
{
	TreapNode* node = new TreapNode;
	node->Data = value;

	if (treap->Root == nullptr)
	{
		treap->Root = node;
		return true;
	}

	TreapNode* parentNode = SearchParentNode(treap->Root, value);

	if (value >= parentNode->Data)
	{
		parentNode->Right = node;
	}
	else
	{
		parentNode->Left = node;
	}

	return true;
}

TreapNode* SearchParentNode(TreapNode* node, int value)
{
	if ((node->Data < value) && (node->Right == nullptr) ||
		(node->Data >= value) && (node->Left == nullptr))
	{
		return node;
	}

	if (node->Data < value)
	{
		SearchParentNode(node->Right, value);
	}
	else if (node->Data > value)
	{
		SearchParentNode(node->Left, value);
	}
}

TreapNode* SearchElement(TreapNode* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Data == value)
	{
		return node;
	}

	if ((node->Data < value) && (node->Right != nullptr))
	{
		SearchElement(node->Right, value);
	}
	else if ((node->Data > value) && (node->Left != nullptr))
	{
		SearchElement(node->Left, value);
	}
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if(node->Data > key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
	else if (node->Data < key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
}

void Merge(TreapNode*& node, TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		node = left ? left : right;
	}
	else if (left->Priority > right->Priority)
	{
		Merge(left->Right, left->Right, right);
		node = left;
	}
	else
	{
		Merge(right->Left, left, right->Left);
		node = right;
	}
}

void AddElementNotOptimization(TreapNode*& root, int value)
{
	TreapNode* left;
	TreapNode* right;
	Split(root, value, left, right);
	TreapNode* newNode = new TreapNode;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	newNode->Data = value;
	newNode->Priority = rand() % Treap().MaxPriority;
	Merge(root, left, newNode);
	Merge(root, root, right);
}

void InsertOptimization(int value, int priority, TreapNode*& node)
{
	if (node == nullptr)
	{
		node = new TreapNode;
		node->Left = nullptr;
		node->Right = nullptr;
		node->Data = value;
		node->Priority = priority;
		return;
	}

	if (priority >= node->Priority)
	{
		TreapNode* left;
		TreapNode* right;
		Split(node, value, left, right);
		TreapNode* newNode = new TreapNode;
		newNode->Left = left;
		newNode->Right = right;
		newNode->Data = value;
		newNode->Priority = priority;
		node = newNode;
	}
	else if (value < node->Data)
	{
		InsertOptimization(value, priority, node->Left);
	}
	else
	{
		InsertOptimization(value, priority, node->Right);
	}
}


