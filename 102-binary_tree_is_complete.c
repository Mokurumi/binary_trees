#include "binary_trees.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	const binary_tree_t **queue, *current;
	int front = 0, rear = 0;
	bool flag = false;

	if (tree == NULL)
		return (0);

	/* Create a queue to perform level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1000);

	current = tree;
	queue[rear++] = current;

	while (front < rear)
	{
		current = queue[front++];

		/* If a node has no left child, it should not have a right child */
		if (current->left == NULL)
			flag = true;
		else if (flag)
		{
			free(queue);
			return (0);
		}
		else
			queue[rear++] = current->left;

		/**
		 * If a node has no right child,
		 * all subsequent nodes must also not have a left or right child
		 */
		if (current->right == NULL)
			flag = true;
		else if (flag)
		{
			free(queue);
			return (0);
		}
		else
			queue[rear++] = current->right;
	}

	free(queue);
	return (1);
}
