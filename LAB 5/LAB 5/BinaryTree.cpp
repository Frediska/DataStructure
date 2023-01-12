#include "BinaryTree.h"


bool AddElement(BinaryTree* binaryTree, int value)
{
	BinaryTreeNode* node = new BinaryTreeNode;
	node->Data = value;

	if (binaryTree->Root == nullptr)
	{
		binaryTree->Root = node;
		return true;
	}

	BinaryTreeNode* parentNode = SearchParentNode(binaryTree->Root, value);

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

BinaryTreeNode* SearchParentNode(BinaryTreeNode* node, int value)
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

BinaryTreeNode* DeleteElement(BinaryTreeNode* binaryTree, int value)
{
	if (binaryTree == nullptr)
	{
		return binaryTree;
	}

	if (value < binaryTree->Data)
	{
		binaryTree->Left = DeleteElement(binaryTree->Left, value);
	}
	else if (value > binaryTree->Data)
	{
		binaryTree->Right = DeleteElement(binaryTree->Right, value);
	}
	else
	{
		if (binaryTree->Left == nullptr)
		{
			BinaryTreeNode* tempNode = binaryTree->Right;
			delete binaryTree;
			return tempNode;
		}
		if (binaryTree->Right == nullptr)
		{
			BinaryTreeNode* tempNode = binaryTree->Left;
			delete binaryTree;
			return tempNode;
		}

		BinaryTreeNode* tempNode = SearchMinElement(binaryTree->Right);
		binaryTree->Data = tempNode->Data;
		binaryTree->Right = DeleteElement(binaryTree->Right, tempNode->Data);
	}
	return binaryTree;
}

BinaryTreeNode* SearchMinElement(BinaryTreeNode* node)
{
	if (node->Left != nullptr)
	{
		node = SearchMinElement(node->Left);
	}
	else
	{
		return node;
	}
}

BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node)
{
	if (node->Right != nullptr)
	{
		node = SearchMaxElement(node->Right);
	}
	else
	{
		return node;
	}
}

BinaryTreeNode* SearchElement(BinaryTreeNode* node, int value)
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

void DeleteBinaryTree(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	DeleteBinaryTree(node->Left);
	DeleteBinaryTree(node->Right);
	delete node;
}