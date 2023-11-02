#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (0);

	h_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((h_left > h_right) ? h_left : h_left);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size (number of nodes) of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t nodes = 1; /* Root node */

	if (tree == NULL)
		return (0);

	while (height > 0)
	{
		/* Double the nodes at each level */
		nodes *= 2;
		height--;
	}

	return (nodes == binary_tree_size(tree));
}
