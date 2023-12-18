#include "binary_trees.h"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * If tree is NULL, return 0
 * One value in right subtree is lower than root node value, return 0
 * One value in left subtree is higher than root node value, return 0
 * Duplicate values are not allowed in this AVL Tree
 * Single node tree, return 1
 * Perfect BST of any height, return 1
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
	{
		if (tree->left->n > tree->n)
			return (0);
	}

	if (tree->right)
	{
		if (tree->right->n < tree->n)
			return (0);
	}

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
