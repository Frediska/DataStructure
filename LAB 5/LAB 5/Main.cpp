#include <iostream>
#include "BinaryTree.h"

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

void ShowBinaryTree(BinaryTreeNode* node, int level)
{
	if (node)
	{
		ShowBinaryTree(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << node->Data << endl;
		ShowBinaryTree(node->Left, level + 1);
	}
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
				binaryTree->Root = DeleteElement(binaryTree->Root, value);
				cout << "--------------------------" << endl;
				ShowBinaryTree(binaryTree->Root, 0);
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
				if (SearchElement(binaryTree->Root, value))
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
				ShowBinaryTree(binaryTree->Root, 0);
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
