#include "binary_trees.h"

/**
 * array_to_heap - Build an max binary tree from an array.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: Pointer to the root node, or NULL upon failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t idx;
	avl_t *root;

	root = NULL;
	if (array == NULL || size == 0)
		return (root);

	for (idx = 0; idx < size; idx++)
		heap_insert(&root, array[idx]);

	return (root);
}
