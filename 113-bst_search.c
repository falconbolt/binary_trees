#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a BST.
 *
 * @tree: Pointer to the root node of the BST.
 * @value: Value to search for.
 *
 * Return: Pointer to the node containing the value, otherwise NULL if not
 * found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *cur;

	if (tree == NULL)
		return (NULL);

	cur = (bst_t *) tree;

	while (cur != NULL)
	{
		if (cur->n == value)
			return (cur);
		if (value < cur->n)
			cur = cur->left;
		else
			cur = cur->right;
	}

	return (NULL);
}
