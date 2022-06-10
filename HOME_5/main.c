#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void main()
{
		BST* bst = (BST*)calloc(1, sizeof(BST));
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		initBST(bst);
		insertBST(bst, 5);
		insertBST(bst, 7);
		insertBST(bst, 6);
		insertBST(bst, 4);
		insertBST(bst, 5);
		insertBST(bst, 6);
		print_ascii_tree(bst->root);
		printf("\n");
		printTreeInorder(bst);
		int N = 2;
		int elementt = findIndexNFromLast(bst, N); 
		printf("The second biggest element %d \n", elementt);
		if (sameHeightLeaves(bst) == 1)
			printf("They are the same height\n");
		printf("They are not the same height");
		destroyBST(bst);
}//main