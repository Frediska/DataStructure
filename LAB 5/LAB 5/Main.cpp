#include <iostream>
#include "Service.h"

using namespace std;

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
				//TODO: duplication
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				DeleteElement(binaryTree->Root, value);
				cout << "--------------------------" << endl;
				ShowBinaryTree(binaryTree->Root, nullptr, false);
				cout << "--------------------------" << endl;
				break;
			}
			case 3:
			{
				//TODO: duplication
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				BinaryTreeNode* node = SearchElement(binaryTree->Root, value);
				//TODO: bool
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
				//TODO: duplication
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				cout << "Max value: " << SearchMaxElement(binaryTree->Root)->Data << endl;
				break;
			}
			case 5:
			{
				//TODO: duplication
				if (!BinaryTreeIsEmpty(binaryTree))
				{
					break;
				}
				cout << "Min value: " << SearchMinElement(binaryTree->Root)->Data << endl;
				break;
			}
			case 6:
			{
				//TODO: duplication
				if (!BinaryTreeIsEmpty(binaryTree))
				{
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
			//TODO: rsdn
			case 1:
			{
				//TODO: duplication
				if (!TreapIsEmpty(treap))
				{
					break;
				}
				int value = CheckingForDigit("Enter value: ");
				TreapNode* node = SearchElement(treap->Root, value);
				//TODO: 
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
				//TODO: duplication
				if (!CheckElement(value, treap, treap->Root))
				{
					break;
				}
				AddElementNotOptimization(treap->Root, value);
				break;
			}
			case 3:
			{
				int value = CheckingForDigit("Enter value: ");
				//TODO: duplication
				if (!CheckElement(value, treap, treap->Root))
				{
					break;
				}
				AddElementOptimization(value, rand() % treap->MaxPriority, treap->Root);
				break;
			}
			case 4:
			{
				//TODO: duplication
				if (!TreapIsEmpty(treap))
				{
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
				//TODO: duplication
				if (!TreapIsEmpty(treap))
				{
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
				//TODO: duplication
				if (!TreapIsEmpty(treap))
				{
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
