#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node;

	if (!root || !*root)
		return (0);

	node = *root;
	value = node->n;

	if (!node->left && !node->right)
	{
		*root = NULL;
		free(node);
		return (value);
	}

	node = get_last_node(node);
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	(*root)->n = node->n;
	free(node);

	heapify(*root);

	return (value);
}

/**
 * get_last_node - gets the last node of a Max Binary Heap
 * @root: pointer to the root node of the heap
 *
 * Return: pointer to the last node, or NULL on failure
 */
heap_t *get_last_node(heap_t *root)
{
	int size, path;
	heap_t *node;

	size = binary_tree_size(root);
	path = size / 2;
	node = root;

	while (path > 0)
	{
		if (path & 1)
			node = node->right;
		else
			node = node->left;
		path /= 2;
	}

	return (node);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree, or 0 on failure
 */
size_t binary_tree_size(const heap_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (size);
}

/**
 * heapify - heapifies a Max Binary Heap
 * @root: pointer to the root node of the heap
 */
void heapify(heap_t *root)
{
	int temp;
	heap_t *node;

	if (!root)
		return;

	node = root;
	while (node->left)
	{
		if (!node->right || node->left->n > node->right->n)
		{
			if (node->left->n > node->n)
			{
				temp = node->n;
				node->n = node->left->n;
				node->left->n = temp;
			}
			node = node->left;
		}
		else
		{
			if (node->right->n > node->n)
			{
				temp = node->n;
				node->n = node->right->n;
				node->right->n = temp;
			}
			node = node->right;
		}
	}
}
