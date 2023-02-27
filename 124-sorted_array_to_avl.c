#include "binary_trees.h"

avl_t *avl_build(int *array, size_t lo, size_t hi, avl_t *parent);

/**
 * sorted_array_to_avl - Build an AVL tree from a sorted array.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: Pointer to the root of the created AVL tree, otherwise NULL on
 * failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (avl_build(array, 0, size - 1, NULL));
}

/**
 * avl_build - A recursive function that builds an AVL tree from a sorted
 * array.
 *
 * @array: Pointer to the array.
 * @lo: The beginning of the subarray that will become a branch in the AVL.
 * @hi: The end of the subarray that will become a branch in the AVL.
 * @parent: Parent node of the sub-branch.
 *
 * Return: Root of the sub-branch.
 */
avl_t *avl_build(int *array, size_t lo, size_t hi, avl_t *parent)
{
	avl_t *node;
	size_t mid;

	if (lo > hi)
		return (NULL);
	mid = (hi - lo) / 2 + lo;

	node = binary_tree_node(parent, array[mid]);
	if (node == NULL)
		return (NULL);

	if (parent != NULL)
	{
		if (node->n < parent->n)
			parent->left = node;
		else
			parent->right = node;
	}
	if (mid > 0)
		avl_build(array, lo, mid - 1, node);
	avl_build(array, mid + 1, hi, node);

	return (node);
}
