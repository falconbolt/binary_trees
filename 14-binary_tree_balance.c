#include "binary_trees.h"

size_t traverse(const binary_tree_t *node, size_t height);

/**
 * binary_tree_balance - Measure the balance factor of a binary tree. If the
 * balance factor is > 0 then the tree is left-heavy, while < 0 is right-heavy.
 * If the balance factor is 0 then the tree is balanced.
 *
 * @tree: Pointer to the root node of a tree.
 *
 * Return: The balance factor of the tree. 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = 0;
	right_h = 0;
	if (tree->left != NULL)
		left_h = traverse(tree->left, left_h);
	if (tree->right != NULL)
		right_h = traverse(tree->right, right_h);

	return ((int) (left_h - right_h));
}

/**
 * traverse - Recursively travel down a binary tree starting with the left
 * branch.
 *
 * @node: Pointer to the current node.
 * @height: Height of the tree currently.
 *
 * Return: The greatest height between the left and right branches.
 */
size_t traverse(const binary_tree_t *node, size_t height)
{
	size_t left_h, right_h;

	height++;
	left_h = height;
	right_h = height;

	if (node->left != NULL)
		left_h = traverse(node->left, height);

	if (node->right != NULL)
		right_h = traverse(node->right, height);

	if (left_h > right_h)
		return (left_h);
	else
		return (right_h);
}
