#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* Set initial minimum and maximum values for node values */
	int min = INT_MIN;
	int max = INT_MAX;

	if (tree == NULL)
		return (0);

	return (bst_helper(tree, min, max));
}

/**
 * bst_helper - Helper function to recursively check if tree is a valid BST
 *
 * @tree: Pointer to the current node
 * @min: Minimum value a node can take (INT_MIN for root node)
 * @max: Maximum value a node can take (INT_MAX for root node)
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1); /* An empty tree is considered as a BST */

	/* Check if the current node's value violates the BST property */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Recursively check the left and right subtrees */
	return (bst_helper(tree->left, min, tree->n)
			&& bst_helper(tree->right, tree->n, max));
}
