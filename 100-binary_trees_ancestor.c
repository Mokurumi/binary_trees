#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);

	temp = first;
	while (temp)
	{
		if (temp == second)
			return ((binary_tree_t *)temp);
		temp = temp->parent;
	}

	temp = second;
	while (temp)
	{
		if (temp == first)
			return ((binary_tree_t *)temp);
		temp = temp->parent;
	}

	return (binary_trees_ancestor(first->parent, second->parent));
}
