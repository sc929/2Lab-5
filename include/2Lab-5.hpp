#include <iostream>
#include <stdlib.h>
using namespace std;
 

template <class Type>
class BinarySearchTree
{

public: 
	unsigned int data;
	int Add(unsigned int new_data, BinarySearchTree *&tree);
	int Print(int check1, BinarySearchTree *tree);
	int Search(int check2, BinarySearchTree *tree);
	int Deletion(int check3, BinarySearchTree *tree);
	int FreeTree(int check4, BinarySearchTree *&tree);
};
