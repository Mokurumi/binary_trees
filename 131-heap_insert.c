#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	insert_node(*root, new_node);
	swap_nodes(new_node);

	return (new_node);
}

/**
 * insert_node - inserts a node into a Max Binary Heap
 * @root: pointer to the root node of the Heap
 * @node: pointer to the node to be inserted
 */
void insert_node(heap_t *root, heap_t *node)
{
	if (root->left && root->right)
	{
		if (binary_tree_size(root->left) <= binary_tree_size(root->right))
			insert_node(root->left, node);
		else
			insert_node(root->right, node);
	}
	else
	{
		if (!root->left)
			root->left = node;
		else
			root->right = node;
		node->parent = root;
	}
}

/**
 * swap_nodes - swaps a node with its parent
 * @node: pointer to the node to be swapped
 */
void swap_nodes(heap_t *node)
{
	int temp;

	while (node->parent)
	{
		if (node->n > node->parent->n)
		{
			temp = node->n;
			node->n = node->parent->n;
			node->parent->n = temp;
			node = node->parent;
		}
		else
			break;
	}
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
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
heap_t *binary_tree_node(heap_t *parent, int value)
{
	heap_t *new_node = NULL;

	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
