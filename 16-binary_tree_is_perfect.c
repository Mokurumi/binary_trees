#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: height of the tree, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: The size (number of nodes) of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_l = 0, size_r = 0;

	if (!tree)
		return (0);

	size_l = tree->left ? binary_tree_size(tree->left) : 0;
	size_r = tree->right ? binary_tree_size(tree->right) : 0;

	return (size_l + size_r + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, size = 0;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	return (size == (2 << height) - 1);
}
