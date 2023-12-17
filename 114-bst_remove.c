#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST from which to remove the node
 * @value: Value to remove in the BST
 *
 * Return: Pointer to the new root node of the BST after removing the desired
 * value, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value == root->n)
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}

		if (root->left)
		{
			node = root->left;
			while (node->right)
				node = node->right;
		}
		else
		{
			node = root->right;
			while (node->left)
				node = node->left;
		}

		root->n = node->n;
		root->left = bst_remove(root->left, node->n);
	}

	return (root);
}
