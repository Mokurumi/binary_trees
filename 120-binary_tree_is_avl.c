#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);

	balance = binary_tree_balance(tree);
	if (balance != 0)
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);

	if (tree->right)
		if (tree->right->n < tree->n)
			return (0);

	if (tree->left && tree->right)
		if (tree->left->n > tree->right->n)
			return (0);

	if (tree->left)
		if (!binary_tree_is_avl(tree->left))
			return (0);

	if (tree->right)
		if (!binary_tree_is_avl(tree->right))
			return (0);

	return (1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = 1 + binary_tree_balance(tree->left);

	if (tree->right)
		right = 1 + binary_tree_balance(tree->right);

	return (left - right);
}
