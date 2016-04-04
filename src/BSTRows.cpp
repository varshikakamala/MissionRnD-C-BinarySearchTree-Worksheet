/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int height_of_bst(struct node* node)
{

	if (node == NULL)
		return 0;

	int height1 = height_of_bst(node->left);
	int height2 = height_of_bst(node->right);
	if (height1 > height2)		return 1 + height1;
	return 1 + height2;
}

void row(struct node* root, int *arr, int *i, int level_of_node)
{
	if (root == NULL || level_of_node == 0)
		return;
	if (level_of_node == 1)
	{
		arr[*i] = root->data;
		*i = *i + 1;
	}
	if (root->right)
		row(root->right, arr, i, level_of_node - 1);
	if (root->left)
		row(root->left, arr, i, level_of_node - 1);
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)	return NULL;
	int *arr = (int *)malloc(sizeof(int));
	int height = height_of_bst(root);
	int i = 0;
	for (int j = 1; j <= height; j++)
		row(root, arr, &i, j);
	return arr;
}