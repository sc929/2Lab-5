#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int height = 0;
int number = 0;
bool t = true, k = true;

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

	void Print(BinarySearchTree *tree)
	{
		if (!tree) return;

		height++;
		Print(tree->left);

		for (int i = 0; i < height - 1; ++i) cout << "- ";
		cout << tree->data << endl;

		Print(tree->right);
		height--;

		return;
	}

	void Free_Tree(BinarySearchTree *root)
	{
		if (!root) return;
		Free_Tree(root->right);
		Free_Tree(root->left);
		delete root;
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

	cout << endl;
	ptr->Print(tree);
	ptr->Search(tree);
	if (t)
	{
		cout << "The number you were searching for was not found" << endl;
	}

	ptr->Free_Tree(tree);
	delete[] data;
	cout << endl << "Press any button to exit the program" << endl;
	_getch();
	return 0;
}