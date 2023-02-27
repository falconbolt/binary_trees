#include "binary_trees.h"
#include <stdlib.h>

size_t get_size(heap_t *heap);

/**
 * heap_to_sorted_array - Convert a binary max heap to a sorted array of
 * integers.
 *
 * @heap: Pointer to the root of a binary max heap.
 * @size: Pointer to the size of the array that will contain the values.
 *
 * Return: Pointer to the sorted array of integersi, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted;
	size_t idx;

	if (heap == NULL || size == NULL)
		return (NULL);

	*size = get_size(heap);

	sorted = malloc(sizeof(int) * (*size));
	if (sorted == NULL)
		return (NULL);

	for (idx = 0; idx < *size; idx++)
		sorted[idx] = heap_extract(&heap);

	return (sorted);
}

/**
 * get_size - Get the size of a max binary heap.
 *
 * @heap: Pointer to root node of current tree.
 *
 * Return: The size of the max binary heap.
 */
size_t get_size(heap_t *heap)
{
	if (heap == NULL)
		return (0);
	return (1 + get_size(heap->left) + get_size(heap->right));
}
