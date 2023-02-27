#include "binary_trees.h"

/**
 * array_to_bst - Build a BST from an array.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: Pointer to the root node, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t idx;
	bst_t *root;

	root = NULL;
	if (array == NULL || size == 0)
		return (root);

	for (idx = 0; idx < size; idx++)
		bst_insert(&root, array[idx]);

	return (root);
}
