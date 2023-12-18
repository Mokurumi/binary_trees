#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *temp, *max_node;
	int value, temp_value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	last_node = *root;
	while (last_node && last_node->left)
	{
		last_node = last_node->left;
		if (last_node->right)
			last_node = last_node->right;
	}

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	temp = *root;
	while (temp->left && temp->left != last_node && temp->right != last_node)
	{
		temp = temp->left;
		if (temp->right && temp->right != last_node)
			temp = temp->right;
	}

	if (temp->left)
		temp->left = NULL;
	else if (temp->right)
		temp->right = NULL;

	(*root)->n = last_node->n;
	free(last_node);

	while (1)
	{
		max_node = *root;
		if (max_node->left && max_node->left->n > max_node->n)
			max_node = max_node->left;
		if (max_node->right && max_node->right->n > max_node->n)
			max_node = max_node->right;

		if (max_node == *root)
			break;

		temp_value = (*root)->n;
		(*root)->n = max_node->n;
		max_node->n = temp_value;
		*root = max_node;
	}

	return (value);
}
