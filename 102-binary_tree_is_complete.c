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
	int current_level_nodes, i, level = 0;
	bool end = false;
	binary_tree_t **queue, *current;

	if (tree == NULL)
		return (0);

	**queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[0] = (binary_tree_t *)tree;

	while (queue[level] != NULL)
	{
		current_level_nodes = 1 << level;
		for (i = 0; i < current_level_nodes; i++)
		{
			*current = queue[i + current_level_nodes];
			if (current == NULL)
				end = true;
			else
			{
				if (end)
				{
					free(queue);
					return (0);
				}
				queue[i] = current;
			}
		}
		if (!end)
			queue[current_level_nodes] = NULL;
		level++;
	}

	free(queue);
	return (1);
}
