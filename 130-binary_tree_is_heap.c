#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);
		left = binary_tree_is_heap(tree->left);
	}

	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		right = binary_tree_is_heap(tree->right);
	}

	return (left && right);
}
