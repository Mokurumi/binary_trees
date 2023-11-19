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
	if (tree == NULL)
		return (NULL);

	/* If the tree is empty, create a new node and make it the root */
	if (*tree == NULL)
	{
		*tree = malloc(sizeof(bst_t));
		if (*tree == NULL)
			return (NULL); /* Memory allocation failed */

		(*tree)->value = value;
		(*tree)->left = (*tree)->right = NULL;
		return (*tree);
	}

	/* If the value is already present in the tree, ignore it */
	if ((*tree)->value == value)
		return (NULL);

	/* If the value is less than the current node's value, go left */
	if (value < (*tree)->value)
		return (bst_insert(&((*tree)->left), value));
	/* If the value is greater than the current node's value, go right */
	else
		return (bst_insert(&((*tree)->right), value));
}
