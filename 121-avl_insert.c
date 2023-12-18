#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Pointer to the root node of the AVL Tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		(*tree)->left = avl_insert(&((*tree)->left), value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert(&((*tree)->right), value);
	else
		return (NULL);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
