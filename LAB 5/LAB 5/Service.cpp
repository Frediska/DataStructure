#include <iostream>
#include "Service.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "An error has occurred. Try again." << endl;
			continue;
		}

		cin.ignore(32767, '\n');
		if (cin.gcount() > 1)
		{
			cout << "An error has occurred. Try again." << endl;
			continue;
		}
		break;
	}
	return value;
}

//TODO: rsdn
void ShowRib(Rib* rib)
{
	if (rib == nullptr) {
		return;
	}

	ShowRib(rib->prev);
	cout << rib->str;
}

void ShowBinaryTree(BinaryTreeNode* root, Rib* prev, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	//TODO: rsdn
	string prevStr = "    ";
	Rib* rib = new Rib(prev, prevStr);

	ShowBinaryTree(root->Right, rib, true);

	if (!prev)
	{
		rib->str = "---";
	}
	else if (isLeft)
	{
		rib->str = ".---";
		prevStr = "   |";
	}
	else
	{
		rib->str = "'---";
		prev->str = prevStr;
	}

	ShowRib(rib);
	cout << " " << root->Data << endl;

	if (prev) {
		prev->str = prevStr;
	}
	rib->str = "   |";

	ShowBinaryTree(root->Left, rib, false);
}

void ShowTreap(TreapNode* node, int level)
{
	if (node)
	{
		ShowTreap(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << node->Data << " : " << node->Priority << endl;
		ShowTreap(node->Left, level + 1);
	}

}

bool BinaryTreeIsEmpty(BinaryTree* binaryTree)
{
	if (!binaryTree->Root)
	{
		cout << "Binary tree empty." << endl;
		return false;
	}
	return true;
}

bool TreapIsEmpty(Treap* treap)
{
	if (!treap->Root)
	{
		cout << "Treap is empty." << endl;
		return false;
	}
	return true;
}

bool CheckElement(int value, Treap* treap, TreapNode* node)
{
	if (treap->Root)
	{
		if (SearchElement(node, value))
		{
			cout << "Element with value " << value << " already exists." << endl;
			return false;
		}
	}
	return true;
}

