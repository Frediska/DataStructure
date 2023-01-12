#include <iostream>
#include "BinaryTree.h"
#include "Rib.h"
#include "Treap.h"

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

void showRib(Rib* rib)
{
	if (rib == nullptr) {
		return;
	}

	showRib(rib->prev);
	cout << rib->str;
}

void ShowBinaryTree(BinaryTreeNode* root, Rib* prev, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	string prev_str = "    ";
	Rib* rib = new Rib(prev, prev_str);

	ShowBinaryTree(root->Right, rib, true);

	if (!prev) 
	{
		rib->str = "---";
	}
	else if (isLeft)
	{
		rib->str = ".---";
		prev_str = "   |";
	}
	else 
	{
		rib->str = "'---";
		prev->str = prev_str;
	}

	showRib(rib);
	cout << " " << root->Data << endl;

	if (prev) {
		prev->str = prev_str;
	}
	rib->str = "   |";

	ShowBinaryTree(root->Left, rib, false);
}

void MenuBinaryTree()
{
	BinaryTree* binaryTree = new BinaryTree();
	cout << "Work with Binary Tree." << endl;

	while (true)
	{
		cout << "1. Add element to tree.\n2. Remove element from tree.\n"
			"3. Find element in tree.\n4. Find the max element.\n"
			"5. Find the min element.\n6. Show tree.\n"
			"0. Go to menu." << endl;

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
				if (!node)
				{
					cout << "Element not found." << endl;
				}
				else
				{
					cout << "Element is found." << endl;
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
				DeleteBinaryTree(binaryTree->Root);
				system("cls");
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

bool CheckElement(int value, TreapNode* treap)
{
	return SearchElement(treap, value);
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
		cout << node->Priority << " : " << node->Data << endl;
		ShowTreap(node->Left, level + 1);
	}

}

void MenuTreap()
{
	Treap* treap = new Treap();
	cout << "Work with Treap." << endl;

	while (true)
	{
		cout << "1. Find element in treap.\n2. Add element to treap (not optimization).\n"
			"3. Add element to treap (optimization).\n4. Delete element in treap (not optimization).\n"
			"5. Delete element in treap (optimization).\n6. Show treap.\n"
			"0. Go to menu." << endl;

		int taskNumber = CheckingForDigit("Enter number action: ");

		switch (taskNumber)
		{
		case 1:
		{
			if (!treap->Root)
			{
				cout << "Binary tree empty." << endl;

				break;
			}
			int value = CheckingForDigit("Enter value: ");
			TreapNode* node = SearchElement(treap->Root, value);
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
		case 2:
		{
			int value = CheckingForDigit("Enter value: ");
			if (treap->Root)
			{
				if (CheckElement(value, treap->Root))
				{
					cout << "Element with value " << value << " Already exists." << endl;
					break;
				}
			}
			AddElementNotOptimization(treap->Root, value);
			break;
		}
		case 3:
		{
			int value = CheckingForDigit("Enter value: ");
			if (treap->Root)
			{
				if (CheckElement(value, treap->Root))
				{
					cout << "Element with value " << value << " Already exists." << endl;
					break;
				}
			}
			AddElementOptimization(value, rand() % treap->MaxPriority, treap->Root);
			break;
		}
		case 4:
		{
			if (!treap->Root)
			{
				cout << "Binary tree empty." << endl;

				break;
			}
			int value = CheckingForDigit("Enter value: ");
			DeleteNotOptimization(treap->Root, value);
			cout << "--------------------------" << endl;
			ShowTreap(treap->Root, 0);
			cout << "--------------------------" << endl;
			break;
		}
		case 5:
		{
			if (!treap->Root)
			{
				cout << "Binary tree empty." << endl;

				break;
			}
			int value = CheckingForDigit("Enter value: ");
			DeleteOptimization(value, treap->Root);
			cout << "--------------------------" << endl;
			ShowTreap(treap->Root, 0);
			cout << "--------------------------" << endl;
			break;
		}
		case 6:
		{
			if (!treap->Root)
			{
				cout << "Binary tree empty." << endl;

				break;
			}
			cout << "--------------------------" << endl;
			ShowTreap(treap->Root, 0);
			cout << "--------------------------" << endl;
			break;
		}
		case 0:
		{
			DeleteTreap(treap->Root);
			system("cls");
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

void main()
{
	cout << "Choose which function you want to use: " << endl;

	while (true)
	{
		cout << "1. Binary tree.\n2. Treap." << endl;

		int taskNumber = CheckingForDigit("Enter function number: ");
		switch (taskNumber)
		{
		case 1:
		{
			system("cls");
			MenuBinaryTree();
			break;
		}
		case 2:
		{
			system("cls");
			MenuTreap();
			break;
		}
		default:
		{
			cout << "Enter correct number of action." << endl;
			break;
		}
		}
	}
}
