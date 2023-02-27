#include "binary_trees.h"

void traverse(const binary_tree_t *node, size_t *count);

/**
 * binary_tree_leaves - Count the leaves of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Return: Size of the binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree != NULL)
		traverse(tree, &count);

	return (count);
}

/**
 * traverse - Recursively travel down the left side of a binary tree first.
 *
 * @node: Pointer to the current node.
 * @count: Pointer to the counter for the number of leaves.
 */
void traverse(const binary_tree_t *node, size_t *count)
{
	size_t not_leaf;

	(*count)++;
	not_leaf = 0;

	if (node->left != NULL)
	{
		traverse(node->left, count);
		not_leaf = 1;
	}

	if (node->right != NULL)
	{
		traverse(node->right, count);
		not_leaf = 1;
	}

	(*count) -= not_leaf;
}
