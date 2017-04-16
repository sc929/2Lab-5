#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int height = 0;
int number = 0;
bool t = true, k = true, deleted = true;

template <class Type>
class BinarySearchTree
{
private:
	Type data;
	BinarySearchTree *right;
	BinarySearchTree *left;

public:
	void Add(Type new_branch, BinarySearchTree *&tree)
	{
		if (!tree)
		{
			tree = new BinarySearchTree;
			tree->data = new_branch;
			tree->right = 0;
			tree->left = 0;
			return;
		}
		else if (tree->data > new_branch) Add(new_branch, tree->right);
		else if (tree->data < new_branch) Add(new_branch, tree->left);
		else return;
	}

	void Search(BinarySearchTree *root)
	{
		if (!root) return;

		if (k)
		{
			k = false;
			cout << endl << "Type the number you want to find: ";
			cin >> number;
		}

		if (root->data == number)
		{
			t = false;
			cout << "Your number '" << number << "' was found!" << endl;
		}

		Search(root->right);
		Search(root->left);
	}

	void Print(BinarySearchTree *tree, bool ptr)
	{
		if (!tree) return;
		if (ptr)
		{
			height++;
			Print(tree->left, true);

			for (int i = 0; i < height - 1; ++i) cout << "- ";
			cout << tree->data << endl;

			Print(tree->right, true);
			height--;
		}
		else
		{
			Print(tree->left, false);

			cout << tree->data << " ";

			Print(tree->right, false);
		}

		return;
	}

	void Delete_branch(BinarySearchTree *tree)
	{
		if (!tree) return;

		if (deleted)
		{
			if (tree->left != 0)
				if (tree->left->data == number)
				{
					deleted = false;
					Free_Tree(tree->left);
					tree->left = 0;
				}
			if (tree->right != 0)
				if (tree->right->data == number)
				{
					deleted = false;
					Free_Tree(tree->right);
					tree->right = 0;
				}
		}

		Delete_branch(tree->left);
		Delete_branch(tree->right);

		return;
	}

	void Free_Tree(BinarySearchTree *tree)
	{
		if (tree != NULL)
		{
			Free_Tree(tree->left);
			Free_Tree(tree->right);
			delete tree;
			tree = NULL;
		}
		return;
	}
};

int main(void)
{
	BinarySearchTree<int> *tree = 0;
	BinarySearchTree<int> *ptr = 0;
	int* data;
	int size = 0;

	cout << "Print the number of nodes: ";
	cin >> size;
	try
	{
		if (size < 0) throw size;
	}
	catch (int error)
	{
		cout << endl << "ERROR!!! The number of nodes ("<< error << ") can't be negative!" << endl;
		return 0;
	}
	data = new int[size];

	for (unsigned int i = 0; i < size; ++i)
	{
		cout << "Add node " << i + 1 << ": ";
		cin >> data[i];
	}
	for (unsigned int i = 0; i < size; ++i)
	{
		ptr->Add(data[i], tree);
	}

	cout << endl << size << " ";
	ptr->Print(tree, false);
	cout << endl << endl;
	ptr->Print(tree, true);
	ptr->Search(tree);
	if (t)
	{
		cout << "The number you were searching for was not found" << endl;
	}

	cout << endl << endl << "Type the node you want to delete: ";
	cin >> number;
	ptr->Delete_branch(tree);
	cout << endl << "The result of deletion: " << endl;
	ptr->Print(tree, true);

	ptr->Free_Tree(tree);
	delete[] data;
	cout << endl << "Press any button to exit the program" << endl;
	_getch();
	return 0;
}
