#include "2Lab-5.hpp"

int BinarySearchTree::Add(unsigned int new_branch, BinarySearchTree *tree)
{
	if (!tree)
	{
		tree = new BinarySearchTree<int>;
		tree->data = new_branch;
		tree->parent = tree;
		return tree->data;
	}
	else if (tree->data > new_branch) Add(new_branch, tree);
	else if (tree->data < new_branch) Add(new_branch, tree); 
	else return tree->data;
}

int BinarySearchTree::Print(int check1, BinarySearchTree *tree)
{
	if (!tree) return check1; 
	if (tree->data == 10 ) check1 = 12;
	
	return check1;
}
int BinarySearchTree::Search(int check2, BinarySearchTree *tree)
{
	if (!tree) return check2;

	if(tree->data >= 0) 
		{ 
			tree->data = 1;
		}
	
	return tree->data;

}
int Deletion(int check3, BinarySearchTree *tree)
{
	if (!tree) return check3;
	
	cout << endl << endl << "Type the node you want to delete: "; 

	if (tree->data == check3) 
		{ 
			cout << endl << "[-] Error: You are trying to remove the root of the tree!" << endl;
			return 0;
		}

	
}
int FreeTree(int check4, BinarySearchTree *tree)
{
	if (tree != NULL)
	{
		delete tree;
		tree = NULL;
	}
	
	return check4;
}
