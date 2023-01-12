#include "Treap.h"
#include <ctime>
#include <cstdlib>

TreapNode* SearchElement(TreapNode* node, int value)
{
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
	else
	{
		return nullptr;
	}
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else
	{
		if (node->Data > key)
		{
			Split(node->Left, key, left, node->Left);
			right = node;
		}
		else
		{
			Split(node->Right, key, node->Right, right);
			left = node;
		}
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

void AddElementOptimization(int value, int priority, TreapNode*& node)
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
		AddElementOptimization(value, priority, node->Left);
	}
	else
	{
		AddElementOptimization(value, priority, node->Right);
	}
}

void DeleteNotOptimization(TreapNode*& root, int value)
{
	TreapNode* left;
	TreapNode* right;
	TreapNode* node;
	Split(root, value - 1, left, right);
	Split(right, value, node, right);
	Merge(root, left, right);
	delete node;
}

void DeleteOptimization(int value, TreapNode*& element)
{
	if (element == nullptr)
	{
		return;
	}
	if (value == element->Data)
	{
		TreapNode* node = element;
		Merge(node, element->Left, element->Right);
		delete element;
	}
	else if (value < element->Data)
	{
		DeleteOptimization(value, element->Left);
	}
	else
	{
		DeleteOptimization(value, element->Right);
	}
}

void DeleteTreap(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	DeleteTreap(node->Left);
	DeleteTreap(node->Right);
	delete node;
}




