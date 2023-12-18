#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, i;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(sizeof(int) * *size);
	if (!array)
		return (NULL);

	for (i = 0; i < (int) *size; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
