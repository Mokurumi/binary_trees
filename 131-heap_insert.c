#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	parent = *root;
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent)
	{
		*root = new_node;
		return (new_node);
	}

	while (1)
	{
		if (parent->n >= value)
		{
			if (!parent->left)
			{
				parent->left = new_node;
				break;
			}
			parent = parent->left;
		}
		else
		{
			if (!parent->right)
			{
				parent->right = new_node;
				break;
			}
			parent = parent->right;
		}
	}

	return (new_node);
}
