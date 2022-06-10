#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

#define CHECK_ALLOCATION(x) do {	\
						if((x)==NULL) {\
						printf("allocation fail");	\
                         exit(1); } \
					    }while(0)





void initBST(BST* bst)
{
	bst->root = NULL;
}//initBST

void insertBST(BST* bst, int value)
{
	insertBST_root(bst->root, value);
}//insertBST

void insertBST_root(TreeNode* node, int value)
{
	if (node == NULL)
		node = createNode(value);
	else
		insertNode(node, value);
}//insertBST_root

void insertNode(TreeNode* node, int data)
{
	if (data <= node->element)
	{
		if (node->left == NULL)
			node->left = createNode(data);
		else
			insertNode(node->left, data);
	}
	else 
	{
		if (node->right == NULL)
			node->right = createNode(data);
		else
			insertNode(node->right, data);
	}
}//insertNode

TreeNode* createNode(int data)
{
	TreeNode* Temp = (TreeNode*)calloc(1, sizeof(TreeNode));
	CHECK_ALLOCATION(Temp);
	Temp->element = data;
	return Temp;
}//createNode

void printTreeInorder(BST* bst)
{
	if (bst != NULL)
	{
		printTreeInorder(bst->root->left);
		printf(" % d", bst->root->element);
		printTreeInorder(bst->root->right);
	}
	else
		printf(" The tree is empty");
}//printTreeInorder

void destroyBST(BST* bst)
{
	if (bst == NULL)
		return;
		destroyBST(bst->root->left);
		destroyBST(bst->root->right);
			free(bst);
}//destroyBST

int findIndexNFromLast(BST* bst, int* N)
{
	
		if (bst != NULL)
		{
			findIndexNFromLast(bst->root->right, N);
			if (*N > 0)
				*N--;
			else
			{
				return bst->root->element;
			}

			findIndexNFromLast(bst->root->left, *N);
		}

}//findIndexNFromLast

int sameHeightLeaves(BST* bst)
{
	int heLeft;
	int heRight;
	if (bst == NULL)
		return 1;
	if (bst->root->left == NULL && bst->root->right == NULL)
		return 1;
	if (bst->root->left != NULL)
		 heLeft = heightRec(bst->root->left);
	if (bst->root->right != NULL)
		 heRight = heightRec(bst->root->right);
	if(heLeft > heRight)
		return 1;
	return 0;
}//sameHeightLeaves

int heightRec(TreeNode* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 0;

	int heLeft = heightRec(node->left);
	int heRight = heightRec(node->right);
	if (heLeft > heRight)
		return 1 + heLeft;
	return 1 + heRight;
}//heightRec