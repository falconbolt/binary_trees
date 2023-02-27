#include "binary_trees.h"

size_t traverse(const binary_tree_t *node, size_t height);

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Return: height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree != NULL)
		height = traverse(tree, height);

	return (height);
}

/**
 * traverse - Recursively travel down the left side first.
 *
 * @node: Pointer to the current node.
 * @height: Height of the tree currently.
 *
 * Return: The greatest height between the left and right branches.
 */
size_t traverse(const binary_tree_t *node, size_t height)
{
	size_t left_h, right_h;

	left_h = height;
	right_h = height;

	if (node->left != NULL)
		left_h = traverse(node->left, height + 1);

	if (node->right != NULL)
		right_h = traverse(node->right, height + 1);

	if (left_h > right_h)
		return (left_h);
	else
		return (right_h);
}
