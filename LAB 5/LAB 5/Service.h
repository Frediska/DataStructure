#pragma once
#include "BinaryTree.h"
#include "Rib.h"
#include "Treap.h"

int CheckingForDigit(const char* text);
void ShowRib(Rib* rib);
void ShowBinaryTree(BinaryTreeNode* root, Rib* prev, bool isLeft);
void ShowTreap(TreapNode* node, int level);
bool BinaryTreeIsEmpty(BinaryTree* binaryTree);
bool TreapIsEmpty(Treap* treap);
bool CheckElement(int value, TreapNode* treap);
bool ForCheckTreap(int value, Treap* treap);