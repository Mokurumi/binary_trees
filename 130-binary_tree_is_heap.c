#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 * Not complete tree, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);
		left = binary_tree_is_heap(tree->left);
		if (!left)
			return (0);
	}
	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		right = binary_tree_is_heap(tree->right);
		if (!right)
			return (0);
	}

	return (1);
}
