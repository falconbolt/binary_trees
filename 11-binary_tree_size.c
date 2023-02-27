#include "binary_trees.h"

void traverse(const binary_tree_t *node, size_t *size);

/**
 * binary_tree_size - Measure the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Return: Size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
		traverse(tree, &size);

	return (size);
}

/**
 * traverse - Recursively travel down the left side of a binary tree first.
 *
 * @node: Pointer to the current node.
 * @size: Pointer to the counter for size.
 */
void traverse(const binary_tree_t *node, size_t *size)
{
	(*size)++;

	if (node->left != NULL)
		traverse(node->left, size);

	if (node->right != NULL)
		traverse(node->right, size);
}
