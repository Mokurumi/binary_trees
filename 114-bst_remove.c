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

	if (root->n == value)
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (!root->left && root->right)
		{
			node = root->right;
			node->parent = root->parent;
			free(root);
			return (node);
		}
		else if (root->left && !root->right)
		{
			node = root->left;
			node->parent = root->parent;
			free(root);
			return (node);
		}
		else
		{
			node = root->right;
			while (node->left)
				node = node->left;
			root->n = node->n;
			if (node->right)
				node->right->parent = node->parent;
			if (node->parent->left == node)
				node->parent->left = node->right;
			else
				node->parent->right = node->right;
			free(node);
			return (root);
		}
	}
	else if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
		return (root);
	}
	else
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
		return (root);
	}
}
