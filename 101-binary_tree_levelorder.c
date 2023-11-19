#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue, *current;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	/* Queue to store nodes for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1000);

	current = tree;
	queue[rear++] = current;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		/* Enqueue left child */
		if (current->left != NULL)
			queue[rear++] = current->left;

		/* Enqueue right child */
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}