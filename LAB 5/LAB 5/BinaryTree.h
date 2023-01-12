#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
};

bool AddElement(BinaryTree* tree, int value);
BinaryTreeNode* SearchParentNode(BinaryTreeNode* node, int value);
BinaryTreeNode* DeleteElement(BinaryTreeNode* binaryTree, int value);
BinaryTreeNode* SearchMinElement(BinaryTreeNode* node);
BinaryTreeNode* SearchMaxElement(BinaryTreeNode* node);
BinaryTreeNode* SearchElement(BinaryTreeNode* node, int value);
void DeleteBinaryTree(BinaryTreeNode* node);