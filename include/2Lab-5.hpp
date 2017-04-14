#include <iostream>
#include <stdlib.h>
using namespace std;
 

class BinarySearchTree
{

public: 
	BinarySearchTree *parent; 
	unsigned int data;
	int Add(unsigned int new_data, BinarySearchTree *&tree);
	int print(int check1, BinarySearchTree *tree);
	int Search(int check2, BinarySearchTree *tree);
	int Deletion(int check3, BinarySearchTree *tree);
	int FreeTree(int check4, BinarySearchTree *&tree);
};
