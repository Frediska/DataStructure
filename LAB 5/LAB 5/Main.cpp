#include <iostream>
#include "BinaryTree.h"
#include "Trunk.h"

using namespace std;

struct Trunk
{
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

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

void showTrunks(Trunk* p)
{
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	cout << p->str;
}

void ShowBinaryTree(BinaryTreeNode* root, Trunk* prev, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	ShowBinaryTree(root->Right, trunk, true);

	if (!prev) 
	{
		trunk->str = "---";
	}
	else if (isLeft)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else 
	{
		trunk->str = "'---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << " " << root->Data << endl;

	if (prev) {
		prev->str = prev_str;
	}
	trunk->str = "   |";

	ShowBinaryTree(root->Left, trunk, false);
}

void main()
{
	BinaryTree* binaryTree = new BinaryTree();
	cout << "Work with Binary Tree." << endl;

	while (true)
	{
		cout << "1. Add element to tree.\n2. Remove element from tree.\n"
			"3. Find element in tree.\n4. Find the max element.\n"
			"5. Find the min element.\n6. Show tree.\n";

		int taskNumber = CheckingForDigit("Enter number action: ");

		switch (taskNumber)
		{
			case 1:
			{
				int value = CheckingForDigit("Enter value: ");
				AddElement(binaryTree, value);
				break;
			}
			case 2:
			{
				if (!binaryTree->Root)
				{
					cout << "Binary tree empty." << endl;

					break;
				}
				int value = CheckingForDigit("Enter value: ");
				BinaryTreeNode* node = DeleteElement(binaryTree->Root, value);
				if (node)
				{
					cout << "Element not found." << endl;
				}
				cout << "--------------------------" << endl;
				ShowBinaryTree(binaryTree->Root, nullptr, false);
				cout << "--------------------------" << endl;
				break;
			}
			case 3:
			{
				if (!binaryTree->Root)
				{
					cout << "Binary tree empty." << endl;

					break;
				}
				int value = CheckingForDigit("Enter value: ");
				BinaryTreeNode* node = SearchElement(binaryTree->Root, value);
				if (!node)
				{
					cout << "Item is found." << endl;
				}
				else
				{
					cout << "Element not found." << endl;
				}
				break;
			}
			case 4:
			{
				if (!binaryTree->Root)
				{
					cout << "Binary tree empty." << endl;

					break;
				}
				cout << "Max value: " << SearchMaxElement(binaryTree->Root)->Data << endl;
				break;
			}
			case 5:
			{
				if (!binaryTree->Root)
				{
					cout << "Binary tree empty." << endl;

					break;
				}
				cout << "Min value: " << SearchMinElement(binaryTree->Root)->Data << endl;
				break;
			}
			case 6:
			{
				if (!binaryTree->Root)
				{
					cout << "Binary tree empty." << endl;

					break;
				}
				cout << "--------------------------" << endl;
				ShowBinaryTree(binaryTree->Root, nullptr, false);
				cout << "--------------------------" << endl;
				break;
			}
			case 0:
			{	
				
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}
