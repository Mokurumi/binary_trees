#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *current = NULL;

	if (!tree)
		return (NULL);

	current = *tree;
	while (current)
	{
		if (value == current->n)
			return (NULL);
		if (value < current->n)
		{
			if (!current->left)
			{
				new_node = binary_tree_node(current, value);
				if (!new_node)
					return (NULL);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (!current->right)
			{
				new_node = binary_tree_node(current, value);
				if (!new_node)
					return (NULL);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}
	new_node = binary_tree_node(current, value);
	if (!new_node)
		return (NULL);
	*tree = new_node;
	return (new_node);
}
