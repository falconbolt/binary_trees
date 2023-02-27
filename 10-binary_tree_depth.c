#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Return: height of the binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *cur;
	size_t depth = 0;

	if (tree == NULL)
		return (depth);

	cur = tree->parent;
	while (cur != NULL)
	{
		depth++;
		cur = cur->parent;
	}

	return (depth);
}
