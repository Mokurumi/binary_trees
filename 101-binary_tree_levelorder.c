#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL, *current;
	size_t front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		*current = queue[front];
		front++;

		func(current->n);

		if (current->left != NULL)
		{
			queue[rear] = current->left;
			rear++;
		}

		if (current->right != NULL)
		{
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
}
